#include "esp8266.h"

extern UART_HandleTypeDef huart3;

STRUCT_USART_Fram_t ESP8266_Fram_Record_Struct;

void ESP8266_Init(uint32_t bound)
{
    GPIO_InitTypeDef GPIO_InitStructure;

	__HAL_RCC_GPIOA_CLK_ENABLE();
	
//    GPIO_InitStructure.Pin = ESP8266_RST_Pin;             
//    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;     //�����������
//    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;  
//	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
//	
//    GPIO_InitStructure.Pin = ESP8266_CH_PD_Pin;               
//    HAL_GPIO_Init(ESP8266_CH_PD_Pin_Port, &GPIO_InitStructure);
//	
//	ESP8266_Rst();
}

//��ESP8266ģ�鷢��ATָ��
// cmd �����͵�ָ��
// ack1,ack2;�ڴ�����Ӧ��ΪNULL������Ӧ������Ϊ���߼���ϵ
// time �ȴ���Ӧʱ��
//����1���ͳɹ��� 0ʧ��
bool ESP8266_Send_AT_Cmd(char *cmd,char *ack1,char *ack2,uint32_t time)
{ 
    ESP8266_Fram_Record_Struct.InfBit.FramLength = 0; //���½����µ����ݰ�
	ESP8266_Fram_Record_Struct.InfBit.FramFinishFlag = 0;
	memset(ESP8266_Fram_Record_Struct.Data_RX_BUF, 0x00, sizeof(ESP8266_Fram_Record_Struct.Data_RX_BUF));
	
    hal_AT_printf("%s\r\n", cmd);
    if(ack1==0&&ack2==0)     //����Ҫ��������
    {
			return true;
    }
    delay_ms(time);   //��ʱ
		delay_ms(1000);
    ESP8266_Fram_Record_Struct.Data_RX_BUF[ESP8266_Fram_Record_Struct.InfBit.FramLength ] = '\0';
		
    printf("------ %s", ESP8266_Fram_Record_Struct.Data_RX_BUF);
    if(ack1!=0&&ack2!=0)
    {
        return ( ( bool ) strstr ( (char *)ESP8266_Fram_Record_Struct.Data_RX_BUF, ack1 ) || 
                         ( bool ) strstr ( (char *)ESP8266_Fram_Record_Struct.Data_RX_BUF, ack2 ) );
    }
    else if( ack1 != 0 )  //strstr(s1,s2);���s2�Ƿ�Ϊs1��һ���֣��Ƿ��ظ�λ�ã����򷵻�false����ǿ��ת��Ϊbool������
        return ( ( bool ) strstr ( (char *)ESP8266_Fram_Record_Struct.Data_RX_BUF, ack1 ) );

    else
        return ( ( bool ) strstr ( (char *)ESP8266_Fram_Record_Struct.Data_RX_BUF, ack2 ) );

}

/*-------------------------------------------------*/
/*��������WiFi��λ                                 */
/*��  ����timeout����ʱʱ�䣨100ms�ı�����          */
/*����ֵ��0����ȷ   ����������                      */
/*-------------------------------------------------*/

char ESP8266_Rst(void)
{
	return ESP8266_Send_AT_Cmd ( "AT+RST\r\n", "OK", 0, 5000 );
}

//���ͻָ�����Ĭ������ָ�ģ��ָ��ɳ�������
void ESP8266_AT_Test(void)
{
    char count=0;
    delay_ms(1000); 
    while(count < 10)
    {
        if(ESP8266_Send_AT_Cmd("AT+RESTORE","OK",NULL,500)) 
        {
            printf("OK\r\n");
            return;
        }
        ++ count;
    }
}

//ȡ������
void ESP8266_ATE0(void)
{
    char count=0;
    delay_ms(1000); 
    while(count < 10)
    {
        if(ESP8266_Send_AT_Cmd("ATE0","OK",NULL,1000)) 
        {
            printf("ATE0 OK\r\n");
            return;
        }
        ++ count;
    }
}

//ѡ��ESP8266�Ĺ���ģʽ
// enumMode ģʽ����
//�ɹ�����true��ʧ�ܷ���false
bool ESP8266_Net_Mode_Choose(ENUM_Net_ModeTypeDef enumMode)
{
    switch ( enumMode )
    {
        case STA:
            return ESP8266_Send_AT_Cmd ( "AT+CWMODE=1", "OK", "no change", 2500 ); 

        case AP:
            return ESP8266_Send_AT_Cmd ( "AT+CWMODE=2", "OK", "no change", 2500 ); 

        case STA_AP:
            return ESP8266_Send_AT_Cmd ( "AT+CWMODE=3", "OK", "no change", 2500 ); 

        default:
          return false;
    }       
}

