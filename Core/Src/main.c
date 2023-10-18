/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define DEF_TIMER_MS 10
#define TIMER_FOR_LED htim3
#define TIMER_FOR_BUTTON htim4
#define SCAN_PERIOD 10 //30ms
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM4_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
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
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&TIMER_FOR_LED);
  HAL_TIM_Base_Start_IT(&TIMER_FOR_BUTTON);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  //GPIO_PinState state;
  while (1)
  {

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 7200-1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 1000-1;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 7200-1;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 100-1;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_R_Pin|LED_G_Pin|LED_B_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : BUTTON_1_Pin BUTTON_2_Pin */
  GPIO_InitStruct.Pin = BUTTON_1_Pin|BUTTON_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_R_Pin LED_G_Pin LED_B_Pin */
  GPIO_InitStruct.Pin = LED_R_Pin|LED_G_Pin|LED_B_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

int effectPhase = 0;
int selectedtEffect = 0;

void effect1() {
	HAL_GPIO_TogglePin(LED_R_GPIO_Port, LED_R_Pin);
	HAL_GPIO_TogglePin(LED_G_GPIO_Port, LED_G_Pin);
	HAL_GPIO_TogglePin(LED_B_GPIO_Port, LED_B_Pin);
}

void effect2(int effectPhase) {
	int temp = effectPhase % 3;
	if(temp == 0)
		HAL_GPIO_TogglePin(LED_R_GPIO_Port, LED_R_Pin);
	else if(temp == 1)
		HAL_GPIO_TogglePin(LED_G_GPIO_Port, LED_G_Pin);
	else
		HAL_GPIO_TogglePin(LED_B_GPIO_Port, LED_B_Pin);
}

void effect3(int effectPhase) {
	int temp = effectPhase / 4;
	if(temp == 0)
		HAL_GPIO_TogglePin(LED_R_GPIO_Port, LED_R_Pin);
	else if(temp == 1)
		HAL_GPIO_TogglePin(LED_G_GPIO_Port, LED_G_Pin);
	else
		HAL_GPIO_TogglePin(LED_B_GPIO_Port, LED_B_Pin);
}

void turnOnAllLeds() {
	// set pin to 0 for turning the led on. check schematic.
	HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_RESET);
}

void toggleLeds() {
	// this function is called every 100ms

	// Check which effect is being used and execute it.
	if(selectedtEffect == 0)
		effect1();
	else if(selectedtEffect == 1)
		effect2(effectPhase);
	else
		effect3(effectPhase);

	// update effectPhase
	effectPhase = (effectPhase + 1) % 12; // there are 9 phase, 0 -> 8.
}

// button 1
GPIO_PinState lastState1 = GPIO_PIN_SET;
uint32_t holdTime1 = 0;

// button 2
GPIO_PinState lastState2 = GPIO_PIN_SET;
uint32_t holdTime2 = 0;

void checkButtons() {
	// this function is called every 10ms

	// check button 1
	GPIO_PinState state = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
	if(state == GPIO_PIN_RESET && lastState1 == GPIO_PIN_RESET) // the button is being pressed
		holdTime1 += SCAN_PERIOD; // add 10ms to holdTime1
	else if(state == GPIO_PIN_SET && lastState1 == GPIO_PIN_RESET) { // the button was released
		HAL_TIM_Base_Stop_IT(&TIMER_FOR_LED); // stop the timer to update its period.
		int newPeriod = 0;
		if(holdTime1 < 500)
			newPeriod = TIMER_FOR_LED.Instance->ARR - 100 * DEF_TIMER_MS; // newPeriod = oldPeriod - 100ms
		else
			newPeriod = TIMER_FOR_LED.Instance->ARR - holdTime1 / 200 * 100 * DEF_TIMER_MS; // giam 100ms cho moi 200ms nut duoc nhan

		// ensure new Period is between 100 and 2000ms.
		if(newPeriod > 2000 * DEF_TIMER_MS - 1)
			newPeriod = 100 * DEF_TIMER_MS;
		else if(newPeriod < 100 * DEF_TIMER_MS - 1)
			newPeriod = 2000 * DEF_TIMER_MS - 1;

		// update period and reset counter.
		__HAL_TIM_SET_AUTORELOAD(&TIMER_FOR_LED, (uint32_t)newPeriod);
		__HAL_TIM_SET_COUNTER(&TIMER_FOR_LED, 0);

		// reset holdTime and restart the timer.
		holdTime1 = 0;
		HAL_TIM_Base_Start_IT(&TIMER_FOR_LED);
	}
	lastState1 = state;

	// check button 2
	state = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
	if(state == GPIO_PIN_RESET && lastState2 == GPIO_PIN_RESET) // the button is being pressed
		holdTime2 += SCAN_PERIOD; // add 10ms to holdTime2
	else if(state == GPIO_PIN_SET && lastState2 == GPIO_PIN_RESET) { // the button was released
		if(holdTime2 < 500) {
			// change effect.
			selectedtEffect = (selectedtEffect + 1) % 3; // there are 3 effect;
			turnOnAllLeds();
			effectPhase = 0;
		}
		else {
			HAL_TIM_Base_Stop_IT(&TIMER_FOR_LED); // stop the timer to update its period.
			int newPeriod = TIMER_FOR_LED.Instance->ARR + holdTime2 / 200 * 100 * DEF_TIMER_MS; // tang 100ms cho moi 200ms nut duoc nhan

			// ensure new Period is between 100 and 2000ms.
			if(newPeriod > 2000 * DEF_TIMER_MS - 1)
				newPeriod = 100 * DEF_TIMER_MS - 1;

			__HAL_TIM_SET_AUTORELOAD(&TIMER_FOR_LED, (uint32_t)newPeriod); // update period
			__HAL_TIM_SET_COUNTER(&TIMER_FOR_LED, 0); // reset counter
			HAL_TIM_Base_Start_IT(&TIMER_FOR_LED); // restart timer
		}
		holdTime2 = 0;
	}
	lastState2 = state;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	//GPIOA->ODR = TIMER_FOR_BUTTON.Instance->ARR / (100 * DEF_TIMER_MS - 1); // only use for debugging
	if (htim == &TIMER_FOR_LED)
		toggleLeds();

	// timer4's period is 10ms
	if (htim == &TIMER_FOR_BUTTON)
		checkButtons();
}

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
