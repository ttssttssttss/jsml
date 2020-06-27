#include "browserwindow.h"
#include "browser.h"
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
    : QMainWindow(parent, flags), m_tabWidget(new TabWidget(this)),
      m_urlLineEdit(new UrlLineEdit(this)) {
  setToolButtonStyle(Qt::ToolButtonFollowStyle);
  setAttribute(Qt::WA_DeleteOnClose, true);
  setStyleSheet(
      "QMainWindow{border-image:url(/root/Documents/bg.jpg);border:0px;}");
  QWidget *centralWidget = new QWidget(this);
  QVBoxLayout *layout = new QVBoxLayout;
  layout->setSpacing(0);
  layout->setMargin(0);
  layout->addWidget(m_tabWidget);
  centralWidget->setLayout(layout);
  setCentralWidget(centralWidget);

  connect(m_tabWidget, &TabWidget::urlChanged, this,
          &BrowserWindow::handleWebViewUrlChanged);
  connect(m_urlLineEdit, &QLineEdit::returnPressed, this,
          [this]() { loadPage(m_urlLineEdit->url()); });

  m_tabWidget->setCornerWidget(m_urlLineEdit, Qt::TopLeftCorner);
  m_tabWidget->createTab();
  statusBar()->close();
  menuBar()->close();
}

BrowserWindow::~BrowserWindow() {}

void BrowserWindow::handleWebViewUrlChanged(const QUrl &url) {
  m_urlLineEdit->setUrl(url);
  if (url.isEmpty())
    m_urlLineEdit->setFocus();
}

void BrowserWindow::handleFileOpenTriggered() {
  QString file = QFileDialog::getOpenFileName(this, tr("Open files"));
  if (file.isEmpty())
    return;
  loadPage(file);
}

void BrowserWindow::loadPage(const QString &page) {
  loadPage(QUrl::fromUserInput(page));
}

void BrowserWindow::loadPage(const QUrl &url) {
  if (url.isValid()) {
    m_urlLineEdit->setUrl(url);
    m_tabWidget->setUrl(url);
  }
}

TabWidget *BrowserWindow::tabWidget() const { return m_tabWidget; }

WebView *BrowserWindow::currentTab() const {
  return m_tabWidget->currentWebView();
}

void BrowserWindow::handleShowWindowTriggered() {
  if (QAction *action = qobject_cast<QAction *>(sender())) {
    int offset = action->data().toInt();
    QVector<BrowserWindow *> windows = Browser::instance().windows();
    windows.at(offset)->activateWindow();
    windows.at(offset)->currentTab()->setFocus();
  }
}

void BrowserWindow::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_F5) {
    m_tabWidget->triggerWebPageAction(QWebEnginePage::Reload);
  } else if (event->key() == Qt::Key_O) {
    this->handleFileOpenTriggered();
  } else if (event->key() == Qt::Key_B) {
    m_tabWidget->triggerWebPageAction(QWebEnginePage::Back);
  }
}
