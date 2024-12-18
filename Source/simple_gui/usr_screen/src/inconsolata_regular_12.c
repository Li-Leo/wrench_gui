#include "font_data.h"

static const unsigned char font_0020[] = {// 
0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,
};

static const unsigned char font_0021[] = {//!
0x00,0x00,0x7c,0x00,0x00,0x00,
0x00,0x00,0x02,0x00,0x00,0x00,
};

static const unsigned char font_0022[] = {//"
0x00,0x04,0x03,0x04,0x03,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,
};

static const unsigned char font_0023[] = {//#
0x90,0xfc,0x90,0xfc,0x90,0x00,
0x00,0x03,0x00,0x03,0x00,0x00,
};

static const unsigned char font_0024[] = {//$
0x18,0x24,0xfe,0x44,0x88,0x00,
0x01,0x02,0x07,0x02,0x01,0x00,
};

static const unsigned char font_0025[] = {//%
0x38,0x44,0xf8,0xd0,0x2c,0xc0,
0x00,0x03,0x00,0x01,0x02,0x01,
};

static const unsigned char font_0026[] = {//&
0xc0,0x38,0xe4,0x18,0xe0,0x20,
0x01,0x02,0x02,0x01,0x02,0x01,
};

static const unsigned char font_0027[] = {//'
0x04,0x03,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,
};

static const unsigned char font_0028[] = {//(
0x00,0x00,0xf8,0x06,0x01,0x00,
0x00,0x00,0x00,0x03,0x04,0x00,
};

static const unsigned char font_0029[] = {//)
0x00,0x01,0x06,0xf8,0x00,0x00,
0x00,0x04,0x03,0x00,0x00,0x00,
};

static const unsigned char font_002a[] = {//*
0x90,0x60,0xf8,0x60,0x90,0x00,
0x00,0x00,0x01,0x00,0x00,0x00,
};

static const unsigned char font_002b[] = {//+
0x00,0x20,0x20,0xf8,0x20,0x20,
0x00,0x00,0x00,0x00,0x00,0x00,
};

static const unsigned char font_002c[] = {//,
0x00,0x00,0x00,0x00,0x00,0x00,
0x04,0x03,0x00,0x00,0x00,0x00,
};

static const unsigned char font_002d[] = {//-
0x20,0x20,0x20,0x20,0x20,0x20,
0x00,0x00,0x00,0x00,0x00,0x00,
};

static const unsigned char font_002e[] = {//.
0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x02,0x00,0x00,0x00,0x00,
};

static const unsigned char font_002f[] = {///
0x00,0x00,0xc0,0x30,0x0c,0x02,
0x04,0x03,0x00,0x00,0x00,0x00,
};

static const unsigned char font_0030[] = {//0
0xf8,0x04,0x04,0x04,0xf8,0x00,
0x01,0x02,0x02,0x02,0x01,0x00,
};

static const unsigned char font_0031[] = {//1
0x00,0x08,0xfc,0x00,0x00,0x00,
0x00,0x02,0x03,0x02,0x00,0x00,
};

static const unsigned char font_0032[] = {//2
0x18,0x84,0x44,0x24,0x18,0x00,
0x03,0x02,0x02,0x02,0x02,0x00,
};

static const unsigned char font_0033[] = {//3
0x08,0x04,0x24,0x24,0xd8,0x00,
0x01,0x02,0x02,0x02,0x01,0x00,
};

static const unsigned char font_0034[] = {//4
0xc0,0xa0,0x98,0xfc,0x80,0x00,
0x00,0x00,0x02,0x03,0x02,0x00,
};

static const unsigned char font_0035[] = {//5
0x7c,0x24,0x24,0x24,0xc4,0x00,
0x01,0x02,0x02,0x02,0x01,0x00,
};

static const unsigned char font_0036[] = {//6
0xf0,0x48,0x24,0x24,0xc8,0x00,
0x01,0x02,0x02,0x02,0x01,0x00,
};

static const unsigned char font_0037[] = {//7
0x00,0x04,0xc4,0x34,0x0c,0x00,
0x00,0x00,0x03,0x00,0x00,0x00,
};

static const unsigned char font_0038[] = {//8
0xd8,0x24,0x24,0x24,0xd8,0x00,
0x01,0x02,0x02,0x02,0x01,0x00,
};

static const unsigned char font_0039[] = {//9
0x38,0x44,0x44,0x24,0xf8,0x00,
0x01,0x02,0x02,0x01,0x00,0x00,
};

