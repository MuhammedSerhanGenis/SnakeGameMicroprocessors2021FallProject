/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "time.h"
#include "stdlib.h"
#include "Nokia_5110.h"
#include "string.h"
#include "dwt_delay.h"
#include "stdio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//Raws are In, PULLUP
#define R1_PORT GPIOB
#define R1_PIN GPIO_PIN_6

#define R2_PORT GPIOB
#define R2_PIN GPIO_PIN_7

#define R3_PORT GPIOB
#define R3_PIN GPIO_PIN_15

#define R4_PORT GPIOB
#define R4_PIN GPIO_PIN_14

//Columns are Output
#define C1_PORT GPIOB
#define C1_PIN GPIO_PIN_11

#define C2_PORT GPIOB
#define C2_PIN GPIO_PIN_10

#define C3_PORT GPIOC
#define C3_PIN GPIO_PIN_11

#define C4_PORT GPIOC
#define C4_PIN GPIO_PIN_10

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */
char Read_KeyPad (void)
{
	
	/* SUTUN 1 LOW DIGER SUTUNLAR HIGH */
	HAL_GPIO_WritePin (C1_PORT, C1_PIN, GPIO_PIN_RESET);  
	HAL_GPIO_WritePin (C2_PORT, C2_PIN, GPIO_PIN_SET);  
	HAL_GPIO_WritePin (C3_PORT, C3_PIN, GPIO_PIN_SET);  
	HAL_GPIO_WritePin (C4_PORT, C4_PIN, GPIO_PIN_SET);  
	

	if (!(HAL_GPIO_ReadPin (R1_PORT, R1_PIN)))   // SATIR 1 LOW ISE
	{
		while (!(HAL_GPIO_ReadPin (R1_PORT, R1_PIN)));   
		return '1';
	}
	
	if (!(HAL_GPIO_ReadPin (R2_PORT, R2_PIN)))   // SATIR 2 LOW ISE
	{
		while (!(HAL_GPIO_ReadPin (R2_PORT, R2_PIN)));  
		return '4';
	}
	
	if (!(HAL_GPIO_ReadPin (R3_PORT, R3_PIN)))   // SATIR 3 LOW ISE
	{
		while (!(HAL_GPIO_ReadPin (R3_PORT, R3_PIN)));   
		return '7';
	}
	
	if (!(HAL_GPIO_ReadPin (R4_PORT, R4_PIN)))   // SATIR 4 LOW ISE
	{
		while (!(HAL_GPIO_ReadPin (R4_PORT, R4_PIN)));   
		return '*';
	}

	
/* SUTUN 2 LOW DIGER SUTUNLAR HIGH */
	HAL_GPIO_WritePin (C1_PORT, C1_PIN, GPIO_PIN_SET);  
	HAL_GPIO_WritePin (C2_PORT, C2_PIN, GPIO_PIN_RESET); 
	HAL_GPIO_WritePin (C3_PORT, C3_PIN, GPIO_PIN_SET);  
	HAL_GPIO_WritePin (C4_PORT, C4_PIN, GPIO_PIN_SET);  


	
	if (!(HAL_GPIO_ReadPin (R1_PORT, R1_PIN)))   // SATIR 1 LOW ISE
	{
		while (!(HAL_GPIO_ReadPin (R1_PORT, R1_PIN)));   		
		return '2';
	}
	
	if (!(HAL_GPIO_ReadPin (R2_PORT, R2_PIN)))   // SATIR 2 LOW ISE
	{
		while (!(HAL_GPIO_ReadPin (R2_PORT, R2_PIN)));   
		return '5';
	}
	
	if (!(HAL_GPIO_ReadPin (R3_PORT, R3_PIN)))   // SATIR 3 LOW ISE
	{
		while (!(HAL_GPIO_ReadPin (R3_PORT, R3_PIN)));   
		return '8';
	}
	
	if (!(HAL_GPIO_ReadPin (R4_PORT, R4_PIN)))   // SATIR 4 LOW ISE
	{
		while (!(HAL_GPIO_ReadPin (R4_PORT, R4_PIN)));   
		return '0';
	}
	
	/* SUTUN 3 LOW DIGER SUTUNLAR HIGH */
	HAL_GPIO_WritePin (C1_PORT, C1_PIN, GPIO_PIN_SET);  
	HAL_GPIO_WritePin (C2_PORT, C2_PIN, GPIO_PIN_SET);  
	HAL_GPIO_WritePin (C3_PORT, C3_PIN, GPIO_PIN_RESET);  
	HAL_GPIO_WritePin (C4_PORT, C4_PIN, GPIO_PIN_SET);  


	if (!(HAL_GPIO_ReadPin (R1_PORT, R1_PIN)))   // SATIR 1 LOW ISE
	{
		while (!(HAL_GPIO_ReadPin (R1_PORT, R1_PIN)));   
		return '3';
	}
	
	if (!(HAL_GPIO_ReadPin (R2_PORT, R2_PIN)))   // SATIR 2 LOW ISE
	{
		while (!(HAL_GPIO_ReadPin (R2_PORT, R2_PIN)));   
		return '6';
	}
	
	if (!(HAL_GPIO_ReadPin (R3_PORT, R3_PIN)))   // SATIR 3 LOW ISE
	{
		while (!(HAL_GPIO_ReadPin (R3_PORT, R3_PIN)));   
		return '9';
	}
	
	if (!(HAL_GPIO_ReadPin (R4_PORT, R4_PIN)))   // SATIR 4 LOW ISE
	{
		while (!(HAL_GPIO_ReadPin (R4_PORT, R4_PIN)));   
		return '#';
	}

	
			
	/* SUTUN 4 LOW DIGER SUTUNLAR HIGH */
	HAL_GPIO_WritePin (C1_PORT, C1_PIN, GPIO_PIN_SET);  
	HAL_GPIO_WritePin (C2_PORT, C2_PIN, GPIO_PIN_SET);  
	HAL_GPIO_WritePin (C3_PORT, C3_PIN, GPIO_PIN_SET);  
	HAL_GPIO_WritePin (C4_PORT, C4_PIN, GPIO_PIN_RESET);  

	
	if (!(HAL_GPIO_ReadPin (R1_PORT, R1_PIN)))   // SATIR 1 LOW ISE
	{
		while (!(HAL_GPIO_ReadPin (R1_PORT, R1_PIN)));   
		return 'A';
	}
	
	if (!(HAL_GPIO_ReadPin (R2_PORT, R2_PIN)))   // SATIR 2 LOW ISE
	{
		while (!(HAL_GPIO_ReadPin (R2_PORT, R2_PIN)));   
		return 'B';
	}
	
	if (!(HAL_GPIO_ReadPin (R3_PORT, R3_PIN)))  // SATIR 3 LOW ISE
	{
		while (!(HAL_GPIO_ReadPin (R3_PORT, R3_PIN)));   
		return 'C';
	}
	
	if (!(HAL_GPIO_ReadPin (R4_PORT, R4_PIN)))   // SATIR 4 LOW ISE
	{
		return 'D';  //BASILI TUTULDUGU SURECE D ALGILANMASI ICIN WHILE'I KALDIRDIM.
	}

	return 0;

}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */

