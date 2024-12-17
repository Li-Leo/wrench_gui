#include "bsp.h"


/*******************************************************************************
 �������ƣ�    void DMA_StructInit(DMA_InitTypeDef *DMAInitStruct)
 ����������    DMA�ṹ���ʼ��
 �����ı���    ��
 ���������    ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2021.10.14      V1.0           Yangzj              ����
 *******************************************************************************/
void DMA_StructInit(DMA_InitTypeDef *DMAInitStruct)
{
    memset(DMAInitStruct, 0, sizeof(DMA_InitTypeDef));
}

/*******************************************************************************
 �������ƣ�    void DMA_Init(DMA_RegTypeDef *DMAx, DMA_InitTypeDef *DMAInitStruct)
 ����������    DMA��ʼ��
 �����ı���    ��
 ���������    ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2021.10.14      V1.0           Yangzj              ����
 *******************************************************************************/
void DMA_Init(DMA_RegTypeDef *DMAx, DMA_InitTypeDef *DMAInitStruct)
{
    DMA_CTRL       = 0x0001;
    /* ͨ�����üĴ��� ��ֵ */
    DMAx->DMA_CCR  = 0;
    DMAx->DMA_CTMS = DMAInitStruct->DMA_TIMES; /* ��������Ĵ��� */
    DMAx->DMA_SADR = DMAInitStruct->DMA_SADR;   /* �����ַ�Ĵ��� */
    DMAx->DMA_DADR = DMAInitStruct->DMA_DADR;   /* �ڴ��ַ�Ĵ��� */
    DMAx->DMA_REN  = DMAInitStruct->DMA_REQ_EN;
    DMAx->DMA_CCR  = (DMAInitStruct -> DMA_SBTW  << 10) | (DMAInitStruct -> DMA_DBTW  <<8) |
                     (DMAInitStruct -> DMA_SINC  <<  6) | (DMAInitStruct -> DMA_DINC  <<4) |
                     (DMAInitStruct -> DMA_CIRC  <<  3) | (DMAInitStruct -> DMA_RMODE <<1) |
                     (DMAInitStruct -> DMA_Channel_EN);
    if(DMAInitStruct->DMA_IRQ_EN)
    switch((u32)DMAx)
    {
        case (u32)DMA_CH0:
            DMA_IE |= BIT0;
            break;
        case (u32)DMA_CH1:
            DMA_IE |= BIT1;
            break;
        case (u32)DMA_CH2:
            DMA_IE |= BIT2;
            break;
        case (u32)DMA_CH3:
            DMA_IE |= BIT3;
            break;
    }
    DMA_CTRL  = 0x0001;  /*enable dma, mcu has higher priorit */
}  


