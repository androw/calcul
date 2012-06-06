//      Table.cpp
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

#include "Table.h"

Table::Table(QMainWindow *p,bool reel)
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
    taVariable = rand()%10+1;
    if (reel) {
        float decim = rand()%9+1;
        float decim2 = rand()%9+1;
        taVariable += decim/10 + decim2/100;
    }
    while(taVariable == 1) {
        taVariable = rand()%10+1;
    }
    taVariable2= rand()%10+1;
    if (reel) {
        float decim = rand()%9+1;
        float decim2 = rand()%9+1;
        taVariable2 += decim/10 + decim2/100;
    }
    while(taVariable2 == 1) {
        taVariable2 = rand()%10+1;
    }
    while(taVariable2 == taVariable)
    {
        taVariable2= rand()%10+1;
        if (reel) {
            float decim = rand()%9+1;
            float decim2 = rand()%9+1;
            taVariable2 += decim/10 + decim2/100;
        }
        while(taVariable2 == 1) {
            taVariable2 = rand()%10+1;
        }
    }
    taVariable3= rand()%10+1;
    if (reel) {
        float decim = rand()%9+1;
        float decim2 = rand()%9+1;
        taVariable3 += decim/10 + decim2/100;
    }
    while(taVariable3 == 1) {
        taVariable3 = rand()%10+1;
    }
    while((taVariable3 == taVariable) || (taVariable3 == taVariable2 ))
    {
        taVariable3= rand()%10+1;
        if (reel) {
            float decim = rand()%9+1;
            float decim2 = rand()%9+1;
            taVariable3 += decim/10 + decim2/100;
        }
        while(taVariable3 == 1) {
            taVariable3 = rand()%10+1;
        }
    }
    
    //BOUTON VALIDATION
    m_bouton = new QPushButton("Valider", this);
    m_bouton->setToolTip("VÃ©rifier bien votre rÃ©sultat");
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

    for(int i=0;i<10;i++){
        reponse[i] = new QLineEdit("",this);
        reponse[i]->setGeometry(120+100, 10*i+20+40+30*i+80,50,20);
    }
    for(int i=0;i<10;i++){
        reponse[i+10] = new QLineEdit("",this);
        reponse[i+10]->setGeometry(320+100, 10*i+20+40+30*i+80,50,20);
    }
    for(int i=0;i<10;i++){
        reponse[i+20] = new QLineEdit("",this);
        reponse[i+20]->setGeometry(540+100, 10*i+20+40+30*i+80,50,20);
    }

    QLabel * calcul[30];

    for(int i=0;i<10;i++){
        calcul[i] = new  QLabel(QString::number(i+1) +" x "+ QString::number(taVariable) +" =",this);
        calcul[i]->setGeometry(30+100, 10*i+15+40+30*i+80,90,40);
        calcul[i]->setFont(QFont("PncilPete FONT", 14));
    }
    for(int i=0;i<10;i++){
        calcul[i+10] = new  QLabel(QString::number(i+1) +" x "+ QString::number(taVariable2) +" =",this);
        calcul[i+10]->setGeometry(230+100, 10*i+15+40+30*i+80,90,40);
        calcul[i+10]->setFont(QFont("PncilPete FONT", 14));
    }
    for(int i=0;i<10;i++){
        calcul[i+20] = new  QLabel(QString::number(i+1) +" x "+ QString::number(taVariable3) +" =",this);
        calcul[i+20]->setGeometry(440+100, 10*i+15+40+30*i+80,90,40);
        calcul[i+20]->setFont(QFont("PecilPete FONT", 14));
    }

    //CONSIGNE
    QLabel *label1 = new QLabel("Remplissez les Cases avec le bon résultat", this);
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
void Table::consigne() {
    QFrame* popup1 = new QFrame(this, Qt::Popup | Qt::Window );
    popup1->resize(500,50);
    QLabel *text1 = new QLabel("Aide", popup1);
    QLabel *text2 = new QLabel("Exercice de révision. Complétez les tables de multiplications demandées.", popup1);
    text1->move(10, 10);
    text2->move(10,30);
    popup1->show();
}

