#include "bsp.h"

void SetTime_TimeOut_Counter(u16 hTimeout);
// volatile u32 hardFault;
void bldc_table( void );

volatile u16 hBLDC_PWM_value;

void NMI_Handler(void)
{

}

void SVC_Handler(void)
{

}
void PendSV_Handler(void)
{

}
void SysTick_Handler(void)
{

}

void HardFault_Handler(void)
{
    // hardFault++;
    // StopMotorImmdly();
    NVIC_SystemReset();
} 
void SleepTimer_IRQHandler(void)
{
    // while (1)
        ;
}
void SW_IRQHandler(void)
{

}
void WAKE_IRQHandler(void)
{
    // while(1);
}
void DMA_IRQHandler(void)
{
    DMA_IF = 0x0f;
}

void HALL_IRQHandler(void)
{

}
void VC3_IRQHandler(void)
{
    // while (1)
        ;
}

void CSX_IRQHandler(void)
{
    // while (1)
        ;
}
u8 Uart0_Buff = 0;
void UART_IRQHandler(void)
{
    if ( UART_IF & UART_IF_RcvOver ){   // ��������ж�?
		UART_IF |= UART_IF_RcvOver;     // ���������ɱ�־λ
		Uart0_Buff = UART_BUFF;  // ���� 1 Byte����

        // UartAnalysis(Uart0_Buff);  
	}
    if ( UART_IF &UART_IF_SendOver ){   // ��������ж�?
        UART_IF |= UART_IF_SendOver;  // ���������ɱ�־λ
	}    
    UART_IF = 0xff;
}
 
void NSX_IRQHandler(void)
{
    // while (1)
        ;
}

void I2C_IRQHandler(void)
{
    // while (1)
        ;
}

void SPI_IRQHandler(void)
{
    // while (1)
        ;
}

u16 flag_20ms;

void TIMER0_IRQHandler(void)
{
    if(UTIMER0_IF & TIM_IRQ_IF_ZC){
        UTIMER0_IF = TIM_IRQ_IF_ZC;
        gTimeBaseFlg = 1;
        if (flag_20ms++ >= 10) {
            flag_20ms = 0;
            flex_button_scan();
        }

    }
}

void TIMER1_IRQHandler(void)
{
    if(UTIMER1_IF & TIM_IRQ_IF_ZC){
        UTIMER1_IF = TIM_IRQ_IF_ZC;
        // gTimeBaseFlg = 1;

    }
}
void TIMER2_IRQHandler(void)
{

}

void TIMER3_IRQHandler(void)
{

}

void ENCODER0_IRQHandler(void)
{
    // while (1);
}

void ENCODER1_IRQHandler(void)
{
    // while (1);
}
void GPIO_IRQHandler(void)
{
	if(EXTI_IF & GPIO_P05_EXTI_IF)
	{
    EXTI_IF = GPIO_P05_EXTI_IF;
	}
}
 

// uint8_t gUart0Send;

void ADC_IRQHandler(void)
{

}

// void ADC_IRQHandler(void)
// {
//     s32 t_pwmValue;
//     u8  l_temp;

//     ADC_IF |= BIT1 | BIT0;

//     if( ReceiveUnion.bits.RunStop ){
//         if( g_500us_cnt <= 10000 ){
//             g_500us_cnt ++;
//         }
//         else{
//             g_500us_cnt = 0 ;
//             gRunS++;
//         }
//     }
        
//     gUart0Send++;
//     if( gUart0Send >= 30 ){ //5
//         gUart0Send = 0;
//         if( fifo_read_uart( &g_send_main_uart ,&l_temp )){
//             UART_BUFF = l_temp;
//         }
//     }
//     t_pwmValue =100;
//     t_pwmValue = LimitTheSizeMinVsMax(t_pwmValue, 0, PWM_PERIOD);
//     MCPWM_TH00 = -t_pwmValue;
//     MCPWM_TH01 = t_pwmValue;
//     MCPWM_TH10 = -t_pwmValue;
//     MCPWM_TH11 = t_pwmValue;
//     MCPWM_TH20 = -t_pwmValue;
//     MCPWM_TH21 = t_pwmValue;
//     MCPWM_TMR0 = 50;
// }


void MCPWM0_IRQHandler(void)
{
    if (MCPWM_EIF & BIT5) {
        MCPWM_EIF = BIT5;
//        if (currentShortCnt < MAX_SHORT_TIME) {
//            currentShortCnt++;
//        }
    }
}
void MCPWM1_IRQHandler(void)
{


}

void CMP_IRQHandler(void)
{
    // CMP01_IF_RST();
    MCPWM_PRT = 0x0000ABCD;
    // DBG_CMP_OFF();
}

// void CMP_IRQHandler(void)
// {
//     // CMP01_IF_RST();
//     MCPWM_PRT = 0x0000ABCD;
//     // DBG_CMP_OFF();
// }