char alaneleman[100];
int zorluk=1;
int skor=0;
float sure=0;
int x=6;
int y=14;
char alan[100][100];
int tus=0;
int i;
int k;
int pass=0;
int yilan_x=3;
int yilan_y=6;
int yilan_boy=0;
int yon=4;//yon 1=yukari,yon 2=asagi,yon 3=sol,yon 4=sag ;
	int yilanx[49];
	int yilany[49];
	void duvar(int i,int k)
{
	
	for(i=0;i<=x;i++)
		{
			for(k=0;k<=y;k++)
			{
				
				alan[i][k]=' ';

			}
		
			
			
		}
	for(i=0;i<=x;i++)
		{
			for(k=0;k<=y;k++)
			{
				
			
					if(i==1)
				{
						alan[i][k]='X';
					
				}
			if(i==6)
				{
						alan[i][k]='X';
					
				}
		
						if(k==1)
				{
						alan[i][k]='X';
					
				}
			if(k==14)
				{
						alan[i][k]='X';
					
				}
			
		
				
				
			}
			
			
		}
}

void kuyruk(int x,int y)
{
	for(int ik=48;ik>=1;ik--){
	
	yilanx[ik]=yilanx[ik-1];
	yilany[ik]=yilany[ik-1];
	}
	yilanx[0]=x;
	yilany[0]=y;
}

   
void yilan(int yilan_x,int yilan_y)
{
	alan[yilan_x][yilan_y]='O';
	for(i=0;i<yilan_boy;i++)
	alan[yilanx[i]][yilany[i]]='*';
	
		
	
}
int yedi=0;
void cizdir(int i,int k)
{
	
	
	
	
	
		for(i=1;i<=x;i++)
		{
			for(k=1;k<=y;k++)
			{
				NOKIA_Out(i,k,&alan[i][k]);
			}

		}
	
}
int restart=1;
  int elma_okey=1;
	int sol=0;
	int sag=0;
	int ust=0;
	int asagi=0;
	int xe = 3;
	int ye = 3;
	int carpti_mi=0;
  char key;


