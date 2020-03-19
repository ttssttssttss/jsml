#ifndef BROWSERWINDOW_H
#define BROWSERWINDOW_H

#include <QMainWindow>
#include <QWebEnginePage>
#include <QComboBox>
#include <QtDebug>

QT_BEGIN_NAMESPACE
class QProgressBar;
QT_END_NAMESPACE

class TabWidget;
class UrlLineEdit;
class WebView;

class BrowserWindow : public QMainWindow
{
    Q_OBJECT

public:
    BrowserWindow(QWidget *parent = nullptr, Qt::WindowFlags flags = 0);
    ~BrowserWindow();
    QSize sizeHint() const override;
    TabWidget *tabWidget() const;
    WebView *currentTab() const;

    void loadPage(const QString &url);
    void loadPage(const QUrl &url);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void handleFileOpenTriggered();
    void handleShowWindowTriggered();
    void handleWebViewTitleChanged(const QString &title);
    void handleComboIndexChanged(const QString &text);
    void handleWebViewUrlChanged(const QUrl &url);
    void handleWebViewIconChanged(const QIcon &icon);
    void handleWebActionEnabledChanged(QWebEnginePage::WebAction action, bool enabled);

private:
    QToolBar *createToolBar(QComboBox *opsCombo);

private:
    TabWidget *m_tabWidget;
    QAction *m_historyBackAction;
    UrlLineEdit *m_urlLineEdit;
		QComboBox *opsCombo;
};

#endif // BROWSERWINDOW_H
