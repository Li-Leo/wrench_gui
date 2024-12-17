/*******************************************************************************
 * 版权所有 (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * 文件名称： Control_Param.h
 * 文件标识：
 * 内容摘要： 电机驱动底层头文件
 * 其它说明： 无
 * 当前版本： V 1.0
 * 作    者： Howlet
 * 完成日期： 2015年11月5日
 *
 * 修改记录1：
 * 修改日期：2015年11月5日
 * 版 本 号：V 1.0
 * 修 改 人：Howlet
 * 修改内容：创建
 *
 * 修改记录2：
 * 修改日期：
 * 版 本 号：
 * 修 改 人：
 * 修改内容：
 *
 *******************************************************************************/
 
/*------------------------------prevent recursive inclusion -------------------*/
#ifndef __PWM_PARAM_H
#define __PWM_PARAM_H

/* ==============================PWM 频率及死区定义=========================== */
#define PWM_MCLK	((u32)50000000uL) /* PWM模块运行主频 */
#define PWM_PRSC ((u8)0) /* PWM模块运行预分频器 */
#define PWM_FREQ ((u16)30000) /* PWM斩波频率 */
/* PWM 周期计数器值 */
#define PWM_PERIOD ((u16) (PWM_MCLK / (u32)(2 * PWM_FREQ *(PWM_PRSC+1))))

#define DEADTIME_NS0 ((u16)800)/* 死区时间 */
#define DEADTIME_NS1 ((u16)1000)/* 死区时间 */
#define DEADTIME_NS2 ((u16)1200)/* 死区时间 */
#define DEADTIME_NS3 ((u16)1400)/* 死区时间 */
#define DEADTIME_NS4 ((u16)1600)/* 死区时间 */
#define DEADTIME_NS5 ((u16)1800)/* 死区时间 */
#define DEADTIME_NS6 ((u16)2000)/* 死区时间 */
#define DEADTIME_NS7 ((u16)2200)/* 死区时间 */

#define DEADTIME0  (u16)(((unsigned long long)PWM_MCLK * (unsigned long long)DEADTIME_NS0)/1000000000uL)
#define DEADTIME1  (u16)(((unsigned long long)PWM_MCLK * (unsigned long long)DEADTIME_NS1)/1000000000uL)
#define DEADTIME2  (u16)(((unsigned long long)PWM_MCLK * (unsigned long long)DEADTIME_NS2)/1000000000uL)
#define DEADTIME3  (u16)(((unsigned long long)PWM_MCLK * (unsigned long long)DEADTIME_NS3)/1000000000uL)
#define DEADTIME4  (u16)(((unsigned long long)PWM_MCLK * (unsigned long long)DEADTIME_NS4)/1000000000uL)
#define DEADTIME5  (u16)(((unsigned long long)PWM_MCLK * (unsigned long long)DEADTIME_NS5)/1000000000uL)
#define DEADTIME6  (u16)(((unsigned long long)PWM_MCLK * (unsigned long long)DEADTIME_NS6)/1000000000uL)
#define DEADTIME7  (u16)(((unsigned long long)PWM_MCLK * (unsigned long long)DEADTIME_NS7)/1000000000uL)
   
#define MAX_MODULATION_100_PER_CENT
/* Current reading parameters ----------------------------------------------- */
///****************************此处配置ABC 相电流采样端口  end**********************************************///



///****************************此处配置总线电压  采样端口  start**********************************************///
#define VOL_BUS_ADC_CHANNEL     ADC_Channel_7   //PA_7
#define VOL_BUS_GPIO_PORT       GPIOA
#define VOL_BUS_GPIO_PIN        GPIO_Pin_7
///****************************此处配置总线电压  采样端口  end**********************************************///



#define VOLATAGE_RAMP         15 /* 0.3V/S */



/*  Power Stage management Conversions setting */

#define SPEED_CMD_CHANNEL                 ADC_Channel_3
#define SPEED_CMD_CHANNEL_GPIO_PORT       GPIOA
#define SPEED_CMD_CHANNEL_GPIO_PIN        GPIO_Pin_3


#define BUS_VOLT_FDBK_CHANNEL             ADC_Channel_7
#define BUS_VOLT_FDBK_CHANNEL_GPIO_PORT   GPIOA
#define BUS_VOLT_FDBK_CHANNEL_GPIO_PIN    GPIO_Pin_7



/////////////////////////////欠压  过压 设定部分  start////////////////////////////////
#define LOW_VOLATAGE_THD                  3000 /* 30V为欠压值 */   
#define RSM_LO_VOLATAGE_THD               3100 /* 欠压恢复电压 */
#define OV_VOLTAGE_THD                    6100 /* 过压门槛 */
#define RSM_OV_VOLTAGE_THD                5500 /* 过压恢复门槛 */
/////////////////////////////欠压  过压 设定部分  end////////////////////////////////

#define BREAK_INPUT                       (GPIOA->IDR & GPIO_Pin_12)
#define LEARN_INPUT                       (GPIOB->IDR & GPIO_Pin_1)


#endif  /*__MC_PWM_3SHUNT_PRM_H*/

/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR **********************/
/* ------------------------------END OF FILE------------------------------------ */
