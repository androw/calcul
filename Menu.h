//      Menu.h
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

#ifndef MENU_H
#define MENU_H

#include <Qt>
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
#include <QLCDNumber>


#include "ExerciceSerie.h"
#include "Boite.h"
#include "Boite2.h"
#include "Table.h"
#include "Deduction.h"
#include "Grad.h"
#include "Equation.h"
#include "Tableau.h"

class Menu : public QMainWindow {
    Q_OBJECT

        protected:
        QPushButton *boite1;
        QPushButton *boite2;
        QPushButton *boite3;
        QPushButton *boite4;
        QPushButton *boite5;
        QPushButton *boite6;
        QPushButton *boite7;
        QPushButton *boite8;
        QPushButton *boite9;
        QPushButton *boite10;
        QPushButton *boite11;
        QPushButton *boite12;
        QPushButton *serie;
        QPushButton *tablem;
        QPushButton *grad;
        QPushButton *dedu;
        QPushButton *equation;
        QPushButton *devFac;
        QPushButton *tableau;
        QPropertyAnimation *animation1;
        QPropertyAnimation *animation2;
        QLineEdit *prenom;
        QLineEdit *nom;
        QComboBox *classe;
        QSlider *m_slider;

        public slots:
        void facil();
        void normal();
        void difficil();
        void aboite1();
        void aboite2();
        void aboite3();
        void aboite4();
        void aboite5();
        void aboite6();
        void aboite7();
        void aboite8();
        void aboite9();
        void aboite10();
        void aboite11();
        void aboite12();
        void aserie();
        void atable();
        void adedu();
        void agrad();
        void aequation();
        void atableau();
        void deplacer();
        signals:

        public :
        Menu();
};
#endif // MENU_H
