#include "bsp.h"


/*******************************************************************************
 函数名称：    void ADC_Init(ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct)
 功能描述：    ADC初始化
 操作的表：    无
 输入参数：    无
 输出参数：    无
 返 回 值：    无
 其它说明：
 修改日期      版本号          修改人            修改内容
 -----------------------------------------------------------------------------
2021/10/14    V1.0             HMG               创建
 *******************************************************************************/
void ADC_Init(ADC_TypeDef *ADCx, ADC_InitTypeDef *ADC_InitStruct)
{
    uint16_t t_reg;

    SYS_AnalogModuleClockCmd(SYS_AnalogModule_ADC, ENABLE); // ADC模块使能

    if(ADC_InitStruct->ADC_SAMP_CLK > 4){      
        t_reg = ADC_InitStruct->ADC_SAMP_CLK - 4;
    }
    else{
        t_reg = 0;
    }
    SYS_PROTECT = 0x7A83;    //解除系统寄存器写保护
    SYS_AFE_REG2 = (t_reg << 8); //设置ADC采样时间

    SYS_WR_PROTECT = 0;    //使能系统寄存器写保护
		
    ADCx->IE = ADC_InitStruct->IE;

    t_reg = (ADC_InitStruct->Align << 10) | (ADC_InitStruct->Trigger_En) | (ADC_InitStruct->SEL_En << 12) |
            (ADC_InitStruct->Trigger_Cnt << 4) | (ADC_InitStruct->Trigger_Mode << 8);
    ADCx->CFG = t_reg;

    ADCx->CHNT0 = ADC_InitStruct->FirSeg_Ch | (ADC_InitStruct->SecSeg_Ch << 4) |
                  (ADC_InitStruct->ThrSeg_Ch << 8) | (ADC_InitStruct->FouSeg_Ch << 12);

    ADC_LTH = ADC_InitStruct->ADC_GEN_LTH;

    ADC_HTH = ADC_InitStruct->ADC_GEN_HTH;

    ADC_GEN = ADC_InitStruct->ADC_GEN_En;

    SYS_WR_PROTECT = 0x7a83;   /* 解除系统寄存器写保护 */
    SYS_AFE_REG1 |= ADC_InitStruct->REFOUT_EN << 6;
    SYS_WR_PROTECT = 0;        /* 开启系统寄存器写保护 */
}

/*******************************************************************************
 函数名称：    void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct)
 功能描述：    ADC结构体初始化
 操作的表：    无
 输入参数：    无
 输出参数：    无
 返 回 值：     无
 其它说明：
 修改日期      版本号          修改人            修改内容
 -----------------------------------------------------------------------------
2021/10/14    V1.0             HMG               创建
 *******************************************************************************/
void ADC_StructInit(ADC_InitTypeDef *ADC_InitStruct)
{
    ADC_InitStruct->IE = 0;
    ADC_InitStruct->Align = 0;
    ADC_InitStruct->Con_Sample = 0;
    ADC_InitStruct->Trigger_Cnt = 0;
    ADC_InitStruct->FirSeg_Ch = 0;
    ADC_InitStruct->SecSeg_Ch = 0;
    ADC_InitStruct->ThrSeg_Ch = 0;
    ADC_InitStruct->FouSeg_Ch = 0;
    ADC_InitStruct->Trigger_Mode = 0;
    ADC_InitStruct->Trigger_En = 0;
    ADC_InitStruct->SEL_En = 0;
    ADC_InitStruct->ADC_GEN_En = 0;
    ADC_InitStruct->ADC_GEN_HTH = 0;
    ADC_InitStruct->ADC_GEN_LTH = 0;
	  ADC_InitStruct->REFOUT_EN = DISABLE;
}