static const unsigned char font_003a[] = {//:
0x00,0x00,0x10,0x00,0x00,0x00,
0x00,0x00,0x02,0x00,0x00,0x00,
};

static const unsigned char font_003b[] = {//;
0x00,0x00,0x20,0x00,0x00,0x00,
0x00,0x00,0x06,0x00,0x00,0x00,
};

static const unsigned char font_003c[] = {//<
0x00,0x60,0x90,0x08,0x04,0x00,
0x00,0x00,0x00,0x01,0x02,0x00,
};

static const unsigned char font_003d[] = {//=
0x50,0x50,0x50,0x50,0x50,0x50,
0x00,0x00,0x00,0x00,0x00,0x00,
};

static const unsigned char font_003e[] = {//>
0x00,0x04,0x08,0x90,0x60,0x00,
0x00,0x02,0x01,0x00,0x00,0x00,
};

static const unsigned char font_003f[] = {//?
0x18,0x04,0xc4,0x24,0x18,0x00,
0x00,0x00,0x02,0x00,0x00,0x00,
};

static const unsigned char font_0041[] = {//A
0x00,0xe0,0x9c,0xf0,0x80,0x00,
0x02,0x03,0x00,0x00,0x03,0x02,
};

static const unsigned char font_0042[] = {//B
0x04,0xfc,0x24,0x24,0xd8,0x00,
0x02,0x03,0x02,0x02,0x01,0x00,
};

static const unsigned char font_0043[] = {//C
0xf8,0x04,0x04,0x04,0x0c,0x00,
0x01,0x02,0x02,0x02,0x01,0x00,
};

static const unsigned char font_0044[] = {//D
0x04,0xfc,0x04,0x04,0xf8,0x00,
0x02,0x03,0x02,0x02,0x01,0x00,
};

static const unsigned char font_0045[] = {//E
0x04,0xfc,0x24,0x74,0x0c,0x00,
0x02,0x03,0x02,0x02,0x03,0x00,
};

static const unsigned char font_0046[] = {//F
0x04,0xfc,0x24,0x74,0x0c,0x00,
0x02,0x03,0x02,0x00,0x00,0x00,
};

static const unsigned char font_0047[] = {//G
0xf0,0x08,0x04,0x44,0xcc,0x40,
0x00,0x01,0x02,0x02,0x01,0x00,
};

static const unsigned char font_0048[] = {//H
0x04,0xfc,0x20,0x20,0xfc,0x04,
0x02,0x03,0x00,0x00,0x03,0x02,
};

static const unsigned char font_0049[] = {//I
0x04,0x04,0xfc,0x04,0x04,0x00,
0x02,0x02,0x03,0x02,0x02,0x00,
};

static const unsigned char font_004a[] = {//J
0x00,0x04,0x04,0xfc,0x04,0x04,
0x0c,0x08,0x08,0x07,0x00,0x00,
};

static const unsigned char font_004b[] = {//K
0x04,0xfc,0x24,0x50,0x8c,0x04,
0x02,0x03,0x02,0x00,0x03,0x02,
};

static const unsigned char font_004c[] = {//L
0x04,0xfc,0x04,0x00,0x00,0x00,
0x02,0x03,0x02,0x02,0x02,0x03,
};

static const unsigned char font_004d[] = {//M
0xfc,0x3c,0xc0,0x3c,0xfc,0x06,
0x03,0x00,0x03,0x00,0x03,0x03,
};

static const unsigned char font_004e[] = {//N
0x04,0xfc,0x30,0xc4,0xfc,0x04,
0x02,0x03,0x02,0x00,0x03,0x00,
};

static const unsigned char font_004f[] = {//O
0xf8,0x04,0x04,0x04,0xf8,0x00,
0x01,0x02,0x02,0x02,0x01,0x00,
};

static const unsigned char font_0050[] = {//P
0x04,0xfc,0x24,0x24,0x18,0x00,
0x02,0x03,0x02,0x00,0x00,0x00,
};

static const unsigned char font_0051[] = {//Q
0xf8,0x84,0x84,0x04,0xf8,0x00,
0x01,0x02,0x02,0x07,0x05,0x00,
};

static const unsigned char font_0052[] = {//R
0x04,0xfc,0x24,0x64,0x98,0x00,
0x02,0x03,0x02,0x00,0x03,0x02,
};

