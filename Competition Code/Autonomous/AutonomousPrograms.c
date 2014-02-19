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
	lowerLift(400);

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
	motor[leftIntake] = motor[rightIntake] = -127;
	wait1Msec(1200);
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
		wait1Msec(800);
		motor[leftIntake] = motor[rightIntake] = 0;

		//Spin to big ball
		spin(-90, 10);
		wait1Msec(500);

		////Lift lift
		liftLift(829);
		wait1Msec(500);

		//Drive into big ball
		encoderDrive(85, 550);
		wait1Msec(500);

		//Return to tile
		encoderDrive(127, 0);
		wait1Msec(500);
		resetEncoders();

		////Lower lift
		lowerLift(140);
		wait1Msec(500);

		//Go forward when button is pushed
		while(true)
		{
			if(SensorValue[button])
			{
				encoderDrive(127, 1100);
				wait1Msec(500);
				resetEncoders();
				break;
			}
		}

		//Lift lift
		liftLift(2495);
		wait1Msec(500);
		motor[leftLift]=motor[rightLift]=15;

		//Spin to tube
		wait1Msec(500);
		resetEncoders();

		//Drive forward
		encoderDrive(127, 200);

		// Drive to tube
		motor[leftLift] = motor[rightLift] = 127;
		wait1Msec(1200);
		encoderDriveWithLift(35, 580, 1440);
		wait1Msec(500);
		resetEncoders();

		//Lift lift
		liftLift(1440);
		wait1Msec(500);

		//Outtake
		motor[leftIntake] = motor[rightIntake] = 127;

		//Drive back
		encoderDrive(100, -110);
		wait1Msec(500);
		resetEncoders();

		//Outtake big ball
		motor[leftIntake] = motor[rightIntake] = 127;
		wait1Msec(1200);
		motor[leftIntake] = motor[rightIntake] = 0;

		//Drive back a bit for large ball
		encoderDrive(100, -200);
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
		wait1Msec(800);
		motor[leftIntake] = motor[rightIntake] = 0;

		//Spin to big ball
		spin(-90, 10);
		wait1Msec(500);

		////Lift lift
		liftLift(829);
		wait1Msec(500);

		//Drive into big ball
		encoderDrive(85, 550);
		wait1Msec(500);

		//Return to tile
		encoderDrive(127, 0);
		wait1Msec(500);
		resetEncoders();

		////Lower lift
		lowerLift(140);
		wait1Msec(500);

		//Go forward when button is pushed
		while(true)
		{
			if(SensorValue[button])
			{
				encoderDrive(127, 1100);
				wait1Msec(500);
				resetEncoders();
				break;
			}
		}

		//Lift lift
		liftLift(2495);
		wait1Msec(500);
		motor[leftLift]=motor[rightLift]=15;

		//Spin to tube
		wait1Msec(500);
		resetEncoders();

		//Drive forward
		encoderDrive(127, 200);

		// Drive to tube
		motor[leftLift] = motor[rightLift] = 127;
		wait1Msec(1200);
		encoderDriveWithLift(35, 580, 1440);
		wait1Msec(500);
		resetEncoders();

		//Lift lift
		liftLift(1440);
		wait1Msec(500);

		//Outtake
		motor[leftIntake] = motor[rightIntake] = 127;

		//Drive back
		encoderDrive(100, -110);
		wait1Msec(500);
		resetEncoders();

		//Outtake big ball
		motor[leftIntake] = motor[rightIntake] = 127;
		wait1Msec(1200);
		motor[leftIntake] = motor[rightIntake] = 0;

		//Drive back a bit for large ball
		encoderDrive(100, -200);
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
		wait1Msec(800);
		motor[leftIntake] = motor[rightIntake] = 0;

		//Spin to big ball
		spin(-90, 10);
		wait1Msec(500);

		////Lift lift
		liftLift(829);
		wait1Msec(500);

		//Drive into big ball
		encoderDrive(85, 550);
		wait1Msec(500);

		//Return to tile
		encoderDrive(127, 0);
		wait1Msec(500);
		resetEncoders();

		////Lower lift
		lowerLift(140);
		wait1Msec(500);

		//Go forward when button is pushed
		while(true)
		{
			if(SensorValue[button])
			{
				encoderDrive(127, 1100);
				wait1Msec(500);
				resetEncoders();
				break;
			}
		}

		//Lift lift
		liftLift(2495);
		wait1Msec(500);
		motor[leftLift]=motor[rightLift]=15;

		//Spin to tube
		wait1Msec(500);
		resetEncoders();

		//Drive forward
		encoderDrive(127, 200);

		// Drive to tube
		motor[leftLift] = motor[rightLift] = 127;
		wait1Msec(1200);
		encoderDriveWithLift(35, 580, 1440);
		wait1Msec(500);
		resetEncoders();

		//Lift lift
		liftLift(1440);
		wait1Msec(500);

		//Outtake
		motor[leftIntake] = motor[rightIntake] = 127;

		//Drive back
		encoderDrive(100, -110);
		wait1Msec(500);
		resetEncoders();

		//Outtake big ball
		motor[leftIntake] = motor[rightIntake] = 127;
		wait1Msec(1200);
		motor[leftIntake] = motor[rightIntake] = 0;

		//Drive back a bit for large ball
		encoderDrive(100, -200);
		wait1Msec(500);
		resetEncoders();
}
