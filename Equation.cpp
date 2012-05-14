//      Equation.cpp
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

#include "Equation.h"

Equation::Equation(QMainWindow *p)
{
    parent = p;
    setFixedSize(800, 600);

    //FOND ECRAN
    QLabel *image = new QLabel(this);
    image->setPixmap(QPixmap("23.jpg"));
    image->setGeometry(0, 0, 800, 600);

    SECONDES = 00;
    MINUTES = 00;
    erreur = 0;
    currenterr = 0;
        timerA = new QTimer();
      label = new QLabel(QString::number(MINUTES)+" : 0"+ QString::number(SECONDES),this );
      timerA->start(1000); // Attention pas 100 = 0,1 seconde
      connect(timerA, SIGNAL(timeout()), this, SLOT(chrono()));
      //statusBar()->addWidget(label,1);
      label->setFont(QFont("PencilPet", 14));
      label->setStyleSheet("color:White;");
      label->setGeometry(500+200,30, 640, 50);


      progress = new QProgressBar(this);
      progress->setValue(erreur*10);
      progress->setGeometry(280+60, 415+110,200,30);



    srand(time(NULL));
    for(int i=0;i<10;i++) {
        taVariable = rand()%10+1;
        m[i].setCoefficient(taVariable);
        taVariable = rand()%10+1;
        m[i].setConstante(taVariable);
        taVariable = rand()%10+1;
        m[i].setResultat(taVariable);
        taVariable = rand()%10+1;
    }
    //BOUTON VALIDATION

    m_bouton = new QPushButton("Valider", this);
    m_bouton->setToolTip("Vérifier bien votre résultat");
    m_bouton->setFont(QFont("encilPete FONT", 14));
    m_bouton->setCursor(Qt::PointingHandCursor);
    m_bouton->move(180+60, 450+110);

    m_menu = new QPushButton("Menu", this);
    m_menu->setToolTip("Retour au Menu");
    m_menu->setFont(QFont("encilPete FONT", 14));
    m_menu->setCursor(Qt::PointingHandCursor);
    m_menu->move(380+60, 450+110);

    QObject::connect(m_bouton, SIGNAL(clicked()), this, SLOT(message()));
    QObject::connect(m_menu, SIGNAL(clicked()), this, SLOT(menu()));
    //QObject::connect(m_menu, SIGNAL(clicked()), qApp, SLOT(quit()));


    for(int i=0;i<10;i++){
        numerateur[i] = new QLineEdit("",this);
        numerateur[i]->setGeometry(520, 10*i+20+40+30*i+80,50,20);

    }
    for(int i=0;i<10;i++){
        denominateur[i] = new QLineEdit("",this);
        denominateur[i]->setGeometry(590, 10*i+20+40+30*i+80,50,20);

    }


    QLabel * calcul[10];
     QLabel * traitfraction[10];





    for(int i=0;i<10;i++){
        calcul[i] = new  QLabel(QString::number(m[i].getCoefficient()) +" x + "+ QString::number(m[i].getConstante()) +" = "+ QString::number(m[i].getResultat())+"  ",this);
        calcul[i]->setGeometry(300, 10*i+15+40+30*i+80,140,40);
        calcul[i]->setFont(QFont("PncilPete FONT", 14));
    }

    for(int i=0;i<10;i++){
        traitfraction[i] = new  QLabel("/",this);
        traitfraction[i]->setGeometry(575,10*i+20+30+30*i+80,15,40);
        traitfraction[i]->setFont(QFont("PncilPete FONT", 14));
    }

    for(int i=0;i<10;i++){
        traitfraction[i] = new  QLabel("x =",this);
        traitfraction[i]->setGeometry(470,10*i+20+30+30*i+80,30,40);
        traitfraction[i]->setFont(QFont("PncilPete FONT", 14));
    }




     //CONSIGNE
     QLabel *label1 = new QLabel("Résoudre ces équations", this);
     label1->setFont(QFont("PenclPete FONT", 18));
     label1->setStyleSheet("color:White;");
     label1->setGeometry(40, 23, 500, 50);
     label1->setStyleSheet("border-width: 2px;\
                           border-style: outset;\
                           border-width: 2px;\
                           border-radius: 10px;\
                           border-color: black;\
                           background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\
                           stop: 0 #FFFFFF, stop: 1 #BA55D3);");


}

