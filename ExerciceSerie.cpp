#include "ExerciceSerie.h"

ExerciceSerie::ExerciceSerie() {}

void ExerciceSerie::exercice(float nombre) {
	struct timeval tv1,tv2; //declaration des heures a venir
	struct timezone tz;  //fuseau horaire (?)
	int i;
	float reponse;
	cout << "Appuyez sur entree pour commencer l'exercice.\n";
	getchar();
	getchar();
	gettimeofday(&tv1, &tz); //heure de depart
	for (i=0;i<31;i++) {
		cout << nombre <<" * "<< i <<" = ";
		cin >> reponse;
		while (reponse != i * nombre) {
			cout << "Faux ! \n";
			bilan.setErreur(bilan.getErreur() + 1);
			cout << nombre <<" * "<< i <<" = ";
			cin >> reponse;
		}
	}
	gettimeofday(&tv2, &tz); //heure de fin	
	bilan.setNote(30 - bilan.getErreur());

	if (bilan.getNote() < 0) {
		bilan.setNote(0);
	}
	bilan.setTime(tv2.tv_sec - tv1.tv_sec); //soustraction
}

void ExerciceSerie::evaluation(float nombre) {
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