int main(void)
{
	HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
	
	NOKIA_Init();
	NOKIA_Contrast(50);
	DWT_Init();
	
	
	
	
  /* USER CODE BEGIN 1 */
	
	NOKIA_Out(2,2,"Ogulcan Col");
	NOKIA_Out(3,2,"Serhan Genis");
	HAL_Delay(3000);
	NOKIA_Clear();
	
	while(1)
	{
	key = Read_KeyPad();
	NOKIA_Out(2,2,"zorluk secinz:");
	NOKIA_Out(3,2,"kolay(1)");
	NOKIA_Out(4,2,"orta(2)");
	NOKIA_Out(5,2,"zor(3)");
	if(key=='1'){
  zorluk=1;	
	NOKIA_Clear();
	NOKIA_Out(3,2,"zorluk 1");	
  HAL_Delay(3000);
		NOKIA_Clear();
		break;
	}
	if(key=='2'){
  zorluk=2;	
	NOKIA_Clear();
	NOKIA_Out(3,2,"zorluk 2");	
  HAL_Delay(3000);
		NOKIA_Clear();
		break;
	}
	if(key=='3'){
  zorluk=3;	
	NOKIA_Clear();
	NOKIA_Out(3,2,"zorluk 3");	
  HAL_Delay(3000);
		NOKIA_Clear();
		break;
	}
}
	

  /* USER CODE END 2 */
 duvar(i,k);
	  alan[xe][ye]='A';
		yilan(yilan_x,yilan_y);
		cizdir(i,k);
		HAL_Delay(1000/zorluk);
    NOKIA_Clear();
    yilanx[0]=yilan_x;
    yilany[0]=yilan_y;
char scr[50];
char time[50];

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		key=Read_KeyPad();
		
    /* USER CODE END WHILE */

			if(yilan_x==1||yilan_x==6||yilan_y==1 || yilan_y==14) 
	{ 
	
	 carpti_mi=1;
	 duvar(i,k);
	 yilan(yilan_x,yilan_y);
	 cizdir(i,k);
	HAL_Delay(200);
	NOKIA_Clear();
	HAL_Delay(200);
	 duvar(i,k);
	 yilan(yilan_x,yilan_y);
	 cizdir(i,k);
	HAL_Delay(200);
	NOKIA_Clear();
	HAL_Delay(200);
	 duvar(i,k);
	 yilan(yilan_x,yilan_y);
	 cizdir(i,k);
	 HAL_Delay(200);
	NOKIA_Clear();
HAL_Delay(200);
	 duvar(i,k);
	 yilan(yilan_x,yilan_y);
	 cizdir(i,k);
	 NOKIA_Clear();
	 NOKIA_Out(2,2,"OYUN BITTI !");
	 NOKIA_Out(4,2,"SKOR:");
	 sprintf(scr,"%d",skor);
	 NOKIA_Out(4,7,scr);
	 NOKIA_Out(5,2,"SURE:");
	 sprintf(time,"%.2f",sure);
	 NOKIA_Out(5,7,time);
	 HAL_Delay(5000);
	 
   break;
	}   
	
	for(i=0;i<yilan_boy;i++)
	{
	
	if(yilan_x==yilanx[i]&&yilan_y==yilany[i] )
	{
		carpti_mi=1;
	}
	
}

if(carpti_mi)
{
	 
   duvar(i,k);
	 yilan(yilan_x,yilan_y);
	 cizdir(i,k);
	 HAL_Delay(200);
	 NOKIA_Clear();
	 HAL_Delay(200);
	 duvar(i,k);
	 yilan(yilan_x,yilan_y);
	 cizdir(i,k);
	 HAL_Delay(200);
	 NOKIA_Clear();
	 HAL_Delay(200);
	 duvar(i,k);
	 yilan(yilan_x,yilan_y);
	 cizdir(i,k);
	 HAL_Delay(200);
	 NOKIA_Clear();
	 HAL_Delay(200);
	 duvar(i,k);
	 yilan(yilan_x,yilan_y);
	 cizdir(i,k);
 	 NOKIA_Clear();
	 NOKIA_Out(2,2,"OYUN BITTI !");
	 NOKIA_Out(4,2,"SKOR:");
	 sprintf(scr,"%d",skor);
	 NOKIA_Out(4,7,scr);
	 NOKIA_Out(5,2,"SURE:");
	 sprintf(time,"%d",sure);
	 NOKIA_Out(5,7,time);
	 
	 HAL_Delay(5000);
	 break;
	
}


                    kuyruk(yilan_x,yilan_y);
                    
    
    
    if(yilan_x==xe&&yilan_y==ye)
	{
		  NOKIA_Clear();
    	yedi=1;	
    	skor++;
    	yilan_boy++;
    	
	}
	pass=0;
	
	switch(key)
	{
		case '8':
	  if(sag!=1){
		sol=1;
    sag=0;
	  ust=0;
		asagi=0;
					 
					 
    yilan_x=yilan_x-1;
                    
		duvar(i,k);

					
					if(yedi==1){
					
             		elma_okey=1;
	 				while(elma_okey){
	 						elma_okey=0;
	 					xe = rand()%4+2;
						ye = rand()%12+2;
						
						for(i=0;i<=yilan_boy;i++)
                   		{
							if((xe==yilanx[i]&&ye==yilany[i]))
								{ elma_okey=1;
									xe = rand()%4+2;
						           ye = rand()%12+2;
								}	
					 
						}
					}
				
					alan[xe][ye]='A';	
					}
					
					else{
						alan[xe][ye]='A';
					}
					yon=1;
					yilan(yilan_x,yilan_y);
					cizdir(i,k);
					HAL_Delay(500/zorluk);
          NOKIA_Clear();
          pass=1;
					}
         break;
					
				case '0': 
					 if(sol!=1){
					 sag=1;
	         sag=0;
					 ust=0;
					 asagi=0;
					 yilan_x=yilan_x+1;
           duvar(i,k); 
    	            
    	            
                       if(yedi==1){
                       	
			    elma_okey=1;
	 				while(elma_okey){
	 					elma_okey=0;
	 					xe = rand()%4+2;
						ye = rand()%12+2;
						
						for(i=0;i<=yilan_boy;i++)
                   		{
							if((xe==yilanx[i]&&ye==yilany[i]))
								{ elma_okey=1;
									xe = rand()%4+2;
						      ye = rand()%12+2;
								}	
					 
						}
					}
					alan[xe][ye]='A';	
					}
					
					
					else{
						alan[xe][ye]='A';
					}
                          yon=2;
						  yilan(yilan_x,yilan_y);
                        cizdir(i,k);
			HAL_Delay(500/zorluk);
                     	NOKIA_Clear();
                     	pass=1;
					 }                   	
                    	
                        break;
					
					
					case '#':

					 if(ust!=1){
					 sol=0;
	                 sag=0;
					 ust=0;
					 asagi=1;
					 	yilan_y=yilan_y+1;
				      	yon=4;
                         duvar(i,k);
    	            
    	            
    	            
    	            
                        if(yedi==1){

	 				elma_okey=1;
	 				while(elma_okey){
	 					elma_okey=0;
	 					xe = rand()%4+2;
						ye = rand()%12+2;
						
						for(i=0;i<=yilan_boy;i++)
                   		{
							if((xe==yilanx[i]&&ye==yilany[i]))
								{ elma_okey=1;
									xe = rand()%4+2;
						           ye = rand()%12+2;
								}	
					 
						}
					}
				
					alan[xe][ye]='A';	
					}
					else{
						alan[xe][ye]='A';
					}
                         yilan(yilan_x,yilan_y);
						cizdir(i,k);
					  HAL_Delay(500/zorluk);
                     NOKIA_Clear();
                     	pass=1;
					 }
					 					 
				      	
                        break;
					
					case '*':
					 if(asagi!=1){
					 sol=0;
	                 sag=0;
					 ust=1;
					 asagi=0;
    	            

    	            
					if(yedi==1){
						
	 				elma_okey=1;
	 				while(elma_okey){
	 						elma_okey=0;
	 					xe = rand()%4+2;
						ye = rand()%12+2;
						
						for(i=0;i<=yilan_boy;i++)
                   		{
							if((xe==yilanx[i]&&ye==yilany[i]))
								{ elma_okey=1;
									xe = rand()%4+2;
						           ye = rand()%12+2;
								}	
					 
						}
					}
					alan[xe][ye]='A';	
					}
					else{
						alan[xe][ye]='A';
					}
					yilan_y=yilan_y-1;
					yon=3;
                         duvar(i,k);
                         yilan(yilan_x,yilan_y);
						cizdir(i,k); 
                      HAL_Delay(500/zorluk);
                     	NOKIA_Clear();
                     	pass=1;
					 }	
					
						 break;
						 
					
				}
	if(!pass){
	
if(yon==1){
	
	 yilan_x=yilan_x-1;
	 duvar(i,k);
	 
    	            
	 	if(yedi==1){

	 				elma_okey=1;
	 				while(elma_okey){
	 						elma_okey=0;
	 					xe = rand()%4+2;
						ye = rand()%12+2;
						
						for(i=0;i<=yilan_boy;i++)
                   		{
							if((xe==yilanx[i]&&ye==yilany[i]))
								{ elma_okey=1;
									xe = rand()%4+2;
						           ye = rand()%12+2;
								}	
					 
						}
					}
					alan[xe][ye]='A';	
					}
					else{
						alan[xe][ye]='A';
					}
	 yilan(yilan_x,yilan_y);
	 cizdir(i,k);
HAL_Delay(500/zorluk);
NOKIA_Clear();
}
if(yon==2){
	
	 yilan_x=yilan_x+1;
	 duvar(i,k);
	 
    	            
	 	if(yedi==1){

	 				elma_okey=1;
	 				while(elma_okey){
	 					elma_okey=0;
	 					xe = rand()%4+2;
						ye = rand()%12+2;
						
						for(i=0;i<=yilan_boy;i++)
                   		{
							if((xe==yilanx[i]&&ye==yilany[i]))
								{ elma_okey=1;
									xe = rand()%4+2;
						           ye = rand()%12+2;
								}	
					 
						}
					}
					alan[xe][ye]='A';	
					}
					else{
						alan[xe][ye]='A';
					}
	yilan(yilan_x,yilan_y);
	 cizdir(i,k);
HAL_Delay(500/zorluk);
NOKIA_Clear();
}
if(yon==4){
	
	 yilan_y=yilan_y+1;
	 duvar(i,k);
    	            
    	            
	 	if(yedi==1){
	 		
	 				elma_okey=1;
	 				while(elma_okey){
	 					elma_okey=0;
	 					xe = rand()%4+2;
						ye = rand()%12+2;
						
						for(i=0;i<=yilan_boy;i++)
                   		{
							if((xe==yilanx[i]&&ye==yilany[i]))
								{ elma_okey=1;
									xe = rand()%4+2;
						           ye = rand()%12+2;
								}	
					 
						}
					}
					alan[xe][ye]='A';	
					}
					else{
						alan[xe][ye]='A';
					}
	yilan(yilan_x,yilan_y);
	 cizdir(i,k);
HAL_Delay(500/zorluk);
NOKIA_Clear();
}
if(yon==3){
	
	 yilan_y=yilan_y-1;
	 duvar(i,k);
    	            
    	            
	 	if(yedi==1){
	 		
	 				elma_okey=1;
	 				while(elma_okey){
	 						elma_okey=0;
	 					xe = rand()%4+2;
						ye = rand()%12+2;
						
						for(i=0;i<=yilan_boy;i++)
                   		{
							if((xe==yilanx[i]&&ye==yilany[i]))
								{ elma_okey=1;
									xe = rand()%4+2;
						           ye = rand()%12+2;
								}	
					 
						}
					}
	 				
	 				
	 				

					alan[xe][ye]='A';	
					}
					else{
						alan[xe][ye]='A';
					}
	yilan(yilan_x,yilan_y);
	 cizdir(i,k);
HAL_Delay(500/zorluk);
NOKIA_Clear();
}


}
 
yedi=0;

if(zorluk==3)
{
 sure=sure+2.0/zorluk;
}	
	
if(zorluk==2)
{
 sure=sure+1.5/zorluk;
}	
if(zorluk==1)
{
 sure=sure+1.0/zorluk;
}	
		
    /* USER CODE BEGIN 3 */
  /* USER CODE END 3 */
}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	 //if(htim->Instance == htim2.Instance) sure=sure+1;
	
}
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 15999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 999;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_7|GPIO_PIN_13
                          |GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5|GPIO_PIN_10|GPIO_PIN_11, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA4 PA5 PA7 PA13
                           PA14 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_7|GPIO_PIN_13
                          |GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PC5 PC10 PC11 */
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_10|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PB10 PB11 PB3 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB14 PB15 PB6 PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