//ESP8266�����ⲿ��WIFI
//pSSID WiFi�ʺ�
//pPassWord WiFi����
//���óɹ�����true ��֮false
bool ESP8266_JoinAP( char * pSSID, char * pPassWord)
{
    char cCmd [120];
	
    sprintf ( cCmd, "AT+CWJAP=\"%s\",\"%s\"", pSSID, pPassWord );
    return ESP8266_Send_AT_Cmd( cCmd, "OK", "WIFI CONNECTED", 5000 );
}

//ESP8266 ͸��ʹ��
//enumEnUnvarnishTx  �Ƿ�����ӣ�bool����
//���óɹ�����true����֮false
bool ESP8266_Enable_MultipleId (FunctionalState enumEnUnvarnishTx )
{
    char cStr [20];

    sprintf ( cStr, "AT+CIPMUX=%d", ( enumEnUnvarnishTx ? 1 : 0 ) );

    return ESP8266_Send_AT_Cmd ( cStr, "OK", 0, 500 );

}

//ESP8266 ʹ���Զ�����
//enumEnUnvarnishTx  �Ƿ�����ӣ�bool����
//���óɹ�����true����֮false
bool ESP8266_Enable_AutoConnect (int enable )
{
    char cStr [20];

    sprintf ( cStr, "AT+CWAUTOCONN=%d", enable );

    return ESP8266_Send_AT_Cmd ( cStr, "OK", 0, 500 );

}

//ESP8266 ���ӷ�����
//enumE  ��������
//ip ��������IP
//ComNum  �������˿�
//id�����Ӻţ�ȷ��ͨ�Ų���������
//���óɹ�����true����֮fasle
bool ESP8266_Link_Server(ENUM_NetPro_TypeDef enumE, char * ip, char * ComNum, ENUM_ID_NO_TypeDef id)
{
    char cStr [100] = { 0 }, cCmd [120];

    switch (  enumE )
    {
        case enumTCP:
          sprintf ( cStr, "\"%s\",\"%s\",%s", "TCP", ip, ComNum );
          break;

        case enumUDP:
          sprintf ( cStr, "\"%s\",\"%s\",%s", "UDP", ip, ComNum );
          break;

        default:
            break;
    }

    if ( id < 5 )
        sprintf ( cCmd, "AT+CIPSTART=%d,%s", id, cStr);

    else
        sprintf ( cCmd, "AT+CIPSTART=%s", cStr );

    return ESP8266_Send_AT_Cmd ( cCmd, "OK", "ALREAY CONNECT", 4000 );

}


//͸��ʹ��
//���óɹ�����true�� ��֮false
bool ESP8266_UnvarnishSend ( void )
{
    if (!ESP8266_Send_AT_Cmd ( "AT+CIPMODE=1", "OK", 0, 500 ))
        return false;

    return 
        ESP8266_Send_AT_Cmd( "AT+CIPSEND", "OK", ">", 500 );
}


//ESP8266�����ַ���
//enumEnUnvarnishTx�Ƿ�ʹ��͸��ģʽ
//pStr�ַ���
//ulStrLength�ַ�������
//ucId ���Ӻ�
//���óɹ�����true�� ��֮false
bool ESP8266_SendString(FunctionalState enumEnUnvarnishTx, char * pStr, uint32_t ulStrLength, ENUM_ID_NO_TypeDef ucId )
{
    char cStr [20];
    bool bRet = false;

    if ( enumEnUnvarnishTx )
    {
        hal_AT_printf ( "%s", pStr );

        bRet = true;
    }
    else
    {
        if ( ucId < 5 )
            sprintf ( cStr, "AT+CIPSEND=%d,%d", ucId, ulStrLength + 2 );

        else
            sprintf ( cStr, "AT+CIPSEND=%d", ulStrLength + 2 );

        ESP8266_Send_AT_Cmd ( cStr, "> ", 0, 1000 );

        bRet = ESP8266_Send_AT_Cmd ( pStr, "SEND OK", 0, 1000 );
    }
    return bRet;
}


//ESP8266�˳�͸��ģʽ
void ESP8266_ExitUnvarnishSend ( void )
{
    delay_ms(1000);
    hal_AT_printf( "+++" );
    delay_ms( 500 );    
}


//ESP8266 �������״̬
//����0����ȡ״̬ʧ��
//����2�����ip
//����3���������� 
//����4��ʧȥ���� 
uint8_t ESP8266_Get_LinkStatus ( void )
{
    if (ESP8266_Send_AT_Cmd( "AT+CIPSTATUS", "OK", 0, 500 ) )
    {
        if ( strstr ( (char *)ESP8266_Fram_Record_Struct.Data_RX_BUF, "STATUS:2\r\n" ) )
            return 2;
        else if ( strstr ( (char *)ESP8266_Fram_Record_Struct.Data_RX_BUF, "STATUS:3\r\n" ) )
            return 3;
        else if ( strstr ( (char *)ESP8266_Fram_Record_Struct.Data_RX_BUF, "STATUS:4\r\n" ) )
            return 4;       
    }
    return 0;
}



extern char mqtt_tcp_connect(int timeout);

