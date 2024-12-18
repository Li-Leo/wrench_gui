/********************金逸晨**************************本公司模块SDA,SCK已内置上拉电阻，
*****************1.3  4PIN IIC OLED FOR STM32F103*************
*****STM32F103驱动**************************
***** PB5----3  SCK   ,  PB6----4  SDA   ,    
***** BY:GU 

********************************************************/
#include "bsp.h"
#include "stdint.h"

uint8_t OLED_DisplayBuf[8][128];

#define IIC_SCK_1  GPIO0_PDO |= BIT4        // 设置sck接口到     清零
#define IIC_SCK_0  GPIO0_PDO &= ~BIT4       //置位
#define IIC_SDA_1  GPIO0_PDO |= BIT5        // 设置SDA接口到  
#define IIC_SDA_0  GPIO0_PDO &= ~BIT5


const unsigned char  *point;
unsigned char ACK=0;
const unsigned char  OLED_init_cmd[25]=			//SH1106
{
    /*0xae,0X00,0X10,0x40,0X81,0XCF,0xff,0xa1,0xa4,
    0xA6,0xc8,0xa8,0x3F,0xd5,0x80,0xd3,0x00,0XDA,0X12,
    0x8d,0x14,0xdb,0x40,0X20,0X02,0xd9,0xf1,0xAF*/
    0xAE,//关闭显示
    0xD5,//设置时钟分频因子,震荡频率
    0x80,  //[3:0],分频因子;[7:4],震荡频率 0x80
    0xA8,//设置驱动路数
    0X3F,//默认(1/64)
    0xD3,//设置显示偏移
    0X00,//默认为0
    0x40,//设置显示开始行 [5:0],行数.
    0x8D,//电荷泵设置
    0x14,//bit2，开启/关闭
    0x20,//设置内存地址模式
    0x02,//[1:0],00，列地址模式;01，行地址模式;10,页地址模式;默认10;
    0xA1,//段重定义设置,bit0:0,0->0;1,0->127;  A1
    0xC8,//设置COM扫描方向;bit3:0,普通模式;1,重定义模式 COM[N-1]->COM0;N:驱动路数 (C0 翻转显示) C8
    
//    0xA0,//段重定义设置,bit0:0,0->0;1,0->127;  A1
//    0xC0,//设置COM扫描方向;bit3:0,普通模式;1,重定义模式 COM[N-1]->COM0;N:驱动路数 (C0 翻转显示) C8
//    
    0xDA,//设置COM硬件引脚配置
    0x12,//[5:4]配置
    0x81,//对比度设置
    0x66,//1~255;默认0X7F (亮度设置,越大越亮)
    0xD9,//设置预充电周期
    0xf1,//[3:0],PHASE 1;[7:4],PHASE 2;
    0xDB,//设置VCOMH 电压倍率
    0x30,//[6:4] 000,0.65*vcc;001,0.77*vcc;011,0.83*vcc;
    0xA4,//全局显示开启;bit0:1,开启;0,关闭;(白屏/黑屏)
    0xA6,//设置显示方式;bit0:1,反相显示;0,正常显示
    0xAF,//开启显示
};


//写入  最后将SDA拉高,以等待从设备产生应答
void IIC_write(unsigned char date)
{
	unsigned char i, temp;
	temp = date;
			
	for(i=0; i<8; i++)
	{	
        IIC_SCK_0;
        if ((temp&0x80)==0){
            IIC_SDA_0;
        }
        else {
            IIC_SDA_1;
        }
		temp = temp << 1;
		delay_us(1);
		IIC_SCK_1;
		delay_us(1);
	}
	IIC_SCK_0;
	delay_us(1);
	IIC_SDA_1;
	delay_us(1);
	IIC_SCK_1;
//  不需要应答
//	if (READ_SDA==0)
//		ACK = 1;
//	else ACK =0;
//	delay_us(1);
    delay_us(1);//jcwu
	IIC_SCK_0;
	delay_us(1);
}
//启动信号
//SCL在高电平期间，SDA由高电平向低电平的变化定义为启动信号
void IIC_start()
{
	IIC_SDA_1;
	delay_us(1);
	IIC_SCK_1;
	delay_us(1);				   //所有操作结束释放SCL	
	IIC_SDA_0;
	delay_us(3);
	IIC_SCK_0;
}

//停止信号
//SCL在高电平期间，SDA由低电平向高电平的变化定义为停止信号
void IIC_stop()
{
	IIC_SDA_0;
	delay_us(1);
	IIC_SCK_1;
	delay_us(3);
	IIC_SDA_1;
}

