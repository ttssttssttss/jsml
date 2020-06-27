#include <QApplication>
#include <QNetworkProxy>
#include <QWebEngineSettings>

#include "browser.h"
#include "browserwindow.h"

QString getCommandLineUrlArgument() {
  const QStringList args = QCoreApplication::arguments();
  if (args.count() > 1) {
    const QString lastArg = args.last();
    const bool isValidUrl = QUrl::fromUserInput(lastArg).isValid();
    if (isValidUrl)
      return lastArg;
  }
  return QString();
}

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  BrowserWindow *window = new BrowserWindow();
  Browser::instance().addWindow(window);

  const QString url = getCommandLineUrlArgument();
  if (!url.isEmpty())
    window->loadPage(url);

  return app.exec();
}
