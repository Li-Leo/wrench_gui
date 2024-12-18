#ifndef __lks32mc03x_IWDG_H
#define __lks32mc03x_IWDG_H

/* Includes ------------------------------------------------------------------*/
#include "lks32mc03x.h"
#include "basic.h"

typedef struct
{
    __IO uint32_t PSW;
    __IO uint32_t CFG;
    __IO uint32_t CLR;
    __IO uint32_t WTH;
    __IO uint32_t RTH;
    __IO uint32_t CNT;
} IWDG_TypeDef;

typedef struct
{
    u32 DWK_EN;             // 深度休眠定时唤醒使能
    u32 WDG_EN;             // 独立看门狗使能
    u32 WTH;                // 看门狗定时唤醒时间（21位计数器，但低12恒位0）
    u32 RTH;                // 看门狗超时复位时间
}IWDG_InitTypeDef;

/*******************************************************************************
 函数名称：    u32 SECOND2IWDGCNT(float)
 功能描述：    看门狗时间计算
 输入参数：    时间，单位S
 返 回 值：    看门狗计数值
 其它说明：    RC时钟精度有限，全温度范围内误差±20%
               0x1000为计算后取整
 修改日期      版本号          修改人            修改内容
 -----------------------------------------------------------------------------
 2021/11/10    V1.0           Yangzj              创建
 *******************************************************************************/
#define SECOND2IWDGCNT(x)   ((u32)(64000*x)&0x1ff000)

void IWDG_Init(IWDG_InitTypeDef *);                 //看门狗初始化
void IWDG_StrutInit(IWDG_InitTypeDef *);            //看门狗配置结构体初始化
void IWDG_DISABLE(void);                            //关闭看门狗
void IWDG_Feed(void);                               //看门狗喂狗
#endif 

