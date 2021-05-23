// Motors:
//	Rigth: motorB
//	Left: motorC

// Wall:
// 	Vertical: motorD
//	Horizontal: motorA

// Fwd - Forward; Bwd - Backward. Recta direction definitions
// Lft - Left; Rgt - Right. Turns direction definitions

// From max side to middle: 1.1
// Recta(Direction, Count, Power)
// Turn(Direction, Angle, Power)
// Align(Direction, Time)
// MoveMotor(Motor, Count, Power)
// MoveMotorAsync(Motor, Count, Power)

// ROBOPRO || VEATRIZ

#include "Core/Core.h"

void Sortida_2bR(bool align = false)
{
	//Align
	if (align == true)
	{
		MoveMotorTime(motorA, 2, -70);
		MoveMotorTime(motorD, 3, 70);
		delay(200);
		MoveMotor(motorD, 1, -70);		// abans 0.6
		MoveMotor(motorA, 1.3, 70);		//1.35 abans ... li he tret
	}
	//Fer ajust inicial
	flushButtonMessages();
	waitForButtonPress();
	flushButtonMessages();
	delay(250);
	Recta(Bwd, 0.02, 10, false, false);


	// Anem a boccia
	Recta(Fwd, 4.7, 60);
	MoveMotorAsync(motorA, 0.5, 70);
	MoveMotor(motorD, 5, -70); // abans 5.4
	Recta(Fwd, 0.85, 60, true, true);			// Robopro 0.7  (0.6 + 0.27)
	MoveMotorAsync(motorD, 3.8, 70);			//abans 3.3 (+0.7 amunt)
	//Recta(Fwd, 0.27, 50, true, true);		//Robopro 0.27
	MoveMotor(motorA, 0.5, -70);
	Turn(Rgt, 40, 10);		//tota l'estona 41

	//Per comprovar
	//Recta(Fwd, 0.5, 60); // per comprovar
	//if (getColorReflected(S3)< 40)	{

	//	Turn(Lft, 3, 10);
	//}
	//Turn(Rgt, 39, 10);
	Recta(Fwd, 2.35, 30);		//2.35

	// Moure rodes
	MoveMotor(motorA, 0.4, 70);			//0.6 per l'aliniat
	MoveMotorTime(motorA, 0.2, 70);
	MoveMotor(motorD, 3.1, -70);			//2.2
	MoveMotor(motorA, 1.5, -70);
	MoveMotorTime(motorA, 0.3, -70);
	MoveMotorAsync(motorD, 1, 70);

	// Tirem dau
	Recta(Bwd, 0.6, 40);
	MoveMotorAsync(motorA, 0.2, 70);
	MoveMotor(motorD, 0.8, 60);


	//Avan�ar cap palanca i agafar porci�
	MoveMotorAsync(motorD, 2.5, -30);
	Recta(Fwd, 3.5, 60, true, false);
	MoveMotorAsync(motorB, 0.3, -40);
	MoveMotor(motorC, 0.3, -40);
	MoveMotorAsync(motorD, 0.3, 70);
	Recta(Bwd, 0.25, 20);

	//Situar l'extremitat sota la M13
	MoveMotor(motorA, 1.4, 70);
	MoveMotorTime(motorA, 0.3, 70);

	//Aixecar M13 i col�locar-se de nou
	MoveMotor(motorD, 5.3, 70);
	MoveMotorAsync(motorA, 1.7, -70);	//1.7 abans al recollir
	MoveMotor(motorD, 2.9, -70);			//2.1 +1.5 avall per evitar enganxarm-e ... 3.6


	//Tornar

	MoveMotorAsync(motorD, 0.9, 70);
	Recta(Bwd, 2.5, 60, true, false);
	MoveMotorAsync(motorA, 0.4, 20); 	//Pala en posici� per S3
	Recta(Bwd, 3, 60, false, true);
	setMotorSpeed (motorB, -35);
	setMotorSpeed (motorC, 35);
	delay(420);
	setMotorSpeed (motorB, 0);
	setMotorSpeed (motorC, 0);			//Turn(Lft, 35, 20);
	MoveMotorAsync(motorD, 1.9, 70);
	Recta(Bwd, 6, 60);
	MoveMotor(motorD, 2, -70);		//Preparem al�ada S3



	// Anem a boccia com abans ... amb recollida a la tornada

	//Recta(Fwd, 5.7, 60);	//5.71 Si gira perfect. 5.72 ABANS
	//Turn(Rgt, 41, 10);
	//MoveMotorAsync(motorD, 2.5, -70);  // 2.2
	//Recta(Fwd, 2.2, 50);


		//MoveMotorAsync(motorD, 1.5, 70);
	//Turn(Rgt, 2, 10);		//Turn(Lft, 2, 10); para veatriz
	//Recta(Bwd, 5.03, 60);
	//Turn(Lft, 35, 20);
	//MoveMotorAsync(motorD, 2.4, -70);
	//MoveMotor(motorA, 1.1, 70);
	//MoveMotorTime(motorA, 0.2, 70);   // tope dreta

	////// agafar vida
	//Recta(Bwd, 0.6, 40);
	//MoveMotorAsync(motorD, 4, 70);  // Cal pujar per salvar el columpi
	//MoveMotor(motorA, 1.5, -70);	// Preparar pala sortida 3

	////// Entrar a base
	//Recta(Bwd, 5.5, 60);

	////// posicionem pala. Preparar pala sortida 3

	//MoveMotorAsync(motorD, 1.7, -70);
	//MoveMotor(motorA, 0.25, 70);

}
