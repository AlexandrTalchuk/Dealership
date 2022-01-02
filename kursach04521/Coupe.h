#include "Cars.h"
#pragma once
class Coupe : public Cars
{
	public:
	void WritePurchaseToFile() override;
	void ShowCars() override;

	/*void SetData(string Name, string Type, int Cost, int EngineValue, string DriveAxis, int Id);
	void ViewAll();
	void AddCars();
	void DeleteCars(int);
	void View(int) const;
	void AddPurchase(string);
	void SortByName();
	void SortByCost();
	bool ViewSorted(int);
	bool Search(string, string);
	friend bool comC(const Coupe& a, const Coupe& b);
	friend bool camC(const Coupe& a, const Coupe& b);*/
};

