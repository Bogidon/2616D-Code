/////////////////////////////////////////////////////////////////////////////////////////
//**Reset encoders**/
/////////////////////////////////////////////////////////////////////////////////////////
void	resetEncoders(){			//Clears drive encoders
	nMotorEncoder[leftDrive2] = 0;
	nMotorEncoder[rightDrive2] = 0;
}
/////////////////////////////////////////////////////////////////////////////////////////
//**Basic**/
//
//Caveman-simple driving with nothing
/////////////////////////////////////////////////////////////////////////////////////////
void basicDrive(int leftPower, int rightPower){
	motor[leftDrive1]=motor[leftDrive2]=motor[leftDrive3] = leftPower;
	motor[rightDrive1] = motor[rightDrive2] = rightPower;
}
/////////////////////////////////////////////////////////////////////////////////////////
//**Drive**/
//
//Simple driving with straighening but no stopping limit
/////////////////////////////////////////////////////////////////////////////////////////
void drive(int power){

	if(power != 0)		//Adds ability to use to use function to stop drive
	{
		basicDrive(power, power);
		//Compares left and right encoder values to straighten robot
		if(nMotorEncoder[leftDrive2] == nMotorEncoder[rightDrive2])
		{
			basicDrive(power, power);
		}
		else if(nMotorEncoder[leftDrive2] < nMotorEncoder[rightDrive2])
		{
			basicDrive(power, power-40);
		}
		else
		{
			basicDrive(power-40,power);
		}

	}
	else 	//Stops drive if power is zero
	{
		basicDrive(0,0);
	}
}


/////////////////////////////////////////////////////////////////////////////////////////
//**Encoder-based Drive**/
//
//Info:
// • + or - power determines front or back
// • encoder count must be positive
// • drive power of 80 is very reliable
/////////////////////////////////////////////////////////////////////////////////////////
void encoderDrive(int power, int encoderCount){

	while(abs(nMotorEncoder[leftDrive2]) < encoderCount && abs(nMotorEncoder[rightDrive2]) < encoderCount - 300){
		drive(power);	//Drive robot at power

		if(nMotorEncoder[leftDrive2] >= encoderCount)
			motor[leftDrive1]=motor[leftDrive2]=motor[leftDrive3] = 0;

		if(nMotorEncoder[rightDrive2] >= encoderCount)
			motor[rightDrive1] = motor[rightDrive2] = 0;
	}

	//Slow down near destination
	while(abs(nMotorEncoder[leftDrive2]) < encoderCount && abs(nMotorEncoder[rightDrive2]) < encoderCount){
		drive(power/2.5);	//Drive robot at power

		if(nMotorEncoder[leftDrive2] >= encoderCount)
			motor[leftDrive1]=motor[leftDrive2]=motor[leftDrive3] = 0;

		if(nMotorEncoder[rightDrive2] >= encoderCount)
			motor[rightDrive1] = motor[rightDrive2] = 0;
	}
	drive(0);	//Turn off after it has reached destination
}

/////////////////////////////////////////////////////////////////////////////////////////
//**Encoder-based Drive w/ Lift**/
//
//Info:
// • + or - power determines front or back
// • + or - position determines lift up or down
// • encoder count must be positive
/////////////////////////////////////////////////////////////////////////////////////////
void encoderDriveWithLift(int power, int encoderCount, int position){

	while(abs(nMotorEncoder[leftDrive2]) < encoderCount && abs(nMotorEncoder[rightDrive2]) < encoderCount - 300){
		drive(power);	//Drive robot at power

		if(nMotorEncoder[leftDrive2] >= encoderCount)
			motor[leftDrive1]=motor[leftDrive2] = motor[leftDrive3] = 0;

		if(nMotorEncoder[rightDrive2] >= encoderCount)
			motor[rightDrive1] = motor[rightDrive2] = 0;

		if(SensorValue[armPot] < position)
			motor[leftLift] = motor[rightLift] = 127;
		else
			motor[leftLift] = motor[rightLift] = 0;
	}

	//Slow down near destination
	while(abs(nMotorEncoder[leftDrive2]) < encoderCount && abs(nMotorEncoder[rightDrive2]) < encoderCount){
		drive(power);	//Drive robot at power

		if(nMotorEncoder[leftDrive2] >= encoderCount)
			motor[leftDrive1]=motor[leftDrive2] = motor[leftDrive3] = 0;

		if(nMotorEncoder[rightDrive2] >= encoderCount)
			motor[rightDrive1] = motor[rightDrive2] = 0;

		if(SensorValue[armPot] < position)
			motor[leftLift] = motor[rightLift] = 127;
		else
			motor[leftLift] = motor[rightLift] = 0;
	}
	drive(0);	//Turn off after it has reached destination
}

/////////////////////////////////////////////////////////////////////////////////////////
//**Spin**/
//
//Spin robot using encoders
//positive degrees10 = clockwise
/////////////////////////////////////////////////////////////////////////////////////////
void spin(int power, int encoderCount){
	//Clockwise with positive power
	if(power > 0){
		while(abs(nMotorEncoder[leftDrive2]) < encoderCount){
			basicDrive(power, -power);
		}
	}
	else{
		while(abs(nMotorEncoder[leftDrive2]) < encoderCount){
			basicDrive(power, -power);
		}
	}
	drive(0);
}

/////////////////////////////////////////////////////////////////////////////////////////
//**Lift the lift up**/
/////////////////////////////////////////////////////////////////////////////////////////
void liftLift(int position)
{
	while(SensorValue[armPot] < position)	{
		motor[leftLift] = motor[rightLift] = 127;
	}
	motor[leftLift] = motor[rightLift] = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
//**Lower the lift down**/
/////////////////////////////////////////////////////////////////////////////////////////
void lowerLift(int position)
{
	while(SensorValue[armPot] > position)
	{
		motor[leftLift] = motor[rightLift] = -127;
	}
	motor[leftLift] = motor[rightLift] = 0;
	return;
}

void timeLift(int power, int time)
{
	motor[leftLift] = power;
	wait1Msec(time);		//Time intake runs
	motor[leftLift] = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
//**Time-based intake**
//
//Spins intake for designated time
/////////////////////////////////////////////////////////////////////////////////////////
void intake(int power, int time){
	motor[leftIntake] = power;
	wait1Msec(time);		//Time intake runs
	motor[leftIntake] = 0;
}
