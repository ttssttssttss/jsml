#include "urllineedit.h"

#include <QToolButton>
#include <QUrl>

UrlLineEdit::UrlLineEdit(QWidget *parent) : QLineEdit(parent) {
  setStyleSheet("QLineEdit{background:transparent;border-width:0;border-style:"
                "outset;color:white;}"); //地址栏透明
}

QUrl UrlLineEdit::url() const { return QUrl::fromUserInput(text()); }

void UrlLineEdit::setUrl(const QUrl &url) {
  setText(url.toString());
  setCursorPosition(0);
}
