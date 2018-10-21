#ifndef _PERIPHERAL_H_
#define _PERIPHERAL_H_

#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"

#ifdef _MCU_STM32_
#include "stm32f1xx_hal.h"
#endif

struct Peripheral
{
	void* gpio;

	uint16_t pin;

	bool (*GetPinState)(struct Peripheral* this);

	void (*BindPin)(struct Peripheral* this, uint16_t pin);
	void (*BindGPIO)(struct Peripheral* this, void* gpio);
	void (*SetPinState)(struct Peripheral* this, bool state);
	void (*TogglePinState)(struct Peripheral* this);
};

typedef struct Peripheral Peripheral;

Peripheral* new_Peripheral();

#endif
