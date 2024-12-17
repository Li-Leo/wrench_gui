#ifndef __HARDWARE_CONFIG_H_
#define __HARDWARE_CONFIG_H_

#define MCU_MCLK	                   ((u32)48000000LL) // MCU������Ƶ 
// ==============================PWM Ƶ�ʼ���������=========================== 
#define PWM_MCLK                     ((u32)48000000LL) // PWMģ��������Ƶ 
#define PWM_PRSC                     ((u8)0) // PWMģ������Ԥ��Ƶ�� 
#define PWM_RUN_FREQ                 (u16)(10)
#define PWM_FREQ                     ((u16)(PWM_RUN_FREQ*1000)) // PWMն��Ƶ��
#define RUN_POSITION_TMR0            (u16)(400)  //jcwu  1200
// PWM ���ڼ�����ֵ
#define PWM_PERIOD                   ((u16) (PWM_MCLK / (u32)(2 * PWM_FREQ *(PWM_PRSC+1))))

#define PWM_FREQ_SEEK_POSITION      ((u16)12000) // PWMն��Ƶ��  16000 
// PWM ���ڼ�����ֵ
#define SEEK_POSITION_PLUS_WIDTH    ((u16) (PWM_MCLK / (u32)(2 * PWM_FREQ_SEEK_POSITION *(PWM_PRSC+1))))
#define SEEK_POSITION_TMR0          (u16)(1400)      // Ѱ�ҳ�ʼת��λ�ã������� 

//#define PWM_FREQ_SEEK_POSITION      ((u16)10000) // PWMն��Ƶ��  16000 
//// PWM ���ڼ�����ֵ
//#define SEEK_POSITION_PLUS_WIDTH    ((u16) (PWM_MCLK / (u32)(2 * PWM_FREQ_SEEK_POSITION *(PWM_PRSC+1))))
//#define SEEK_POSITION_TMR0          (u16)(3000)      // Ѱ�ҳ�ʼת��λ�ã������� 

#define ADC_STATE_RESET()            {ADC_CFG |= BIT11;}   // ADC0 ״̬����λ,���Լ��������ȷ��ADC����״̬
#define ADC_SOFTWARE_TRIG_ONLY()     {ADC_CFG = 0;}        // ADC����Ϊ���������

#define DEADTIME_NS                  ((u16)1000) 
#define DEADTIME                     (u16)(((unsigned long long)PWM_MCLK * (unsigned long long)DEADTIME_NS)/1000000000uL)

// ******************************ADCͨ���Ŷ���****************************************** 

#define ADC_CHANNEL_OPA0            ADC_CHANNEL_0
#define ADC_CHANNEL_OPA1            ADC_CHANNEL_1
#define ADC_CHANNEL_OPA2            ADC_CHANNEL_2
#define ADC_CHANNEL_OPA3            ADC_CHANNEL_3

#define ADC_BUS_CUR         ADC_CHANNEL_OPA0
#define ADC_PEAK_CUR        ADC_CHANNEL_OPA0

#define ADC_BUS_VOL         ADC_CHANNEL_7 
#define ADC_SPEED           ADC_CHANNEL_5
#define ADC_M0_TEM          ADC_CHANNEL_11
#define ADC_NTC_MOS         ADC_CHANNEL_3
#define ADC_NTC_BAT         ADC_CHANNEL_6

//CMP1
#define CMP1_IP0        0x00
#define OPA0_IP         0x01
#define OPA0_OUT        0x02
#define CMP1_IP1        0x03
#define CMP1_IP2        0x04
#define CMP1_IP3        0x05
//#define CMP1_AVSS_1     0x06
//#define CMP1_AVSS_2     0x07

#define CMP1_IN         0x00
#define CMP1_REF        0x01
#define DAC_OUT_CMP1    0x02
#define HALL1_MID       0x03
//CMP0
#define CMP0_IP0        0x00
#define OPA0_IP         0x01
#define OPA0_OUT        0x02
#define CMP0_IP1        0x03
#define CMP0_IP2        0x04
#define CMP0_IP3        0x05

#define CMP0_IN         0x00
#define CMP0_REF        0x01
#define DAC_OUT_CMP0    0x02
#define HALL0_MID       0x03

#define BEMF_CH_A       ADC_CHANNEL_4
#define BEMF_CH_B       ADC_CHANNEL_2
#define BEMF_CH_C       ADC_CHANNEL_1

