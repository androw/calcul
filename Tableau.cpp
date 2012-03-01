//      Tableau.cpp
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

#include "Tableau.h"

Tableau::Tableau(QMainWindow *p)
{
    parent = p;
    setFixedSize(800, 600);

    //FOND ECRAN
    QLabel *image = new QLabel(this);
    image->setPixmap(QPixmap("25.jpg"));
    image->setGeometry(0, 0, 800, 600);
    
    
    fleche = new QLabel(this);
    aid = new QLabel("", this);
    

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

    srand(time(NULL));

    taVariable = rand()%90+1;
    while(taVariable == 1) {
        taVariable = rand()%10+1;
    }
    
    suiva[1]=9;
    suiva[2]=4;
    suiva[3]=1;
    suiva[4]=3;
    suiva[5]=7;
    suiva[6]=2;
    suiva[7]=5;
    suiva[8]=6;
    suiva[9]=8;
    suiva[0]=0;
    
    suiv=0;


    //BOUTON VALIDATION
    m_bouton = new QPushButton("Valider", this);
    m_bouton->setToolTip("vérifier bien votre résultat");
    m_bouton->setFont(QFont("encilPete FONT", 14));
    m_bouton->setCursor(Qt::PointingHandCursor);
    m_bouton->move(180+60, 450+110);

    m_next = new QPushButton("Suivant", this);
    m_next->setToolTip("vérifier bien votre résultat");
    m_next->setFont(QFont("encilPete FONT", 14));
    m_next->setCursor(Qt::PointingHandCursor);
    m_next->move(340, 450+50);
    
    
    m_help = new QPushButton("?", this);
    m_help->setToolTip("Aide  ");
    m_help->setFont(QFont("encilPete FONT", 14));
    m_help->setCursor(Qt::PointingHandCursor);
    m_help->setGeometry(640, 450+50, 40, 40);
    m_help->setStyleSheet("border-width: 2px;\
                          border-style: outset;\
                          border-width: 2px;\
                          border-radius: 20px;\
                          min-width: 0em;\
                          border-color: black;\
                          background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\
                          stop: 0 #FF0000, stop: 1 #F5F5F5);");

    m_menu = new QPushButton("Menu", this);
    m_menu->setToolTip("Retour au Menu");
    m_menu->setFont(QFont("encilPete FONT", 14));
    m_menu->setCursor(Qt::PointingHandCursor);
    m_menu->move(380+60, 450+110);

    QObject::connect(m_bouton, SIGNAL(clicked()), this, SLOT(message()));
    QObject::connect(m_menu, SIGNAL(clicked()), this, SLOT(menu()));
    QObject::connect(m_next, SIGNAL(clicked()), this, SLOT(suivant()));
    QObject::connect(m_help, SIGNAL(clicked()), this, SLOT(aide()));
    


    
    //CONSIGNE
    QLabel *label1 = new QLabel(" Faire la table de "+ QString::number(taVariable), this);
    label1->setFont(QFont("PenclPete FONT", 18));
    label1->setStyleSheet("color:White;");
    label1->setGeometry(40, 23, 300, 50);
    label1->setStyleSheet("border-width: 2px;\
                          border-style: outset;\
                          border-width: 2px;\
                          border-radius: 10px;\
                          border-color: black;\
                          background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\
                          stop: 0 #FFFFFF, stop: 1 #BA55D3);");

    


    QLabel * calcul[10];
    
    
    

    for(int i=0;i<10;i++){
        calcul[i] = new  QLabel(" x "+ QString::number(i+1),this);
        calcul[i]->setGeometry(70+73*i,245,90,40);
        calcul[i]->setFont(QFont("PncilPete FONT", 14));
    }
    
    for(int i=0;i<10;i++){
        reponse[i] = new QLineEdit("",this);
        reponse[i]->setGeometry(0,0,0,0);
    }
    
    reponse[suiva[suiv]]->setGeometry(50+80*suiva[suiv],320,50,20);
    



}

