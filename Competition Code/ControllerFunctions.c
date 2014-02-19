//Functions for VEX Controller
//By: Bogdan Vitoc
//Date: 8/22/2013

void controllerDrive(int leftPow, int rightPow){
	motor[leftDrive1] = motor[leftDrive2] = motor[leftDrive3] = leftPow;
	motor[rightDrive1] = motor[rightDrive2] = rightPow;
}
void intakeController()
{
	if(vexRT(Btn6U)){
		motor[leftIntake] = motor[rightIntake] = 127;
		}else if(vexRT(Btn6D)){
		motor[leftIntake] = motor[rightIntake] = -127;
		}else{
		motor[leftIntake] = motor[rightIntake] = 0;
	}
}
void lift()
{
	if(SensorValue[armPot] < 1500){
			if(vexRT(Btn5U)){
			motor[port7] = motor[port8] = 127;
			}else if(vexRT(Btn5D)){
			motor[port7] = motor[port8] = -80;
			}else{
			motor[port7] = motor[port8] = 0;
		}
	}else{
		motor[port7] = motor[port8] = 0;
	}
}
