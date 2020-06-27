#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QIcon>
#include <QWebEngineView>

class WebPage;

class WebView : public QWebEngineView {
  Q_OBJECT

public:
  WebView(QWidget *parent = nullptr);

protected:
  // void contextMenuEvent(QContextMenuEvent *event) override;
  QWebEngineView *createWindow(QWebEnginePage::WebWindowType type) override;
};

#endif
