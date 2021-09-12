#include "mqtt.h"

void ESP8266_STA_MQTTClient_Init(void)
{
	char str[] = "{\"deviceNum\":\"863488052352477\"\,\"relayStatus\":0\,\
			\"lightStatus\":0\,\"isOnline\":1\,\"rssi\":-54\,\"deviceTemperature\":40\,\"airTemperature\":0\,\
			\"airHumidity\":0\,\"triggerSource\":0\,\"brightness\":11\,\"lightInterval\":432\,\
			\"lightMode\":0\,\"fadeTime\":259\,\"red\":255\,\"green\":0\,\"blue\":0}";
	
	printf("��������ESP8266����\r\n");
	ESP8266_ATE0();//ȡ������
	ESP8266_Net_Mode_Choose(STA);
	while(!ESP8266_JoinAP(WIFI_SSID, WIFI_PWD));
	
	// �����û�����
	ESP8266_MQTTUSERCFG(WIFI_client_id,WIFI_username,WIFI_password);
	delay_ms(200);
	// ����MQTT������
	ESP8266_MQTTCONN( WIFI_MQTTServer_IP, WIFI_MQTTServer_PORT);
	// ��������
	ESP8266_MQTTSUB( WIFI_MQTTServer_Topic_SUB);
	printf("\r\nMQTT�������");
	
	delay_ms(200);

	//�������ݵ�MQTT������
	if (MQTT_SendString (WIFI_MQTTServer_Topic_PUB, str))
	{
		printf("send data to mqtt server success\r\n");
	}else
	{
		printf("send data to mqtt server error\r\n");
		printf(": %s\r\n", str);
	}
	
}

