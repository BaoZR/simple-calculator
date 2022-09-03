#ifndef BUTTONNUM_H
#define BUTTONNUM_H

#include <QPushButton>
#include <QObject>
#include <QLineEdit>
#include <QGridLayout>

class ButtonNum : public QPushButton
{
    Q_OBJECT
public:
    ButtonNum(int i);

public:
    int index;
signals:
    void changeNum();
private slots:
    void clickButton();

};

#endif // BUTTONNUM_H
