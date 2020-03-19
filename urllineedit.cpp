#include "urllineedit.h"
#include <QToolButton>
#include <QUrl>

UrlLineEdit::UrlLineEdit(QWidget *parent)
    : QLineEdit(parent)
{
}

QUrl UrlLineEdit::url() const
{
    return QUrl::fromUserInput(text());
}

void UrlLineEdit::setUrl(const QUrl &url)
{
    setText(url.toString());
    setCursorPosition(0);
}
