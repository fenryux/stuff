#include "calculator.h"
#include "ui_calculator.h"

#include <math.h>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator), calcVal(0.0), waitingForOperand(true),
      equalPressed(false)
{
    ui->setupUi(this);

    QPushButton * digButtons[digits];
    for(int i=0;i<digits;++i){
        QString butName = "Button" + QString::number(i);
        digButtons[i] = findChild<QPushButton*>(butName);
        connect(digButtons[i],SIGNAL(clicked()),this,SLOT(digitClicked()));
    }

    connect(ui->addButton,SIGNAL(clicked()), this, SLOT(addOperatorClicked()));
    connect(ui->subButton,SIGNAL(clicked()), this, SLOT(addOperatorClicked()));
    connect(ui->mulButton, SIGNAL(clicked()), this, SLOT(mulOperatorClicked()));
    connect(ui->divButton, SIGNAL(clicked()), this, SLOT(mulOperatorClicked()));
    connect(ui->modButton, SIGNAL(clicked()), this, SLOT(mulOperatorClicked()));

    connect(ui->equalButton,SIGNAL(clicked()),this,SLOT(equalClicked()));
    connect(ui->pointButton,SIGNAL(clicked()),this,SLOT(pointClicked()));
    connect(ui->changeSignButton,SIGNAL(clicked()),this,SLOT(changeSignClicked()));

    connect(ui->clearAllButton,SIGNAL(clicked()), this, SLOT(clearAll()));
    connect(ui->clearButton,SIGNAL(clicked()), this, SLOT(clearClicked()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::digitClicked(){
    QPushButton* button = qobject_cast<QPushButton *>(sender());
    if(button == nullptr)
        return;

    if(equalPressed)
        equalPressed = false;

    if(waitingForOperand){
        ui->display->clear();
        waitingForOperand = false;
    }
    ui->display->setText(ui->display->text() + button->text());
}

void Calculator::addOperatorClicked(){
    QPushButton* button = qobject_cast<QPushButton *>(sender());
    if(button == nullptr)
        return;

    if((pendingAddOperator == "+" && waitingForOperand && button->text() == "-")||
       (pendingAddOperator == "-" && waitingForOperand && button->text() == "+")){
        pendingAddOperator = button->text();
    }

    if(equalPressed){
        waitingForOperand = false;
        equalPressed = false;
    }


    if(waitingForOperand)
        return;

    if(!pendingMulOperator.isEmpty()){
        if(!calculate(ui->display->text().toDouble(), pendingMulOperator)){
            clearAll();
            return;
        }
        waitingForOperand = true;
        pendingAddOperator = button->text();
        pendingMulOperator.clear();
        return;
    }
    else if(!pendingAddOperator.isEmpty()){
        if(!calculate(ui->display->text().toDouble(), pendingAddOperator)){
            clearAll();
            return;
        }
        waitingForOperand = true;
        pendingAddOperator = button->text();
        pendingMulOperator.clear();
        return;
    }


    calcVal = ui->display->text().toDouble();
    pendingAddOperator = button->text();
    pendingMulOperator.clear();
    waitingForOperand = true;
}

void Calculator::mulOperatorClicked(){
    QPushButton* button = qobject_cast<QPushButton *>(sender());
    if(button == nullptr)
        return;

    if((pendingMulOperator == "*" && waitingForOperand && button->text() == "/")||
       (pendingMulOperator == "/" && waitingForOperand && button->text() == "*")){
        pendingMulOperator = button->text();
    }

    if(equalPressed){
        waitingForOperand = false;
        equalPressed = false;
    }


    if(waitingForOperand)
        return;

    if(!pendingMulOperator.isEmpty()){
        if(!calculate(ui->display->text().toDouble(), pendingMulOperator)){
            clearAll();
            return;
        }
        waitingForOperand = true;
        pendingMulOperator = button->text();
        pendingAddOperator.clear();
        return;
    }
    else if(!pendingAddOperator.isEmpty()){
        if(!calculate(ui->display->text().toDouble(), pendingAddOperator)){
            clearAll();
            return;
        }
        waitingForOperand = true;
        pendingMulOperator = button->text();
        pendingAddOperator.clear();
        return;
    }


    calcVal = ui->display->text().toDouble();
    pendingMulOperator = button->text();
    pendingAddOperator.clear();
    waitingForOperand = true;
}

bool Calculator::calculate(double rightOperand, QString &binOperator){
    if(QString::compare(binOperator,"+",Qt::CaseInsensitive) == 0){
        calcVal += rightOperand;
    }
    else if(QString::compare(binOperator,"-",Qt::CaseInsensitive) == 0){
        calcVal -= rightOperand;
    }
    else if(QString::compare(binOperator,"*",Qt::CaseInsensitive) == 0){
        calcVal *= rightOperand;
    }
    else if(QString::compare(binOperator,"/",Qt::CaseInsensitive) == 0){
        if(rightOperand == 0.0)
            return false;
        calcVal /= rightOperand;
    }
    else if(QString::compare(binOperator,"%",Qt::CaseInsensitive) == 0){
        if(rightOperand == 0.0 || (rightOperand < 0.0 || calcVal < 0.0))
            return false;
        calcVal = std::fmod(calcVal, rightOperand);
    }
    return true;
}

void Calculator::clearClicked(){
    ui->display->setText("0");
    waitingForOperand = true;
}

void Calculator::clearAll(){
    calcVal = 0.0;
    ui->display->setText("0");
    waitingForOperand = true;
    pendingAddOperator.clear();
    pendingMulOperator.clear();
}

void Calculator::equalClicked(){
    if(waitingForOperand)
        return;

    if(!pendingAddOperator.isEmpty()){
        if(!calculate(ui->display->text().toDouble(),pendingAddOperator)){
            clearAll();
            return;
        }
        ui->display->setText(QString::number(calcVal));

        calcVal = 0.0;
        pendingAddOperator.clear();
        pendingMulOperator.clear();
        waitingForOperand = true;
    }
    else  if(!pendingMulOperator.isEmpty()){
        if(!calculate(ui->display->text().toDouble(), pendingMulOperator)){
            clearAll();
            return;
        }
        ui->display->setText(QString::number(calcVal));

        calcVal = 0.0;
        pendingAddOperator.clear();
        pendingMulOperator.clear();
        waitingForOperand = true;
    }
    equalPressed = true;
}

void Calculator::pointClicked(){
    QString displayVal = ui->display->text();

    for(QChar it:displayVal){
        if(it == '.')
            return;
    }
    ui->display->setText(displayVal + '.');
    waitingForOperand = false;
}

void Calculator::changeSignClicked(){
    ui->display->setText(QString::number(ui->display->text().toDouble() * -1));
}
