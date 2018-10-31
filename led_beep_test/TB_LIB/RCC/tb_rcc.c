#include "tb_rcc.h"
#include "stm32f10x_rcc.h"


void tb_rcc_init(void) {
//--------------------------- CLK INIT, HSE PLL ----------------------------
	ErrorStatus HSEStartUpStatus;
	//RCC reset
	RCC_DeInit();
	//�����ⲿʱ�� ��ִ�г�ʼ��
	RCC_HSEConfig(RCC_HSE_ON); 
	//�ȴ��ⲿʱ��׼����
	HSEStartUpStatus = RCC_WaitForHSEStartUp();
	//����ʧ�� ������ȴ�
	while(HSEStartUpStatus == ERROR);
	//�����ڲ�����ʱ��
	RCC_HCLKConfig(RCC_SYSCLK_Div1);//SYSCLK
	RCC_PCLK1Config(RCC_HCLK_Div2);//APB1  MAX = 36M
	RCC_PCLK2Config(RCC_HCLK_Div1);//APB2  MAX = 72M
	//�ⲿʱ��Ϊ8M ���ﱶƵ��72M
	RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);
	RCC_PLLCmd(ENABLE); 
	while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
	while(RCC_GetSYSCLKSource() != 0x08);

	//----------------------------- CLOSE HSI ---------------------------
	//�ر��ڲ�ʱ��HSI
	//RCC_HSICmd(DISABLE);
	//�ر��ڲ�ʼ��LSI
	//RCC_LSICmd(DISABLE);
	
	//����IO��ʱ��
	//��PA��ʱ��
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	//��PB��ʱ��
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	



	return;
}




