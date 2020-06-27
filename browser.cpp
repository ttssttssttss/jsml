#include "browser.h"

#include <QAuthenticator>

#include "browserwindow.h"
#include "webview.h"

Browser::Browser() {}

Browser::~Browser() {
  qDeleteAll(m_windows);
  m_windows.clear();
}

Browser &Browser::instance() {
  static Browser browser;
  return browser;
}

QVector<BrowserWindow *> Browser::windows() { return m_windows; }

void Browser::addWindow(BrowserWindow *mainWindow) {
  if (m_windows.contains(mainWindow))
    return;
  m_windows.prepend(mainWindow);
  QObject::connect(mainWindow, &QObject::destroyed,
                   [this, mainWindow]() { m_windows.removeOne(mainWindow); });
  mainWindow->show();
}
