#pragma once
#include "Cars.h"
class Wagon : public Cars
{
public:
	void WritePurchaseToFile() override;
	void ShowCars() override;

};