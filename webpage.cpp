#include "browserwindow.h"
#include "tabwidget.h"
#include "webpage.h"
#include "webview.h"
#include <QAuthenticator>
#include <QMessageBox>

WebPage::WebPage(QWebEngineProfile *profile, QObject *parent)
    : QWebEnginePage(profile, parent)
{
	//connect(this->profile(), SIGNAL(downloadRequested(QWebEngineDownloadItem*)),this, SLOT(downloadRequested(QWebEngineDownloadItem*)));
}

/*void WebPage::downloadRequested(QWebEngineDownloadItem * download){
	download->accept();
}*/
