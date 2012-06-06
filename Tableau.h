#ifndef TABLEAU_H
#define TABLEAU_H

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

class Tableau : public Exercice {
    Q_OBJECT

protected:
    QPushButton *m_bouton;
    QPushButton *m_menu;
    QPushButton *m_next;
    QPushButton *m_help;
    QPushButton *m_consigne;
    QLineEdit * reponse[30];
    float taVariable;
    float taVariable2;
    float taVariable3;
    int SECONDES;
    int MINUTES;
    QTimer *timerA;
    QLabel *label;
    QLabel *fleche;
    QLabel *aid;
    int erreur;
    int currenterr;
    QLabel *comment;
    QMainWindow *parent;
    int suiv;
    int suiva[10];

        public slots:
    void message();
    void chrono();
    void suivant();
    void aide();
    void consigne();

        public slots:
    void menu();

public :
        Tableau(QMainWindow *p,bool reel);
~Tableau();
bool verif();
void evaluation(float nombre);


};


#endif // TABLEAU_H
