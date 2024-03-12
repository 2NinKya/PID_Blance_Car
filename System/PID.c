#include "stm32f10x.h"                  // Device header

float error_last;
//float integral;													//积分

int PID_Balance(float Angle)
{
	float error_now,differential=0;
	float Kp=-5.3;//,Kd=-1.1;			//Ki=2.2,								//调参
	short int Balance=0;										//最终电机的PWM	
	
//	if(Angle >60 | Angle < -60)
//	{
//		Balance = 0;
//		return Balance;
//	}															//倾斜角度过大时电机停止,防止意外
	//积分分离
//	if(Angle <= 60 | Angle >= -60)
//	{
//		integral+=error_now;		
//	}
//	
	error_now=Angle-5;											//-5是机械中值,需要根据实际荷重更改
	differential=error_now - error_last;						//微分
	Balance = Kp*error_now;//+Kd*differential;//+Ki*integral;
	error_last = error_now;
	
	
//	if(Balance >500)
//	{
//		Balance = 500;
//	}
//	if(Balance < -500)
//	{
//		Balance = -500;
//	}
//	
	
	return Balance;
}


