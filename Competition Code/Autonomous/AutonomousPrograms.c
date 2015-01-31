//****************************//
//			MIDDLE   	      //
//****************************//

////////////////////////////////////////
////////////////////
//		BLUE      //
////////////////////
////////////////////////////////////////
void blueMiddle () {

	//FlipOut
	motor[leftIntake] = motor[rightIntake] = -127;
	wait1Msec(300);
	motor[leftIntake] = motor[rightIntake] = 0;

	//Keep buckyball from going out
	motor[leftIntake] = motor[rightIntake] = 127;
	wait1Msec(300);
	motor[leftIntake] = motor[rightIntake] = 0;

	//Spin to big ball
	spin(-40, 120);
	wait1Msec(300);
	resetEncoders();

	//Drive into big ball
	encoderDriveWithLift(100, 950, 1029);
	wait1Msec(500);
	resetEncoders();

	//Return to tile
	encoderDrive(-127, 950);
	wait1Msec(500);
	resetEncoders();

	////Lower lift
	lowerLift(200);

	//Go forward when button is pushed
	while(true)
	{
		if(SensorValue[button])
		{
			resetEncoders();
			encoderDrive(127, 1400);
			wait1Msec(500);
			resetEncoders();
			break;
		}
	}

	//Lift lift
	liftLift(1400);
	motor[leftLift]=motor[rightLift]=15;

	//Spin to tube
	spin(-40, 105);
	wait1Msec(500);
	resetEncoders();

	//Drive forward
	encoderDrive(127, 600);
	wait1Msec(500);
	resetEncoders();

	//Outtake
	motor[leftIntake] = motor[rightIntake] = -127;
	writeDebugStreamLine("Outtaking");

	//Drive back for large ball
	encoderDrive(-100, 140);
	wait1Msec(500);
	resetEncoders();

	//Outtake big ball
	motor[leftIntake] = motor[rightIntake] = -70;
	wait1Msec(1600);
	motor[leftIntake] = motor[rightIntake] = 0;

	//Drive back a bit
	encoderDrive(-100, 600);
	wait1Msec(500);
	resetEncoders();
}

////////////////////////////////////////
////////////////////
//		RED      //
////////////////////
////////////////////////////////////////
void redMiddle () {

	//FlipOut
	motor[leftIntake] = motor[rightIntake] = -127;
	wait1Msec(300);
	motor[leftIntake] = motor[rightIntake] = 0;

	//Keep buckyball from going out
	motor[leftIntake] = motor[rightIntake] = 127;
	wait1Msec(300);
	motor[leftIntake] = motor[rightIntake] = 0;

	//Spin to big ball
	spin(40, 120);
	wait1Msec(300);
	resetEncoders();

	//Drive into big ball
	encoderDriveWithLift(100, 950, 1029);
	wait1Msec(500);
	resetEncoders();

	//Return to tile
	encoderDrive(-127, 950);
	wait1Msec(500);
	resetEncoders();

	////Lower lift
	lowerLift(200);

	//Go forward when button is pushed
	while(true)
	{
		if(SensorValue[button])
		{
			resetEncoders();
			encoderDrive(127, 1400);
			wait1Msec(500);
			resetEncoders();
			break;
		}
	}

	//Lift lift
	liftLift(1400);
	motor[leftLift]=motor[rightLift]=15;

	//Spin to tube
	spin(40, 95);
	wait1Msec(500);
	resetEncoders();

	//Drive forward
	encoderDrive(127, 660);
	wait1Msec(500);
	resetEncoders();

	//Outtake
	motor[leftIntake] = motor[rightIntake] = -127;
	writeDebugStreamLine("Outtaking");

	//Drive back for large ball
	encoderDrive(-100, 140);
	wait1Msec(500);
	resetEncoders();

	//Outtake big ball
	motor[leftIntake] = motor[rightIntake] = -127;
	wait1Msec(1200);
	motor[leftIntake] = motor[rightIntake] = 0;

	//Drive back a bit
	encoderDrive(-100, 600);
	wait1Msec(500);
	resetEncoders();
}







