//      Menu.cpp
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

#include "Menu.h"


Menu::Menu()
{
    setFixedSize(800, 600);

    //FOND ECRAN
    QLabel *image = new QLabel(this);
    image->setPixmap(QPixmap("22.jpg"));
    image->setGeometry(0, 0, 800, 600);
    
    nom = new QLineEdit("Nom",this);
    nom->setGeometry(600,100,110,30);
    nom->setStyleSheet("border-style: outset;\
                              border-width: 2px;\
                              border-radius: 10px;");
    prenom = new QLineEdit("Prenom",this);
    prenom->setGeometry(480,100,110,30);
    prenom->setStyleSheet("border-style: outset;\
                       border-width: 2px;\
                       border-radius: 10px;");
    
    classe = new QComboBox(this);
    classe->addItem("CM2");
    classe->addItem("6eme");
    classe->addItem("5eme");
    classe->addItem("4eme");
    classe->setGeometry(720, 100, 70,30);

    //BOUTON VALIDATION
    boite1 = new QPushButton("Exercice \n Boite x4", this);
    boite2 = new QPushButton("Exercice \n Boite x20", this);
    boite3 = new QPushButton("Exercice \n Boite x5", this);
    boite4 = new QPushButton("Exercice \n Boite x3", this);
    boite5 = new QPushButton("Exercice \n Boite x9", this);
    serie = new QPushButton("Exercice \n Serie", this);
    tablem = new QPushButton("Exercice \n Table de \n Multiplication", this);
    grad = new QPushButton("Exercice \n Graduation \n de Droite", this);
    dedu = new QPushButton("Exercice \n de Deduction", this);
    equation = new QPushButton("Exercice \n Equation", this);

    boite1->setFont(QFont("encilPete FONT", 20));
    boite2->setFont(QFont("encilPete FONT", 20));
    boite3->setFont(QFont("encilPete FONT", 20));
    boite4->setFont(QFont("encilPete FONT", 20));
    boite5->setFont(QFont("encilPete FONT", 20));
    serie->setFont(QFont("encilPete FONT", 20));
    tablem->setFont(QFont("encilPete FONT", 20));
    grad->setFont(QFont("encilPete FONT", 20));
    dedu->setFont(QFont("encilPete FONT", 20));
    equation->setFont(QFont("encilPete FONT", 20));

    boite1->setCursor(Qt::PointingHandCursor);
    boite2->setCursor(Qt::PointingHandCursor);
    boite3->setCursor(Qt::PointingHandCursor);
    boite4->setCursor(Qt::PointingHandCursor);
    serie->setCursor(Qt::PointingHandCursor);
    tablem->setCursor(Qt::PointingHandCursor);
    grad->setCursor(Qt::PointingHandCursor);
    dedu->setCursor(Qt::PointingHandCursor);
    equation->setCursor(Qt::PointingHandCursor);

    equation->setGeometry(0, 0, 0, 0);
    serie->setGeometry(0, 0, 0, 0);
    tablem->setGeometry(0, 0, 0, 0);
    grad->setGeometry(0, 0, 0, 0);
    dedu->setGeometry(0, 0, 0, 0);


    QPropertyAnimation *animation1 = new QPropertyAnimation (boite1, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(0, 0, 100, 100));
    animation1->setEndValue(QRect(110, 200, 100, 100));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    QPropertyAnimation *animation2 = new QPropertyAnimation (boite2, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(0, 0, 100, 30));
    animation2->setEndValue(QRect(320, 200, 100, 100));
    animation2->setEasingCurve(QEasingCurve::OutBack);
    animation2->start();

    QPropertyAnimation *animation3 = new QPropertyAnimation (boite3, "geometry");
    animation3->setDuration(500);
    animation3->setStartValue(QRect(0, 0, 100, 30));
    animation3->setEndValue(QRect(530, 200, 100, 100));
    animation3->setEasingCurve(QEasingCurve::OutBack);
    animation3->start();

    QPropertyAnimation *animation4 = new QPropertyAnimation (boite4, "geometry");
    animation4->setDuration(500);
    animation4->setStartValue(QRect(0, 0, 100, 30));
    animation4->setEndValue(QRect(110, 340, 100, 100));
    animation4->setEasingCurve(QEasingCurve::OutBack);
    animation4->start();

    QPropertyAnimation *animation5 = new QPropertyAnimation (boite5, "geometry");
    animation5->setDuration(500);
    animation5->setStartValue(QRect(0, 0, 100, 30));
    animation5->setEndValue(QRect(320, 340, 100, 100));
    animation5->setEasingCurve(QEasingCurve::OutBack);
    animation5->start();

    tableau = new QPushButton("Exercice \n Tableau", this);
    tableau->setFont(QFont("encilPete FONT", 20));
    tableau->setCursor(Qt::PointingHandCursor);
    tableau->setGeometry(0, 0, 0, 0);

    lancerTest = new QPushButton("Lancer l'évaluation", this);
    lancerTest->setGeometry(320, 500, 100, 40);
    lancerTest->setFont(QFont("encilPete FONT", 20));
    lancerTest->setCursor(Qt::PointingHandCursor);
    lancerTest->setStyleSheet(" background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\
                           stop: 0 #FF0000, stop: 1 #F5F5F5);");


    QGroupBox *groupbox = new QGroupBox("Catégories", this);

    QRadioButton *Facile = new QRadioButton("Décomposition calcul");
    QRadioButton *Normal = new QRadioButton("Normal");
    QRadioButton *Difficile = new QRadioButton("Difficile");
    QRadioButton *TresDifficile = new QRadioButton("Trés Difficile");

    QVBoxLayout *vbox = new QVBoxLayout;
        vbox->addWidget(Facile);
        vbox->addWidget(Normal);
        vbox->addWidget(Difficile);
        vbox->addWidget(TresDifficile);

        groupbox->setLayout(vbox);
        groupbox->setGeometry(600, 490, 50, 100);

        Facile->setChecked(true);

	// m_bouton->setToolTip("vérifier bien votre résultat");
    QObject::connect(boite1, SIGNAL(clicked()), this, SLOT(aboite1()));
    QObject::connect(boite2, SIGNAL(clicked()), this, SLOT(aboite2()));
    QObject::connect(boite3, SIGNAL(clicked()), this, SLOT(aboite3()));
    QObject::connect(boite4, SIGNAL(clicked()), this, SLOT(aboite4()));
    QObject::connect(boite5, SIGNAL(clicked()), this, SLOT(aboite5()));
    QObject::connect(serie, SIGNAL(clicked()), this, SLOT(aserie()));
    QObject::connect(tablem, SIGNAL(clicked()), this, SLOT(atable()));
    QObject::connect(tableau, SIGNAL(clicked()), this, SLOT(atableau()));
    QObject::connect(dedu, SIGNAL(clicked()), this, SLOT(adedu()));
    QObject::connect(grad, SIGNAL(clicked()), this, SLOT(agrad()));
    QObject::connect(equation, SIGNAL(clicked()), this, SLOT(aequation()));
    QObject::connect(Facile, SIGNAL(clicked()), this, SLOT(facil()));
    QObject::connect(Normal, SIGNAL(clicked()), this, SLOT(normal()));
    QObject::connect(Difficile, SIGNAL(clicked()), this, SLOT(difficil()));
    QObject::connect(TresDifficile, SIGNAL(clicked()), this, SLOT(Tdifficil()));

	//CONSIGNE
	QLabel *label1 = new QLabel("Choisissez l'exercice que vous voulez", this);
	label1->setFont(QFont("PenclPete FONT", 18));
	label1->setStyleSheet("color:White;");
	label1->setGeometry(40, 23, 450, 50);
    label1->setStyleSheet("border-width: 2px;\
                          border-style: outset;\
                          border-width: 2px;\
                          border-radius: 10px;\
                          border-color: black;\
                          background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\
                          stop: 0 #FFFFFF, stop: 1 #BA55D3);");

     /*   QComboBox * Liste = new QComboBox(this);
        Liste->addItem("Entraînement");
        Liste->addItem("Evaluation");
        Liste->addItem("Compétition");
        Liste->setGeometry(40, 90, 100, 25);
        Liste->setCursor(Qt::PointingHandCursor); */




}


