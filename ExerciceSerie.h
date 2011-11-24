#ifndef SERIE_H
#define SERIE_H

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


class ExerciceSerie : public Exercice {
    Q_OBJECT

        protected:
        QPushButton *m_bouton;
        QPushButton *m_menu;
        QLineEdit * reponse[30];
        float taVariable;
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
        ExerciceSerie(QMainWindow *p);
        ~ExerciceSerie();
         bool verif();
         void evaluation(float nombre);


};

#endif // SERIE_H