void Tableau::aide() {

    if (suiv == 2) {
        aid->setText(": 2");
        aid->setGeometry(750,180,90,40);
        aid->setFont(QFont("PncilPete FONT", 14));
        fleche->setPixmap(QPixmap("fleche1.png"));
        fleche->setGeometry(310, 0, 694, 400);
        
    }else if (suiv == 3) {
        aid->setText("+ " + QString::number(taVariable));
        aid->setGeometry(110, 380,90,40);
        aid->setFont(QFont("PncilPete FONT", 14));
        fleche->setPixmap(QPixmap("fleche2.png"));
        fleche->setGeometry(70, 380, 142, 142);
        
    }else if (suiv == 4) {
        aid->setText("x 2");
        aid->setGeometry(155, 380,90,40);
        aid->setFont(QFont("PncilPete FONT", 14));
        fleche->setPixmap(QPixmap("fleche3.png"));
        fleche->setGeometry(175, 225, 694, 400);
        
    }else if (suiv == 5) {
        aid->setText("x 2");
        aid->setGeometry(322, 375,90,40);
        aid->setFont(QFont("PncilPete FONT", 14));
        fleche->setPixmap(QPixmap("fleche4.png"));
        fleche->setGeometry(322, 235, 694, 400);
        
    }else if (suiv == 6) {
        aid->setText("+ " + QString::number(taVariable));
        aid->setGeometry(140, 380,90,40);
        aid->setFont(QFont("PncilPete FONT", 14));
        fleche->setPixmap(QPixmap("fleche2.png"));
        fleche->setGeometry(140, 380, 142, 142);
        
    }else if (suiv == 7) {
        aid->setText("x 2");
        aid->setGeometry(240,380,90,40);
        aid->setFont(QFont("PncilPete FONT", 14));
        fleche->setPixmap(QPixmap("fleche6.png"));
        fleche->setGeometry(240,240, 694, 400);
        
    }else if (suiv == 8) {
        aid->setText("+ " + QString::number(taVariable));
        aid->setGeometry(440, 380,90,40);
        aid->setFont(QFont("PncilPete FONT", 14));
        fleche->setPixmap(QPixmap("fleche2.png"));
        fleche->setGeometry(440, 380, 142, 142);
        
    }else if (suiv == 9) {
        aid->setText("+ " + QString::number(taVariable));
        aid->setGeometry(580, 380,90,40);
        aid->setFont(QFont("PncilPete FONT", 14));
        fleche->setPixmap(QPixmap("fleche2.png"));
        fleche->setGeometry(580, 380, 142, 142);
        
    }
}

bool Tableau::verif() {
    if (suiv == 9){
    currenterr = 0;
    for(int i=0; i<10;i++) {
        if(reponse[i]->text().toFloat() != (i+1)*taVariable) {
            reponse[i]->setStyleSheet("border-style: outset;\
                                      background-color: #FF6347;\
                                      border-width: 2px;\
                                      border-radius: 10px;");
            currenterr++;
            erreur++;
        }
        if(reponse[i]->text().toFloat() == (i+1)*taVariable) {
            reponse[i]->setStyleSheet("border-style: outset;\
                                      border-width: 2px;\
                                      border-radius: 10px;");
        }
    }
        for(int i=0; i<10;i++) {
        if(reponse[i]->text().toFloat() != (i+1)*taVariable) {
            return false;
        }
    }
    return true;
    }
    return false;
}

void Tableau::message(){
    if(verif()) {
        timerA->stop();
        if(SECONDES<10) {
                        QMessageBox::information(this, "Felicitation", "Vous avez résolue le problème avec succès en " + QString::number(MINUTES)+ ":0" + QString::number(SECONDES)+ " ! \n Vous avez fait "+ QString::number(erreur)+ " erreurs!");
        }else {
            QMessageBox::information(this, "Felicitation", "Vous avez résolue le problème avec succès en " + QString::number(MINUTES)+ ":" + QString::number(SECONDES)+ " ! \n Vous avez fait "+ QString::number(erreur)+ " erreurs!");
        }
    }else {
        QMessageBox::critical(this, "Attention", "Il reste "+ QString::number(currenterr)+ " erreurs!");
    }
}

void Tableau::evaluation(float nombre) {
        if (erreur < 10) {
                comment->setText("WOUAOUHH !!! ");
    } else if (erreur < 15) {
        comment->setText( "Pas mal ! ");
    } else if (erreur < 25) {
        comment->setText("Mouais ..");
    } else {
        comment->setText( "LOOSER");
    }
    if (MINUTES < 2) {
        comment->setText( "Rapide comme l'éclair !");
    } else if (MINUTES < 3) {
        comment->setText("Pas trop lent");
    } else {
        comment->setText( "Escargal !!");
    }
}

void Tableau::chrono(){
    if (SECONDES < 10) {
        label->setText(QString::number(MINUTES)+" : 0"+ QString::number(SECONDES) );
    } else {
        label->setText( QString::number(MINUTES)+" : "+ QString::number(SECONDES) );
    }
        if (SECONDES == 59) {
                SECONDES=00;
                MINUTES++;
        }else {
                SECONDES++;
        }
}

void Tableau::menu() {
    close();
    parent->show();
}

void Tableau::suivant() {
    if (reponse[suiva[suiv]]->text().toFloat() != (suiva[suiv]+1)*taVariable) {
        reponse[suiva[suiv]]->setStyleSheet("border-style: outset;\
                                  background-color: #FF6347;\
                                  border-width: 2px;\
                                  border-radius: 10px;");
        
        erreur++;
        
    }else if (reponse[suiva[suiv]]->text().toFloat() == (suiva[suiv]+1)*taVariable &&  suiv < 9) {
        reponse[suiva[suiv]]->setStyleSheet("border-style: outset;\
                                  border-width: 2px;\
                                  border-radius: 10px;");
        suiv++;
        
        QPropertyAnimation *animation3 = new QPropertyAnimation (reponse[suiva[suiv]], "geometry");
        animation3->setDuration(500);
        animation3->setStartValue(QRect(50+75*suiva[suiv-1],320,50,20));
        animation3->setEndValue(QRect(50+75*suiva[suiv],320,50,20));
        animation3->setEasingCurve(QEasingCurve::OutExpo);
        animation3->start();
        
        //reponse[suiva[suiv]]->setGeometry(50+75*suiva[suiv],320,50,20);
        
    }
    
}

Tableau::~Tableau() {
    delete[] reponse;
}

