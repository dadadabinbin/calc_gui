#include "widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    //设置窗口名称
    this->setWindowTitle("LiuDi");
    //定义输入框
    x1_line=new QLineEdit;
    y1_line=new QLineEdit;
    x2_line=new QLineEdit;
    y2_line=new QLineEdit;
    dict_line=new QLineEdit;
    angle_line=new QLineEdit;

    //表单布局
    lay=new QFormLayout;
    lay->addRow(QStringLiteral("第一个点的横坐标："),x1_line);
    lay->addRow(QStringLiteral("第一个点的纵坐标："),y1_line);
    lay->addRow(QStringLiteral("第二个点的横坐标："),x2_line);
    lay->addRow(QStringLiteral("第二个点的纵坐标："),y2_line);
    lay->addRow(QStringLiteral("两点之间距离："),dict_line);
    lay->addRow(QStringLiteral("方向角："),angle_line);
    lay->setRowWrapPolicy(QFormLayout::DontWrapRows);
    lay->setHorizontalSpacing(30);
    lay->setVerticalSpacing(30);
    QVBoxLayout* main=new QVBoxLayout;
    //按钮布局
    QPushButton* positiveButton=new QPushButton(tr("正算"));
    QPushButton* negativeButton=new QPushButton(tr("反算"));
    QHBoxLayout* bottom=new QHBoxLayout;
    bottom->addStretch();
    bottom->addWidget(positiveButton);
    bottom->addWidget(negativeButton);
    bottom->addStretch();
    //整理界面布局
    main->addStretch(1);
    main->addLayout(lay);
    main->addLayout(bottom);
    main->addStretch(1);

    this->setLayout(main);
    //点击按键触发的事件
    connect(positiveButton,SIGNAL(clicked()),this,SLOT(onPositiveButtonClicked()));
    connect(negativeButton,SIGNAL(clicked()),this,SLOT(onNegativeButtonClicked()));
}
void Widget::onPositiveButtonClicked(){
    //计算时候这些输入框必须有数字，否则则会有提示
    if(!x1_line->text().isEmpty()){
        x1=x1_line->text().toDouble();
    }else{
        QMessageBox::information(this,tr("提示"),tr("输入x1"));
        return;
    }
    if(!y1_line->text().isEmpty()){
        y1=y1_line->text().toDouble();
    }else{
        QMessageBox::information(this,tr("提示"),tr("输入y1"));
        return;
    }
    if(!dict_line->text().isEmpty()){
        dict=dict_line->text().toDouble();
    }else{
        QMessageBox::information(this,tr("提示"),tr("输入两点距离"));
        return;
    }
    if(!angle_line->text().isEmpty()){
        angle=angle_line->text().toDouble();
    }else{
        QMessageBox::information(this,tr("提示"),tr("输入角度"));
        return;
    }
    angle=(angle*3.14)/180.0;
    double si,co;
    si=sin(angle);
    co=cos(angle);
    x2=x1+dict*si;
    y2=y1+dict*co;
    x2_line->setText(QString::number(x2));
    y2_line->setText(QString::number(y2));
    //调试用
    qDebug()<<"第二个点横坐标为："<<x2<<endl;
    qDebug()<<"第二个点纵坐标为："<<y2<<endl;
}

void Widget::onNegativeButtonClicked(){
        //计算时候这些输入框必须有数字，否则则会有提示
        if(!x1_line->text().isEmpty()){
            x1=x1_line->text().toDouble();
        }else{
            QMessageBox::information(this,tr("提示"),tr("输入x1"));
            return;
        }
        if(!x2_line->text().isEmpty()){
            x2=x2_line->text().toDouble();
        }else{
            QMessageBox::information(this,tr("提示"),tr("输入x2"));
            return;
        }
        if(!y1_line->text().isEmpty()){
            y1=y1_line->text().toDouble();
        }else{
            QMessageBox::information(this,tr("提示"),tr("输入y1"));
            return;
        }
        if(!y2_line->text().isEmpty()){
            y2=y2_line->text().toDouble();
        }else{
            QMessageBox::information(this,tr("提示"),tr("输入y2"));
            return;
        }
        double dist1=pow(x2-x1,2.0);
        double dist2=pow(y2-y1,2.0);
        dict=sqrt(dist1+dist2);
        double sin=(x2-x1)/dict;
        angle=asin(sin);
        dict_line->setText(QString::number(dict));
        angle_line->setText(QString::number(angle));
        //调试用
        qDebug()<<"两点间距离为："<<dict<<endl;
        qDebug()<<"方向角为："<<angle<<endl;
}

Widget::~Widget()
{

}
