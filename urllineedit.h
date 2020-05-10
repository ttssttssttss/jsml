#ifndef URLLINEEDIT_H
#define URLLINEEDIT_H

#include <QLineEdit>

QT_BEGIN_NAMESPACE
class QToolButton;
QT_END_NAMESPACE

class UrlLineEdit : public QLineEdit {
  Q_OBJECT

  public:
  UrlLineEdit(QWidget *parent = nullptr);

  public:
  QUrl url() const;
  void setUrl(const QUrl &url);
};

#endif	// URLLINEEDIT_H
