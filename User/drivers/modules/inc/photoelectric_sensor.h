/**
	|-------------------------------- Copyright -----------------------------------|
	|                                                                              |
	|                        (C) Copyright 2019,����ƽͷ��,                         |
	|            1 Xuefu Rd, Huadu Qu, Guangzhou Shi, Guangdong Sheng, China       |
	|                            All Rights Reserved                               |
	|                                                                              |
	|            By(GCU The wold of team | ��������ѧ����ѧԺ������Ұ�Ƕ�)          |
	|                     https://github.com/GCUWildwolfteam                       |
	|------------------------------------------------------------------------------|
	|--FileName    : photoelectric_sensor.h                                                
	|--Version     : v1.0                                                            
	|--Author      : ����ƽͷ��                                                       
	|--Date        : 2019-01-12               
	|--Libsupports : STM32CubeF1 Firmware Package V1.6.0(�ñ�Ŀ�����������)
	|--Description :                                                       
	|--FunctionList                                                       
	|-------1. ....                                                       
	|          <version>:                                                       
	|     <modify staff>:                                                       
	|             <data>:                                                       
	|      <description>:                                                        
	|-------2. ...                                                       
	|---------------------------------declaration of end----------------------------|
 **/
#ifndef __PHOTOELECTRIC_SENSOR_H 
#define __PHOTOELECTRIC_SENSOR_H 
	#include "baseclass.h"
	#include "can.h"

	/* ----------------- ���ṹ�� -------------------- */
		typedef struct
		{
			int16_t front; 
			int16_t back;
			int16_t right;
			int16_t left;
			CAN_HandleTypeDef* hcanx; //����can���͵�ַ
			void* p_addr_cache;      //��ʱ��ַ���棬����һ��Ҫָ�գ�Σ�գ�
			
		}photoelectricStruct;
	/* ----------------- ���ID�� -------------------- */
		#define FRONT 1   //ǰ
		#define LEFT  2 	//��
		#define BLACK 3 	//��
		#define RIGHT 4 	//��
	HAL_StatusTypeDef PhotoelectricInit(photoelectricStruct* ps,CAN_HandleTypeDef* hcan);
	HAL_StatusTypeDef PhotoelectricGetInfo(photoelectricStruct* ps);
#endif	// __PHOTOELECTRIC_SENSOR_H
	
 /*------------------------------------file of end-------------------------------*/


