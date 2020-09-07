#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;

    double calcVal;

    bool waitingForOperand;
    bool equalPressed;

    QString pendingAddOperator;
    QString pendingMulOperator;

    enum{digits = 10};

    bool calculate(double rightOperand, QString &binOperator);

private slots:
    void digitClicked();
    void addOperatorClicked();
    void mulOperatorClicked();
    void pointClicked();
    void changeSignClicked();
    void equalClicked();
    void clearClicked();
    void clearAll();
};
#endif // CALCULATOR_H
