#include "tabwidget.h"

#include <qnamespace.h>

#include <QMenu>
#include <QTabBar>
#include <QWebEngineProfile>

#include "webpage.h"
#include "webview.h"

TabWidget::TabWidget(QWidget *parent) : QTabWidget(parent) {
  QTabBar *tabBar = this->tabBar();
  tabBar->setSelectionBehaviorOnRemove(QTabBar::SelectPreviousTab);
  tabBar->setMovable(true);
  tabBar->setContextMenuPolicy(Qt::CustomContextMenu);
  tabBar->setStyleSheet("QTabBar::tab{background:transparent;color:white;};");
  connect(tabBar, &QTabBar::tabCloseRequested, this, &TabWidget::closeTab);
  connect(tabBar, &QTabBar::tabBarDoubleClicked, [this](int index) {
    if (index != -1) {
      closeTab(index);
      return;
    }
    createTab();
  });

  setDocumentMode(true);
  setElideMode(Qt::ElideRight);

  connect(this, &QTabWidget::currentChanged, this,
          &TabWidget::handleCurrentChanged);
}

TabWidget::~TabWidget() {}

void TabWidget::handleCurrentChanged(int index) {
  if (index != -1) {
    WebView *view = webView(index);
    if (!view->url().isEmpty())
      view->setFocus();
    emit titleChanged(view->title());
    emit urlChanged(view->url());
  } else {
    emit titleChanged(QString());
    emit urlChanged(QUrl());
  }
}

WebView *TabWidget::currentWebView() const { return webView(currentIndex()); }

WebView *TabWidget::webView(int index) const {
  return qobject_cast<WebView *>(widget(index));
}

void TabWidget::setupView(WebView *webView) {
  connect(webView, &QWebEngineView::titleChanged,
          [this, webView](const QString &title_full) {
            QString title = title_full.left(8);
            int index = indexOf(webView);
            if (index != -1)
              setTabText(index, title);
            if (currentIndex() == index)
              emit titleChanged(title);
          });
  connect(webView, &QWebEngineView::urlChanged,
          [this, webView](const QUrl &url) {
            int index = indexOf(webView);
            if (index != -1)
              tabBar()->setTabData(index, url);
            if (currentIndex() == index)
              emit urlChanged(url);
          });
}

WebView *TabWidget::createTab(bool makeCurrent) {
  WebView *webView = new WebView;
  WebPage *webPage = new WebPage(QWebEngineProfile::defaultProfile(), webView);
  webPage->setBackgroundColor(Qt::transparent);
  webView->setAttribute(Qt::WA_TranslucentBackground);
  webView->setStyleSheet("background:transparent");
  webView->setPage(webPage);
  setupView(webView);
  addTab(webView, tr("(Untitled)"));
  if (makeCurrent)
    setCurrentWidget(webView);
  connect(webPage->profile(),
          SIGNAL(downloadRequested(QWebEngineDownloadItem *)), this,
          SLOT(downloadRequested(QWebEngineDownloadItem *)));
  return webView;
}

void TabWidget::downloadRequested(QWebEngineDownloadItem *download) {
  download->accept();
}

void TabWidget::closeTab(int index) {
  if (WebView *view = webView(index)) {
    bool hasFocus = view->hasFocus();
    removeTab(index);
    if (hasFocus && count() > 0)
      currentWebView()->setFocus();
    if (count() == 0)
      createTab();
    view->deleteLater();
  }
}

void TabWidget::setUrl(const QUrl &url) {
  if (WebView *view = currentWebView()) {
    view->setUrl(url);
    view->page()->setBackgroundColor(Qt::transparent);
    view->setFocus();
  }
}

void TabWidget::triggerWebPageAction(QWebEnginePage::WebAction action) {
  if (WebView *webView = currentWebView()) {
    webView->triggerPageAction(action);
    webView->setFocus();
  }
}
