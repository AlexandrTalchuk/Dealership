#include "Cars.h"
#pragma once
class SUV : public Cars
{
public:
	void WritePurchaseToFile() override;
	void ShowCars() override;
};