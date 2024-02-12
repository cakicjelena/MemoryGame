#include "field.h"
#include <QDebug>

QSize Field::m_size = {QSize(100, 100)};

bool Field::opened() const { return m_opened; }

void Field::setOpened(bool newOpened) { m_opened = newOpened; }

int Field::value()  { return m_value; }

void Field::click() {
  if (m_opened) {
    setIcon(QPixmap(":/new/images/back"));
    m_opened = false;
    setIconSize(m_size);
  } else {
    m_frontImage.scaled(QSize(100, 200));
    setIcon(m_frontImage);
    m_opened = true;
  }
  emit open(this);
}

void Field::mousePressEvent(QMouseEvent *ev) { click(); }

void Field::reset()
{
    setOpened(false);
    setIcon(QPixmap(":/new/images/back"));
    setEnabled(true);
}


Field::Field() {}

///@brief Constructor with params.
/// @param QPixmap Image,
///
Field::Field(const QPixmap &image, const int &value)
    : m_frontImage(image), m_value(value) {
  setIcon(QPixmap(":/new/images/back"));
  setIconSize(m_size);
  m_opened = false;

  connect(this, SIGNAL(clicked()), this, SLOT(click()));
}

Field::~Field() {}
