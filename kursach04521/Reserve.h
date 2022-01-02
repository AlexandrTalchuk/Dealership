#pragma once
#include "Cars.h"
class Reserv:public Cars
{
	string log;
public:
	Reserv();
	void Write();
	void Write1();
	Reserv(string NameOfCar, string Type, int Cost, int EngineValue, string DriveAxis, int Id, string log);
	void DelReserve(int id1, string log);
	void AddReserve(int id1, string log);
	void ShowReserve(string log);
};

