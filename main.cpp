#include "TwinCAT3_Qt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TwinCAT3_Qt w;
    w.show();
    return a.exec();
}
