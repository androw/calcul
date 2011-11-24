#include "Bilan.h"
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<sys/time.h>

using namespace std;
clock_t clock(void);

Bilan::Bilan() {
        erreur = 0;
        temps = 0;
        note = 0;
}



void Bilan::setErreur(int er) {
        erreur = er;
}

int Bilan::getErreur() {
        return erreur;
}

void Bilan::setTime(double t) {
        temps = t;
}

double Bilan::getTime() {
        return temps;
}

void Bilan::setNote(float n) {
        note = n;
}

float Bilan::getNote() {
        return note;
}
/*
void Bilan::exercice(int nombre) {
        struct timeval tv1,tv2; //declaration des heures a venir
        struct timezone tz;  //fuseau horaire (?)
        int i;
        float reponse;
        gettimeofday(&tv1, &tz); //heure de depart
        for (i=0;i<11;i++) {
                cout << nombre <<" * "<< i <<" = ";
                cin >> reponse;
                while (reponse != i * nombre) {
                        cout << "Faux ! \n";
                        erreur ++;
                        cout << nombre <<" * "<< i <<" = ";
                        cin >> reponse;
                }
        gettimeofday(&tv2, &tz); //heure de fin
        cout << endl;
        }
        cout << "En déduire la table suivante :\n";
        for (i=0;i<11;i++) {
                cout << nombre * 2 <<" * "<< i <<" = ";
                cin >> reponse;
                while (reponse != 2 * i * nombre) {
                        cout << "Faux ! \n";
                        erreur ++;
                        cout << nombre * 2 <<" * "<< i <<" = ";
                        cin >> reponse;
                }
        }
        srand(time(NULL));
        int alea = rand() % 2;
        if (alea == 0) {
                cout << "En déduire la table suivante :\n";
                for (i=0;i<11;i++) {
                        cout << nombre * 4 <<" * "<< i <<" = ";
                        cin >> reponse;
                        while (reponse != 4 * i * nombre) {
                                cout << "Faux ! \n";
                                erreur ++;
                                cout << nombre * 2 <<" * "<< i <<" = ";
                                cin >> reponse;
                        }
                }
        }
        else {
                for (i=0;i<11;i++) {
                        cout << nombre * 0.5 <<" * "<< i <<" = ";
                        cin >> reponse;
                        while (reponse != 0.5 * i * nombre) {
                                cout << "Faux ! \n";
                                erreur ++;
                                cout << nombre * 0.5 <<" * "<< i <<" = ";
                                cin >> reponse;
                        }
                }
        }
        note = 30 - erreur;

        if (note < 0) {
                note = 0;
        }
        temps = (tv2.tv_sec - tv1.tv_sec); //soustraction
}


void Bilan::evaluation(int nombre) {
        exercice(nombre);
        if (note < 10) {
                cout << " Looser ! ";
        }
        else if (note < 15) {
                cout << "Mouais. ";
        }
        else if (note < 25) {
                cout << "Pas mal ! ";
        }
        else {
                cout << "WOUAOUHH !!! ";
        }
        if (temps < 30) {
                cout << "Rapide comme l'éclair !\n";
        }
        else if (temps < 45) {
                cout << "Pas trop lent\n";
        }
        else {
                cout << "Escargal !!\n";
        }
}

*/


