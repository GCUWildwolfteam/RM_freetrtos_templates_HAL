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
	|--FileName    : Chassis.c                                                
	|--Version     : v1.0                                                            
	|--Author      : ����ƽͷ��                                                       
	|--Date        : 2018-12-11               
	|--Description : 1�����ֵ���
	|								 2���õ����ļ�,�����motor.h��motor.c�ļ�                                                       
	|--FunctionList                                                       
	|-------1. ....                                                       
	|          <version>:                                                       
	|     <modify staff>:                                                       
	|             <data>:                                                       
	|      <description>:                                                        
	|-------2. ...                                                       
	|---------------------------------declaration of end---------------------------------|
 **/
#include "Chassis.h" 
	  /**
		* @Data    2018-12-11 20:25
		* @brief   �������ݳ�ʼ����
		* @param   chassisClass_t * cC
		* @retval  void
		*/
		HAL_StatusTypeDef ChassisClassInit(chassiStruct * cc,CAN_HandleTypeDef* hcan\
																											,photoelectricStruct* ps)
		{
		/* -------- ��⻺��ռ��Ƿ����ɹ� --------- */		
			if(cc == NULL)
	 			return HAL_ERROR;
			SET_BIT(e_objects_flag,CREATE_OBJECTS_OF_CHASSIS); //��ȡ��־
			cc->p_canx = RecognizeCanType(hcan); //ʶ��can���ͣ���can���͵�ַ
		/* -------- ��⴫ֵ --------- */
			if(cc->p_canx != hcan&&cc->p_canx ==NULL)
			{
				SET_BIT(e_periphera_error_flag,GET_CAN_ADDR_FAIL);
				return HAL_ERROR;
			}
			cc->thirdWheelChassis_t.motorspeed1= 0;
			cc->thirdWheelChassis_t.motorspeed2 = 0;
			cc->thirdWheelChassis_t.motorspeed3 = 0;
			cc->thirdWheelChassis_t.v_x = 0;
			cc->thirdWheelChassis_t.v_y = 0;
			cc->thirdWheelChassis_t.v_w = 0;
			cc->status = 0;
			cc->p_addr_cache = NULL; //���ܶ���仰��Σ�գ�
			UserCANConfig(hcan);          //can��ʼ��

			/* -------- �̳� --------- */
				cc->photoelectric_t = ps;
			/* -------- ģ���ʼ�� --------- */
				PhotoelectricInit(ps,hcan);
			return HAL_OK;
		}
  /**
	* @Data    2018-12-11 20:31
	* @brief   ���̵��ģʽ��ʼ��
	* @param   uint8_t mode ���̵������ģʽ
	* @retval  void
	*/
	void ChassisMotorModeInit(uint8_t mode)
	{
		// CAN_TRANSMIT(&hcan,0x001,mode,0,0,0); //ѡ���������ٶ�ģʽ
	}
/*------------------------------------file of end------------------------------------*/