static const unsigned char font_0053[] = {//S
0x18,0x24,0x24,0x44,0x8c,0x00,
0x03,0x02,0x02,0x02,0x01,0x00,
};

static const unsigned char font_0054[] = {//T
0x0c,0x04,0xfc,0x04,0x0c,0x00,
0x00,0x02,0x03,0x02,0x00,0x00,
};

static const unsigned char font_0055[] = {//U
0x04,0xfc,0x00,0x00,0xfc,0x04,
0x00,0x01,0x02,0x02,0x01,0x00,
};

static const unsigned char font_0056[] = {//V
0x04,0x7c,0x80,0xe0,0x1c,0x04,
0x00,0x00,0x03,0x00,0x00,0x00,
};

static const unsigned char font_0057[] = {//W
0x3c,0xc0,0x7c,0xc0,0x3c,0x00,
0x00,0x03,0x00,0x03,0x00,0x00,
};

static const unsigned char font_0058[] = {//X
0x04,0x9c,0x60,0x9c,0x04,0x00,
0x02,0x03,0x00,0x03,0x02,0x00,
};

static const unsigned char font_0059[] = {//Y
0x04,0x3c,0xc0,0x3c,0x04,0x00,
0x00,0x02,0x03,0x02,0x00,0x00,
};

static const unsigned char font_005a[] = {//Z
0x0c,0x84,0x64,0x1c,0x04,0x00,
0x02,0x03,0x02,0x02,0x03,0x00,
};

static const unsigned char font_005b[] = {//[
0x00,0x00,0xff,0x01,0x01,0x00,
0x00,0x00,0x07,0x04,0x04,0x00,
};

static const unsigned char font_005c[] = {//\
0x00,0x06,0x38,0xc0,0x00,0x00,
0x00,0x00,0x00,0x01,0x06,0x00,
};

static const unsigned char font_005d[] = {//]
0x00,0x01,0x01,0xff,0x00,0x00,
0x00,0x04,0x04,0x07,0x00,0x00,
};

static const unsigned char font_005f[] = {//_
0x00,0x00,0x00,0x00,0x00,0x00,
0x08,0x08,0x08,0x08,0x08,0x08,
};

static const unsigned char font_0061[] = {//a
0x00,0x40,0xa0,0xa0,0xc0,0x00,
0x00,0x01,0x02,0x02,0x03,0x02,
};

static const unsigned char font_0062[] = {//b
0x02,0xfe,0x20,0x20,0xc0,0x00,
0x00,0x03,0x02,0x02,0x01,0x00,
};

static const unsigned char font_0063[] = {//c
0x00,0xc0,0x20,0x20,0x60,0x00,
0x00,0x01,0x02,0x02,0x01,0x00,
};

static const unsigned char font_0064[] = {//d
0x00,0xc0,0x20,0x22,0xfe,0x00,
0x00,0x01,0x02,0x02,0x03,0x02,
};

static const unsigned char font_0065[] = {//e
0x00,0xc0,0xa0,0xa0,0xc0,0x00,
0x00,0x01,0x02,0x02,0x02,0x00,
};

static const unsigned char font_0066[] = {//f
0x00,0x20,0xfc,0x22,0x22,0x04,
0x00,0x02,0x03,0x02,0x02,0x00,
};

static const unsigned char font_0067[] = {//g
0x00,0x40,0xa0,0xa0,0x60,0x20,
0x00,0x05,0x0a,0x0a,0x0a,0x04,
};

static const unsigned char font_0068[] = {//h
0x02,0xfe,0x20,0x20,0xc0,0x00,
0x02,0x03,0x02,0x00,0x03,0x02,
};

static const unsigned char font_0069[] = {//i
0x00,0x20,0xe6,0x00,0x00,0x00,
0x00,0x02,0x03,0x02,0x00,0x00,
};

static const unsigned char font_006a[] = {//j
0x00,0x00,0x20,0xe6,0x00,0x00,
0x08,0x08,0x08,0x07,0x00,0x00,
};

static const unsigned char font_006b[] = {//k
0x02,0xfe,0x80,0x60,0x20,0x00,
0x02,0x03,0x00,0x01,0x02,0x00,
};

static const unsigned char font_006c[] = {//l
0x02,0x02,0xfe,0x00,0x00,0x00,
0x02,0x02,0x03,0x02,0x02,0x00,
};

