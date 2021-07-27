/****************************************Copyright (c)****************************************************
**     
** File name:               flash.h
** Created by:              XiaoYi
** Created date:            2020-10-16
** Version:                 v1.0
** Descriptions:            The original 
** Link address:            https://blog.csdn.net/weixin_45006076
**
*********************************************************************************************************/

#ifndef __FLASH_H__
#define __FLASH_H__

#include "main.h"

#define FLASH_WRITE_START_ADDR  0x0800FC00  //���1K�����Զ������

#define FLASH_SIZE              64          //��ѡMCU��FLASH������С(��λΪK)

#if FLASH_SIZE < 256
  #define SECTOR_SIZE           1024    //�ֽ�
#else
  #define SECTOR_SIZE           2048    //�ֽ�
#endif


uint16_t FLASH_ReadHalfWord(uint32_t address);

void FLASH_ReadMoreData(uint32_t startAddress,uint16_t *readData,uint16_t countToRead);

void FLASH_WriteMoreData(uint32_t startAddress,uint16_t *writeData,uint16_t countToWrite);

#endif

