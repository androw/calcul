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

class Exercice : public QDialog
{
Q_OBJECT

    protected:

   Bilan bilan;



    public:
    Exercice();
   virtual void evaluation(float nombre) = 0;
};

#endif // EXERCICE_H
