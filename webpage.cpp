#include "webpage.h"

#include <QAuthenticator>
#include <QMessageBox>

#include "browserwindow.h"
#include "tabwidget.h"
#include "webview.h"

WebPage::WebPage(QWebEngineProfile *profile, QObject *parent)
    : QWebEnginePage(profile, parent) {
  // connect(this->profile(),
  // SIGNAL(downloadRequested(QWebEngineDownloadItem*)),this,
  // SLOT(downloadRequested(QWebEngineDownloadItem*)));
}

/*void WebPage::downloadRequested(QWebEngineDownloadItem * download){
	download->accept();
}*/