bool Table::verif() {
    currenterr = 0;
    for(int i=0; i<10;i++) {
        if(reponse[i]->text().toFloat() - (i+1)*taVariable >= 0.0001 || reponse[i]->text().toFloat() - (i+1)*taVariable <= -0.0001) {
            reponse[i]->setStyleSheet("border-style: outset;\
                                      background-color: #FF6347;\
                                      border-width: 2px;\
                                      border-radius: 10px;");
            currenterr++;
            erreur++;
            progress->setValue(erreur*20);
        }
        if(reponse[i]->text().toFloat() - (i+1)*taVariable < 0.0001 && reponse[i]->text().toFloat() - (i+1)*taVariable > -0.0001) {
            reponse[i]->setStyleSheet("border-style: outset;\
                                      border-width: 2px;\
                                      border-radius: 10px;");
        }
    }
    for(int i=0; i<10;i++) {
        if(reponse[i+10]->text().toFloat() - (i+1)*taVariable2 >= 0.0001 || reponse[i+10]->text().toFloat() - (i+1)*taVariable2 <= -0.0001) {
            reponse[i+10]->setStyleSheet("border-style: outset;\
                                         background-color: #FF6347;\
                                         border-width: 2px;\
                                         border-radius: 10px;");
            currenterr++;
            erreur++;
            progress->setValue(erreur*20);
        }
        if(reponse[i+10]->text().toFloat() - (i+1)*taVariable2 < 0.0001 && reponse[i+10]->text().toFloat() - (i+1)*taVariable2 > -0.0001) {
            reponse[i+10]->setStyleSheet("border-style: outset;\
                                         border-width: 2px;\
                                         border-radius: 10px;");
        }
    }
    for(int i=0; i<10;i++) {
        if(reponse[i+20]->text().toFloat() - (i+1)*taVariable3 >= 0.0001 || reponse[i+20]->text().toFloat() - (i+1)*taVariable3 <= -0.0001) {
            reponse[i+20]->setStyleSheet("border-style: outset;\
                                         background-color: #FF6347;\
                                         border-width: 2px;\
                                         border-radius: 10px;");
            currenterr++;
            erreur++;
            progress->setValue(erreur*20);
        }
        if(reponse[i+20]->text().toFloat() - (i+1)*taVariable3 < 0.0001 && reponse[i+20]->text().toFloat() - (i+1)*taVariable3 > -0.0001) {
            reponse[i+20]->setStyleSheet("border-style: outset;\
                                         border-width: 2px;\
                                         border-radius: 10px;");
        }
    }
    for(int i=0; i<10;i++) {
        if(reponse[i]->text().toFloat() - (i+1)*taVariable >= 0.0001 || reponse[i]->text().toFloat() - (i+1)*taVariable <= -0.0001) {
            return false;
        }
    }
    for(int i=0; i<10;i++) {
        if(reponse[i+10]->text().toFloat() - (i+1)*taVariable2 >= 0.0001 || reponse[i+10]->text().toFloat() - (i+1)*taVariable2 <= -0.0001) {
            return false;
        }
    }
    for(int i=0; i<10;i++) {
        if(reponse[i+20]->text().toFloat() - (i+1)*taVariable3 >= 0.0001 || reponse[i+20]->text().toFloat() - (i+1)*taVariable3 <= -0.0001) {
            return false;
        }
    }
    return true;
}

void Table::message(){
    if(verif()) {
        timerA->stop();
        if(SECONDES<10) {
            QMessageBox::information(this, "Félicitation", "Vous avez résolue le problème avec succès en " + QString::number(MINUTES)+ ":0" + QString::number(SECONDES)+ " ! \n Vous avez fait "+ QString::number(erreur)+ " erreurs!");
        }else {
            QMessageBox::information(this, "Félicitation", "Vous avez résolue le problème avec succès en " + QString::number(MINUTES)+ ":" + QString::number(SECONDES)+ " ! \n Vous avez fait "+ QString::number(erreur)+ " erreurs!");
        }
    }else {
	if (progress->value() >= 100) QMessageBox::critical(this, "Attention", "Tu as fais beaucoup d'erreur, tu devrais lire la consigne et recommencer l'exercice.");
        QMessageBox::critical(this, "Attention", "Il reste "+ QString::number(currenterr)+ " erreurs!");
    }
}

void Table::evaluation(float nombre) {
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
        comment->setText( "Rapide comme l'clair !");
    } else if (MINUTES < 3) {
        comment->setText("Pas trop lent");
    } else {
        comment->setText( "Escargal !!");
    }
}

void Table::chrono(){
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

void Table::menu() {
    close();
    parent->show();
}

Table::~Table() {
    delete[] reponse;
}