#define CMP_IP_A        CMP0_IP3
#define CMP_IP_B        CMP0_IP1 
#define CMP_IP_C        CMP0_IP2

/////////////////////////////Ƿѹ  ��ѹ �趨����  start////////////////////////////////

//36V  10
////#define LOW_VOLATAGE_OPEN_V     31   // 42Ƿѹ��ѹ
//#define LOW_VOLATAGE_THD_V        30   // 42Ƿѹ��ѹ
//#define VERY_LOW_VOLATAGE_THD_V   28   // 26Ƿѹ��ѹ
//#define RSM_LO_VOLATAGE_THD_V     32   // 44Ƿѹ�ָ���ѹ
//#define OV_VOLTAGE_THD_V          45   // ��ѹ�ż� 65V
//#define RSM_OV_VOLTAGE_THD_V      43.5 // ��ѹ�ָ��ż� 60

//////24V --6
//#define LOW_VOLATAGE_THD_V        18   //  ������ѹ
//#define VERY_LOW_VOLATAGE_THD_V   17.5    //  Ƿѹ��ѹ
//#define RSM_LO_VOLATAGE_THD_V		20   //  Ƿѹ�ָ���ѹ
//#define OV_VOLTAGE_THD_V			32   //  ��ѹ�ż�
//#define RSM_OV_VOLTAGE_THD_V 		29   //  ��ѹ�ָ��ż�

//// 21--24V
//#define LOW_VOLATAGE_THD_V        15   // 42Ƿѹ��ѹ
//#define VERY_LOW_VOLATAGE_THD_V   14   // 26Ƿѹ��ѹ
//#define RSM_LO_VOLATAGE_THD_V     16   // 44Ƿѹ�ָ���ѹ
//#define OV_VOLTAGE_THD_V          32   // ��ѹ�ż� 65V
//#define RSM_OV_VOLTAGE_THD_V      29   // ��ѹ�ָ��ż� 60

////21V --5
//#define LOW_VOLATAGE_THD_V          13.5   // ������ѹ
//#define VERY_LOW_VOLATAGE_THD_V     12.8   // Ƿѹ��ѹ
//#define RSM_LO_VOLATAGE_THD_V		13.5   // Ƿѹ�ָ���ѹ
//#define OV_VOLTAGE_THD_V			25   // ��ѹ�ż�
//#define RSM_OV_VOLTAGE_THD_V		24   // ��ѹ�ָ��ż�

////16.8V --4
//#define LOW_VOLATAGE_THD_V          12   // ������ѹ
//#define VERY_LOW_VOLATAGE_THD_V     11.2 // Ƿѹ��ѹ
//#define RSM_LO_VOLATAGE_THD_V       13   // Ƿѹ�ָ���ѹ
//#define OV_VOLTAGE_THD_V			20   // ��ѹ�ż�
//#define RSM_OV_VOLTAGE_THD_V		19   // ��ѹ�ָ��ż�

//12V
#define LOW_VOLATAGE_THD_V        9     // ������ѹ
#define VERY_LOW_VOLATAGE_THD_V   8.0   // Ƿѹͣ��
#define RSM_LO_VOLATAGE_THD_V     9.6   // Ƿѹ�ָ���ѹ
#define OV_VOLTAGE_THD_V          15    // ��ѹ�ż�
#define RSM_OV_VOLTAGE_THD_V      14.4  // ��ѹ�ָ��ż�

#define VOLTAGE_SHUNT_RATIO               (1.0/(10+1.0))
#define VOLTAGE_SHUNT_RATIO_ex            ((10.0+1.0)/1.0)

#define VOLATAGE_ADC_MAX_V                 3.6 //2.4  3.6
#define VOL_MAX_ADC                       32768// jcwu 0X7FF
#define VOLATAGE_18V_ADC_VALUE            (u16)(VOLATAGE_18V * VOLTAGE_SHUNT_RATIO/VOLATAGE_ADC_MAX_V*VOL_MAX_ADC)
#define VERY_LOW_VOLATAGE_THD             (u16)(VERY_LOW_VOLATAGE_THD_V * VOLTAGE_SHUNT_RATIO/VOLATAGE_ADC_MAX_V*VOL_MAX_ADC)
#define LOW_VOLATAGE_THD                  (u16)(LOW_VOLATAGE_THD_V * VOLTAGE_SHUNT_RATIO/VOLATAGE_ADC_MAX_V*VOL_MAX_ADC)
#define RSM_LO_VOLATAGE_THD               (u16)(RSM_LO_VOLATAGE_THD_V * VOLTAGE_SHUNT_RATIO/VOLATAGE_ADC_MAX_V*VOL_MAX_ADC)
#define OV_VOLTAGE_THD                    (u16)(OV_VOLTAGE_THD_V * VOLTAGE_SHUNT_RATIO/VOLATAGE_ADC_MAX_V*VOL_MAX_ADC)
#define RSM_OV_VOLTAGE_THD                (u16)(RSM_OV_VOLTAGE_THD_V * VOLTAGE_SHUNT_RATIO/VOLATAGE_ADC_MAX_V*VOL_MAX_ADC)

