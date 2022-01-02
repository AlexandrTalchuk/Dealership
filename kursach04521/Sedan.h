#pragma once
#include "Cars.h"
class Sedan : public Cars
{
public:
	void WritePurchaseToFile() override;
	void ShowCars() override;
};