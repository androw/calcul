#include <QApplication>
#include<QStyle>
#include "ExerciceSerie.h"
#include "Exercice.h"
#include "Menu.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setStyleSheet("QPushButton {\
                      background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\
                                        stop: 0 #aaeeff, stop: 1 #3399cc);\
                      border-style: outset;\
                      border-width: 2px;\
                      border-radius: 10px;\
                      border-color: white;\
                      font: bold 14px;\
                      min-width: 10em;\
                      padding: 6px;\
                  }\
                  QPushButton:hover {\
                      background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\
                      stop: 0 #aaeeff, stop: 1 #0131B4);\
                      border-style: inset;\
                  }\
                  QMessageBox {\
                         border-style: inset;\
                    }\
                  QLabel {\
                        border-width: 2px;\
                        border-radius: 10px;\
                    }\
                    QLineEdit{\
                       border-style: outset;\
                       border-width: 2px;\
                       border-radius: 10px;\
\
                    }\
                    QLineEdit:hover {\
                        border-style: outset;\
                        border-width: 2px;\
                         border-radius: 10px;\
                        border-color: #1E90FF;\
\
}\
                    ");


    Menu fenetre;
    fenetre.show();

    return app.exec();
}
