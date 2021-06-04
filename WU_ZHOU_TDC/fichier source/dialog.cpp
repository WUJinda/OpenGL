#include "dialog.h"
#include "ui_dialog.h"
#include "qdebug.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->label->setText("Game Over");
    ui->Time->setText("Time : " );
    ui->Record->setText("Record : ");
}
void Dialog::setRandT(int record, QString time){
    ui->Time->setText("Time :  " + time);
    ui->Record->setText("Record :  " + QString::number(record));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_Restart_clicked()
{
    restart_ = true;
    this->close();
}

void Dialog::on_Quit_clicked()
{
    quit_ = true;
    this->close();
}
