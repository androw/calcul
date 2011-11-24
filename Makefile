calcul: main.cpp Bilan.o Exercice.o ExerciceTable.o ExerciceDeduction.o ExerciceSerie.o DroiteG.o
	g++ -Wall main.cpp Bilan.o Exercice.o ExerciceTable.o ExerciceDeduction.o ExerciceSerie.o DroiteG.o -o calcul

Bilan.o: Bilan.h Bilan.cpp
	g++ -c Bilan.cpp

Exercice.o: Exercice.h Exercice.cpp Bilan.o
	g++ -c Exercice.cpp

ExerciceTable.o: ExerciceTable.h ExerciceTable.cpp Exercice.o
	g++ -c ExerciceTable.cpp

ExerciceDeduction.o: ExerciceDeduction.h ExerciceDeduction.cpp Exercice.o
	g++ -c ExerciceDeduction.cpp

ExerciceSerie.o: ExerciceSerie.h ExerciceSerie.cpp Exercice.o
	g++ -c ExerciceSerie.cpp

DroiteG.o: DroiteG.h DroiteG.cpp Exercice.o
	g++ -c DroiteG.cpp
