#ifndef __MQTT_H
#define __MQTT_H 

#include "main.h"
#include "esp8266.h"

/*
*���²�����Ҫ�û������޸Ĳ��ܲ����ù�
*/


#define User_ESP8266_SSID     "brown"    //wifi��
#define User_ESP8266_PWD      "123456789a"      //wifi����

#define User_ESP8266_client_id    "50fccfefb50a48b98a93ce27bb04591f"   //MQTTclientID ���ڱ�־client���  �256�ֽ�
#define User_ESP8266_username     "admin"						//���ڵ�¼ MQTT ������ �� username, � 64 �ֽ�	
#define User_ESP8266_password			"admin13"          //���ڵ�¼ MQTT ������ �� password, � 64 �ֽ�
#define User_ESP8266_MQTTServer_IP     "106.12.9.213"     //MQTT���ط�����IP
#define User_ESP8266_MQTTServer_PORT   1883     //�������˿ں�
#define User_ESP8266_MQTTServer_Topic_PUB  "status"    //����MQTT����
#define User_ESP8266_MQTTServer_Topic_SUB  "status/set/E8DB84933089"    //����MQTT����


void ESP8266_STA_MQTTClient_Init(void);

#endif