////16.8
//#define VOLTAGE_HIGH        15      //  3
//#define VOLTAGE_MID         13.5    //  2
//#define VOLTAGE_LOW         12      //  1
//#define VOLTAGE_LOW_ex      11      //  ��˸

////21
//#define VOLTAGE_HIGH        18.8  //  3
//#define VOLTAGE_MID         17.4  //  2
//#define VOLTAGE_LOW         16.6  //  1

////21
//#define VOLTAGE_HIGH        18.8  //  3
//#define VOLTAGE_MID         17.8  //  2
//#define VOLTAGE_LOW         17.0  //  1

//12.6V
#define VOLTAGE_HIGH        11.25 //  3
#define VOLTAGE_MID         10.7  //  2
#define VOLTAGE_LOW         9.5   //  1

////12.6V
//#define VOLTAGE_HIGH        10.6 //  3
//#define VOLTAGE_MID         10.0  //  2
//#define VOLTAGE_LOW         9.0   //  1

#define VOLTAGE_HIGH_ADC_VALUE      (u16)(VOLTAGE_HIGH * VOLTAGE_SHUNT_RATIO/VOLATAGE_ADC_MAX_V*VOL_MAX_ADC)   
#define VOLTAGE_MID_ADC_VALUE       (u16)(VOLTAGE_MID * VOLTAGE_SHUNT_RATIO/VOLATAGE_ADC_MAX_V*VOL_MAX_ADC)   
#define VOLTAGE_LOW_ADC_VALUE       (u16)(VOLTAGE_LOW * VOLTAGE_SHUNT_RATIO/VOLATAGE_ADC_MAX_V*VOL_MAX_ADC)   

/////////////////////////////Ƿѹ  ��ѹ �趨����  end////////////////////////////////
#define TOTAL_CUR_RES       ( 0.001 )
#define PEAK_OPA0_RATIO     (200.0/(10.4+1.0))

#define CURRENT_ADC_MAX_V    3.6 //2.4  3.6

#define CURRENT_ADC_PER_01A       (TOTAL_CUR_RES*PEAK_OPA0_RATIO*32768/CURRENT_ADC_MAX_V) // ÿ������ADCֵ

#define CURRENT_LIM_VALUE_A             (45 )
#define CURRENT_LIM_VALUE               (s32)(CURRENT_LIM_VALUE_A * TOTAL_CUR_RES*32768*PEAK_OPA0_RATIO/CURRENT_ADC_MAX_V)

#define CURRENT_LIM_ONE_VALUE_A         (33 )         // 1���𱣻�����
#define CURRENT_LIM_ONE_TIME_MS         (PWM_RUN_FREQ*4000) // 5000ms
#define CURRENT_LIM_ONE_VALUE           (s32)(CURRENT_LIM_ONE_VALUE_A * TOTAL_CUR_RES*32768*PEAK_OPA0_RATIO/CURRENT_ADC_MAX_V)

#define CURRENT_LIM_TWO_LOAD_A          (45 )         // 2���𱣻�����
#define CURRENT_LIM_TWO_LOAD_TIME_MS    (PWM_RUN_FREQ*500)   // 500ms
#define CURRENT_LIM_TWO_LOAD_VALUE      (s32)(CURRENT_LIM_TWO_LOAD_A * TOTAL_CUR_RES*32768*PEAK_OPA0_RATIO/CURRENT_ADC_MAX_V)

#define CURRENT_LIM_THREE_LOAD_A        (55 )         // 3���𱣻�����
#define CURRENT_LIM_THREE_LOAD_TIME_MS  (PWM_RUN_FREQ*20)
#define CURRENT_LIM_THREE_LOAD_VALUE    (s32)(CURRENT_LIM_THREE_LOAD_A * TOTAL_CUR_RES*32768*PEAK_OPA0_RATIO/CURRENT_ADC_MAX_V)

