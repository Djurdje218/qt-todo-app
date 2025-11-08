#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();

    //QPushButton button("Zdravo iz QT");
    //button.resize(200,60);
    //button.show();
    return app.exec();
}
