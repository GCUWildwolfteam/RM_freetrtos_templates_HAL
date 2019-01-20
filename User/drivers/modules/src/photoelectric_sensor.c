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
	|--FileName    : photoelectric_sensor.c                                                
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
#include "photoelectric_sensor.h" 
 /*---------------------------------80�ַ�����-----------------------------------*/
	 /**
	 * @Data    2019-01-12 13:24
	 * @brief   ����ʼ��
	 * @param   ���ṹ��
	 * @retval  HAL_StatusTypeDef
	 */
	 HAL_StatusTypeDef PhotoelectricInit(photoelectricStruct* ps,CAN_HandleTypeDef* hcan)
	 {
		 if(ps == NULL)
		 {
			 	return HAL_ERROR;
		 }
		 
		 ps->back = 0;
		 ps->front = 0;
		 ps->right = 0;
		 ps->left = 0;
		 ps->hcanx = hcan;
		 ps->p_addr_cache = NULL;
		 return HAL_OK;
	 }

	/*---------------------------------80�ַ�����-----------------------------------*/
		/**
		* @Data    2019-01-12 13:15
		* @brief   ������ݽ���
		* @param   void
		* @retval  void
		*/
		HAL_StatusTypeDef PhotoelectricGetInfo(photoelectricStruct* ps)
		{
				//Ҫ���ж�֡��
				CanRxMsgTypeDef* rx;
				CACHE_ADDR(rx,ps->hcanx->pRxMsg); //�õ�can���սṹ���ַ
			switch (rx->StdId)
			{
				case FRONT:
					ps->front = (int16_t)(rx->Data[0]<<8)| (rx->Data[1]);
					break;
				case BLACK:
					ps->back = (int16_t)(rx->Data[0]<<8)| (rx->Data[1]);
					break;
				case RIGHT:
					ps->right = (int16_t)(rx->Data[0]<<8)| (rx->Data[1]);
					break;
			 case LEFT:
					ps->left = (int16_t)(rx->Data[0]<<8)| (rx->Data[1]);
					break;
				default:
					break;
			}
			FREE_ADDR(rx); //�ͷŵ�ַ
			return HAL_OK;
		}
/*------------------------------------file of end-------------------------------*/


