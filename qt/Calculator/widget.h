#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_Button_1_clicked();

    void on_Button_2_clicked();

    void on_Button_3_clicked();

    void on_Button_4_clicked();

    void on_Button_5_clicked();

    void on_Button_6_clicked();

    void on_Button_7_clicked();

    void on_Button_8_clicked();

    void on_Button_9_clicked();

    void on_Button_10_clicked();

    void on_plus_clicked();

    void on_minus_clicked();

    void on_time_clicked();

    void on_devide_clicked();

    void on_clear_clicked();

    void on_equal_clicked();

private:
    Ui::Widget *ui;
    void trans(char key);
    void cal(void);
    enum state {FIRST,SECOND}my_state;
    enum sign {PLUS,MINUS,TIME,DEVIDE,NO}my_sign;
    int first;
    int second;
    int result;
};

#endif // WIDGET_H
