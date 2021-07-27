#ifndef __ESP8266_H
#define __ESP8266_H 

#include "main.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

//ESP8266ģʽѡ��
typedef enum
{
    STA,
    AP,
    STA_AP  
}ENUM_Net_ModeTypeDef;

//���紫���Э�飬ö������
typedef enum{
     enumTCP,
     enumUDP,
} ENUM_NetPro_TypeDef;
//���Ӻţ�ָ��Ϊ�����Ӻſ��Է�ֹ�������������ͬһ�˿ڶ���������
typedef enum{
    Multiple_ID_0 = 0,
    Multiple_ID_1 = 1,
    Multiple_ID_2 = 2,
    Multiple_ID_3 = 3,
    Multiple_ID_4 = 4,
    Single_ID_0 = 5,
} ENUM_ID_NO_TypeDef;

#define ESP8266_RST_Pin          GPIO_PIN_4    //��λ�ܽ�
#define ESP8266_RST_Pin_Port     GPIOA    //��λ 

#define ESP8266_CH_PD_Pin     	 GPIO_PIN_5   //ʹ�ܹܽ�
#define ESP8266_CH_PD_Pin_Port   GPIOA   //ʹ�ܶ˿�


#define ESP8266_RST_Pin_SetH     HAL_GPIO_WritePin(ESP8266_RST_Pin_Port, ESP8266_RST_Pin, GPIO_PIN_SET)
#define ESP8266_RST_Pin_SetL     HAL_GPIO_WritePin(ESP8266_RST_Pin_Port, ESP8266_RST_Pin, GPIO_PIN_RESET)


#define ESP8266_CH_PD_Pin_SetH     HAL_GPIO_WritePin(ESP8266_CH_PD_Pin_Port,ESP8266_CH_PD_Pin, GPIO_PIN_SET)
#define ESP8266_CH_PD_Pin_SetL     HAL_GPIO_WritePin(ESP8266_CH_PD_Pin_Port,ESP8266_CH_PD_Pin, GPIO_PIN_RESET)


#define ESP8266_USART(fmt, ...)  USART_printf (fmt, ##__VA_ARGS__)    
#define PC_USART(fmt, ...)       printf(fmt, ##__VA_ARGS__)       //���Ǵ��ڴ�ӡ����������1��ִ��printf����Զ�ִ��fput�������ض�����printf��



#define RX_BUF_MAX_LEN 1024       //����ֽ���
extern struct STRUCT_USART_Fram   //����֡�ṹ��
{
    uint8_t Data_RX_BUF[RX_BUF_MAX_LEN];
    union 
    {
        __IO uint16_t InfAll;
        struct 
        {
            __IO uint16_t FramLength       :15;                               // 14:0 
            __IO uint16_t FramFinishFlag   :1;                                // 15 
        }InfBit;
    }; 
	
}ESP8266_Fram_Record_Struct;


//��ʼ����TCP���ܺ���
void ESP8266_Init(uint32_t bound);
void ESP8266_AT_Test(void);
bool ESP8266_Send_AT_Cmd(char *cmd,char *ack1,char *ack2,uint32_t time);
void ESP8266_Rst(void);
bool ESP8266_Net_Mode_Choose(ENUM_Net_ModeTypeDef enumMode);
bool ESP8266_JoinAP( char * pSSID, char * pPassWord );
bool ESP8266_Enable_MultipleId ( FunctionalState enumEnUnvarnishTx );
bool ESP8266_Link_Server(ENUM_NetPro_TypeDef enumE, char * ip, char * ComNum, ENUM_ID_NO_TypeDef id);
bool ESP8266_SendString(FunctionalState enumEnUnvarnishTx, char * pStr, uint32_t ulStrLength, ENUM_ID_NO_TypeDef ucId );
bool ESP8266_UnvarnishSend ( void );
void ESP8266_ExitUnvarnishSend ( void );
uint8_t ESP8266_Get_LinkStatus ( void );
void USART_printf( char * Data, ... );

//MQTT���ܺ���
bool ESP8266_MQTTUSERCFG( char * pClient_Id, char * pUserName,char * PassWord);
bool ESP8266_MQTTCONN( char * Ip, int Num);
bool ESP8266_MQTTSUB(char * Topic);
bool ESP8266_MQTTPUB( char * Topic,char *temp);
bool ESP8266_MQTTCLEAN(void);
bool MQTT_SendString(char * pTopic,char *temp2);

#endif

