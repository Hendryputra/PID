#include <stdio.h>
#include "pid.h"

#define SPEED_MAX	((i32)1000)
i32 kp, ki, kd, kd2;
i32 hasil;
i32 input;

int main(void){
	//u(n) = u(n-1) + b0*e(n) + b1*e(n-1) + b2*e(n-2) + b3*e(n-3)

	//where
	//b0 = kp + ki + kd + kd2;
	//b1 = -kp -2*kd -3*kd2;
	//b2 = kd + 3*kd2;
	//b3 = -kd2;

	//set parameter PID dulu
	
	struct sPID pid;
	
	kp=256;
	ki=25;
	kd=25;
	kd2=100;
	input=100;
	
	pid_init(&pid, SPEED_MAX,kp,ki,kd,kd2);   //kalau pake kp,ki,kd
	//pid_synthetise(&pid,10,20,30,40);      //kalau pake b0,b1,b2,b3
	
	hasil=pid_process(&pid,input);           //proses PID
	
	printf("input : %d ,hasilnya : %d\r\n",input ,hasil);
	
}
