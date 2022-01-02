#pragma once
#include "Cars.h"
#include "Reserve.h"
#include "Customer.h"
class Buy : public Cars
{
	string log;
public:
	void ShowBuy();
	void SetData(string NameOfCar, string Type, int Cost, int EngineValue, string DriveAxis, int Id, string log);
	void Write();
	void AddBuy(int id1, string log, double money);

};