void Menu::facil() {


    animation2 = new QPropertyAnimation (equation, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(120, 120, 0, 0));
    animation2->setEndValue(QRect(0, 0, 0, 0));
    animation2->setEasingCurve(QEasingCurve::OutBack);
    animation2->start();

    animation2 = new QPropertyAnimation (serie, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(120, 120, 0, 0));
    animation2->setEndValue(QRect(0, 0, 0, 0));
    animation2->setEasingCurve(QEasingCurve::OutBack);
    animation2->start();

    animation2 = new QPropertyAnimation (tablem, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(120, 120, 0, 0));
    animation2->setEndValue(QRect(0, 0, 0, 0));
    animation2->setEasingCurve(QEasingCurve::OutBack);
    animation2->start();

    animation2 = new QPropertyAnimation (tableau, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(120, 120, 0, 0));
    animation2->setEndValue(QRect(0, 0, 0, 0));
    animation2->setEasingCurve(QEasingCurve::OutBack);
    animation2->start();

    animation2 = new QPropertyAnimation (grad, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(120, 120, 0, 0));
    animation2->setEndValue(QRect(0, 0, 0, 0));
    animation2->setEasingCurve(QEasingCurve::OutBack);
    animation2->start();

    animation2 = new QPropertyAnimation (dedu, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(120, 120, 0, 0));
    animation2->setEndValue(QRect(0, 0, 0, 0));
    animation2->setEasingCurve(QEasingCurve::OutBack);
    animation2->start();

    animation1 = new QPropertyAnimation (boite1, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(0, 0, 100, 100));
    animation1->setEndValue(QRect(110, 200, 100, 100));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite2, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(0, 0, 100, 30));
    animation1->setEndValue(QRect(320, 200, 100, 100));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite3, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(0, 0, 100, 30));
    animation1->setEndValue(QRect(530, 200, 100, 100));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite4, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(0, 0, 100, 30));
    animation1->setEndValue(QRect(110, 340, 100, 100));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite5, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(0, 0, 100, 30));
    animation1->setEndValue(QRect(320, 340, 100, 100));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();
}