#define CURRENT_LIM_FOUR_LOAD_A        (65 )         // 4���𱣻�����
#define CURRENT_LIM_FOUR_LOAD_TIME_MS  (PWM_RUN_FREQ*6)   //
#define CURRENT_LIM_FOUR_LOAD_VALUE    (s32)(CURRENT_LIM_FOUR_LOAD_A * TOTAL_CUR_RES*32768*PEAK_OPA0_RATIO/CURRENT_ADC_MAX_V)


#define CURRENT_NO_LOAD_A           (12.0)
#define CURRENT_NO_LOAD_VALUE       (s32)(CURRENT_NO_LOAD_A * TOTAL_CUR_RES/CURRENT_ADC_MAX_V*32768*PEAK_OPA0_RATIO)

#define CURRENT_RUN_MAX_A        (80.0) //jcwu 60A 70A  80
#define CURRENT_RUN_MAX_VALUE    (s32)(CURRENT_RUN_MAX_A * TOTAL_CUR_RES*32768*PEAK_OPA0_RATIO/CURRENT_ADC_MAX_V)

#define OV_mcu_TEMPER_VALUE             90.0
#define RSM_mcu_OV_TEMPER_VALUE         70.0

#define OV_ntc_mos_TEMPER_VALUE         105.0
#define OV_ntc_mos_speed_VALUE          95.0
#define RSM_ntc_mos_OV_TEMPER_VALUE     90.0

#define OV_ntc_bat_TEMPER_VALUE         75.0
#define RSM_ntc_bat_OV_TEMPER_VALUE     60.0

#define PGA_GAIN_20010      0x0000 // �������� 200:10
#define PGA_GAIN_19020      0x0001 // �������� 190:20
#define PGA_GAIN_18030      0x0002 // �������� 180:30
#define PGA_GAIN_17040      0x0003 // �������� 170:40

#define OPA_GIAN    PGA_GAIN_20010

#define DAC_MAX_48V         1
#define DAC_MAX_12V         0

#if CMP_SAFE_MODE  ==  CMP_OUT 

    #define DAC_MAX_V                       (3)

    #define CMP_CFG_RUN     ((HALL0_MID << 2)|(DAC_OUT_CMP1 << 4)|(OPA0_OUT << 12))
    // CMP0P����HALL0_MID     CMP1P����DAC      CMP1P����OPA3_OUT

    #define CURRENT_PEAK_MAX_A              (120.0)  //80A ��ͣ��
    #define CMP_CURRENT_PEAK_MAX_A_VALUE    (u32)((((CURRENT_PEAK_MAX_A * TOTAL_CUR_RES*PEAK_OPA0_RATIO)/2 + 1.9)*255)/DAC_MAX_V)

#elif CMP_SAFE_MODE == CMP_IP

    #define DAC_MAX_V                       (1.2)

    #define CMP_CFG_RUN     ((HALL0_MID << 2)|(DAC_OUT_CMP1 << 4)|(OPA0_IP << 12) )

    #define CURRENT_PEAK_MAX_A              (100.0)
    #define CMP_CURRENT_PEAK_MAX_A_VALUE    (u16)((4096* TOTAL_CUR_RES*CURRENT_PEAK_MAX_A)/DAC_MAX_V)

#endif


