#include "musicinterfase.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MusicInterfase w;
    w.show();

    return a.exec();
}
