//      Monome.h
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

#ifndef MONOME_H
#define MONOME_H

#include <iostream>
#include <cmath>

#include "Exercice.h"

class Monome : public Exercice {
protected :
        float constante;
float coefficient;
float resultat;

public :
        Monome();
Monome(float c,float coe,float res);
float getConstante();
void setConstante(float nc);
float getCoefficient();
void setCoefficient(float nc);
float getResultat();
void setResultat(float nr);
void affichage();
float resolution();
void exercice(float nombre);
void evaluation(float nombre);
};
#endif
