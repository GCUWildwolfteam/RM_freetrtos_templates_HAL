/**
	|-------------------------------- Copyright ----------------------------------------|
	|                                                                                   |
	|                        (C) Copyright 2018,����ƽͷ��,                              |
	|            1 Xuefu Rd, Huadu Qu, Guangzhou Shi, Guangdong Sheng, China            |
	|                            All Rights Reserved                                    |
	|                                                                                   |
	|            By(GCU The wold of team | ��������ѧ����ѧԺ������Ұ�Ƕ�)               |
	|                     https://github.com/GCUWildwolfteam                            |
	|-----------------------------------------------------------------------------------|
	|--FileName    : Chassis.h                                                
	|--Version     : v1.0                                                            
	|--Author      : ����ƽͷ��                                                       
	|--Date        : 2018-12-11               
	|--Description : 1�����ֵ��� THIRD_OMNIDIRECTIONAL_WHEEL_CHASSIS ��1������0�ر�
	|								 2����ͨ��������ֵ���	MCUNAMM_WHEEL_CHASSIS ��1������0�ر�
	|								    ��ע�⣬���� ͬʱ��1������
	|								 2���õ����ļ���һ��Ҫcan.c��can.h��motor.h �������ļ�                                                 
	|--FunctionList                                                       
	|-------1. ....                                                       
	|          <version>:                                                       
	|     <modify staff>:                                                       
	|             <data>:                                                       
	|      <description>:                                                        
	|-------2. ...                                                       
	|---------------------------------declaration of end---------------------------------|
 **/
#ifndef __CHASSIS_H
	#include "motor.h" 
	#include "photoelectric_sensor.h" 
	/* ----------------- ��������ѡ��(����ȫ����1) ---------------- */
		#define THIRD_OMNIDIRECTIONAL_WHEEL_CHASSIS			 1
		#define MCUNAMM_WHEEL_CHASSIS              			 0
  /* ----------------- ���ֵ��̽ṹ�� -------------------- */
		typedef struct 
		{
				int16_t v_x;																			  //Vx�ٶ�
				int16_t v_y;																				//Vy�ٶ�
				int16_t v_w;																				//�����ٶ�

				int16_t motorspeed1;																//���1�����ٶ�
				int16_t motorspeed2;																//���2�����ٶ�
				int16_t motorspeed3;																//���3�����ٶ�

		}thirdWheelChassisStruct;
	/* -------- ���̵���ṹ�� --------- */	
		typedef struct
		{ 
	#if THIRD_OMNIDIRECTIONAL_WHEEL_CHASSIS 
		/* -------- ȫ�����ֵ��� --------- */
			thirdWheelChassisStruct thirdWheelChassis_t;//���ֵ��̽ṹ������
	#elif MCUNAMM_WHEEL_CHASSIS
	/* -------- �����ķ�ֵ��� --------- */
	#endif 
		/* -------- �̳� --------- */
			photoelectricStruct* photoelectric_t;
			CAN_HandleTypeDef* p_canx;												//��ȡcan����
			uint8_t status;                               //0�������ɹ� ���������ʧ��
			void* p_addr_cache  ;                          //��ʱ��ַ���棬����һ��Ҫָ�գ�Σ�գ�
		}chassiStruct;	
  /* -------- robomoter�������ģʽ --------- */
		HAL_StatusTypeDef ChassisClassInit(chassiStruct * cC,CAN_HandleTypeDef* hcan\
																			,photoelectricStruct* plt);
		void ChassisMotorModeInit(uint8_t mode);


		
#endif	// __CHASSIS_H
	
 /*------------------------------------file of end------------------------------------*/


