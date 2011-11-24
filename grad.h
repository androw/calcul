#ifndef GRAD_H
#define GRAD_H


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

#include"Exercice.h"


class ExerciceGraduation : public Exercice {
    Q_OBJECT

        protected:
        QPushButton *m_bouton;
        QPushButton *m_menu;
        QLineEdit * reponse[9];
        double corrige[9];
        double taVariable;
        int place;
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

        public slots:
        void menu();


        public :
        ExerciceGraduation(QMainWindow *p);
        ~ExerciceGraduation();
         bool verif();
         void evaluation(float nombre);


};


#endif // GRAD_H
