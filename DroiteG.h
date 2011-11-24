#ifndef DROITEG_H
#define DROITEG_H
#include"Exercice.h"

class DroiteG : public Exercice {
	
	protected :
	
	float tab[11];
	
	public :

	DroiteG();
	void affichageExo(float nombre,float avancement[]);
	void affichage(float nombre);
	void exercice(float nombre);
	void evaluation(float nombre);
};

bool complete(float avancement[]);
#endif