#if MOS_DRIVE_PWM == MOS_LOW_NO_INVERTED
    #define DRIVE_POLARITY          (0x0000)
     //three  PWM = 0X00  ON = 0X1C  ���� = 0X0C  ----ÿһ�Ŀ���3��mos��ͬ������
    #define A_OFF__B_PWM__C_ON()    { MCPWM_IO01 = 0x000C; MCPWM_IO23 = 0x0C1C ;}
    // 2_step A��ON��B��PWM C������ ����������ع����¼�  
    #define A_ON__B_PWM__C_OFF()    { MCPWM_IO01 = 0x001C; MCPWM_IO23 = 0x0C0C ;}
    // 3_step A��ON��B������ C��PWM ������½��ع����¼�  
    #define A_ON__B_OFF__C_PWM()    { MCPWM_IO01 = 0x0C1C; MCPWM_IO23 = 0x0C00 ;}
    // 4_step A�����գ�B��ON C��PWM  ����������ع����¼� 
    #define A_OFF__B_ON__C_PWM()    { MCPWM_IO01 = 0x1C0C; MCPWM_IO23 = 0x0C00 ;}
    // 5_step A��PWM��B��ON C������  ������½��ع����¼� 
    #define A_PWM__B_ON__C_OFF()    { MCPWM_IO01 = 0x1C00; MCPWM_IO23 = 0x0C0C ;}
    // 6_step A��PWM��B������ C ON����������ع����¼�  
    #define A_PWM__B_OFF__C_ON()    { MCPWM_IO01 = 0x0C00; MCPWM_IO23 = 0x0C1C ;}

    #define ABC_ALL_ON()            { MCPWM_IO01 = 0x1C1C; MCPWM_IO23 = 0x1C1C ;}
    #define ABC_ALL_SOFT()          { MCPWM_IO01 = 0X0808; MCPWM_IO23 = 0X0808 ;}
    #define ABC_ALL_OFF()           { MCPWM_IO01 = 0X0C0C; MCPWM_IO23 = 0X0C0C ;}
    #define MOS_ALL_OFF             0X0C0C

    #define C_HPWM_LOFF_AB_OFF()    { MCPWM_IO01 = 0X0C0C; MCPWM_IO23 = 0X0404 ;}
    #define DIS_HPWM_FUNC()     {MCPWM_PRT = 0x0000DEAD;MCPWM_IO01 = 0x0808;MCPWM_IO23 = 0x0008;MCPWM_PRT = 0x0000CAFE;}
    #define EN_HPWM_FUNC()      {MCPWM_PRT = 0x0000DEAD;MCPWM_IO01 = 0x0101;MCPWM_IO23 = 0x0101;MCPWM_PRT = 0x0000CAFE;}

#elif MOS_DRIVE_PWM == MOS_LOW_INVERTED
    #define DRIVE_POLARITY          (0x0101)
     //three  PWM = 0X01  ON = 0X1D  ���� = 0X0D----ÿһ�Ŀ���3��mos��ͬ������
     //1_step A�����գ�B��PWM C��ON ������½��ع����¼�  
    #define A_OFF__B_PWM__C_ON()    { MCPWM_IO01 = 0x010D; MCPWM_IO23 = 0x0D1D ;}
    // 2_step A��ON��B��PWM C������ ����������ع����¼�  
    #define A_ON__B_PWM__C_OFF()    { MCPWM_IO01 = 0x011D; MCPWM_IO23 = 0x0D0D ;}
    // 3_step A��ON��B������ C��PWM ������½��ع����¼�  
    #define A_ON__B_OFF__C_PWM()    { MCPWM_IO01 = 0x0D1D; MCPWM_IO23 = 0x0D01 ;}
    // 4_step A�����գ�B��ON C��PWM  ����������ع����¼� 
    #define A_OFF__B_ON__C_PWM()    { MCPWM_IO01 = 0x1D0D; MCPWM_IO23 = 0x0D01 ;}
    // 5_step A��PWM��B��ON C������  ������½��ع����¼� 
    #define A_PWM__B_ON__C_OFF()    { MCPWM_IO01 = 0x1D01; MCPWM_IO23 = 0x0D0D ;}
    // 6_step A��PWM��B������ C ON����������ع����¼�  
    #define A_PWM__B_OFF__C_ON()    { MCPWM_IO01 = 0x0D01; MCPWM_IO23 = 0x0D1D ;}

    #define ABC_ALL_ON()            { MCPWM_IO01 = 0x1D1D; MCPWM_IO23 = 0x1D1D ;}
    #define ABC_ALL_SOFT()          { MCPWM_IO01 = 0X0909; MCPWM_IO23 = 0X0909 ;}
    #define ABC_ALL_OFF()           { MCPWM_IO01 = 0X0D0D; MCPWM_IO23 = 0X0D0D;}
    #define MOS_ALL_OFF             0X0D0D

    #define C_HPWM_LOFF_AB_OFF()    { MCPWM_IO01 = 0X0D0D; MCPWM_IO23 = 0X0D05 ;}
    #define DIS_HPWM_FUNC()     {MCPWM_PRT = 0x0000DEAD;MCPWM_IO01 = 0x0808;MCPWM_IO23 = 0x0008;MCPWM_PRT = 0x0000CAFE;}
    #define EN_HPWM_FUNC()      {MCPWM_PRT = 0x0000DEAD;MCPWM_IO01 = 0x0101;MCPWM_IO23 = 0x0101;MCPWM_PRT = 0x0000CAFE;}
#endif

#endif


