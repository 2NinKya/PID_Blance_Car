#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "sys.h"
#include "usart.h"
#include "stdio.h"
#include "mpu6050.h"
#include "inv_mpu.h"
//#include "TIM_Capture.H"
#include "Motor.h"
#include "PID.h"


	
float pitch,roll,yaw; 								  				    //ŷ����(��̬��)
short aacx,aacy,aacz;													//���ٶȴ�����ԭʼ����
short gyrox,gyroy,gyroz;											 	//������ԭʼ����
float temp; 															//�¶�
int Balance;

int main(void)
{
	uart_init(115200);
	OLED_Init();
	MPU_Init();					    			 //=====��ʼ��MPU6050
	mpu_dmp_init();								 //=====��ʼ��MPU6050��DMPģʽ	
	Motor_Init();									//����������ʼ��
	
	OLED_ShowString(1,1,"Pitch");				
	OLED_ShowString(2,1,"Roll :");
	OLED_ShowString(3,1,"Yaw  :");	
	while (1)
	{
		/*�������ǲ鿴���ݵı仯,�鿴��̬��;�����Ҫ�����ٶ��Լ����ٶȿ������޸�***/
		mpu_dmp_get_data(&pitch,&roll,&yaw);			//�õ���̬�Ǽ�ŷ����
		temp=MPU_Get_Temperature();								//�õ��¶�ֵ
		MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
		MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������	

		OLED_ShowSignedNum(1,7,pitch,2);
		OLED_ShowSignedNum(2,7,roll,2);
		OLED_ShowSignedNum(3,7,yaw,2);

		
		Balance=PID_Balance(pitch);
		Motor_SetSpeed(Balance);
	}
}

//void send_format_data(unsigned char f_code, unsigned char * data, unsigned char length)
//{
//    unsigned char buf[32];

//    if (length > 28)
//        return;

//    buf[length + 3] = 0;

//    buf[0] = 0x88;
//    buf[1] = 0xaa;

//    buf[1] = f_code;
//    buf[2] = length;

//    for (unsigned char i = 0; i < length; i++)
//        buf[i + 3] = data[i];

//    for (unsigned char i = 0; i < length + 3; i++)
//        buf[length + 3] = buf[length + 3] + buf[i];

//    for (unsigned char i = 0; i < length + 4; i++)
//        usart_send_byte(CURRENT_USART, buf[i]);
//}


//void send_mpu6050_data(short aacx, short aacy, short aacz, short gyrox, short gyroy, short gyroz)
//{
//    unsigned char buf[12];

//    buf[0] = (aacx >> 8) & 0xff;
//    buf[1] = aacx & 0xff;
//    buf[2] = (aacy >> 8) & 0xff;
//    buf[3] = aacy & 0xff;
//    buf[4] = (aacz >> 8) & 0xff;
//    buf[5] = aacz & 0xff; 
//    buf[6] = (gyrox >> 8) & 0xff;
//    buf[7] = gyrox & 0xff;
//    buf[8] = (gyroy >> 8) & 0xff;
//    buf[9] = gyroy & 0xff;
//    buf[10]= (gyroz >> 8) & 0xff;
//    buf[11]= gyroz & 0xff;

//    send_format_data(0xa1, buf, 12);
//}

//void send_dmp_data(short aacx, short aacy, short aacz, short gyrox, short gyroy, short gyroz, short roll, short pitch, short yaw)
//{
//    unsigned char buf[28]; 

//    memset(buf, 0, 28);

//    buf[0]  = (aacx >> 8) & 0xff;
//    buf[1]  = aacx & 0xff;

//    buf[2]  = (aacy >> 8) & 0xff;
//    buf[3]  = aacy & 0xff;

//    buf[4]  = (aacz >> 8) & 0xff;
//    buf[5]  = aacz & 0xff;

//    buf[6]  = (gyrox >> 8) & 0xff;
//    buf[7]  = gyrox & 0xff;

//    buf[8]  = (gyroy >> 8) & 0xff;
//    buf[9]  = gyroy & 0xff;

//    buf[10] = (gyroz >> 8) & 0xff;
//    buf[11] = gyroz & 0xff;

//    buf[18] = (roll >> 8) & 0xff;
//    buf[19] = roll & 0xff;

//    buf[20] = (pitch >> 8) & 0xff;
//    buf[21] = pitch & 0xff;

//    buf[22] = (yaw >> 8) & 0xff;
//    buf[23] = yaw & 0xff;

//    send_format_data(0xaf, buf, 28);
//}