void OLED_send_cmd(unsigned char o_command)
{
    IIC_start();
    IIC_write(0x78);
    IIC_write(0x00); 
    IIC_write(o_command);
    IIC_stop();
}
void OLED_send_data(unsigned char o_data)
{ 
    IIC_start();
    IIC_write(0x78);
    IIC_write(0x40);
    IIC_write(o_data);
    IIC_stop();
}
// void Column_set(unsigned char column)
// {
//     column+=OLED_COLUMN_OFFSET;
//     OLED_send_cmd(0x10|(column>>4));    //设置列地址高位
//     OLED_send_cmd(0x00|(column&0x0f));   //设置列地址低位
// }
// void Page_set(unsigned char page)
// {
//     OLED_send_cmd(0xb0+page);
// }

void OLED_SetCursor(uint8_t Page, uint8_t X)
{
	/*如果使用此程序驱动1.3寸的OLED显示屏，则需要解除此注释*/
	/*因为1.3寸的OLED驱动芯片（SH1106）有132列*/
	/*屏幕的起始列接在了第2列，而不是第0列*/
	/*所以需要将X加2，才能正常显示*/
	X += 2;

	/*通过指令设置页地址和列地址*/
	OLED_send_cmd(0xB0 | Page);					//设置页位置
	OLED_send_cmd(0x10 | ((X & 0xF0) >> 4));	//设置X位置高4位
	OLED_send_cmd(0x00 | (X & 0x0F));			//设置X位置低4位
}


void oled_draw_point(int X, int Y, unsigned int color)
{
	if (X >= 0 && X <= 127 && Y >=0 && Y <= 63)		//超出屏幕的内容不显示
	{
		/*将显存数组指定位置的一个Bit数据置1*/
		if (color) {
            OLED_DisplayBuf[Y / 8][X] |= 0x01 << (Y % 8);
		} else {
			OLED_DisplayBuf[Y / 8][X] &= ~(0x01 << (Y % 8));
		}
	}
}


void OLED_WriteData(uint8_t *Data, uint8_t Count)
{
	uint8_t i;

	IIC_start();				//I2C起始
	IIC_write(0x78);		//发送OLED的I2C从机地址
	IIC_write(0x40);		//控制字节，给0x40，表示即将写数据
	/*循环Count次，进行连续的数据写入*/
	for (i = 0; i < Count; i ++)
	{
		IIC_write(Data[i]);	//依次发送Data的每一个数据
	}
	IIC_stop();				//I2C终止
}

void OLED_clear_ex(void)
{
	uint8_t j;
	uint8_t buff[128] = {0};
	/*遍历每一页*/

	for (j = 0; j < 8; j ++)
	{
		/*设置光标位置为每一页的第一列*/
		OLED_SetCursor(j, 0);
		/*连续写入128个数据，将显存数组的数据写入到OLED硬件*/
		OLED_WriteData(buff, 128);
	}
}


void oled_clear(void)
{
	uint8_t i,j;
	for (j = 0; j < 8; j ++)				//遍历8页
	{
		for (i = 0; i < 128; i ++)			//遍历128列
		{
			OLED_DisplayBuf[j][i] = 0x00;	//将显存数组数据全部清零
		}
	}
	OLED_clear_ex();
}

void oled_update(void)
{
	uint8_t j;
	/*遍历每一页*/
	for (j = 0; j < 8; j ++)
	{
		/*设置光标位置为每一页的第一列*/
		OLED_SetCursor(j, 0);
		/*连续写入128个数据，将显存数组的数据写入到OLED硬件*/
		OLED_WriteData(OLED_DisplayBuf[j], 128);
	}
}

void oled_draw_rectangle(int16_t X, int16_t Y, uint8_t Width, uint8_t Height, uint8_t IsFilled, unsigned int color)
{
	int16_t i, j;
	if (!IsFilled)		//指定矩形不填充
	{
		/*遍历上下X坐标，画矩形上下两条线*/
		for (i = X; i < X + Width; i ++)
		{
			oled_draw_point(i, Y, color);
			oled_draw_point(i, Y + Height - 1, color);
		}
		/*遍历左右Y坐标，画矩形左右两条线*/
		for (i = Y; i < Y + Height; i ++)
		{
			oled_draw_point(X, i, color);
			oled_draw_point(X + Width - 1, i, color);
		}
	}
	else				//指定矩形填充
	{
		/*遍历X坐标*/
		for (i = X; i < X + Width; i ++)
		{
			/*遍历Y坐标*/
			for (j = Y; j < Y + Height; j ++)
			{
				/*在指定区域画点，填充满矩形*/
				oled_draw_point(i, j, color);
			}
		}
	}
}


void oled_init(void)
{
    unsigned char i;
    for (i = 0; i < 25; i++) {
        OLED_send_cmd(OLED_init_cmd[i]);
    }
}



