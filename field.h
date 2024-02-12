#ifndef FIELD_H
#define FIELD_H

#include "QObject"
#include "qobjectdefs.h"
#include "qpushbutton.h"
class Field : public QPushButton {
  Q_OBJECT

protected:
  QPixmap m_frontImage; ///< Front image of field.
  // static QPixmap m_backImage; ///< Back image of field.
  int m_value;         ///< Value of field
  bool m_opened;       ///< Indicator is true if field is open.
  static QSize m_size; ///< size of field.

public:
  Field();
  ///@brief Constructor with params.
  /// @param QPixmap Image,
  ///
  Field(const QPixmap &image, const int &value);
  virtual ~Field();

  bool opened() const;
  void setOpened(bool newOpened);

  int value();

  static QPixmap backImage();

signals:
  void open(Field* tempField);

public slots:
  void click();

protected:
  void mousePressEvent(QMouseEvent *ev);

public:
  void reset();
};

#endif // FIELD_H
