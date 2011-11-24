#include "DroiteG.h"
#include<iostream>
using namespace std;

DroiteG::DroiteG() {
	int i;
	for(i=0;i<11;i++) {
		tab[i] = 0;
	}
}

void DroiteG::exercice(float nombre) {
	struct timeval tv1,tv2; //declaration des heures a venir
	struct timezone tz;  //fuseau horaire (?)
	int i,valeur;
	int zone;
	srand(time(NULL));
	int indice = rand()%10 + 1;
	float avancement[11];
	for(i=0;i<11;i++) {
		avancement[i] = 0;
	}
	for(i=0;i<11;i++) {
		tab[i] = nombre * i;
	}
	avancement[indice] = indice * nombre;
	cout << "Appuyez sur entree pour commencer l'exercice.\n";
	getchar();
	getchar();
	affichageExo(nombre,avancement);
	gettimeofday(&tv1, &tz); //heure de depart
	while (!complete(avancement)) {
		cout << "\nZone ?";
		cin >> zone;
		cout << "\n Valeur ?";
		cin >> valeur;
		while (tab[zone] != valeur) {
			cout << "FAUX !";
			affichageExo(nombre,avancement);
			bilan.setErreur(bilan.getErreur()+1);
			cout << "\nZone ?";
			cin >> zone;
			cout << "\n Valeur ?";
			cin >> valeur;
		}
		avancement[zone] = valeur;
		affichageExo(nombre,avancement);
	}
	gettimeofday(&tv2, &tz); //heure de fin	
	bilan.setNote(10 - bilan.getErreur());

	if (bilan.getNote() < 0) {
		bilan.setNote(0);
	}
	bilan.setTime(tv2.tv_sec - tv1.tv_sec); //soustraction
}

void DroiteG::affichageExo(float nombre,float* avancement) {
	int i;
	cout << endl;
	for(i=0;i<11;i++) {
		cout << "|---";
	}
	cout << ">\n0   ";
	for(i=1;i<11;i++) {
		if (avancement[i] != 0) {
			if (avancement[i] < 10) {
				cout << avancement[i] << "   ";
			}
			else if (avancement[i] < 100) {
				cout << avancement[i] << "  ";
			}
			else {
				cout << avancement[i] << " ";
			}
		}
		else {
			cout << ".   ";
		}
	}
}

void DroiteG::affichage(float nombre) {
	int i;
	cout << endl;
	for(i=0;i<11;i++) {
		cout << "|---";
	}
	cout << ">\n";
	for(i=0;i<11;i++) {
		if (nombre * i < 10) {
			cout << nombre*i << "   ";
		}
		else if(nombre * i <100) {
			cout << nombre*i << "  ";
		}
		else {
			cout << nombre*i << " ";
		}
	}
	cout << endl;
}

void DroiteG::evaluation(float nombre) {
	exercice(nombre);
	if (bilan.getNote() < 10) {
		cout << " Looser ! ";
	}
	else if (bilan.getNote() < 15) {
		cout << "Mouais. ";
	}
	else if (bilan.getNote() < 25) {
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

bool complete(float avancement[]) {
	int i;
	for(i=1;i<11;i++) {
		if(avancement[i] == 0) {
			return false;
		}
	}
	return true;
}
	
