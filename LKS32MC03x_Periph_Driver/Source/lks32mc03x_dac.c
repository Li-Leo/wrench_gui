#include "bsp.h"
void DAC_StructInit(DAC_InitTypeDef* DAC_InitStruct)
{
    memset(DAC_InitStruct, 0, sizeof(DAC_InitTypeDef));
}
void DAC_Init(DAC_InitTypeDef* DAC_InitStruct)
{
    SYS_AnalogModuleClockCmd(SYS_AnalogModule_DAC, ENABLE);  // DAC ʱ��ʹ��
    SYS_WR_PROTECT = 0x7a83;  // �����Ĵ���д����
    SYS_AFE_REG1 |= DAC_InitStruct->DACOUT_EN << 1; // DAC�����IO��ʹ������ 
    SYS_WR_PROTECT = 0xffff;  // �����Ĵ���д����
}
void DAC_OutputValue(uint32_t DACValue)
{
    s16 DAC_Offset = 0; 
    s16 DAC_Gain = 0;
    s16 temp1 = 0;
    // ����DAC 3.0V����У��ֵ
    DAC_Offset = Read_Trim(0x000001c4);
    DAC_Gain = Read_Trim(0x000001c0);
    SYS_WR_PROTECT = 0x7a83;  // �����Ĵ���д����
    if(DACValue >=255){ // �޷�
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
    SYS_WR_PROTECT = 0xffff;  // �����Ĵ���д����
}
/*******************************************************************************
 �������ƣ�    void DAC_OutputVoltage(uint32_t DACVoltage)
 ����������    DAC���ģ������ֵ����
 �����ı�    ��
 ���������    DACVoltageΪQ12��ʽ,��Χ0~4096��ӦDAC���0~3V
 ���������    ��
 �� �� ֵ��    ��
 ����˵����    03xDAC����Ϊ�̶���3.0V  8λ
               ��05x��08x��ͬ��DAC��������Ҫ��Ϊ������ٸ�ֵ���Ĵ���SYS_AFE_DAC
               y = A * x + B����DAC�����ѹ = DAC_Gain * x + DAC_Offset;
               У��ֵ�ӵ�ַ��ֱ�Ӷ�ȡ �ֱ��Ӧ0x000001c4 �� 0x000001c0;
               ����Read_Trim();��nvr.o�С�
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2022/04/18     V1.0           Zhu Jie              ����
 *******************************************************************************/
void DAC_OutputVoltage(uint16_t DACVoltage)
{
    s32 temp = 0;
    u32 range = 0;
    s16 temp1 = 0; 
    s16 DAC_Offset = 0; 
    s16 DAC_Gain = 0;

    DAC_Offset = Read_Trim(0x000001c4); // ����DAC 3.0V����У��ֵ ��Ӧ��ַ�̶�
    DAC_Gain = Read_Trim(0x000001c0);
    range = (uint16_t)((1.0/3.0)*BIT8); // BIT8 ��ʾ2^8 DACΪ8λ
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
