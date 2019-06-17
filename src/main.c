/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f10x.h"
#include "stm32f1xx_nucleo.h"
#include "bmp180.h"
#include "tim2_delay.h"
			

int main(void)
{
	delay_init();
	BMP180_Init(400000);
	BMP180_ReadCalibration();
	uint32_t u_temp, u_pres, rt, rp;

	for(;;)
	{
		u_temp = BMP180_Read_UT();
		rt = BMP180_Calc_RT(u_temp);
		u_pres = BMP180_Read_PT(0);
		rp = BMP180_Calc_RP(u_pres,0);
		delay_ms(200);
	}
}
