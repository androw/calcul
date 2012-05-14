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
    prenom = new QLineEdit("Prénom",this);
    prenom->setGeometry(480,100,110,30);
    prenom->setStyleSheet("border-style: outset;\
                       border-width: 2px;\
                       border-radius: 10px;");
    
    classe = new QComboBox(this);
    classe->addItem("CM2");
    classe->addItem("6eme");
    classe->addItem("5eme");
    classe->addItem("4eme");
    classe->addItem("3eme");
    classe->setGeometry(720, 100, 70,30);

    //BOUTON VALIDATION
    boite1 = new QPushButton("Boite x4", this);
    boite2 = new QPushButton("Boite x20", this);
    boite3 = new QPushButton("Boite x5", this);
    boite4 = new QPushButton("Boite x3", this);
    boite5 = new QPushButton("Boite x9", this);
    boite6 = new QPushButton("Boite x9 \n version opérateur", this);
    boite7 = new QPushButton("Boite x4 \n version opérateur", this);
    boite8 = new QPushButton("Boite x20 \n version opérateur", this);
    boite9 = new QPushButton("Boite x5 \n version opérateur", this);
    boite10 = new QPushButton("Boite x3 \n version opérateur", this);
    boite11 = new QPushButton("Boite x200 \n version opérateur", this);
    boite12 = new QPushButton("Boite x400 \n version opérateur", this);


    serie = new QPushButton("Série", this);
    tablem = new QPushButton("Table de \n multiplication", this);
    grad = new QPushButton("Graduation \n de droite", this);
    dedu = new QPushButton("Déduction", this);
    equation = new QPushButton("Résolution d'équation", this);
    
    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(350, 500, 100,20);
    m_slider->setRange(0, 800);
            
    boite1->setFont(QFont("encilPete FONT", 20));
    boite2->setFont(QFont("encilPete FONT", 20));
    boite3->setFont(QFont("encilPete FONT", 20));
    boite4->setFont(QFont("encilPete FONT", 20));
    boite5->setFont(QFont("encilPete FONT", 20));
    boite6->setFont(QFont("encilPete FONT", 20));
    boite7->setFont(QFont("encilPete FONT", 20));
    boite8->setFont(QFont("encilPete FONT", 20));
    boite9->setFont(QFont("encilPete FONT", 20));
    boite10->setFont(QFont("encilPete FONT", 20));
    boite11->setFont(QFont("encilPete FONT", 20));
    boite12->setFont(QFont("encilPete FONT", 20));
    serie->setFont(QFont("encilPete FONT", 20));
    tablem->setFont(QFont("encilPete FONT", 20));
    grad->setFont(QFont("encilPete FONT", 20));
    dedu->setFont(QFont("encilPete FONT", 20));
    equation->setFont(QFont("encilPete FONT", 20));

    boite1->setCursor(Qt::PointingHandCursor);
    boite2->setCursor(Qt::PointingHandCursor);
    boite3->setCursor(Qt::PointingHandCursor);
    boite4->setCursor(Qt::PointingHandCursor);
    boite5->setCursor(Qt::PointingHandCursor);
    boite6->setCursor(Qt::PointingHandCursor);
    boite7->setCursor(Qt::PointingHandCursor);
    boite8->setCursor(Qt::PointingHandCursor);
    boite9->setCursor(Qt::PointingHandCursor);
    boite10->setCursor(Qt::PointingHandCursor);
    boite11->setCursor(Qt::PointingHandCursor);
    boite12->setCursor(Qt::PointingHandCursor);
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

    QPropertyAnimation *animation6 = new QPropertyAnimation (boite6, "geometry");
    animation6->setDuration(500);
    animation6->setStartValue(QRect(0, 0, 100, 30));
    animation6->setEndValue(QRect(530, 340, 100, 100));
    animation6->setEasingCurve(QEasingCurve::OutBack);
    animation6->start();

    animation1 = new QPropertyAnimation (boite7, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(0, 0, 100, 100));
    animation1->setEndValue(QRect(110+800, 200, 100, 100));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation2 = new QPropertyAnimation (boite8, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(0, 0, 100, 30));
    animation2->setEndValue(QRect(320+800, 200, 100, 100));
    animation2->setEasingCurve(QEasingCurve::OutBack);
    animation2->start();

    animation3 = new QPropertyAnimation (boite9, "geometry");
    animation3->setDuration(500);
    animation3->setStartValue(QRect(0, 0, 100, 30));
    animation3->setEndValue(QRect(530+800, 200, 100, 100));
    animation3->setEasingCurve(QEasingCurve::OutBack);
    animation3->start();

    animation4 = new QPropertyAnimation (boite10, "geometry");
    animation4->setDuration(500);
    animation4->setStartValue(QRect(0, 0, 100, 30));
    animation4->setEndValue(QRect(110+800, 340, 100, 100));
    animation4->setEasingCurve(QEasingCurve::OutBack);
    animation4->start();

    animation5 = new QPropertyAnimation (boite11, "geometry");
    animation5->setDuration(500);
    animation5->setStartValue(QRect(0, 0, 100, 30));
    animation5->setEndValue(QRect(320+800, 340, 100, 100));
    animation5->setEasingCurve(QEasingCurve::OutBack);
    animation5->start();

    animation6 = new QPropertyAnimation (boite12, "geometry");
    animation6->setDuration(500);
    animation6->setStartValue(QRect(0, 0, 100, 30));
    animation6->setEndValue(QRect(530+800, 340, 100, 100));
    animation6->setEasingCurve(QEasingCurve::OutBack);
    animation6->start();

    tableau = new QPushButton("Tableau", this);
    tableau->setFont(QFont("encilPete FONT", 20));
    tableau->setCursor(Qt::PointingHandCursor);
    tableau->setGeometry(0, 0, 0, 0);




    QGroupBox *groupbox = new QGroupBox("Catégories", this);

    QRadioButton *Facile = new QRadioButton("Décomposition");
    QRadioButton *Normal = new QRadioButton("Calcul basique");
    QRadioButton *Difficile = new QRadioButton("Autre");

    QVBoxLayout *vbox = new QVBoxLayout;
        vbox->addWidget(Facile);
        vbox->addWidget(Normal);
        vbox->addWidget(Difficile);

        groupbox->setLayout(vbox);
        groupbox->setGeometry(600, 490, 50, 100);

        Facile->setChecked(true);

	// m_bouton->setToolTip("vérifier bien votre résultat");
    QObject::connect(boite1, SIGNAL(clicked()), this, SLOT(aboite1()));
    QObject::connect(boite2, SIGNAL(clicked()), this, SLOT(aboite2()));
    QObject::connect(boite3, SIGNAL(clicked()), this, SLOT(aboite3()));
    QObject::connect(boite4, SIGNAL(clicked()), this, SLOT(aboite4()));
    QObject::connect(boite5, SIGNAL(clicked()), this, SLOT(aboite5()));
    QObject::connect(boite6, SIGNAL(clicked()), this, SLOT(aboite6()));
    QObject::connect(boite7, SIGNAL(clicked()), this, SLOT(aboite7()));
    QObject::connect(boite8, SIGNAL(clicked()), this, SLOT(aboite8()));
    QObject::connect(boite9, SIGNAL(clicked()), this, SLOT(aboite9()));
    QObject::connect(boite10, SIGNAL(clicked()), this, SLOT(aboite10()));
    QObject::connect(boite11, SIGNAL(clicked()), this, SLOT(aboite11()));
    QObject::connect(boite12, SIGNAL(clicked()), this, SLOT(aboite12()));
    QObject::connect(serie, SIGNAL(clicked()), this, SLOT(aserie()));
    QObject::connect(tablem, SIGNAL(clicked()), this, SLOT(atable()));
    QObject::connect(tableau, SIGNAL(clicked()), this, SLOT(atableau()));
    QObject::connect(dedu, SIGNAL(clicked()), this, SLOT(adedu()));
    QObject::connect(grad, SIGNAL(clicked()), this, SLOT(agrad()));
    QObject::connect(equation, SIGNAL(clicked()), this, SLOT(aequation()));
    QObject::connect(Facile, SIGNAL(clicked()), this, SLOT(facil()));
    QObject::connect(Normal, SIGNAL(clicked()), this, SLOT(normal()));
    QObject::connect(Difficile, SIGNAL(clicked()), this, SLOT(difficil()));
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(deplacer()));

	//CONSIGNE
        QLabel *label1 = new QLabel("Mathémat'EISTI'c", this);
	label1->setFont(QFont("PenclPete FONT", 18));
	label1->setStyleSheet("color:White;");
        label1->setGeometry(40, 23, 250, 50);
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

    animation2 = new QPropertyAnimation (m_slider, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(0, 0, 0, 0));
    animation2->setEndValue(QRect(350, 500, 100,20));
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

    animation1 = new QPropertyAnimation (boite6, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(0, 0, 100, 30));
    animation1->setEndValue(QRect(530, 340, 100, 100));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite7, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(0, 0, 100, 100));
    animation1->setEndValue(QRect(110+800, 200, 100, 100));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation2 = new QPropertyAnimation (boite8, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(0, 0, 100, 30));
    animation2->setEndValue(QRect(320+800, 200, 100, 100));
    animation2->setEasingCurve(QEasingCurve::OutBack);
    animation2->start();

    animation1 = new QPropertyAnimation (boite9, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(0, 0, 100, 30));
    animation1->setEndValue(QRect(530+800, 200, 100, 100));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite10, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(0, 0, 100, 30));
    animation1->setEndValue(QRect(110+800, 340, 100, 100));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite11, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(0, 0, 100, 30));
    animation1->setEndValue(QRect(320+800, 340, 100, 100));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite12, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(0, 0, 100, 30));
    animation1->setEndValue(QRect(530+800, 340, 100, 100));
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

    animation1 = new QPropertyAnimation (m_slider, "geometry");
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

    animation1 = new QPropertyAnimation (boite6, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(320, 340, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite7, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite8, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite9, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite10, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite11, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(320, 340, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite12, "geometry");
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

    animation2 = new QPropertyAnimation (grad, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(0, 0, 100, 100));
    animation2->setEndValue(QRect(110, 200, 100, 100));
    animation2->setEasingCurve(QEasingCurve::OutBack);
    animation2->start();

    animation2 = new QPropertyAnimation (dedu, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(0, 0, 100, 30));
    animation2->setEndValue(QRect(320, 200, 100, 100));
    animation2->setEasingCurve(QEasingCurve::OutBack);
    animation2->start();


    animation1 = new QPropertyAnimation (m_slider, "geometry");
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

    animation2 = new QPropertyAnimation (tableau, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(0, 0, 100, 30));
    animation2->setEndValue(QRect(530, 200, 100, 100));
    animation2->setEasingCurve(QEasingCurve:: OutBack);
    animation2->start();

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

    animation1 = new QPropertyAnimation (boite6, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite7, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation2 = new QPropertyAnimation (boite8, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(QRect(120, 120, 0, 0));
    animation2->setEndValue(QRect(0, 0, 0, 0));
    animation2->setEasingCurve(QEasingCurve::OutBack);
    animation2->start();

    animation1 = new QPropertyAnimation (boite9, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite10, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite11, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();

    animation1 = new QPropertyAnimation (boite12, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(120, 120, 0, 0));
    animation1->setEndValue(QRect(0, 0, 0, 0));
    animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start();
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

void Menu::aboite6() {
    Boite2 *fenetre = new Boite2(this,10,9);
    //hide();
    fenetre->exec();
}

void Menu::aboite7() {
    Boite2 *fenetre = new Boite2(this,2,4);
    //hide();
    fenetre->exec();
}

void Menu::aboite8() {
    Boite2 *fenetre = new Boite2(this,10,20);
    //hide();
    fenetre->exec();
}

void Menu::aboite9() {
    Boite2 *fenetre = new Boite2(this,10,5);
    //hide();
    fenetre->exec();
}

void Menu::aboite10() {
    Boite2 *fenetre = new Boite2(this,2,3);
    //hide();
    fenetre->exec();
}

void Menu::aboite11() {
    Boite2 *fenetre = new Boite2(this,100,200);
    //hide();
    fenetre->exec();
}

void Menu::aboite12() {
    Boite2 *fenetre = new Boite2(this,200,400);
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

void Menu::deplacer() {
   boite1->setGeometry(110 - m_slider->value(), 200, 100, 100);
   boite2->setGeometry(320- m_slider->value(), 200, 100, 100);
   boite3->setGeometry(530- m_slider->value(), 200, 100, 100);
   boite4->setGeometry(110- m_slider->value(), 340, 100, 100);
   boite5->setGeometry(320- m_slider->value(), 340, 100, 100);
   boite6->setGeometry(530- m_slider->value(), 340, 100, 100);
   boite7->setGeometry(110 - m_slider->value()+800, 200, 100, 100);
   boite8->setGeometry(320- m_slider->value()+800, 200, 100, 100);
   boite9->setGeometry(530- m_slider->value()+800, 200, 100, 100);
   boite10->setGeometry(110- m_slider->value()+800, 340, 100, 100);
   boite11->setGeometry(320- m_slider->value()+800, 340, 100, 100);
   boite12->setGeometry(530- m_slider->value()+800, 340, 100, 100);
}
