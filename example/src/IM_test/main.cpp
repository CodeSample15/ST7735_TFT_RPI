/*! 
	@file src/Hello_world_SWSPI/main.cpp
	@brief Hello World software SPI test
	@author Gavin Lyons.
	@note See USER OPTIONS 1-3 in SETUP function, run as sudo
	@test 
		-# 801 Hello World Software SPI
*/

// Section ::  libraries 
#include <bcm2835.h> 
#include "ST7735_TFT.hpp"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 160

// Section :: Globals 
ST7735_TFT myTFT(SCREEN_WIDTH, SCREEN_HEIGHT);

//  Section ::  Function Headers 

uint8_t Setup(void); // setup + user options
void IMTest(void);
void EndTests(void);


//  Section ::  MAIN loop

int main(int argc, char **argv) 
{

	if(Setup() != 0)return -1;
	IMTest();
	EndTests();
	return 0;
}
// *** End OF MAIN **


//  Section ::  Function Space 

uint8_t Setup(void)
{
	std::cout << "TFT Start" << std::endl;
	if(!bcm2835_init())
	{
		std::cout << "Error 1201 Problem with init bcm2835 library" << std::endl;
		return 2;
	}else{
		std::cout <<"bcm2835 library version :" << bcm2835_version() << std::endl;
	}
	
// ** USER OPTION 1 GPIO/SPI TYPE SW **
	int8_t RST_TFT  = 25;
	int8_t DC_TFT   = 24;
	int8_t SCLK_TFT = 6;
	int8_t SDIN_TFT = 5;
	int8_t CS_TFT   = 21;
	myTFT.TFTSetupGPIO(RST_TFT, DC_TFT, CS_TFT, SCLK_TFT, SDIN_TFT);
//*********************************************

// ** USER OPTION 2 Screen Setup **
	uint8_t OFFSET_COL = 0;  // 2, These offsets can be adjusted for any issues->
	uint8_t OFFSET_ROW = 0; // 3, with manufacture tolerance/defects
	uint16_t TFT_WIDTH = SCREEN_WIDTH;// Screen width in pixels
	uint16_t TFT_HEIGHT = SCREEN_HEIGHT; // Screen height in pixels
	myTFT.TFTInitScreenSize(OFFSET_COL, OFFSET_ROW , TFT_WIDTH , TFT_HEIGHT);
// ***********************************

// ** USER OPTION 3 PCB_TYPE **
	uint16_t SWSPI_CommDelay = 0; //uS GPIO SW SPI delay
	// pass enum to param1 ,4 choices,see README
	if(myTFT.TFTInitPCBType(myTFT.TFT_ST7735R_Red, SWSPI_CommDelay) != 0)
	{
		bcm2835_close(); //Close lib & /dev/mem, deallocating mem
		return 3;
	}
//*****************************
	std::cout << "ST7735 library version : " << myTFT.TFTLibVerNumGet()<< std::endl;
	std::cout << "SWSPI Comm GPIO Delay set to : " << myTFT.HighFreqDelayGet()<< "uS" << std::endl;
	TFT_MILLISEC_DELAY(50);
	return 0;
}

void IMTest(void) 
{
	int16_t r=0;
	for(int i=0; i<20; i++) {
		myTFT.IMClear();
		for(int x=0; x<128; x++) {
			for(int y=0; y<160; y++) {
				uint16_t color = myTFT.Color565(r, 255, 255);
				myTFT.IMDrawPixel(x, y, color);
			}
		}
		r+=10;
		myTFT.IMDisplay();
	}

	TFT_MILLISEC_DELAY(500);
}

void EndTests(void)
{
	myTFT.TFTfillScreen(ST7735_BLACK);
	myTFT.TFTPowerDown(); // Power down device
	bcm2835_close(); // Close the bcm2835 library
	std::cout << "TFT End" << std::endl;
}

// *************** EOF ****************
