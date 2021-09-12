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

#include "sensor_light.h"
#include "gpio.h"
#include "adc.h"

uint16_t light_get_value(void)
{
	// ����ADCת��
	HAL_ADC_Start(&hadc1);
	// �ȴ�ת����ɣ��ڶ���������ʾ��ʱʱ�䣬��λms
	HAL_ADC_PollForConversion(&hadc1, 100);
	return HAL_ADC_GetValue(&hadc1);
}

uint8_t light_get_average_value(uint8_t times)  //��ȡ�������ݲ����ظ�������
{
	uint32_t temp_val=0;
	uint8_t t;
	float temp_avrg=0;

	for(t=0;t<times;t++)       //LSENS_READ_TIMES��lsens.h�ļ�����ã�Ĭ��10//
	{
		temp_val += light_get_value();   //��ȡADCֵ
		delay_ms(5);
	}
	temp_val/=times;           //����ƽ��ֵ// 
	if(temp_val>4000)
		temp_val=4000;       //��������ֵ����4000ʱ��ǿ��ת��Ϊ4000//
	
	return (100-(temp_val/40));       //��temp_valֵ��һ����0-100֮��//
}

