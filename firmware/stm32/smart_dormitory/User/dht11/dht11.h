/****************************************Copyright (c)****************************************************
**     
** File name:               dht11.h
** Created by:              xxx
** Created date:            2020-10-16
** Version:                 v1.0
** Descriptions:            The original 
**
*********************************************************************************************************/

#ifndef __DHT11_H__
#define __DHT11_H__

#include "main.h"
/* ���Ͷ��� ------------------------------------------------------------------*/
/************************ DHT11 �������Ͷ���******************************/
typedef struct
{
        uint8_t  humi_high8bit;                //ԭʼ���ݣ�ʪ�ȸ�8λ
        uint8_t  humi_low8bit;                 //ԭʼ���ݣ�ʪ�ȵ�8λ
        uint8_t  temp_high8bit;                 //ԭʼ���ݣ��¶ȸ�8λ
        uint8_t  temp_low8bit;                 //ԭʼ���ݣ��¶ȸ�8λ
        uint8_t  check_sum;                     //У���
  float    humidity;        //ʵ��ʪ��
  float    temperature;     //ʵ���¶�  
} DHT11_Data_TypeDef;

/* �궨�� -------------------------------------------------------------------*/
/***********************   DHT11 �������Ŷ���  **************************/
#define DHT11_Dout_GPIO_CLK_ENABLE()              __HAL_RCC_GPIOB_CLK_ENABLE()
#define DHT11_Dout_PORT                           GPIOB
#define DHT11_Dout_PIN                            GPIO_PIN_5

/***********************   DHT11 �����궨��  ****************************/
#define DHT11_Dout_LOW()                          HAL_GPIO_WritePin(DHT11_Dout_PORT,DHT11_Dout_PIN,GPIO_PIN_RESET)
#define DHT11_Dout_HIGH()                         HAL_GPIO_WritePin(DHT11_Dout_PORT,DHT11_Dout_PIN,GPIO_PIN_SET)
#define DHT11_Data_IN()                                  HAL_GPIO_ReadPin(DHT11_Dout_PORT,DHT11_Dout_PIN)

/* ��չ���� ------------------------------------------------------------------*/
/* �������� ------------------------------------------------------------------*/
void dht11_init( void );
uint8_t dht11_get_tempHumi(DHT11_Data_TypeDef * DHT11_Data);

#endif

