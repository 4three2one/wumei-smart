#ifndef __KEY_SCAN_H
#define __KEY_SCAN_H

#include "main.h"

#define KEY1    0x40
#define KEY2    0x41
#define KEY3    0x42

typedef enum{
	KEY_NONE_PRESS,
	KEY_SHORT_PRESS,
	KEY_LONG_PRESS,
}key_event_e;

typedef struct
{
	int enable;  // ʹ�ܣ��жϰ����Ƿ���
	int key;     // ��������
	int type;    // �������ͣ����key_event_e�ж���
}key_status_t; 
extern key_status_t key_status;


void key_init(void);

int key_scan(void);

#endif

