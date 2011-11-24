#include "deduction.h"

Deduction::Deduction(QMainWindow *p)
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






    srand(time(NULL));
    taVariable = rand()%10+1;
    while(taVariable == 1) {
        taVariable = rand()%10+1;
    }
    taVariable2= taVariable/2;
    if(taVariable == 2) {
        taVariable2 = 0.5;
    }
    taVariable3= taVariable*4;

    //BOUTON VALIDATION

    m_bouton = new QPushButton("Valider", this);
    m_bouton->setToolTip("vérifier bien votre résultat");
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
     label1->setGeometry(40, 23, 450, 50);
     label1->setStyleSheet("border-width: 2px;\
                           border-radius: 10px;\
                            background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\
                               stop: 0 #9932CC, stop: 1 #BA55D3);");


}

bool Deduction::verif() {
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
        if(reponse[i+10]->text().toFloat() != (i+1)*taVariable2) {
            reponse[i+10]->setStyleSheet("border-style: outset;\
                                      background-color: #FF6347;\
                                      border-width: 2px;\
                                      border-radius: 10px;");
            currenterr++;
            erreur++;

        }
        if(reponse[i+10]->text().toFloat() == (i+1)*taVariable2) {
            reponse[i+10]->setStyleSheet("border-style: outset;\
                                      border-width: 2px;\
                                      border-radius: 10px;");

        }
    }
    for(int i=0; i<10;i++) {
        if(reponse[i+20]->text().toFloat() != (i+1)*taVariable3) {
            reponse[i+20]->setStyleSheet("border-style: outset;\
                                      background-color: #FF6347;\
                                      border-width: 2px;\
                                      border-radius: 10px;");
            currenterr++;
            erreur++;

        }
        if(reponse[i+20]->text().toFloat() == (i+1)*taVariable3) {
            reponse[i+20]->setStyleSheet("border-style: outset;\
                                      border-width: 2px;\
                                      border-radius: 10px;");

        }
    }
    for(int i=0; i<10;i++) {
        if(reponse[i]->text().toFloat() != (i+1)*taVariable) {
            return false;

        }
    }
    for(int i=0; i<10;i++) {
        if(reponse[i+10]->text().toFloat() != (i+1)*taVariable2) {
            return false;

        }
    }
    for(int i=0; i<10;i++) {
        if(reponse[i+20]->text().toFloat() != (i+1)*taVariable3) {
            return false;

        }
    }
    return true;
}

void Deduction::message(){
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


void Deduction::evaluation(float nombre) {

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

void Deduction::chrono(){

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

void Deduction::menu() {
    close();
    parent->show();


}

Deduction::~Deduction() {

    delete[] reponse;
}


