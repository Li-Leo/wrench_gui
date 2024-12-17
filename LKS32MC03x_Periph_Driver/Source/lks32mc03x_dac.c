#include "bsp.h"
void DAC_StructInit(DAC_InitTypeDef* DAC_InitStruct)
{
    memset(DAC_InitStruct, 0, sizeof(DAC_InitTypeDef));
}
void DAC_Init(DAC_InitTypeDef* DAC_InitStruct)
{
    SYS_AnalogModuleClockCmd(SYS_AnalogModule_DAC, ENABLE);  // DAC 时钟使能
    SYS_WR_PROTECT = 0x7a83;  // 解锁寄存器写保护
    SYS_AFE_REG1 |= DAC_InitStruct->DACOUT_EN << 1; // DAC输出至IO口使能配置 
    SYS_WR_PROTECT = 0xffff;  // 锁定寄存器写保护
}
void DAC_OutputValue(uint32_t DACValue)
{
    s16 DAC_Offset = 0; 
    s16 DAC_Gain = 0;
    s16 temp1 = 0;
    // 加载DAC 3.0V量程校正值
    DAC_Offset = Read_Trim(0x000001c4);
    DAC_Gain = Read_Trim(0x000001c0);
    SYS_WR_PROTECT = 0x7a83;  // 解锁寄存器写保护
    if(DACValue >=255){ // 限幅
        DACValue = 255;
    }
    temp1 = (s16)(DACValue * DAC_Gain >> 9 )+ (s16)DAC_Offset ;
    if(temp1 < 0){
        temp1 = 0;
    }
    else if(temp1 > 255){
        temp1 = 255;
    }
    SYS_AFE_DAC = (u32)temp1;
    SYS_WR_PROTECT = 0xffff;  // 锁定寄存器写保护
}
/*******************************************************************************
 函数名称：    void DAC_OutputVoltage(uint32_t DACVoltage)
 功能描述：    DAC输出模拟量数值设置
 操作的表：    无
 输入参数：    DACVoltage为Q12格式,范围0~4096对应DAC输出0~3V
 输出参数：    无
 返 回 值：    无
 其它说明：    03xDAC量程为固定的3.0V  8位
               与05x和08x不同，DAC数字量需要人为计算后再赋值给寄存器SYS_AFE_DAC
               y = A * x + B，即DAC输出电压 = DAC_Gain * x + DAC_Offset;
               校正值从地址中直接读取 分别对应0x000001c4 和 0x000001c0;
               函数Read_Trim();在nvr.o中。
 修改日期      版本号          修改人            修改内容
 -----------------------------------------------------------------------------
 2022/04/18     V1.0           Zhu Jie              创建
 *******************************************************************************/
void DAC_OutputVoltage(uint16_t DACVoltage)
{
    s32 temp = 0;
    u32 range = 0;
    s16 temp1 = 0; 
    s16 DAC_Offset = 0; 
    s16 DAC_Gain = 0;

    DAC_Offset = Read_Trim(0x000001c4); // 加载DAC 3.0V量程校正值 对应地址固定
    DAC_Gain = Read_Trim(0x000001c0);
    range = (uint16_t)((1.0/3.0)*BIT8); // BIT8 表示2^8 DAC为8位
    temp = (DACVoltage * range ) >> 12; 
    if(temp >=255){
        temp = 255;
    }
    temp1 = (s16)(temp * DAC_Gain >> 9) + (s16)DAC_Offset ;
    if(temp1 < 0){
        temp1 = 0;
    }
    else if(temp1 > 255){
        temp1 = 255;
    }		
    SYS_AFE_DAC = temp1;
}
