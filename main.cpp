#include "encyclopediawindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationName("Энциклопедия полезных растений");
    a.setWindowIcon(QIcon(":/resources/images/LuckyClover.ico"));
    EncyclopediaWindow w;
    w.show();

    return a.exec();
}
