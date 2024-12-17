
#ifndef __INTERRUPT_H_
#define __INTERRUPT_H_

void SleepTimer_IRQHandler(void);
void GPIO_IRQHandler      (void);
void CSX_IRQHandler       (void);
void I2C0_IRQHandler      (void);

void SleepTimer_IRQHandler(void);
void GPIO_IRQHandler(void);
void VC3_IRQHandler(void);
void CSX_IRQHandler(void);
void NSX_IRQHandler(void);
void I2C0_IRQHandler(void);
void SPI0_IRQHandler(void);
void UART0_IRQHandler(void);
void UART1_IRQHandler(void);
void HALL_IRQHandler(void);
void UTIMER0_IRQHandler(void);
void UTIMER1_IRQHandler(void);
void UTIMER2_IRQHandler(void);
void UTIMER3_IRQHandler(void);
void ENCODER0_IRQHandler(void);
void ENCODER1_IRQHandler(void);
void ADC1_IRQHandler(void);
void ADC0_IRQHandler(void);
void MCPWM_IRQHandler(void);
extern void BLDC_CommunicationOnly( void);
extern void BLDC_Communication( void);
extern void StopMotorImmdly(void);
extern void SetTime_TimeOut_Counter(u16 hTimeout);

#define MOS_ALL_CLOSE_CNT 100

extern volatile uint32_t g_low_speed , g_low_speed_old;

extern volatile s16 BUS_Vol_ADC[7] ;
extern volatile s16 BUS_BUS_ADC[7] ;
extern volatile s16 BUS_BEMF_ADC[7] ;

extern u8 t_sum_cnt ;
extern s32 t_sum ;
extern s32 t_sum_old ;
#endif


