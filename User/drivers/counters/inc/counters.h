/**
	|-------------------------------- Copyright ----------------------------------------|
	|                                                                                   |
	|                        (C) Copyright 2018,����ƽͷ��,                              |
	|            1 Xuefu Rd, Huadu Qu, Guangzhou Shi, Guangdong Sheng, China            |
	|                            All Rights Reserved                                    |
	|                                                                                   |
	|            By(GCU The wold of team | ����������ѧ����ѧԺ������Ұ�Ƕ�)               |
	|                     https://github.com/GCUWildwolfteam                            |
	|-----------------------------------------------------------------------------------|
	|--FileName    : counters.h                                                
	|--Version     : v1.0                                                            
	|--Author      : ����ƽͷ��                                                       
	|--Date        : 2018-11-27               
	|--Description :                                                       
	|--FunctionList                                                       
	|-------1. ....                                                       
	|          <version>:                                                       
	|     <modify staff>:                                                       
	|             <data>:                                                       
	|      <description>:                                                        
	|-------2. ...                                                       
	|---------------------------------declaration of end---------------------------------|
 **/
#ifndef __COUNTERS_H 
#define __COUNTERS_H 
	#include "baseclass.h"

  #define LOCATION_MODE        0  //λ��ʽ
  #define INCREMENTAL_MODE     1  //����ʽ
  #define ER    										0x00U  		//���
  #define LAST_ER 									0x01U  		//�ϴ����
  #define BEFORE_LAST_ER   					0x02U  		//���ϴ����
	#define INTEGRAL_ER								0x03U     //����
  #define KP  											0x04U  		//����p
  #define KI 												0x05U  		//����i
  #define KD  											0x06U  		//����d
	#define TARGET 										0x07U			//Ŀ��ֵ
	#define REAL											0x08U			//��ʵֵ
	#define P_OUT											0x09U			//p���
	#define I_OUT											0x0AU			//i���
	#define D_OUT											0x0BU			//d���
	#define PID_OUT										0x0CU			//pid���
	#define LIMIT_MAX									0x0DU     //����޷�
	#define LIMIT_MIN									0x0EU     //��С�޷�
	float Bezier(int x,int y);
#endif	// __COUNTERS_H
	
 /*------------------------------------file of end------------------------------------*/

