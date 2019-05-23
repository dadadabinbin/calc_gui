#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <math.h>
#include <qDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    QLineEdit* x1_line;
    QLineEdit* y1_line;
    QLineEdit* x2_line;
    QLineEdit* y2_line;
    QLineEdit* dict_line;
    QLineEdit* angle_line;
    QFormLayout* lay;

    double x1;
    double y1;
    double x2;
    double y2;
    double dict;
    double angle;

public slots:
    void onPositiveButtonClicked();
    void onNegativeButtonClicked();

};

#endif // WIDGET_H
