#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEdit->setAlignment(Qt::AlignRight);
    ui->lineEdit->setReadOnly(true);
    my_state=FIRST;
    my_sign=NO;
    first=0;
    second=0;
    result=0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Button_1_clicked()
{
   trans(1);
}

void Widget::on_Button_2_clicked()
{
   trans(2);
}
void Widget::on_Button_3_clicked()
{
   trans(3);
}
void Widget::on_Button_4_clicked()
{
   trans(4);
}
void Widget::on_Button_5_clicked()
{
   trans(5);
}
void Widget::on_Button_6_clicked()
{
   trans(6);
}
void Widget::on_Button_7_clicked()
{
   trans(7);
}
void Widget::on_Button_8_clicked()
{
   trans(8);
}
void Widget::on_Button_9_clicked()
{
   trans(9);
}
void Widget::on_Button_10_clicked()
{
   trans(0);
}
void Widget::on_equal_clicked()
{
    cal();
    ui->lineEdit->setText(QString::number(result));
    first=0;
    second=0;
    my_state=FIRST;
    my_sign=NO;
}
void Widget::on_minus_clicked()
{
    my_sign=MINUS;
    if(my_state==SECOND)
    {
        cal();
        ui->lineEdit->setText(QString::number(result));
        first=result;
        second=0;
   }
    my_state=SECOND;
}

void Widget::on_plus_clicked()
{
    my_sign=PLUS;
    if(my_state==SECOND)
    {
        cal();
        ui->lineEdit->setText(QString::number(result));
        first=result;
        second=0;
    }
    my_state=SECOND;
}

void Widget::on_time_clicked()
{
    my_sign=TIME;
    if(my_state==SECOND)
    {
        cal();
        ui->lineEdit->setText(QString::number(result));
        first=result;
        second=0;
   }
    my_state=SECOND;

}

void Widget::on_devide_clicked()
{
    my_sign=DEVIDE;
    if(my_state==SECOND)
    {
        cal();
        ui->lineEdit->setText(QString::number(result));
        first=result;
        second=0;
   }
    my_state=SECOND;

}

void Widget::on_clear_clicked()
{
    ui->lineEdit->clear();
    my_state=FIRST;
    my_sign=NO;
    first=0;
    second=0;
    result=0;
}
void Widget::trans(char key)
{
    if(my_state==FIRST)
    {
        first=first*10+(int)key;
        ui->lineEdit->setText(QString::number(first));
    }
    else
    {
        second=second*10+(int)key;
        ui->lineEdit->setText(QString::number(second));
    }
}

void Widget::cal(void)
{
    switch(my_sign)
    {
    case PLUS:result=first+second;break;
    case MINUS:result=first-second;break;
    case TIME:result=first*second;break;
    case DEVIDE:result=first/second;break;
    }
}























