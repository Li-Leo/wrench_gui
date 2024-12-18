#include "bsp.h"


void UTimer_init(void);
void GPIO_init(void);
void GPIO_init_ex(void);
void UART1_init(void);
void UART_init(void);
void delay(u16 cnt);
void Clock_Init(void);
void Hardware_init(void);
void SystemInit(void);


void SystemInit(void)
{
    Clock_Init();
}

// void PGA_Init(void)
// {
//     SYS_WR_PROTECT = 0x7A83;
//     SYS_AFE_REG0 |= BIT9 | OPA_GIAN; //开启时钟
// //    SYS_OPA_SEL = 1 ;
// }


void Clock_Init(void)
{
    u32 temp = 0;
    SYS_WR_PROTECT = 0x7a83;   /* 解除系统寄存器写保护 */
    SYS_AFE_REG0 |= BIT15;     /* BIT15:PLLPDN */
    temp = 0;
    while( temp < 200){ //0x1ffff
        temp ++ ;
        __nop();
    }    
    SYS_CLK_CFG = 0x000001ff;
    SYS_CLK_FEN = BIT1|BIT5; //开启 hall pwm tim时钟
    // BIT[9:8]:0: CLK_HS,1:PLL,2:LRC,3:LRC| BIT[7:0]CLK_DIV  | 0x1ff对应48M时钟
}

void GPIO_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_StructInit(&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_8;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIO0, &GPIO_InitStruct);

    /* P0.9-RX0, P0.7-TX0  UART0 */
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIO0, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_Pin =  GPIO_Pin_9;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIO0, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_Pin =  GPIO_Pin_10|GPIO_Pin_11;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIO0, &GPIO_InitStruct);

    GPIO_PinAFConfig(GPIO0, GPIO_PinSource_9, AF4_UART); //P0.9复用为UART_RX
    GPIO_PinAFConfig(GPIO0, GPIO_PinSource_7, AF4_UART); //P0.7复用为UART_TX

    GPIO_PinAFConfig(GPIO0, GPIO_PinSource_4, AF0_GPIO); //
    GPIO_PinAFConfig(GPIO0, GPIO_PinSource_5, AF0_GPIO); //
    GPIO_PinAFConfig(GPIO0, GPIO_PinSource_6, AF0_GPIO); //
    GPIO_PinAFConfig(GPIO0, GPIO_PinSource_8, AF0_GPIO); //
    GPIO_PinAFConfig(GPIO0, GPIO_PinSource_10, AF0_GPIO); //
    GPIO_PinAFConfig(GPIO0, GPIO_PinSource_11, AF0_GPIO); // 
/////////////////////////////////////////////////////////
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_Pin =  GPIO_Pin_6|GPIO_Pin_3;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIO1, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_Pin =  GPIO_Pin_4;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIO1, &GPIO_InitStruct);
    GPIO_PinAFConfig(GPIO1, GPIO_PinSource_3, AF0_GPIO);
    GPIO_PinAFConfig(GPIO1, GPIO_PinSource_4, AF0_GPIO);
    GPIO_PinAFConfig(GPIO1, GPIO_PinSource_6, AF0_GPIO);
}

void GPIO_init_ex(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_StructInit(&GPIO_InitStruct);

    SYS_WR_PROTECT = 0x7a83;
    SYS_IO_CFG =BIT5 | BIT6 ;

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
    GPIO_Init(GPIO1, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
    GPIO_Init(GPIO0, &GPIO_InitStruct);

    GPIO_PinAFConfig(GPIO0, GPIO_PinSource_2, AF0_GPIO );
    GPIO_PinAFConfig(GPIO1, GPIO_PinSource_9, AF0_GPIO );
}
void dealy()
{
    u32 temp = 0;
    temp = 0;
    while( temp < 200){ //0x1ffff
        temp ++ ;
        __nop();
    }   
}
void Hardware_init(void)
{
    __disable_irq();// 关闭中断  中断总开关 
    SYS_WR_PROTECT = 0x7A83;    // 解除系统寄存器写保护
    IWDG_DISABLE();             // 关闭独立看门狗使能
    FLASH_CFG |= 0x00080000;    // FLASH预取加速使能
    dealy();
    GPIO_init();
    UTimer_init();
    // UART_init();

    SYS_WR_PROTECT = 0xffff ;
    NVIC_SetPriority(TIMER0_IRQn, 2);;
    NVIC_EnableIRQ (TIMER0_IRQn);

    // NVIC_EnableIRQ(ADC_IRQn);
    // NVIC_EnableIRQ (UART_IRQn);
    // NVIC_DisableIRQ (MCPWM0_IRQn);
    __enable_irq();
}

// void UART_init(void)
// {
//     UART_InitTypeDef UART_InitStruct;

//     UART_StructInit(&UART_InitStruct);
//     UART_InitStruct.BaudRate     = 4800;                /* 设置波特率9600 */
//     UART_InitStruct.WordLength   = UART_WORDLENGTH_8b;  /* 发送数据长度8位 */
//     UART_InitStruct.StopBits     = UART_STOPBITS_1b;    /* 停止位长度1位 */
//     UART_InitStruct.FirstSend    = UART_FIRSTSEND_LSB;  /* 先发送LSB */
//     UART_InitStruct.ParityMode   = UART_Parity_NO;      /* 无奇偶校验 */
//     UART_InitStruct.RXD_INV      = DISABLE;             /* RXD电平正常输出*/
//     UART_InitStruct.TXD_INV      = DISABLE;             /* TXD电平正常输出*/
//     /*使能接收和发送完成中断*/
//     UART_InitStruct.IRQEna       = UART_IRQEna_RcvOver; 
//     UART_Init(UART0, &UART_InitStruct);
// }

void UTimer_init(void)
{
    TIM_TimerInitTypeDef TIM_InitStruct;
    TIM_TimerStrutInit(&TIM_InitStruct);        // Timer结构体变量初始化 
    TIM_InitStruct.EN = ENABLE;                 // 模块使能 
    TIM_InitStruct.CH1_MODE = TIMER_OPMode_CAP; // 设置Timer CH1为捕获模式
    TIM_InitStruct.CH1_FE_CAP_EN = DISABLE;     // Timer 通道1下降沿捕获事件使能
    TIM_InitStruct.CH1_RE_CAP_EN = DISABLE;     // Timer 通道1上升沿捕获事件使能
    TIM_InitStruct.SRC1 = TIM_SRC0_1;           // 捕获模式通道1信号来源,Timer通道1
    TIM_InitStruct.CAP1_CLR_EN = DISABLE;       // 当发生CAP1捕获事件时，清零Timer计数器
    TIM_InitStruct.TH = 48100;                  // 设置计数器计数模值 1ms
    TIM_InitStruct.FLT = 0;                     // 通道 0/1 信号滤波宽度选择，0-255 
    TIM_InitStruct.CLK_DIV = TIM_Clk_Div1;      // 设置Timer模块数据分频系数 
    TIM_InitStruct.IE = TIM_IRQ_IE_ZC;          // 使能Timer模块CH1比较中断 
    TIM_TimerInit(TIMER0, &TIM_InitStruct);
}
