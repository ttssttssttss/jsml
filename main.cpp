#include <QApplication>
#include <QtWebEngineWidgets>
int main (int argc, char *argv[]) {
	QApplication a(argc,argv);
	QWebEngineView *view = new QWebEngineView();
	view->setUrl(QUrl("http://www.cnbeta.com"));
	view->show();
	
	return a.exec();
}
