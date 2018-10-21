#include "Peripheral.h"

void BindGPIO(Peripheral* this, void* gpio);
void BindPin(Peripheral* this, uint16_t pin);
void SetPinState(Peripheral* this, bool state);
void TogglePinState(Peripheral* this);
bool GetPinState(Peripheral* this);

Peripheral* new_Peripheral()
{
	Peripheral* this = (Peripheral*)malloc(sizeof(Peripheral));

	this->BindPin = BindPin;
	this->BindGPIO = BindGPIO;
	this->SetPinState = SetPinState;
	this->GetPinState = GetPinState;
	this->TogglePinState = TogglePinState;

	return this;
}

void BindGPIO(Peripheral* this, void* gpio)
{
	this->gpio = gpio;
}

void BindPin(Peripheral* this, uint16_t pin)
{
	this->pin = pin;
}

void SetPinState(Peripheral* this, bool state)
{
#ifdef _MCU_STM32_
	HAL_GPIO_WritePin(this->gpio, this->pin, state);
#endif
}

bool GetPinState(Peripheral* this)
{
#ifdef _MCU_STM32_
	return HAL_GPIO_ReadPin(this->gpio, this->pin);
#endif
}

void TogglePinState(Peripheral* this)
{
	if(this->GetPinState(this))
		this->SetPinState(this, false);
	else
		this->SetPinState(this, true);
}
