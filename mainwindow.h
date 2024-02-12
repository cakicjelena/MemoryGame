#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "table.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {

  Q_OBJECT

protected:
  Table *m_table; ///< Pointer to the table object.

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
