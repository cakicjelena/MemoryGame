#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  m_table = new Table(this);
  setCentralWidget(m_table);
}

MainWindow::~MainWindow() { delete ui; }
