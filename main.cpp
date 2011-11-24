//      main.cpp
//      
//      Copyright 2011 http://redmine.androw.eu/projects/tipe1112/
//      
//      This program is free software: you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation, either version 3 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <QApplication>
#include <QStyle>
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
