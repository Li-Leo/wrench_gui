#ifndef __BLDC__
#define __BLDC__
#include "basic.h"
#include "MC_type.h"
#define CMP0_IE_ENABLE()    {CMP_IE |= BIT0;}   // �Ƚ���0����ʹ��
#define CMP0_IE_DISABLE()   {CMP_IE &= ~BIT0;}  // �Ƚ���0�ر�ʹ��
#define CMP_IE_STATE()      (CMP_IE & BIT0)     // �жϵ�ǰ�Ƚ���0״̬
#define CMP0_OUT_LEVEL()    (CMP_DATA & BIT0)   // �Ƚ���0�����ƽԭʼ�ź�״̬
#define CMP0_POL_STATE()    (CMP_CFG & BIT0)    // ��ǰ�Ƚ���0�������ѡ��
#define CMP1_OUT_LEVEL()    (CMP_DATA & BIT1)   // �Ƚ���0�����ƽԭʼ�ź�״̬
#define CMP0_IF_STATE()     (CMP_IF & BIT0)     //
#define CMP1_IF_STATE()     (CMP_IF & BIT1)     // �жϵ�ǰ�Ƚ���0״̬
#define CMP1_IF_RST()       (CMP_IF = BIT1)     // �жϵ�ǰ�Ƚ���0״̬
#define CMP0_IF_RST()       (CMP_IF = BIT0)     // �жϵ�ǰ�Ƚ���0״̬
#define CMP01_IF_RST()      (CMP_IF = 0X03)     // �жϵ�ǰ�Ƚ���0״̬
typedef struct {
    u8 state;
    u8 state_old;
    u8 RunFlg;
    u8 Run_mode;
    u8 seekPosFlg;              // ���ҳ�ʼλ�ñ�־
    u8 seekPosState;            // ��ǰ��ʼλ��״̬��־
    u8 seekPosMosError ;
    u8 check_Zerocross;         // ��������ʾ
    u8 commStep;                // ��ǰ�����Ƕ�λ��
    u8 HallState;               // Hall �Ƕ�
    u8 motorDirect;             // ����������
    u8 BEMF_edgeFlg;            // �����Ƽ�ⷽ��
    u8 BEMF_edgeSetting;
    u8 PWM_CommCnt;
    u8 blankEndFlg;             // ����������־

    u8 seek_cnt ;
    u8 old_Step ;

    u32 SpeedTimerCnt;          // ��ǰ�ٶ�
    u16 actPWM_Value;
    u32 minCommcationTime;
    u16 sCommmStabCnt;
    u32 RunStepCnt;   // ����ģʽ�»��ಽ������
    u16 abs_cnt;
    s16 BEMF_adcValue;          // ������ADCֵ
    s16 last_BEMF_adcValue;     // �ϴη�����ADCֵ
    s16 PhaseVoltage;
    s16 PhaseVoltage_old;

    u32 focusCommCnt;      // ǿ�ƻ������ 

    u8 seekPositionError ;
    u8 seekPosition_run_Error ;
    u8 totalFocusCommCnt;
    u8 current_commStep;   // ��ǰ���ಽ�� 
    u32 blankTime; // ��������ʱʱ��� 

    s16 BEMF_A_AdcValue;        // A������ADCֵ
    s16 BEMF_B_AdcValue;        // B������ADCֵ
    s16 BEMF_C_AdcValue;        // C������ADCֵ
    u32 blankEndTime ; 
    u32 run_time_ms ;

    u8 onTheFly_zero_flg;
    u8 onTheFly_Step;
    u8 onTheFly_Direct;

    u8 onTheFly_State;          // ˳����������  0--ʶ����λ  1--��Ѱ�ٶ�  3--����ջ�
    s16 BEMF_Fly_MAX_AdcValue;  // C������ADCֵ
    u32 onTheFly_OK_cnt ;       // ˳������  �ɹ��������
    u32 onTheFly_OK_time ;

//    u8 speed_mode ;
//    u8 work_mode ;
//    u8 strickFlg;           // �����־
//    u32 noLoadCnt;          // �޸��ؼ���
}eBLDCStruct;

extern eBLDCStruct eBLDC;
enum {
    k_blank_state     = 0 ,
    k_confirm_state   = 1 ,
    k_delay_state     = 2 ,
    k_cross_state     = 3 ,
    k_comm_state      = 4 ,
    k_quick_comm_state = 5,
    k_default_state = 6,
};
enum {
    k_high_speed_mode = 0, 
    k_low_speed_mode  = 1 
};
enum {
    k_normal_mode = 0, 
    k_strike_mode  = 1 
};


void bldc_comm_process(void);
void force_CommProcess(void);
void BLDC_Communication_ex(void);

extern volatile u16 g_dbg_ss;
#endif


