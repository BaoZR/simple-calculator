#include "buttonnum.h"
#include "dialog.h"

ButtonNum::ButtonNum(int i):QPushButton(QString::number(i)),index(i){};

void ButtonNum::clickButton()
{
    Dialog::S += QString::number(index);
    emit changeNum();

    if(Dialog::mark == 1){
        Dialog::num1 = Dialog::num1 * 10 + index;
    }else{
        Dialog::num2 = Dialog::num2 * 10 + index;
    }
}
