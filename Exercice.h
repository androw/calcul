//      Exercice.h
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

#ifndef EXERCICE_H
#define EXERCICE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QSlider>
#include <QInputDialog>
#include <QGroupBox>
#include <QtGui>
#include <QMenuBar>
#include <QTextEdit>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<sys/time.h>
#include<iostream>
#include "Bilan.h"
using namespace std;
//float abs(float a);

class Exercice : public QDialog
{
    Q_OBJECT

protected:
    Bilan bilan;
    QProgressBar *progress;

public:
    Exercice();
    virtual void evaluation(float nombre) = 0;
    void verifDec(double a, double b);
};

#endif // EXERCICE_H
