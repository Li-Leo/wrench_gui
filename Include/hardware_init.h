 
#ifndef __HARDWARE_INIT_H_
#define __HARDWARE_INIT_H_

extern uint32_t Read_NVR(uint32_t adr);
extern void Get_NVR_Data(void);
extern volatile uint16_t Temp_B, Temp_A;
extern void Hardware_init(void);
extern void SystemInit(void);
extern void MCPWM_init(void);
extern void ADC_data_init(void);
extern void GPIO_init_ex(void);
extern volatile uint16_t TH_MAX ;
extern volatile uint16_t led_duty ;

#endif
 
