#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "buttonnum.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();


    ButtonNum* button_num[10];
    QPushButton* button_plus;
    QPushButton* button_minus;
    QPushButton* button_multiply;
    QPushButton* button_devide;
    QPushButton* button_equal;
    QPushButton* button_clearAll;
    QLineEdit* lineEdit;
    static float num1,num2,result;
    static QString S;
    static char sign;
    static int mark;


private slots:
    void button_plus_clicked();
    void button_minus_clicked();
    void button_multiply_clicked();
    void button_devide_clicked();
    void button_equal_clicked();
    void button_clearAll_clicked();
    void hello_world();
    void edit_changed();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
