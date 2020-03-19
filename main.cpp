#include "browser.h"
#include "browserwindow.h"
#include <QApplication>
#include <QWebEngineSettings>

int main(int argc, char **argv)
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(QLatin1String(":simplebrowser.svg")));

    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);

    BrowserWindow *window = new BrowserWindow();
    Browser::instance().addWindow(window);

    return app.exec();
}
