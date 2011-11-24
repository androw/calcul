#ifndef TABLE_H
#define TABLE_H


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


class Table : public Exercice {
    Q_OBJECT

        protected:
        QPushButton *m_bouton;
        QPushButton *m_menu;
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

        public slots:
        void menu();


        public :
        Table(QMainWindow *p);
        ~Table();
         bool verif();
         void evaluation(float nombre);


};

#endif // TABLE_H