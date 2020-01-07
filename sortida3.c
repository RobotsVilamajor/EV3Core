#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)
// Sortida 3; Missió a fer: M6, M7 + possar una peça, M8, M12, M9, M10; Comentari: possiblement no es podran fer totes
// Comentar quins motors falten

#include "Core/Core.h"

task main(){
	Recta(1, 2, 20); // vaig capRecta
	//moure els motors per aixecar la prova (quan els sapiguem)
	Recta(-1, 0.2, 10);	// tiro enrere per sortir i anar diractament a M7
	//moure els motors cap a l'altre costat
	Recta (1, 1.5, 20);
	//moure els motors per baixar la barra
	// Baixar la pala perque la construcció es quedi dins del cercle
	Recta (-1, 0.1, 10); //matgeixa raó d'abans
	//Pujar la pala
	Turn(1, 90, 30); //vull girar a la dreta(no acaada la direcció)
}
