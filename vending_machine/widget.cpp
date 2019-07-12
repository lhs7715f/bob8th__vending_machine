#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbCoke->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::checkMoney(int n)
{
    (100<=n) ? ui->pbCoffee->setEnabled(true) : ui->pbCoffee->setEnabled(false);
    (150<=n) ? ui->pbTea->setEnabled(true) : ui->pbTea->setEnabled(false);
    (200<=n) ? ui->pbCoke->setEnabled(true) : ui->pbCoke->setEnabled(false);
}

void Widget::addMoney(int n)
{
    money += n;
    ui->lcdNumber->display(money);
    checkMoney(money);
}

void Widget::subMoney(int n)
{
    money -= n;
    ui->lcdNumber->display(money);
    checkMoney(money);
}

void Widget::on_pb10_clicked()
{
    addMoney(10);
}

void Widget::on_pb50_clicked()
{
    addMoney(50);
}

void Widget::on_pb100_clicked()
{
    addMoney(100);
}

void Widget::on_pb500_clicked()
{
    addMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    subMoney(100);
}

void Widget::on_pbTea_clicked()
{
    subMoney(150);
}

void Widget::on_pbCoke_clicked()
{
    subMoney(200);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox msg;
    QString str;
    int chg500 = money/500;
    int chg100 = (money - chg500*500)/100;
    int chg50 = (money - chg500*500 - chg100*100)/50;
    int chg10 = (money - chg500*500 - chg100*100 - chg50*50)/10;

    str = QString("<number of each coin>\n\n\n"
                  "number of coin 500 : %1 \n"
                  "number of coin 100 : %2 \n"
                  "number of coin 50 : %3 \n"
                  "number of coin 10 : %4")
            .arg(chg500)
            .arg(chg100)
            .arg(chg50)
            .arg(chg10);

    msg.information(nullptr, "Money Change", str);
    money=0;
    ui->lcdNumber->display(money);
}

void Widget::on_pbPowerOff_clicked()
{
    QMessageBox msgBox;

    msgBox.setWindowTitle("Vending Machine");
    msgBox.setText("Are you sure you want to quit vending machine program?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes)
        this->close();
}