static const unsigned char font_006d[] = {//m
0xe0,0x20,0xe0,0x20,0xc0,0x00,
0x03,0x00,0x03,0x00,0x03,0x00,
};

static const unsigned char font_006e[] = {//n
0x20,0xe0,0x20,0x20,0xc0,0x00,
0x02,0x03,0x02,0x00,0x03,0x02,
};

static const unsigned char font_006f[] = {//o
0x00,0xc0,0x20,0x20,0xc0,0x00,
0x00,0x01,0x02,0x02,0x01,0x00,
};

static const unsigned char font_0070[] = {//p
0x20,0xe0,0x20,0x20,0xc0,0x00,
0x08,0x0f,0x0a,0x02,0x01,0x00,
};

static const unsigned char font_0071[] = {//q
0x00,0xc0,0x20,0x20,0xe0,0x00,
0x00,0x01,0x02,0x0a,0x0f,0x08,
};

static const unsigned char font_0072[] = {//r
0x20,0xe0,0x40,0x20,0x20,0x00,
0x02,0x03,0x02,0x00,0x00,0x00,
};

static const unsigned char font_0073[] = {//s
0x00,0x60,0xa0,0xa0,0x20,0x00,
0x00,0x02,0x02,0x02,0x03,0x00,
};

static const unsigned char font_0074[] = {//t
0x00,0x20,0xf8,0x20,0x20,0x00,
0x00,0x00,0x03,0x02,0x02,0x00,
};

static const unsigned char font_0075[] = {//u
0x20,0xe0,0x00,0x20,0xe0,0x00,
0x00,0x01,0x02,0x02,0x03,0x02,
};

static const unsigned char font_0076[] = {//v
0x20,0xe0,0x00,0xe0,0x20,0x00,
0x00,0x00,0x03,0x00,0x00,0x00,
};

static const unsigned char font_0077[] = {//w
0x60,0x80,0xe0,0x80,0x60,0x00,
0x00,0x03,0x00,0x03,0x00,0x00,
};

static const unsigned char font_0078[] = {//x
0x20,0x60,0x80,0x60,0x20,0x00,
0x02,0x03,0x00,0x03,0x02,0x00,
};

static const unsigned char font_0079[] = {//y
0x20,0xe0,0x00,0x00,0xe0,0x20,
0x08,0x08,0x05,0x03,0x00,0x00,
};

static const unsigned char font_007a[] = {//z
0x00,0x20,0xa0,0x60,0x20,0x00,
0x00,0x02,0x03,0x02,0x02,0x00,
};

static const unsigned char font_00d7[] = {//×
0x00,0x00,0x04,0x88,0x50,0x20,0x50,0x88,0x04,0x00,0x00,0x00,
0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,
};

static const unsigned char font_2713[] = {//✓
0x00,0x00,0x40,0x80,0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x00,
0xf0,0xf0,0xf0,0xf0,0xf1,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,
};

