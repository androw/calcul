//      Deduction.h
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
#ifndef Boite2_H
#define Boite2_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QSlider>
#include <QInputDialog>
#include <QGroupBox>
#include <QtGui>
#include <QMenuBar>
#include <QLineEdit>
#include <QColor>
#include <QGridLayout>

#include "Exercice.h"

class Boite2 : public Exercice {
    Q_OBJECT

protected:
    double etude1;
    double etude2;
    QPushButton *m_bouton;
    QPushButton *m_menu;
    QLineEdit * reponse[10];
    float taVariable[5];
    int SECONDES;
    int MINUTES;
    QTimer *timerA;
    QLabel *label;
    int erreur;
    int currenterr;
    QLabel *comment;
    QMainWindow *parent;
    QComboBox *signe[5];

        public slots:
    void message();
    void chrono();
    void menu();

public :
        Boite2(QMainWindow *p,int e1,int e2);
~Boite2();
bool verif(int etude1,int etude2);
bool repet(int);
bool verifsigne(int);
void evaluation(float nombre);
};

#endif // Boite2_H
