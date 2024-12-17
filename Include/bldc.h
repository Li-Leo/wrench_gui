#ifndef __BLDC__
#define __BLDC__
#include "basic.h"
#include "MC_type.h"
#define CMP0_IE_ENABLE()    {CMP_IE |= BIT0;}   // 比较器0开启使能
#define CMP0_IE_DISABLE()   {CMP_IE &= ~BIT0;}  // 比较器0关闭使能
#define CMP_IE_STATE()      (CMP_IE & BIT0)     // 判断当前比较器0状态
#define CMP0_OUT_LEVEL()    (CMP_DATA & BIT0)   // 比较器0输出电平原始信号状态
#define CMP0_POL_STATE()    (CMP_CFG & BIT0)    // 当前比较器0输出极性选择
#define CMP1_OUT_LEVEL()    (CMP_DATA & BIT1)   // 比较器0输出电平原始信号状态
#define CMP0_IF_STATE()     (CMP_IF & BIT0)     //
#define CMP1_IF_STATE()     (CMP_IF & BIT1)     // 判断当前比较器0状态
#define CMP1_IF_RST()       (CMP_IF = BIT1)     // 判断当前比较器0状态
#define CMP0_IF_RST()       (CMP_IF = BIT0)     // 判断当前比较器0状态
#define CMP01_IF_RST()      (CMP_IF = 0X03)     // 判断当前比较器0状态
typedef struct {
    u8 state;
    u8 state_old;
    u8 RunFlg;
    u8 Run_mode;
    u8 seekPosFlg;              // 查找初始位置标志
    u8 seekPosState;            // 当前初始位置状态标志
    u8 seekPosMosError ;
    u8 check_Zerocross;         // 检查过零点标示
    u8 commStep;                // 当前换相电角度位置
    u8 HallState;               // Hall 角度
    u8 motorDirect;             // 电机方向控制
    u8 BEMF_edgeFlg;            // 反电势检测方向
    u8 BEMF_edgeSetting;
    u8 PWM_CommCnt;
    u8 blankEndFlg;             // 消隐结束标志

    u8 seek_cnt ;
    u8 old_Step ;

    u32 SpeedTimerCnt;          // 当前速度
    u16 actPWM_Value;
    u32 minCommcationTime;
    u16 sCommmStabCnt;
    u32 RunStepCnt;   // 开环模式下换相步数计数
    u16 abs_cnt;
    s16 BEMF_adcValue;          // 反电势ADC值
    s16 last_BEMF_adcValue;     // 上次反电势ADC值
    s16 PhaseVoltage;
    s16 PhaseVoltage_old;

    u32 focusCommCnt;      // 强制换相计数 

    u8 seekPositionError ;
    u8 seekPosition_run_Error ;
    u8 totalFocusCommCnt;
    u8 current_commStep;   // 当前换相步数 
    u32 blankTime; // 消隐结束时时间戳 

    s16 BEMF_A_AdcValue;        // A反电势ADC值
    s16 BEMF_B_AdcValue;        // B反电势ADC值
    s16 BEMF_C_AdcValue;        // C反电势ADC值
    u32 blankEndTime ; 
    u32 run_time_ms ;

    u8 onTheFly_zero_flg;
    u8 onTheFly_Step;
    u8 onTheFly_Direct;

    u8 onTheFly_State;          // 顺风启动步骤  0--识别相位  1--找寻速度  3--切入闭环
    s16 BEMF_Fly_MAX_AdcValue;  // C反电势ADC值
    u32 onTheFly_OK_cnt ;       // 顺风启动  成功换相次数
    u32 onTheFly_OK_time ;

//    u8 speed_mode ;
//    u8 work_mode ;
//    u8 strickFlg;           // 打击标志
//    u32 noLoadCnt;          // 无负载计数
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


