#include "browser.h"
#include "browserwindow.h"
#include "tabwidget.h"
#include "urllineedit.h"
#include "webview.h"
#include <QApplication>
#include <QCloseEvent>
#include <QDesktopWidget>
#include <QFileDialog>
#include <QMenuBar>
#include <QMessageBox>
#include <QProgressBar>
#include <QStatusBar>
#include <QToolBar>
#include <QVBoxLayout>

BrowserWindow::BrowserWindow(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags)
    , m_tabWidget(new TabWidget(this))
    , m_historyBackAction(nullptr)
    , m_urlLineEdit(new UrlLineEdit(this))
{
    setToolButtonStyle(Qt::ToolButtonFollowStyle);
    setAttribute(Qt::WA_DeleteOnClose, true);
		
		opsCombo= new QComboBox(this);
		opsCombo->setCurrentIndex(-1);
		opsCombo->addItem("ops");
		opsCombo->addItem("reload");
		opsCombo->addItem("quit");
		opsCombo->addItem("openFile");
		opsCombo->addItem("addTab");
		connect(opsCombo,SIGNAL(currentIndexChanged(const QString &)),this, SLOT(handleComboIndexChanged(const QString &)));
    QToolBar *toolbar = createToolBar(opsCombo);
    addToolBar(toolbar);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setSpacing(0);
    layout->setMargin(0);
    //addToolBarBreak();

    layout->addWidget(m_tabWidget);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(m_tabWidget, &TabWidget::titleChanged, this, &BrowserWindow::handleWebViewTitleChanged);
    connect(m_tabWidget, &TabWidget::urlChanged, this, &BrowserWindow::handleWebViewUrlChanged);
    connect(m_tabWidget, &TabWidget::iconChanged, this, &BrowserWindow::handleWebViewIconChanged);
    connect(m_tabWidget, &TabWidget::webActionEnabledChanged, this, &BrowserWindow::handleWebActionEnabledChanged);
    connect(m_urlLineEdit, &QLineEdit::returnPressed, this, [this]() {
        loadPage(m_urlLineEdit->url());
    });

    m_tabWidget->createTab();
		toolbar->show();
		statusBar()->close();
		menuBar()->close();

}

BrowserWindow::~BrowserWindow()
{
}

QSize BrowserWindow::sizeHint() const
{
    QRect desktopRect = QApplication::desktop()->screenGeometry();
    QSize size = desktopRect.size() * qreal(0.9);
    return size;
}

QToolBar *BrowserWindow::createToolBar(QComboBox *opsCombo)
{
    QToolBar *navigationBar = new QToolBar(tr("Navigation"));
    navigationBar->setAllowedAreas(Qt::TopToolBarArea | Qt::BottomToolBarArea);
    navigationBar->toggleViewAction()->setEnabled(false);

    m_historyBackAction = new QAction(this);
    m_historyBackAction->setIcon(QIcon(QStringLiteral(":go-previous.png")));
    connect(m_historyBackAction, &QAction::triggered, [this]() {
        m_tabWidget->triggerWebPageAction(QWebEnginePage::Back);
    });

    navigationBar->addWidget(m_urlLineEdit);
    navigationBar->addAction(m_historyBackAction);
		navigationBar->addWidget(opsCombo);
		
    int size = m_urlLineEdit->sizeHint().height();
    navigationBar->setIconSize(QSize(size, size));
    return navigationBar;
}

void BrowserWindow::handleWebViewIconChanged(const QIcon &icon)
{
//    m_urlLineEdit->setFavIcon(icon);
}

void BrowserWindow::handleWebViewUrlChanged(const QUrl &url)
{
    m_urlLineEdit->setUrl(url);
    if (url.isEmpty())
        m_urlLineEdit->setFocus();
}

void BrowserWindow::handleWebActionEnabledChanged(QWebEnginePage::WebAction action, bool enabled)
{
    switch (action) {
    case QWebEnginePage::Back:
        m_historyBackAction->setEnabled(enabled);
        break;
    default:
        qWarning("Unhandled webActionChanged singal");
    }
}

void BrowserWindow::handleWebViewTitleChanged(const QString &title)
{
    if (title.isEmpty())
        setWindowTitle(tr("Qt Simple Browser"));
    else
        setWindowTitle(tr("%1 - Qt Simple Browser").arg(title));
}
void BrowserWindow::handleComboIndexChanged(const QString &text)
{
	qDebug()<<"text ->>"<<text;
	if (text=="reload"){
		m_tabWidget->triggerWebPageAction(QWebEnginePage::Reload);
	}else if (text=="quit") {
		this->close();
	}else if (text=="openFile"){
		this->handleFileOpenTriggered();
	}else if (text=="addTab") {
		m_tabWidget->createTab();
	}
	opsCombo->setCurrentIndex(-1);
}

void BrowserWindow::handleFileOpenTriggered()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Open Web Resource"), QString(),
                                                tr("Web Resources (*.html *.htm *.svg *.png *.gif *.svgz);;All files (*.*)"));
    if (file.isEmpty())
        return;
    loadPage(file);
}

void BrowserWindow::closeEvent(QCloseEvent *event)
{
    if (m_tabWidget->count() > 1) {
        int ret = QMessageBox::warning(this, tr("Confirm close"),
                                       tr("Are you sure you want to close the window ?\n"
                                          "There are %1 tabs open.").arg(m_tabWidget->count()),
                                       QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        if (ret == QMessageBox::No) {
            event->ignore();
            return;
        }
    }
    event->accept();
    deleteLater();
}

void BrowserWindow::loadPage(const QString &page)
{
    loadPage(QUrl::fromUserInput(page));
}

void BrowserWindow::loadPage(const QUrl &url)
{
    if (url.isValid()) {
        m_urlLineEdit->setUrl(url);
        m_tabWidget->setUrl(url);
    }
}

TabWidget *BrowserWindow::tabWidget() const
{
    return m_tabWidget;
}

WebView *BrowserWindow::currentTab() const
{
    return m_tabWidget->currentWebView();
}

void BrowserWindow::handleShowWindowTriggered()
{
    if (QAction *action = qobject_cast<QAction*>(sender())) {
        int offset = action->data().toInt();
        QVector<BrowserWindow*> windows = Browser::instance().windows();
        windows.at(offset)->activateWindow();
        windows.at(offset)->currentTab()->setFocus();
    }
}
