// ASCII font file : Wide font 16 by 32 , xbyy
// Define the ASCII table as Data array
// NUMBERS + ":" ONLY 

#ifndef font_five_H
#define font_five_H

// 32 * 16/8 = 64 ,;;, 64 * 11 = 704 bytes
// 32 height 16 width
static const uint8_t Font_Five [11][64] = 
{
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0xFC,    /*"0",0*/
	0x30,0x00,0x00,0x0C,0x30,0x00,0x00,0x0C,0x30,0x00,0x00,0x0C,0x30,0x00,0x00,0x0C,
	0x30,0x00,0x00,0x0C,0x30,0x00,0x00,0x0C,0x30,0x00,0x00,0x0C,0x30,0x00,0x00,0x0C,
	0x3F,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,   /*"1",1*/
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x30,0x00,0x00,0x00,
	0x3F,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x01,0xFF,0xFC,0x3C,0x01,0xFF,0xFC,   /*"2",2*/
	0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,
	0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,
	0x3F,0xFF,0x80,0x0C,0x3F,0xFF,0x80,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x3C,0x38,0x00,0x00,0x3C,   /*"3",3*/
	0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,
	0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,
	0x3F,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0x80,0x00,0x3F,0xFF,0x80,0x00,  /*"4",4*/
	0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,
	0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,
	0x3F,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0x80,0x3C,0x3F,0xFF,0x80,0x3C,  /*"5",5*/
	0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,
	0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,
	0x30,0x01,0xFF,0xFC,0x30,0x01,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0xFC,  /*"6",6*/
	0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,
	0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,
	0x3C,0x01,0xFF,0xFC,0x3C,0x01,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,  /*"7",7*/
	0x30,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x30,0x00,0x00,0x00,
	0x30,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x30,0x00,0x00,0x00,
	0x3F,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},    

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0xFC,  /*"8",8*/
	0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,
	0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,
	0x3F,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0x80,0x3C,0x3F,0xFF,0x80,0x3C,  /*"9",9*/
	0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,
	0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,0x30,0x01,0x80,0x0C,
	0x3F,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  /*":",10*/
	0x00,0x00,0x00,0x00,0x0F,0xF0,0x0F,0xF0,0x0F,0xF0,0x0F,0xF0,0x0C,0x00,0x00,0x30,
	0x0C,0x00,0x00,0x30,0x0F,0xF0,0x0F,0xF0,0x0F,0xF0,0x0F,0xF0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
};  

#endif
