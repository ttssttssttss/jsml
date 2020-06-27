#include "webview.h"

#include <QContextMenuEvent>
#include <QDebug>
#include <QMenu>
#include <QMessageBox>
#include <QTimer>

#include "browser.h"
#include "browserwindow.h"
#include "tabwidget.h"
#include "webpage.h"

WebView::WebView(QWidget *parent) : QWebEngineView(parent) {
  setContextMenuPolicy(Qt::NoContextMenu);
}

QWebEngineView *WebView::createWindow(QWebEnginePage::WebWindowType type) {
  switch (type) {
  case QWebEnginePage::WebBrowserTab: {
    BrowserWindow *mainWindow = qobject_cast<BrowserWindow *>(window());
    return mainWindow->tabWidget()->createTab();
  }
  }
  return nullptr;
}

/* void WebView::contextMenuEvent(QContextMenuEvent *event) { */
// QMenu *menu = page()->createStandardContextMenu();
// //  menu->addAction("test");
// connect(menu, &QMenu::aboutToHide, menu, &QObject::deleteLater);
// menu->popup(event->globalPos());
/* } */