bool Equation::verif() {
    currenterr = 0;

    for(int i=0; i<10;i++) {
        if(denominateur[i]->text().toFloat() == 0 || abs((numerateur[i]->text().toFloat() / denominateur[i]->text().toFloat() - (m[i].getResultat() - m[i].getConstante())/m[i].getCoefficient())) > 0.00001) {
            numerateur[i]->setStyleSheet("border-style: outset;\
                                      background-color: #FF6347;\
                                      border-width: 2px;\
                                      border-radius: 10px;");
            denominateur[i]->setStyleSheet("border-style: outset;\
                                      background-color: #FF6347;\
                                      border-width: 2px;\
                                      border-radius: 10px;");
            currenterr++;
            erreur++;
            progress->setValue(erreur*20);

        }
        if(denominateur[i]->text().toFloat() != 0 && abs((numerateur[i]->text().toFloat() / denominateur[i]->text().toFloat() - (m[i].getResultat() - m[i].getConstante())/m[i].getCoefficient())) < 0.00001) {
            numerateur[i]->setStyleSheet("border-style: outset;\
                                      border-width: 2px;\
                                      border-radius: 10px;");
            denominateur[i]->setStyleSheet("border-style: outset;\
                                      border-width: 2px;\
                                      border-radius: 10px;");

        }
    }



    for(int i=0; i<10;i++) {
        if(denominateur[i]->text().toFloat() == 0 ||abs((numerateur[i]->text().toFloat() / denominateur[i]->text().toFloat() - (m[i].getResultat() - m[i].getConstante())/m[i].getCoefficient())) > 0.00001) {
            return false;

        }
    }
    return true;
}

void Equation::message(){
    if(verif()) {
        timerA->stop();
        if(SECONDES<10) {
        QMessageBox::information(this, "Félicitation", "Vous avez résolue le problème avec succès en " + QString::number(MINUTES)+ ":0" + QString::number(SECONDES)+ " ! \n Vous avez fait "+ QString::number(erreur)+ " erreurs!");
        }else {
            QMessageBox::information(this, "Félicitation", "Vous avez résolue le problème avec succès en " + QString::number(MINUTES)+ ":" + QString::number(SECONDES)+ " ! \n Vous avez fait "+ QString::number(erreur)+ " erreurs!");
        }
    }else {
        QMessageBox::critical(this, "Attention", "Il reste "+ QString::number(currenterr)+ " erreurs!");
    }
}


void Equation::evaluation(float nombre) {

        if (erreur < 10) {
                comment->setText("WOUAOUHH !!! ");
        }
        else if (erreur < 15) {
                comment->setText( "Pas mal ! ");
        }
        else if (erreur < 25) {
                comment->setText("Mouais ..");
        }
        else {
                comment->setText( "LOOSER");
        }
        if (MINUTES < 2) {
                comment->setText( "Rapide comme l'éclair !");
        }
        else if (MINUTES < 3) {
                comment->setText("Pas trop lent");
        }
        else {
                comment->setText( "Escargal !!");
        }
}

void Equation::chrono(){

    if(SECONDES<10) {
        label->setText(QString::number(MINUTES)+" : 0"+ QString::number(SECONDES) );
    }else {
        label->setText( QString::number(MINUTES)+" : "+ QString::number(SECONDES) );
    }
  if (SECONDES == 59) {
  SECONDES=00;
  MINUTES++;
  }else {
      SECONDES++;
  }




}

void Equation::menu() {
    close();
    parent->show();


}

Equation::~Equation() {

    delete[] numerateur;
    delete[] denominateur;
}



