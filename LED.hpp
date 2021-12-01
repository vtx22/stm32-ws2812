#pragma once
#include <stdint.h>
#include "stm32f1xx_hal.h"

class LED
{
	public:
		LED(TIM_HandleTypeDef* tim);
		void setSTAT1(bool on);
		void setSTAT2(bool on);
		void setSTAT3(bool on);
		void toggleSTAT(uint8_t stat);

		void updateNeopixels();



		void setNeopixel(uint8_t* rgb, uint8_t led);
		void setNeopixel(uint8_t red, uint8_t green, uint8_t blue, uint8_t led);

		void setAllNeopixels(uint8_t* rgb);
		void setAllNeopixels(uint8_t red, uint8_t green, uint8_t blue);

	private:
		void setNEOPin(bool on);
		void toggleNEOPin();
		void setNeopixelNOUP(uint8_t* rgb, uint8_t led);
		void setNeopixelNOUP(uint8_t red, uint8_t green, uint8_t blue, uint8_t led);

		static const uint8_t _neoLEDS = 8;

		uint8_t ledBufferRED[_neoLEDS];
		uint8_t ledBufferGREEN[_neoLEDS];
		uint8_t ledBufferBLUE[_neoLEDS];
		TIM_HandleTypeDef* _tim;
};