/*-------------------------------------------------*/
/*��������WiFi���ӷ�����                           */
/*��  ������                                       */
/*����ֵ��0����ȷ   ����������                     */
/*-------------------------------------------------*/
char WiFi_Connect_IoTServer(void)
{	
//	printf("׼����λģ��\r\n");                   //������ʾ����
//	ESP8266_Rst();

	// ȡ������
	ESP8266_ATE0();
	
	printf("ready to set STA mode\r\n");
	// ����STAģʽ
	if (ESP8266_Net_Mode_Choose(STA))
	{
		printf("Set STA mode\r\n");
	}

	// ׼���رն�·����
	if (ESP8266_Enable_MultipleId(DISABLE))
	{
		printf("close multipled ID success\r\n");
	}else
	{
		printf("close multipled ID error\r\n");
	}
	// ȡ���Զ�����
	if(ESP8266_Enable_AutoConnect(0))		 //ȡ���Զ����ӣ�100ms��ʱ��λ���ܼ�5s��ʱʱ��
	{       
		printf("ȡ���Զ����ӳɹ�\r\n");        //������ʾ����
	}else 
	{
		printf("ȡ���Զ�����ʧ�ܣ�׼������\r\n"); //���ط�0ֵ������if��������ʾ����
		return 3;       
	}
			

	// ����·����
	if(ESP8266_JoinAP(User_SSID, User_PWD))
	{
		printf("connect to router success\r\n");
	}else
	{
		printf("connect to router failed\r\n");
		return 9;
	}
	
	// ���ӷ�����
	if(mqtt_tcp_connect(500))      				 //���ӷ�������100ms��ʱ��λ���ܼ�10s��ʱʱ��
	{            
		printf("connect to server success\r\n");    //���ط�0ֵ������if��������ʾ����
		                                 //����10
	}else 
	{
		printf("connect to server failed\r\n");            //������ʾ����	
		return 10;  
	}
	
	// ����͸��ģʽ
	if (ESP8266_UnvarnishSend() )
	{
		printf("go into unvarnishSend mode\r\n");
	}
	return 0;                                        //��ȷ����0
}


static char *itoa( int value, char *string, int radix )
{
    int     i, d;
    int     flag = 0;
    char    *ptr = string;

    /* This implementation only works for decimal numbers. */
    if (radix != 10)
    {
        *ptr = 0;
        return string;
    }

    if (!value)
    {
        *ptr++ = 0x30;
        *ptr = 0;
        return string;
    }

    /* if this is a negative value insert the minus sign. */
    if (value < 0)
    {
        *ptr++ = '-';

        /* Make the value positive. */
        value *= -1;

    }

    for (i = 10000; i > 0; i /= 10)
    {
        d = value / i;

        if (d || flag)
        {
            *ptr++ = (char)(d + 0x30);
            value -= (d * i);
            flag = 1;
        }
    }

    /* Null terminate the string. */
    *ptr = 0;

    return string;

} /* NCL_Itoa */


void hal_AT_printf ( char * Data, ... )
{
    const char *s;
    int d;   
    char buf[16];
	uint8_t ch = 0;


    va_list ap;
    va_start(ap, Data);

    while ( * Data != 0 )     // �ж������Ƿ񵽴������
    {                                         
        if ( * Data == 0x5c )  //'\'
        {                                     
            switch ( *++Data )
            {
                case 'r':                                     //�س���
					ch = 0x0d;
					HAL_UART_Transmit(&huart3, (uint8_t *)&ch, 1, 0xFFFF);
					Data ++;
                break;

                case 'n':                                     //���з�
					ch = 0x0a;
					HAL_UART_Transmit(&huart3, (uint8_t *)&ch, 1, 0xFFFF);
					Data ++;
                break;

                default:
                Data ++;
                break;
            }            
        }

        else if ( * Data == '%')
        {                                     
            switch ( *++Data )
            {               
                case 's':                                         //�ַ���
                s = va_arg(ap, const char *);
                for ( ; *s; s++) 
                {
					HAL_UART_Transmit(&huart3, (uint8_t *)s, 1, 0xFFFF);
					while( __HAL_UART_GET_FLAG(&huart3, UART_FLAG_TXE) == false);
                }
                Data++;
                break;

                case 'd':           
                    //ʮ����
                d = va_arg(ap, int);
                itoa(d, buf, 10);
                for (s = buf; *s; s++) 
                {
					HAL_UART_Transmit(&huart3, (uint8_t *)s, 1, 0xFFFF);
					while( __HAL_UART_GET_FLAG(&huart3, UART_FLAG_TXE) == false);
                }
                     Data++;
                     break;
                default:
                     Data++;
                     break;
            }        
        } 
        else 
		{
			HAL_UART_Transmit(&huart3, (uint8_t *)Data, 1, 0xFFFF);
			Data++;
			while( __HAL_UART_GET_FLAG(&huart3, UART_FLAG_TXE) == false);
		}
    }
}

 