//****************************//
//			HANGING   	      //
//****************************//

////////////////////////////////////////
////////////////////
//		BLUE      //
////////////////////
////////////////////////////////////////
void blueHanging () {

	//FlipOut
	motor[leftIntake] = motor[rightIntake] = -127;
	wait1Msec(300);
	motor[leftIntake] = motor[rightIntake] = 0;

	//Start intaking
	motor[leftIntake] = motor[rightIntake] = 127;

	//Drive forward
	encoderDrive(100, 620);
	wait1Msec(500);
	resetEncoders();

	wait1Msec(1250);

	//Drive back
	encoderDrive(-127, 50);
	wait1Msec(500);
	resetEncoders();

	wait1Msec(500);

	//Make sure lift stays up
	liftLift(670);
	motor[leftLift] = motor[rightLift] = 10;

	//Deposit buckys into partner
	while(true)
	{
		if(SensorValue[button])
		{
			//Drive onto bump
			drive(127);
			wait1Msec(400);
			drive(0);
			wait1Msec(500);
			resetEncoders();

			//Outtake
			motor[leftIntake] = motor[rightIntake] = -127;
			wait1Msec(2200);
			motor[leftIntake] = motor[rightIntake] = 0;

			//Turn Lift off
			motor[leftLift] = motor[rightLift] = 0;

			break;
		}
	}

	//Drive back a tad
	resetEncoders();
	encoderDrive(-127, 150);
	wait1Msec(500);
	resetEncoders();

	//Spin
	spin(40, 80);
	wait1Msec(500);
	resetEncoders();

	//Drive back
	encoderDrive(-127, 400);
	wait1Msec(500);
	resetEncoders();

	// Spin more
	spin(40, 250);
	wait1Msec(500);
	resetEncoders();

	//Drive back into balls
	encoderDrive(-127, 700);
	wait1Msec(500);
	resetEncoders();
}

////////////////////////////////////////
////////////////////
//		RED      //
////////////////////
////////////////////////////////////////
void redHanging () {

		//FlipOut
	motor[leftIntake] = motor[rightIntake] = -127;
	wait1Msec(300);
	motor[leftIntake] = motor[rightIntake] = 0;

	//Start intaking
	motor[leftIntake] = motor[rightIntake] = 127;

	//Drive forward
	encoderDrive(100, 620);
	wait1Msec(500);
	resetEncoders();

	wait1Msec(1250);

	//Drive back
	encoderDrive(-127, 50);
	wait1Msec(500);
	resetEncoders();

	wait1Msec(500);

	//Make sure lift stays up
	liftLift(670);
	motor[leftLift] = motor[rightLift] = 10;

	//Deposit buckys into partner
	while(true)
	{
		if(SensorValue[button])
		{
			//Drive onto bump
			drive(127);
			wait1Msec(400);
			drive(0);
			wait1Msec(500);
			resetEncoders();

			//Outtake
			motor[leftIntake] = motor[rightIntake] = -127;
			wait1Msec(2200);
			motor[leftIntake] = motor[rightIntake] = 0;

			//Turn Lift off
			motor[leftLift] = motor[rightLift] = 0;

			break;
		}
	}

	//Drive back a tad
	resetEncoders();
	encoderDrive(-127, 150);
	wait1Msec(500);
	resetEncoders();

	//Spin
	spin(-40, 120);
	wait1Msec(500);
	resetEncoders();

	//Drive back
	encoderDrive(-127, 420);
	wait1Msec(500);
	resetEncoders();

	// Spin more
	spin(-40, 400);
	wait1Msec(500);
	resetEncoders();

	//Drive back into balls
	encoderDrive(-127, 700);
	wait1Msec(500);
	resetEncoders();
}
