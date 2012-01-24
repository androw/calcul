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

    //BOUTON VALIDATION
    serie = new QPushButton("Exercice \n Serie", this);
    tablem = new QPushButton("Exercice \n Table de \n Multiplication", this);
    grad = new QPushButton("Exercice \n Graduation \n de Droite", this);
    dedu = new QPushButton("Exercice \n de Deduction", this);
    equation = new QPushButton("Exercice \n Equation", this);
    devFac = new QPushButton("Exercice \n developpement \n et \n Factorisation", this);
    serie->setFont(QFont("encilPete FONT", 20));
    tablem->setFont(QFont("encilPete FONT", 20));
    grad->setFont(QFont("encilPete FONT", 20));
    dedu->setFont(QFont("encilPete FONT", 20));
    equation->setFont(QFont("encilPete FONT", 20));
    devFac->setFont(QFont("encilPete FONT", 20));
    serie->setCursor(Qt::PointingHandCursor);
    tablem->setCursor(Qt::PointingHandCursor);
    grad->setCursor(Qt::PointingHandCursor);
    dedu->setCursor(Qt::PointingHandCursor);
    equation->setCursor(Qt::PointingHandCursor);
    devFac->setCursor(Qt::PointingHandCursor);
    serie->setGeometry(110, 200, 100, 100);
    tablem->setGeometry(320, 200, 100, 100);
    grad->setGeometry(530, 200, 100, 100);
    dedu->setGeometry(110, 350, 100, 100);
    equation->setGeometry(320, 350, 100, 100);
    devFac->setGeometry(530, 350, 100, 100);
    lancerTest = new QPushButton("Lancer l'évaluation", this);
    lancerTest->setGeometry(320, 500, 100, 40);
    lancerTest->setFont(QFont("encilPete FONT", 20));
    lancerTest->setCursor(Qt::PointingHandCursor);
    lancerTest->setStyleSheet(" background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\
                           stop: 0 #FF0000, stop: 1 #F5F5F5);");

	// m_bouton->setToolTip("vérifier bien votre résultat");

    QObject::connect(serie, SIGNAL(clicked()), this, SLOT(aserie()));
    QObject::connect(tablem, SIGNAL(clicked()), this, SLOT(atable()));
    QObject::connect(dedu, SIGNAL(clicked()), this, SLOT(adedu()));
    QObject::connect(grad, SIGNAL(clicked()), this, SLOT(agrad()));
    QObject::connect(equation, SIGNAL(clicked()), this, SLOT(aequation()));

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

        QGroupBox *groupbox = new QGroupBox("Difficulté", this);

        QRadioButton *Facile = new QRadioButton("Facile");
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

}


void Menu::aserie() {
    ExerciceSerie *fenetre = new ExerciceSerie(this);
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
