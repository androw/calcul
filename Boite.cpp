//      Boite.cpp
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

#include "Boite.h"

Boite::Boite(QMainWindow *p,int e1,int e2)
{
    parent = p;
    setFixedSize(800, 600);

    //FOND ECRAN
    QLabel *image = new QLabel(this);
    image->setPixmap(QPixmap("boite.jpg"));
    image->setGeometry(0, 0, 800, 600);
    etude1 = e1;
    etude2 = e2;
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
    progress->setGeometry(280+60, 400+110,200,30);

    srand(time(NULL));
    for(int i = 0;i<5;i++) {
        taVariable[i] = rand()%20+11;
        while(repet(i) && i>0){
            taVariable[i] = rand()%20+11;
        }

    }


    //BOUTON VALIDATION

    m_bouton = new QPushButton("Valider", this);
    m_bouton->setToolTip("Vérifier bien votre résultat");
    m_bouton->setFont(QFont("encilPete FONT", 14));
    m_bouton->setCursor(Qt::PointingHandCursor);
    m_bouton->move(140+60, 450+110);

    m_menu = new QPushButton("Menu", this);
    m_menu->setToolTip("Retour au Menu");
    m_menu->setFont(QFont("encilPete FONT", 14));
    m_menu->setCursor(Qt::PointingHandCursor);
    m_menu->move(340+60, 450+110);
    
    m_consigne = new QPushButton("Consigne", this);
    m_consigne->setToolTip("Afficher la consigne");
    m_consigne->setFont(QFont("encilPete FONT", 14));
    m_consigne->setCursor(Qt::PointingHandCursor);
    m_consigne->move(540+60, 450+110);


    QObject::connect(m_bouton, SIGNAL(clicked()), this, SLOT(message()));
    QObject::connect(m_menu, SIGNAL(clicked()), this, SLOT(menu()));
    QObject::connect(m_consigne, SIGNAL(clicked()), this, SLOT(consigne()));
    //QObject::connect(m_menu, SIGNAL(clicked()), qApp, SLOT(quit()));

    for(int i=0;i<5;i++){
        reponse[i] = new QLineEdit("",this);
        reponse[i]->setGeometry(385, 50*i+28+40+30*i+80,50,20);


    }
    for(int i=0;i<5;i++){
        reponse[i+5] = new QLineEdit("",this);
        reponse[i+5]->setGeometry(547, 50*i+34+40+30*i+80,50,20);

    }


    QLabel * calcul[20];

    for(int i=0;i<5;i++){
        calcul[i] = new  QLabel(QString::number(taVariable[i]),this);
        calcul[i]->setGeometry(245, 50*i+15+50+30*i+80,90,40);
        calcul[i]->setFont(QFont("PncilPete FONT", 14));
    }



    for(int i=0;i<5;i++){
        calcul[i+5] = new  QLabel("x" + QString::number(etude1),this);
        calcul[i+5]->setGeometry(230+84, 50*i+34+30*i+80,90,40);
        calcul[i+5]->setFont(QFont("PncilPete FONT", 14));
    }

    for(int i=0;i<5;i++){
        if(etude2/etude1 == 0.5) {
            calcul[i+10] = new  QLabel(": 2",this);
	}
	else if(etude2 == 3) {
            calcul[i+10] = new  QLabel("+ " + QString::number(taVariable[i]),this);
	}
	else if(etude2 == 9) {
            calcul[i+10] = new  QLabel("- " + QString::number(taVariable[i]),this);
	}
        else {
            calcul[i+10] = new  QLabel("x" + QString::number(etude2/etude1),this);
        }

        calcul[i+10]->setGeometry(390+84, 50*i+34+30*i+80,90,40);
        calcul[i+10]->setFont(QFont("PncilPete FONT", 14));

    }

    for(int i=0;i<5;i++){
        calcul[i+15] = new  QLabel("x" + QString::number(etude2),this);
        calcul[i+15]->setGeometry(310+84, 50*i+13+30*i+80,90,40);
        calcul[i+15]->setFont(QFont("PncilPete FONT", 14));
    }





    //CONSIGNE
    QLabel *label1 = new QLabel("Compléter ces calculs", this);
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

void Boite::consigne() {
    QFrame* popup1 = new QFrame(this, Qt::Popup | Qt::Window );
    popup1->resize(500,300);
    QLabel *text1 = new QLabel("Aide", popup1);
    QLabel *text2 = new QLabel("Il faut ici effectuer une multiplication difficile.\nPour cela, le calcul est décomposé en deux étapes.\nDans la case centrale, il faut donner un resultat intermédiaire donné par \nl'opération suivante :\nNombre initial * coefficient de gauche = resultat intermédiaire.\nEnfin, pour trouver la solution final, vous pouvez utiliser ce nombre afin \nd?obtenir le resultat dans le cadre de droite.", popup1);
    text1->move(10, 10);
    text2->move(10,30);
    popup1->show();
}

bool Boite::verif(int etude1,int etude2) {
    currenterr = 0;
    for(int i=0; i<5;i++) {
        if(reponse[i]->text().toFloat() != etude1*taVariable[i]) {
            reponse[i]->setStyleSheet("border-style: outset;\
                                      background-color: #FF6347;\
                                      border-width: 2px;\
                                      border-radius: 10px;");
            currenterr++;
            erreur++;
            progress->setValue(erreur*20);

        }
        if(reponse[i]->text().toFloat() == etude1*taVariable[i]) {
            reponse[i]->setStyleSheet("border-style: outset;\
                                      border-width: 2px;\
                                      border-radius: 10px;");

        }
    }
    for(int i=0; i<5;i++) {
        if(reponse[i+5]->text().toFloat() != etude2*taVariable[i]) {
            reponse[i+5]->setStyleSheet("border-style: outset;\
                                        background-color: #FF6347;\
                                        border-width: 2px;\
                                        border-radius: 10px;");
            currenterr++;
            erreur++;
            progress->setValue(erreur*20);

        }
        if(reponse[i+5]->text().toFloat() == etude2*taVariable[i]) {
            reponse[i+5]->setStyleSheet("border-style: outset;\
                                        border-width: 2px;\
                                        border-radius: 10px;");

        }
    }

    for(int i=0; i<5;i++) {
        if(reponse[i]->text().toFloat() != etude1*taVariable[i]) {
            return false;

        }
    }
    for(int i=0; i<5;i++) {
        if(reponse[i+5]->text().toFloat() != etude2*taVariable[i]) {
            return false;

        }
    }
    return true;
}

void Boite::message(){
    if(verif(etude1,etude2)) {
        timerA->stop();
        if(SECONDES<10) {
            QMessageBox::information(this, "Félicitation", "Vous avez résolue le problème avec succès en " + QString::number(MINUTES)+ ":0" + QString::number(SECONDES)+ " ! \n Vous avez fait "+ QString::number(erreur)+ " erreurs!");
        }else {
            QMessageBox::information(this, "Félicitation", "Vous avez résolue le problème avec succès en " + QString::number(MINUTES)+ ":" + QString::number(SECONDES)+ " ! \n Vous avez fait "+ QString::number(erreur)+ " erreurs!");
        }
    }else {
	if (progress->value() >= 100) QMessageBox::critical(this, "Attention", "Tu as fais beaucoup d'erreur, tu devrais lire la consigne et recommencer l'exercice."); 	
        QMessageBox::critical(this, "Attention", "Il reste "+ QString::number(currenterr)+ " erreurs !");
    }
}

void Boite::chrono(){
    if(SECONDES<10) {
        label->setText(QString::number(MINUTES)+" : 0"+ QString::number(SECONDES) );
    }else {
        label->setText( QString::number(MINUTES)+" : "+ QString::number(SECONDES) );
    }
    if (SECONDES == 59) {
        SECONDES = 00;
        MINUTES++;
    }else {
        SECONDES++;
    }
}

void Boite::menu() {
    close();
    parent->show();
}

bool Boite::repet(int i) {
    int jj;
    for(jj=i-1;jj>-1;jj--) {
        if(taVariable[i] == taVariable[jj]){
            return true;
        }
    }
    return false;
}

Boite::~Boite() {
    delete[] reponse;
}


