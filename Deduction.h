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

#ifndef DEDUCTION_H
#define DEDUCTION_H

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

class Deduction : public Exercice {
    Q_OBJECT

protected:
    QPushButton *m_bouton;
    QPushButton *m_menu;
    QPushButton *m_consigne;
    QLineEdit * reponse[30];
    float taVariable;
    float taVariable2;
    float taVariable3;
    int SECONDES;
    int MINUTES;
    QTimer *timerA;
    QLabel *label;
    int erreur;
    int currenterr;
    QLabel *comment;
    QMainWindow *parent;

public slots:
    void message();
    void chrono();
    void consigne();
    void menu();

public :
    Deduction(QMainWindow *p, bool reel);
    ~Deduction();
    bool verif();
    void evaluation(float nombre);
};
#endif // DEDUCTION_H
