/****************************************Copyright (c)****************************************************
**     
** File name:               process.c
** Created by:              XiaoYi
** Created date:            2020-10-16
** Version:                 v1.0
** Descriptions:            The original 
** Link address:            https://blog.csdn.net/weixin_45006076
**
*********************************************************************************************************/

#include "process.h"
#include "gpio.h"
#include "flash.h"
#include "tim.h"
#include "oled.h"

/*
	SG90�Ķ��Ҫ����ƶ���� PWM �ź�Ƶ����50Hz���ң�������Ϊ 20ms �� PWM �źţ������źŵĸߵ�ƽ������0.5ms - 2.5ms֮��ʱ����Ӧ���ת���ĽǶȣ������Ӧ�������
	value����ֵ    �ߵ�ƽ����        ���ת���Ƕ�
		50							0.5ms              0��
		100               1ms              45��
		150             1.5ms              90��
		200               2ms              135��
		250             2.5ms              180��
*/
void set_sg90(int value)  // ģ�⿪��
{
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, value);
}

void start_buzz(void)
{
	BUZZ = 1;
}

void stop_buzz(void)
{
	BUZZ = 1;
}
  
void process_local_handle(uint16_t value_humi)
{
	/* ���ʪ��С��ϵͳ���õ���Сֵ��ת�������ˮ����ʪ�ȳ������ֵʱ��ֹͣ��ˮ���رյ�� */
;
}

void process_report_data(void)
{
	uint8_t send_buff[12];
	
	// ��ǰϵͳ��������״̬ʱ��������

}

void process_handle_wifi_data(void)
{
	int i = 0;


}

