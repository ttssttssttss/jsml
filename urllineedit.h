#ifndef URLLINEEDIT_H
#define URLLINEEDIT_H

#include <QLineEdit>

QT_BEGIN_NAMESPACE
class QToolButton;
QT_END_NAMESPACE

class UrlLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    UrlLineEdit(QWidget *parent = nullptr);

public:
    QUrl url() const;
    void setUrl(const QUrl &url);
    void setFavIcon(const QIcon &icon);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QToolButton *m_favButton;
    QToolButton *m_clearButton;
};

#endif // URLLINEEDIT_H