const char_info_t inconsolata_regular_12[] = {
	{0x0020, font_0020, 6, 12}, //  ' '
	{0x0021, font_0021, 6, 12}, //! '!'
	{0x0022, font_0022, 6, 12}, //" '"'
	{0x0023, font_0023, 6, 12}, //# '#'
	{0x0024, font_0024, 6, 12}, //$ '$'
	{0x0025, font_0025, 6, 12}, //% '%'
	{0x0026, font_0026, 6, 12}, //& '&'
	{0x0027, font_0027, 6, 12}, //' "'"
	{0x0028, font_0028, 6, 12}, //( '('
	{0x0029, font_0029, 6, 12}, //) ')'
	{0x002a, font_002a, 6, 12}, //* '*'
	{0x002b, font_002b, 6, 12}, //+ '+'
	{0x002c, font_002c, 6, 12}, //, ','
	{0x002d, font_002d, 6, 12}, //- '-'
	{0x002e, font_002e, 6, 12}, //. '.'
	{0x002f, font_002f, 6, 12}, /// '/'
	{0x0030, font_0030, 6, 12}, //0 '0'
	{0x0031, font_0031, 6, 12}, //1 '1'
	{0x0032, font_0032, 6, 12}, //2 '2'
	{0x0033, font_0033, 6, 12}, //3 '3'
	{0x0034, font_0034, 6, 12}, //4 '4'
	{0x0035, font_0035, 6, 12}, //5 '5'
	{0x0036, font_0036, 6, 12}, //6 '6'
	{0x0037, font_0037, 6, 12}, //7 '7'
	{0x0038, font_0038, 6, 12}, //8 '8'
	{0x0039, font_0039, 6, 12}, //9 '9'
	{0x003a, font_003a, 6, 12}, //: ':'
	{0x003b, font_003b, 6, 12}, //; ';'
	{0x003c, font_003c, 6, 12}, //< '<'
	{0x003d, font_003d, 6, 12}, //= '='
	{0x003e, font_003e, 6, 12}, //> '>'
	{0x003f, font_003f, 6, 12}, //? '?'
	{0x0041, font_0041, 6, 12}, //A 'A'
	{0x0042, font_0042, 6, 12}, //B 'B'
	{0x0043, font_0043, 6, 12}, //C 'C'
	{0x0044, font_0044, 6, 12}, //D 'D'
	{0x0045, font_0045, 6, 12}, //E 'E'
	{0x0046, font_0046, 6, 12}, //F 'F'
	{0x0047, font_0047, 6, 12}, //G 'G'
	{0x0048, font_0048, 6, 12}, //H 'H'
	{0x0049, font_0049, 6, 12}, //I 'I'
	{0x004a, font_004a, 6, 12}, //J 'J'
	{0x004b, font_004b, 6, 12}, //K 'K'
	{0x004c, font_004c, 6, 12}, //L 'L'
	{0x004d, font_004d, 6, 12}, //M 'M'
	{0x004e, font_004e, 6, 12}, //N 'N'
	{0x004f, font_004f, 6, 12}, //O 'O'
	{0x0050, font_0050, 6, 12}, //P 'P'
	{0x0051, font_0051, 6, 12}, //Q 'Q'
	{0x0052, font_0052, 6, 12}, //R 'R'
	{0x0053, font_0053, 6, 12}, //S 'S'
	{0x0054, font_0054, 6, 12}, //T 'T'
	{0x0055, font_0055, 6, 12}, //U 'U'
	{0x0056, font_0056, 6, 12}, //V 'V'
	{0x0057, font_0057, 6, 12}, //W 'W'
	{0x0058, font_0058, 6, 12}, //X 'X'
	{0x0059, font_0059, 6, 12}, //Y 'Y'
	{0x005a, font_005a, 6, 12}, //Z 'Z'
	{0x005b, font_005b, 6, 12}, //[ '['
	{0x005c, font_005c, 6, 12}, //\ '\\'
	{0x005d, font_005d, 6, 12}, //] ']'
	{0x005f, font_005f, 6, 12}, //_ '_'
	{0x0061, font_0061, 6, 12}, //a 'a'
	{0x0062, font_0062, 6, 12}, //b 'b'
	{0x0063, font_0063, 6, 12}, //c 'c'
	{0x0064, font_0064, 6, 12}, //d 'd'
	{0x0065, font_0065, 6, 12}, //e 'e'
	{0x0066, font_0066, 6, 12}, //f 'f'
	{0x0067, font_0067, 6, 12}, //g 'g'
	{0x0068, font_0068, 6, 12}, //h 'h'
	{0x0069, font_0069, 6, 12}, //i 'i'
	{0x006a, font_006a, 6, 12}, //j 'j'
	{0x006b, font_006b, 6, 12}, //k 'k'
	{0x006c, font_006c, 6, 12}, //l 'l'
	{0x006d, font_006d, 6, 12}, //m 'm'
	{0x006e, font_006e, 6, 12}, //n 'n'
	{0x006f, font_006f, 6, 12}, //o 'o'
	{0x0070, font_0070, 6, 12}, //p 'p'
	{0x0071, font_0071, 6, 12}, //q 'q'
	{0x0072, font_0072, 6, 12}, //r 'r'
	{0x0073, font_0073, 6, 12}, //s 's'
	{0x0074, font_0074, 6, 12}, //t 't'
	{0x0075, font_0075, 6, 12}, //u 'u'
	{0x0076, font_0076, 6, 12}, //v 'v'
	{0x0077, font_0077, 6, 12}, //w 'w'
	{0x0078, font_0078, 6, 12}, //x 'x'
	{0x0079, font_0079, 6, 12}, //y 'y'
	{0x007a, font_007a, 6, 12}, //z 'z'
	{0x00d7, font_00d7, 12, 12}, //× '\xc3\x97'
	{0x2713, font_2713, 12, 12}, //✓ '\xe2\x9c\x93'
};
