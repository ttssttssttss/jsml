#ifndef WEBPOPUPWINDOW_H
#define WEBPOPUPWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QWebEngineProfile;
class QWebEngineView;
QT_END_NAMESPACE

class WebView;
class UrlLineEdit;

class WebPopupWindow : public QWidget
{
    Q_OBJECT

public:
    WebPopupWindow(QWebEngineProfile *profile);
    QWebEngineView *view() const;
    void setUrl(const QUrl &url);

private slots:
    void handleGeometryChangeRequested(const QRect &newGeometry);
    void handleIconChanged(const QIcon &icon);

private:
    UrlLineEdit *m_addressBar;
    WebView *m_view;
};
#endif // WEBPOPUPWINDOW_H
