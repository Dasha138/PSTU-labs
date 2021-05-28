#include "comi.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Comi w;
    w.show();
    return a.exec();
}
