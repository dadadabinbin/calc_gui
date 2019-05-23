#include "widget.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //编码
    QTextCodec* pCodec=QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(pCodec);

    Widget w;
    w.show();

    return a.exec();
}
