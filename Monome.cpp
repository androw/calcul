//      Monome.cpp
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

#include "Monome.h"

using namespace std;

Monome::Monome() {
    constante =5;
    coefficient = 15;
    resultat = 956;
}

Monome::Monome(float c,float coe,float res) {
        constante =c;
        coefficient = coe;
        resultat = res;
}

float Monome::getConstante() {
        return constante ;
}

void Monome::setConstante(float nc) {
        constante = nc;
}

float Monome::getCoefficient() {
        return coefficient;
}

void Monome::setCoefficient(float nc) {
        coefficient = nc;
}

float Monome::getResultat() {
        return resultat;
}

void Monome::setResultat(float nr) {
        resultat = nr;
}

float Monome::resolution() {
        return (resultat - constante)/coefficient;
}

void Monome::exercice(float nombre) {
        struct timeval tv1,tv2; //declaration des heures a venir
        struct timezone tz;  //fuseau horaire (?)
        srand(time(NULL));
        float a;
        int acc = 1;
        float numerateur,denominateur;
        cout << "Appuyez sur entree pour commencer l'exercice.\n";
        getchar();
        getchar();
        gettimeofday(&tv1, &tz); //heure de depart
        while (acc < 10) {
                a = rand() % 6;
                nombre += a;
                coefficient = nombre;
                constante = rand() % 10+1;
                resultat = rand() % 10+1;
                cout << coefficient<< "x + " << constante << " = " << resultat << endl << "x = \nNumerateur :";
                cin >> numerateur;
                cout << "\nDenominateur :";
                cin >> denominateur;
                while ((numerateur/denominateur) - resolution() > 0.0001) {
                        cout << "FAUX ! \n";
                        cout << coefficient<< "x + " << constante << " = " << resultat << endl << "x = \nNumerateur :";
                        cin >> numerateur;
                        cout << "\nDenominateur :";
                        cin >> denominateur;
                }
        acc ++;
        }
        gettimeofday(&tv2, &tz); //heure de fin
        bilan.setNote(10 - bilan.getErreur());

        if (bilan.getNote() < 0) {
                bilan.setNote(0);
        }
        bilan.setTime(tv2.tv_sec - tv1.tv_sec); //soustraction
}

void Monome::evaluation(float nombre) {
        exercice(nombre);
        if (bilan.getNote() < 3) {
                cout << " Looser ! ";
        }
        else if (bilan.getNote() < 5) {
                cout << "Mouais. ";
        }
        else if (bilan.getNote() < 75) {
                cout << "Pas mal ! ";
        }
        else {
                cout << "WOUAOUHH !!! ";
        }
        if (bilan.getTime() < 30) {
                cout << "Rapide comme l'éclair !\n";
        }
        else if (bilan.getTime() < 45) {
                cout << "Pas trop lent\n";
        }
        else {
                cout << "Escargal !!\n";
        }
}


