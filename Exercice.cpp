//      Exercice.cpp
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

#include "Exercice.h"

Exercice::Exercice() {}

//float abs(float a) {
//    if (a >=0) {
//        return a;
//    }
//    else {
//        return -a;
//    }
//}

void Exercice::verifDec(double a, double b){
    double ent = floor(b);
    double dec = b - ent;
    dec = dec*10;
    while ((dec-floor(dec) > 0.001) || (dec-floor(dec) < -0.001)){
       if (((ent+dec) - a < 0.001) && ((ent+dec) - a > -0.001)){
            QMessageBox::critical(this, "Attention", "Il semblerait que tu différencies la partie entière de la partie décimale");
        }
        dec = dec*10;
    }
}
