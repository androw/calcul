//      Bilan.h
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

#ifndef BILAN_H
#define BILAN_H

#include <ctime>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sys/time.h>

class Bilan{
protected :
        double temps;
int erreur;
float note;

public :
        Bilan();
void setErreur(int er);
int getErreur();
void setTime(double t);
double getTime();
float getNote();
void setNote(float n);
/*void exercice(int nombre);
        void evaluation(int nombre);*/
};
#endif // BILAN_H
