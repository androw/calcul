//      Bilan.cpp
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

#include "Bilan.h"

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
