#include "dialog.h"
#include "ui_dialog.h"




Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    button_plus = new QPushButton("+");
    button_minus = new QPushButton("-");
    button_multiply = new QPushButton("*");
    button_devide = new QPushButton("/");
    button_equal = new QPushButton("=");
    button_clearAll = new QPushButton("c");
    lineEdit = new QLineEdit("c");

    for(int i = 0; i < 10; i++){
        button_num[i] = new ButtonNum(i);
    }

    QGridLayout * Grid = new QGridLayout;
    Grid->addWidget(lineEdit,1,1,1,4,Qt::Alignment());
    for(int i = 2;i <= 5;i++){
        for(int j = 1;j <= 4;j++){
            Grid->addWidget((QPushButton*)button_num[(i-2)*4 + j -1],i,j,Qt::Alignment());
        }
    }

    this->setLayout(Grid);

    for(int i = 0; i < 10 ; i++){
        connect(button_num[i],SIGNAL(clicked()),button_num[i],SLOT(clickButton()));
    }

    for(int i = 0; i < 10 ; i++){
        connect(button_num[i],SIGNAL(changeNum()),this,SLOT(edit_changed()));
    }

    connect(button_plus,SIGNAL(clicked()),this,SLOT(button_plus_clicked()));
    connect(button_minus,SIGNAL(clicked()),this,SLOT(button_minus_clicked()));
    connect(button_multiply,SIGNAL(clicked()),this,SLOT(button_multiply_clicked()));
    connect(button_devide,SIGNAL(clicked()),this,SLOT(button_devide_clicked()));
    connect(button_equal,SIGNAL(clicked()),this,SLOT(button_equal_clicked()));
    connect(button_clearAll,SIGNAL(clicked()),this,SLOT(button_clearAll_clicked()));




}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::button_plus_clicked(){
    S+="+";
    sign = '+';
    mark = 2;
    lineEdit -> setText(S);
}

void Dialog::button_minus_clicked(){
    S+="-";
    sign = '-';
    mark = 2;
    lineEdit -> setText(S);

};
void Dialog::button_multiply_clicked(){
    S+="*";
    sign = '*';
    mark = 2;
    lineEdit -> setText(S);
};
void Dialog::button_devide_clicked(){
    S+="/";
    sign = '/';
    mark = 2;
    lineEdit -> setText(S);
};
void Dialog::button_equal_clicked(){
    S+="=";
    switch(sign){
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    default:
        break;
    }
    S+=QString("%1").arg(result);
    lineEdit->setText(S);
};
void Dialog::button_clearAll_clicked(){
    S = "";
    lineEdit->setText(S);
    mark = 1;
    num1 = 0.0;
    num2 = 0.0;
    result = 0.0;
}

void Dialog::hello_world()
{
    lineEdit->setText(QString("hello"));
};

void Dialog::edit_changed()
{
    lineEdit->setText(S);
}

//QLineEdit *Dialog::lineEdit = new QLineEdit("C");
QString Dialog::S = "";
float Dialog::num1 = 0;
float Dialog::num2 = 0;
float Dialog::result = 0.0;
char Dialog::sign = ' ';
int Dialog::mark = 1;












