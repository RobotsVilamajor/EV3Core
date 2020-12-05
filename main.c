#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Fwd - Forward; Bwd - Backward. Recta direction definitions
// Lft - Left; Rgt - Right. Turns direction definitions

// Recta(Direction, Count, Power)
// Turn(Direction, Angle, Power)
// Align(Direction, Time)
// MoveMotor(Motor, Count, Power)
// MoveMotorAsync(Motor, Count, Power)


#include "Core/Core.h"

task main()
{
	setMotorBrakeMode(motorB, motorBrake);
	setMotorBrakeMode(motorC, motorBrake);
	setMotorSpeed(motorC,0);
	setMotorSpeed(motorB,0);

	waitForButtonPress();

	Recta(Fwd, 1, 50);
	Turn(Rgt, 90, 50);

	delay(5000);

	Recta(Fwd, 1, 50);
	Turn(Rgt, 90, 50);
	//Recta(Fwd, 1, 50);
}
