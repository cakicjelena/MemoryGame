#include "table.h"
#include "field.h"
#include "ui_table.h"
#include "qdebug.h"
#include "math.h"
Table::Table(QWidget *parent) : QWidget(parent), ui(new Ui::Table) {
  ui->setupUi(this);

  int k = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      m_vectorFields.append(new Field(
          QPixmap(":/new/images/" + QString::number(k % 8 + 1)), k % 8 + 1));
      ui->gridLayout->addWidget(m_vectorFields.at(4 * i + j), i, j);
      k++;
    }
  }

  for (int i  = 0; i < m_vectorFields.size(); ++i) {
      connect(m_vectorFields[i], SIGNAL(open(Field*)), this, SLOT(clickField(Field*)));

  }
  cleanTable();
}


Table::~Table() { delete ui; }

bool Table::checkWin()
{
    if(m_hitsCount==8){
        cleanTable();
        m_hitsCount = 0;
        return true;
    }
    else{
        resetFields();
        return false;
    }
}

void Table::shuffle()
{
    Field* pom;
    int random=0;
    for (int i = 0; i < m_vectorFields.size(); ++i) {
        random=rand()%15;
        pom=m_vectorFields[i];
        m_vectorFields[i]=m_vectorFields[random];
        m_vectorFields[random]=pom;
    }
}

void Table::resetFields()
{
    m_currentField=nullptr;
    m_secondField = nullptr;
}

void Table::cleanTable()
{
    for (int i = 0; i < m_vectorFields.size(); ++i) {
        ui->gridLayout->removeWidget(m_vectorFields[i]);
        m_vectorFields[i]->reset();
    }
    shuffle();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ui->gridLayout->addWidget(m_vectorFields.at(4 * i + j), i, j);
        }
    }
}


void Table::clickField(Field* tempField)
{
    if(!m_currentField){
        m_currentField=tempField;
    }
    else {
        m_secondField=tempField;

        if(m_currentField->value()==m_secondField->value()&& m_currentField!=m_secondField){
            m_currentField->setEnabled(false);
            m_secondField->setEnabled(false);
            m_hitsCount++;
            if(!checkWin()){

            }

        }
        else{
            m_secondField->setOpened(false);
            m_secondField->setIcon(QPixmap(":/new/images/back"));
            m_currentField->setOpened(false);
            m_currentField->setIcon(QPixmap(":/new/images/back"));
            resetFields();
        }

    }

}
