#ifndef __MQTT_H
#define __MQTT_H 

#include "main.h"
#include "esp8266.h"

/*
*���²�����Ҫ�û������޸Ĳ��ܲ����ù�
*/


#define WIFI_SSID     "DianJing"    //wifi��
#define WIFI_PWD      "wzry6666"      //wifi����

#define WIFI_client_id    "50fccfefb50a48b98a93ce27bb04591f"   //MQTTclientID ���ڱ�־client���  �256�ֽ�
#define WIFI_username     "admin"						//���ڵ�¼ MQTT ������ �� username, � 64 �ֽ�	
#define WIFI_password			"admin13"          //���ڵ�¼ MQTT ������ �� password, � 64 �ֽ�
#define WIFI_MQTTServer_IP     "106.12.9.213"     //MQTT���ط�����IP
#define WIFI_MQTTServer_PORT   1883     //�������˿ں�
#define WIFI_MQTTServer_Topic_PUB  "status"    //����MQTT����
#define WIFI_MQTTServer_Topic_SUB  "status/set/863488052352477"    //����MQTT����


void ESP8266_STA_MQTTClient_Init(void);

#endif