void Menu::normal() {

    
    animation1 = new QPropertyAnimation (grad, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (dedu, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (tableau, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite1, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();
    
    animation1 = new QPropertyAnimation (boite2, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();
    
    animation1 = new QPropertyAnimation (boite3, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();
    
    animation1 = new QPropertyAnimation (boite4, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();
    
    animation1 = new QPropertyAnimation (boite5, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(320, 340, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation2 = new QPropertyAnimation (equation, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(0, 0, 100, 100));
    animation2->setEndValue(QRect(110, 200, 100, 100));
    animation2->setEasingCurve(QEasingCurve::OutBack);
    animation2->start();

    animation2 = new QPropertyAnimation (serie, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(0, 0, 100, 30));
    animation2->setEndValue(QRect(320, 200, 100, 100));
    animation2->setEasingCurve(QEasingCurve::OutBack);
    animation2->start();

    animation2 = new QPropertyAnimation (tablem, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(0, 0, 100, 30));
    animation2->setEndValue(QRect(530, 200, 100, 100));
    animation2->setEasingCurve(QEasingCurve::OutBack);
    animation2->start();
}
void Menu::difficil() {


    animation1 = new QPropertyAnimation (equation, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (tableau, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (serie, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (tablem, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite1, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite2, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite3, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite4, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite5, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(320, 340, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation2 = new QPropertyAnimation (grad, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(0, 0, 100, 100));
    animation2->setEndValue(QRect(110, 200, 100, 100));
    animation2->setEasingCurve(QEasingCurve:: OutBack);
    animation2->start();

    animation2 = new QPropertyAnimation (dedu, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(0, 0, 100, 30));
    animation2->setEndValue(QRect(320, 200, 100, 100));
    animation2->setEasingCurve(QEasingCurve:: OutBack);
    animation2->start();

}
void Menu::Tdifficil() {

    animation1 = new QPropertyAnimation (grad, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (dedu, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (equation, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (serie, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (tablem, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite1, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite2, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite3, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite4, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite5, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(320, 340, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation2 = new QPropertyAnimation (tableau, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(0, 0, 100, 100));
    animation2->setEndValue(QRect(110, 200, 100, 100));
    animation2->setEasingCurve(QEasingCurve:: OutBack);
    animation2->start();


}


void Menu::aserie() {
    ExerciceSerie *fenetre = new ExerciceSerie(this);
    //hide();
    fenetre->exec();
}

void Menu::atableau() {
    Tableau *fenetre = new Tableau(this);
    //hide();
    fenetre->exec();
}

void Menu::aboite1() {
    Boite *fenetre = new Boite(this,2,4);
    //hide();
    fenetre->exec();
}

void Menu::aboite2() {
    Boite *fenetre = new Boite(this,10,20);
    //hide();
    fenetre->exec();
}

void Menu::aboite3() {
    Boite *fenetre = new Boite(this,10,5);
    //hide();
    fenetre->exec();
}

void Menu::aboite4() {
    Boite *fenetre = new Boite(this,2,3);
    //hide();
    fenetre->exec();
}

void Menu::aboite5() {
    Boite *fenetre = new Boite(this,10,9);
    //hide();
    fenetre->exec();
}

void Menu::atable() {
    Table *fenetre = new Table(this);
    //hide();
    fenetre->exec();
}

void Menu::adedu() {
    Deduction *fenetre = new Deduction(this);
    //hide();
    fenetre->exec();
}

void Menu::agrad() {
    ExerciceGraduation *fenetre = new ExerciceGraduation(this);
    //hide();
    fenetre->exec();
}

void Menu::aequation() {
    Equation *fenetre = new Equation(this);
    //hide();
    fenetre->exec();
}
