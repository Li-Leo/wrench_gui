#ifndef __Etool_related_H__
#define __Etool_related_H__

#define PORT_RUN_STOP_IN    // (GPIO0_PDI & BIT0)
#define PORT_MODE_IN        // (GPIO0_PDI & BIT2)

#define POWER_ON()    // (GPIO1_PDO |=  BIT5 )
#define POWER_OFF()   // (GPIO1_PDO &= ~ BIT5 )

#define LED1_OFF()    //  (GPIO0_PDO |= BIT8)
#define LED1_ON()     //  (GPIO0_PDO &= ~BIT8)

#define LED2_OFF()    //  (GPIO0_PDO |= BIT6)
#define LED2_ON()     //  (GPIO0_PDO &= ~BIT6)

#define LED3_OFF()    //  (GPIO0_PDO |= BIT5)
#define LED3_ON()     //  (GPIO0_PDO &= ~BIT5)

#define LED4_OFF()     // (GPIO0_PDO |= BIT4)
#define LED4_ON()     //  (GPIO0_PDO &= ~BIT4)

#define LED_OFF()       (GPIO1_PDO  &= ~BIT4)
#define LED_ON()        (GPIO1_PDO  |= BIT4)

#define DBG_CMP_ON()  // (GPIO1_PDO |= BIT4)
#define DBG_CMP_OFF() // (GPIO1_PDO &= ~BIT4)

typedef union{
    uint8_t  Word;
    struct{
        uint8_t PowerHigh   :1; //2
        uint8_t PowerMid    :1; //3
        uint8_t PowerLow    :1; //5
        uint8_t Work    :1; //4
        uint8_t NC1 :1; //6 SpeedSix
        uint8_t NC2 :1; //7 SpeedSeven
        uint8_t NC3 :1; //1 SpeedOne
        uint8_t NC4 :1; // SpeedEight
    }bits;
}Leds;
extern Leds gLedState;

extern void led_error( void );  // 考虑下关机事情
extern void LED_Dispay(void);
void restart_motor( void );
#define LED_PWOER_ON_TIME       (5*1000 )
#define PWOER_INIT_TIME_MS      100S
#define RUN_PARAMETER_ADDR      0x7C00
extern u32 g_power_led_on_cnt ;
extern volatile u16 g_power  ;
extern void GPIO_LED( uint8_t  data );
extern void led_on_off_cmd( void );

extern u32 gRunS ;
void MemoSave(void); 
void MemoLoad(void);
#endif

