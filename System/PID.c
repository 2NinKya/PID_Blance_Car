#include "stm32f10x.h"                  // Device header

float error_last;
//float integral;													//����

int PID_Balance(float Angle)
{
	float error_now,differential=0;
	float Kp=-5.3;//,Kd=-1.1;			//Ki=2.2,								//����
	short int Balance=0;										//���յ����PWM	
	
//	if(Angle >60 | Angle < -60)
//	{
//		Balance = 0;
//		return Balance;
//	}															//��б�Ƕȹ���ʱ���ֹͣ,��ֹ����
	//���ַ���
//	if(Angle <= 60 | Angle >= -60)
//	{
//		integral+=error_now;		
//	}
//	
	error_now=Angle-5;											//-5�ǻ�е��ֵ,��Ҫ����ʵ�ʺ��ظ���
	differential=error_now - error_last;						//΢��
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


