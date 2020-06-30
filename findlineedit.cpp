#include "findlineedit.h"
#include <qevent.h>

FindLineEdit::FindLineEdit(QWidget *parent) : QLineEdit(parent) {
  setStyleSheet("QLineEdit{background:transparent;border-width:0;border-style:"
                "outset;color:white;}"); //地址栏透明
}
void FindLineEdit::focusOutEvent(QFocusEvent *e) {
  this->hide();
  this->setText("");
}
