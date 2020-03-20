#include "tabwidget.h"
#include "webpage.h"
#include "webview.h"
#include <QMenu>
#include <QTabBar>
#include <QWebEngineProfile>

TabWidget::TabWidget(QWidget *parent)
    : QTabWidget(parent)
{
    QTabBar *tabBar = this->tabBar();
    tabBar->setTabsClosable(true);
    tabBar->setSelectionBehaviorOnRemove(QTabBar::SelectPreviousTab);
    tabBar->setMovable(true);
    tabBar->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(tabBar, &QTabBar::tabCloseRequested, this, &TabWidget::closeTab);
    connect(tabBar, &QTabBar::tabBarDoubleClicked, [this](int index) {
        if (index != -1)
            return;
        createTab();
    });

    setDocumentMode(true);
    setElideMode(Qt::ElideRight);

    connect(this, &QTabWidget::currentChanged, this, &TabWidget::handleCurrentChanged);
}

TabWidget::~TabWidget()
{
}

void TabWidget::handleCurrentChanged(int index)
{
    if (index != -1) {
        WebView *view = webView(index);
        if (!view->url().isEmpty())
            view->setFocus();
        emit titleChanged(view->title());
        emit loadProgress(view->loadProgress());
        emit urlChanged(view->url());
        QIcon pageIcon = view->page()->icon();
        if (!pageIcon.isNull())
            emit iconChanged(pageIcon);
        else
            emit iconChanged(QIcon(QStringLiteral(":defaulticon.png")));
    } else {
        emit titleChanged(QString());
        emit loadProgress(0);
        emit urlChanged(QUrl());
        emit iconChanged(QIcon(QStringLiteral(":defaulticon.png")));
    }
}


WebView *TabWidget::currentWebView() const
{
    return webView(currentIndex());
}

WebView *TabWidget::webView(int index) const
{
    return qobject_cast<WebView*>(widget(index));
}

void TabWidget::setupView(WebView *webView)
{
    QWebEnginePage *webPage = webView->page();

    connect(webView, &QWebEngineView::titleChanged, [this, webView](const QString &title) {
        int index = indexOf(webView);
        if (index != -1)
            setTabText(index, title);
        if (currentIndex() == index)
            emit titleChanged(title);
    });
    connect(webView, &QWebEngineView::urlChanged, [this, webView](const QUrl &url) {
        int index = indexOf(webView);
        if (index != -1)
            tabBar()->setTabData(index, url);
        if (currentIndex() == index)
            emit urlChanged(url);
    });
    connect(webView, &QWebEngineView::loadProgress, [this, webView](int progress) {
        if (currentIndex() == indexOf(webView))
            emit loadProgress(progress);
    });
    connect(webPage, &WebPage::iconChanged, [this, webView](const QIcon &icon) {
        int index = indexOf(webView);
        QIcon ico = icon.isNull() ? QIcon(QStringLiteral(":defaulticon.png")) : icon;

        if (index != -1)
            setTabIcon(index, ico);
        if (currentIndex() == index)
            emit iconChanged(ico);
    });
    connect(webView, &QWebEngineView::loadStarted, [this, webView]() {
        int index = indexOf(webView);
        if (index != -1) {
            QIcon icon(QLatin1String(":view-refresh.png"));
            setTabIcon(index, icon);
        }
    });
    connect(webPage, &QWebEnginePage::windowCloseRequested, [this, webView]() {
        int index = indexOf(webView);
        if (index >= 0)
            closeTab(index);
    });
}

WebView *TabWidget::createTab(bool makeCurrent)
{
    WebView *webView = new WebView;
    WebPage *webPage = new WebPage(QWebEngineProfile::defaultProfile(), webView);
    webView->setPage(webPage);
    setupView(webView);
    addTab(webView, tr("(Untitled)"));
    if (makeCurrent)
        setCurrentWidget(webView);
    return webView;
}

void TabWidget::closeTab(int index)
{
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

void TabWidget::setUrl(const QUrl &url)
{
    if (WebView *view = currentWebView()) {
        view->setUrl(url);
        view->setFocus();
    }
}

void TabWidget::triggerWebPageAction(QWebEnginePage::WebAction action)
{
    if (WebView *webView = currentWebView()) {
        webView->triggerPageAction(action);
        webView->setFocus();
    }
}
