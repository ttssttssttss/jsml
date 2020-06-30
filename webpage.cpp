#include "webpage.h"

#include <QAuthenticator>
#include <QMessageBox>

#include "browserwindow.h"
#include "tabwidget.h"
#include "webview.h"

WebPage::WebPage(QWebEngineProfile *profile, QObject *parent)
    : QWebEnginePage(profile, parent) {}
