#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include "qtimer.h"
class Field;

namespace Ui {
class Table;
}

class Table : public QWidget {
  Q_OBJECT

public:
  explicit Table(QWidget *parent = nullptr);
  ~Table();
  bool checkWin(); ///< Method for ckecking end of game
  void shuffle(); ///< Method for shuffling fields

private:
  Ui::Table *ui;

protected:
  QVector<Field *> m_vectorFields; ///< Vector of fields
    Field* m_currentField;  ///< Current open field object
  Field* m_secondField; ///< Second opened field
  int m_hitsCount; ///< Number of hits

protected:
  void resetFields(); ///< Method for reseting fields
    void cleanTable(); ///< Method for cleaning table

protected slots:
  void clickField(Field* tempField); ///< Method for click field
};

#endif // TABLE_H
