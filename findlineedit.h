#ifndef FINDLINEEDIT_H
#define FINDLINEEDIT_H

#include <QLineEdit>
#include <qevent.h>
#include <qlineedit.h>
#include <qobjectdefs.h>

class FindLineEdit : public QLineEdit {
  Q_OBJECT
public:
  FindLineEdit(QWidget *parent = nullptr);

private:
  void focusOutEvent(QFocusEvent *e);
};

#endif
