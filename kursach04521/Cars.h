#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <algorithm>
#include "Dealer.h"
using namespace std;
class Cars : public Dealer
{
protected:
	string NameOfCar;
	int Cost;
	string Type;
	int EngineValue;
	string DriveAxis;
	string UserName;
	int Id;
public:
	Cars();
	Cars(string NameOfCar, string Type, int Cost, int EngineValue, string DriveAxis, int Id);
	Cars(const Cars& obj);
	int GetCost();
	int GetId();
	virtual void SetData(string NameOfCar, string Type, int Cost, int EngineValue, string DriveAxis, int Id);
	virtual void ViewAll(int CountFile) const;
	virtual void ShowCars();
	virtual void WritePurchaseToFile();
	virtual void WriteIn(string NameOfCar, string Type, int Cost, int EngineValue, string DriveAxis,int Id);
	virtual void RemoveCars(int Id);
	virtual void Find(int,string);
	void Sortirovka();
	void Filtr(int, int);
	friend ostream& operator<<(ostream& os, const Cars& cl);
	virtual void SortWrite();;

};





