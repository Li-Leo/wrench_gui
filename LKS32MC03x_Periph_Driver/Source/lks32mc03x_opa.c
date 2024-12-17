/*******************************************************************************
 * 版权所有 (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * 文件名称： lks32mc08x_opa.c
 * 文件标识：
 * 内容摘要： OPA运放驱动程序
 * 其它说明： 无
 * 当前版本： V 1.0
 * 作    者： 
 * 完成日期： 
 *
 * 修改记录1：
 * 修改日期：
 * 版 本 号：V 1.0
 * 修 改 人：
 * 修改内容：创建
 *
 * 修改记录2：
 * 修改日期：
 * 版 本 号：
 * 修 改 人：
 * 修改内容：
 *
 *******************************************************************************/
#include "lks32mc03x_opa.h"

/*******************************************************************************
 函数名称：    void OPA_Init(OPA_InitTypeDef* OPA_InitStruct)
 功能描述：    OPA初始化
 操作的表：    无
 输入参数：    无
 输出参数：    无
 返 回 值：    无
 其它说明：
 修改日期      版本号          修改人            修改内容
 -----------------------------------------------------------------------------
 2022/4/20      V1.0          HuangMG          创建
 *******************************************************************************/
void OPA_Init(enumOPA opa, OPA_InitTypeDef* OPA_InitStruct)
{
	uint32_t tmp1;
	SYS_WR_PROTECT = 0x7a83;   /* 解除系统寄存器写保护 */
	tmp1 = SYS_AFE_REG0;
	
	if (opa == OPA)
	{
		tmp1 &= ~(BIT0 | BIT1 | BIT5 | BIT9);
		tmp1 |= OPA_InitStruct->OPA_Gain;

		tmp1 |= OPA_InitStruct->OPA_B_EN << 5;
		
		tmp1 |= OPA_InitStruct->OPA_CLEna << 9;	
	}

	SYS_AFE_REG0 = tmp1;
	SYS_WR_PROTECT = 0x0;   /* 开启系统寄存器写保护 */
}

/*******************************************************************************
 函数名称：    void OPA_StructInit(OPA_InitTypeDef* OPA_InitStruct)
 功能描述：    OPA结构体初始化
 操作的表：    无
 输入参数：    无
 输出参数：    无
 返 回 值：    无
 其它说明：
 修改日期      版本号          修改人            修改内容
 -----------------------------------------------------------------------------
 2022/4/20      V1.0          HuangMG          创建
 *******************************************************************************/
void OPA_StructInit(OPA_InitTypeDef* OPA_InitStruct)
{
   OPA_InitStruct->OPA_Gain = PGA_GAIN_4P25;
	 OPA_InitStruct->OPA_B_EN = OPA0_IN_IP;
   OPA_InitStruct->OPA_CLEna = DISABLE;
}

/*******************************************************************************
 函数名称：    void OPA_OUT(enumOPA opa, FuncState state)
 功能描述：    OPA外部输出，输出到外部P2.7引脚
 操作的表：    无
 输入参数：    无
 输出参数：    无
 返 回 值：    无
 其它说明：
 修改日期      版本号          修改人            修改内容
 -----------------------------------------------------------------------------
 2022/4/20      V1.0          HuangMG          创建
 *******************************************************************************/
void OPA_OUT(enumOPA opa, FuncState state)
{
	SYS_WR_PROTECT = 0x7a83;   /* 解除系统寄存器写保护 */
  if(state != DISABLE)
	{
		if(opa == OPA)
		{		
		  SYS_AFE_REG0 |= 0x01<<2;
		}	
  }else{
		  SYS_AFE_REG0 &= ~(0x1<<2);
	}
	SYS_WR_PROTECT = 0x0;   /* 开启系统寄存器写保护 */
}

/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE****/
