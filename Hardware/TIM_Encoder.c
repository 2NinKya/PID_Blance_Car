//#include "stm32f10x.h"                  // Device header
//#include "Delay.h"

///**
//   *@brief 	配置所需GPIO口，TIM3_CH1为GPIOA_6 TIM3_CH2为GPIOA_7
//   *@param	无
//   *@retval	无
//   */
//void Encoder_GPIO_Init(void)
//{
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
//	
//	GPIO_InitTypeDef GPIO_InitStruct;
//	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
//	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_6 | GPIO_Pin_7;
//	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA,&GPIO_InitStruct);
//}
///*PA6,TIM3_CH1*/

///**
//   *@brief 	配置TIM3_CH1、CH2,配置编码器功能
//   *@param	无	
//   *@retval	无
//   */
//void TIM_Encoder_Init(void)
//{
//	Encoder_GPIO_Init();	
//	
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
//	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;		//向上计数	
//	TIM_TimeBaseInitStruct.TIM_Period=50000-1;						//ARR,配置分辨率和占空比
//	TIM_TimeBaseInitStruct.TIM_Prescaler=0;							//PSC,配置占空比
//	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;			//配置预分频值
//	/* 初始化TIM3 */	
//	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStruct);
//	
//	/* 设置编码器模式 */	/* 配置成两相计数,上升沿 */
//	TIM_EncoderInterfaceConfig(TIM3,TIM_EncoderMode_TI12,TIM_ICPolarity_Rising,TIM_ICPolarity_Rising);

//	TIM_ICInitTypeDef TIM_ICInitStruct;
//	/* 输入比较滤波器 */
//	TIM_ICInitStruct.TIM_ICFilter=0;
//	TIM_ICStructInit(&TIM_ICInitStruct);	
//	/* 初始化TIM3 */
//	TIM_ICInit(TIM3,&TIM_ICInitStruct);
//	/* 计数器初始化 */
//	TIM_SetCounter(TIM3,0);											//TIM->CNT=0
//	/* 开启TIM3 */
//	TIM_Cmd(TIM3,ENABLE);										
//}

///**
//   *@brief 读取方波个数
//   *@param	无
//   *@retval	方波数
//   */
///*TIM编码器模式要两个接口都接上*/
//uint16_t GetSpeed(void)
//{
//	uint16_t Speed=0;
//	Speed = TIM_GetCounter(TIM3);
//	TIM_SetCounter(TIM3,0);
//	return Speed;
//}
