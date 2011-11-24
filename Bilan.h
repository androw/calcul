
#ifndef BILAN_H
#define BILAN_H
#include<ctime>


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
