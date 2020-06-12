#include "mainwindow.h"
#include "console.h"
#include <QApplication>
#include <QObject>
#include <QPushButton>
#include <QMessageBox>



int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w; //!< Okno główne programu

    w.setWindowTitle("Balancing Robot Interface");
    w.show();

    return a.exec();
}
