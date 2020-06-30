#ifndef BROWSERWINDOW_H
#define BROWSERWINDOW_H

#include "findlineedit.h"
#include <QComboBox>
#include <QMainWindow>
#include <QWebEnginePage>
#include <QtDebug>
#include <qline.h>

QT_BEGIN_NAMESPACE
class QProgressBar;
QT_END_NAMESPACE

class TabWidget;
class UrlLineEdit;
class FindLineEdit;
class WebView;

class BrowserWindow : public QMainWindow {
  Q_OBJECT

public:
  BrowserWindow(QWidget *parent = nullptr, Qt::WindowFlags flags = 0);
  ~BrowserWindow();
  TabWidget *tabWidget() const;
  WebView *currentTab() const;

  void loadPage(const QString &url);
  void loadPage(const QUrl &url);

  void keyPressEvent(QKeyEvent *event);

private slots:
  void handleFileOpenTriggered();
  void handleShowWindowTriggered();
  void handleWebViewUrlChanged(const QUrl &url);
  void findStrFunc();

private:
  QToolBar *createToolBar();

private:
  TabWidget *m_tabWidget;
  UrlLineEdit *m_urlLineEdit;
  QComboBox *opsCombo;
  FindLineEdit *findStrLineEdit;
};

#endif // BROWSERWINDOW_H
