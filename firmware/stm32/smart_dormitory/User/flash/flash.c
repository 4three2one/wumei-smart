/****************************************Copyright (c)****************************************************
**     
** File name:               humi.c
** Created by:              Brown Lee
** Created date:            2020-10-16
** Version:                 v1.0
** Descriptions:            The original 
** Link address:            https://blog.csdn.net/weixin_45006076
**
*********************************************************************************************************/

#include "flash.h"

//��ָ����ַ��ʼ��ȡ�������
void FLASH_ReadMoreData(uint32_t startAddress,uint16_t *readData,uint16_t countToRead)
{
  uint16_t dataIndex;
  for(dataIndex=0;dataIndex<countToRead;dataIndex++)
  {
    readData[dataIndex]=FLASH_ReadHalfWord(startAddress+dataIndex*2);
  }
}

//��ȡָ����ַ�İ���(16λ����)
uint16_t FLASH_ReadHalfWord(uint32_t address)
{
  return *(__IO uint16_t*)address; 
}

//��ȡָ����ַ��ȫ��(32λ����)
uint32_t FLASH_ReadWord(uint32_t address)
{
  uint32_t temp1,temp2;
  temp1=*(__IO uint16_t*)address; 
  temp2=*(__IO uint16_t*)(address+2); 
  return (temp2<<16)+temp1;
}

//��ָ����ַ��ʼд��������
void FLASH_WriteMoreData(uint32_t startAddress, uint16_t *writeData, uint16_t countToWrite)
{
	uint32_t dataIndex;
	FLASH_EraseInitTypeDef User_Flash;  //���� FLASH_EraseInitTypeDef �ṹ��Ϊ User_Flash
	
  if(startAddress < FLASH_BASE || ((startAddress+countToWrite * 2) >= (FLASH_BASE + 1024 * FLASH_SIZE)))
  {
    return;//�Ƿ���ַ
  }
  HAL_FLASH_Unlock();         //����д����
//  offsetAddress=startAddress-FLASH_BASE;               //����ȥ��0X08000000���ʵ��ƫ�Ƶ�ַ
//  sectorPosition=offsetAddress/FLASH_SIZE;            //����������ַ������STM32F103VET6Ϊ0~255
//  
//  sectorStartAddress=sectorPosition*SECTOR_SIZE+FLASH_BASE;    //��Ӧ�������׵�ַ

	HAL_FLASH_Unlock();               //����Flash
		
	User_Flash.TypeErase = FLASH_TYPEERASE_PAGES;  //����Flashִ��ҳ��ֻ����������
	User_Flash.PageAddress = startAddress;  //����Ҫ�����ĵ�ַ
	User_Flash.NbPages = 1;                        //˵��Ҫ������ҳ�����˲���������Min_Data = 1��Max_Data =(���ҳ��-��ʼҳ��ֵ)֮���ֵ
		
	uint32_t PageError = 0;                    //����PageError,������ִ�����������ᱻ����Ϊ�����FLASH��ַ
	HAL_FLASHEx_Erase(&User_Flash, &PageError);  //���ò�����������

	for(dataIndex=0;dataIndex<countToWrite;dataIndex++)
  {
    HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD,startAddress+dataIndex*2,writeData[dataIndex]);
  }
	
  HAL_FLASH_Lock();//����д����
}

