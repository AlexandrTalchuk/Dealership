#include "Sedan.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
using namespace std;

void Sedan::WritePurchaseToFile()
{
	cout << "Введите название автомобиля " << endl;
	cin >> NameOfCar;
	cout << "Введите тип автомобиля: " << endl;
	cin >> Type;
	cout << "Введите стоимость автомобиля: " << endl;
	cin >> Cost;
	cout << "Введите объем двигателя: " << endl;
	cin >> EngineValue;
	cout << "Введите тип привода: " << endl;
	cin >> DriveAxis;
	cout << "Введите Id автомобиля: " << endl;
	cin >> Id;
	ofstream File;
	File.open("Sedan.txt", ios::app);
	File << NameOfCar << "\t" << Type << "\t" << Cost << "\t" << EngineValue << "\t" << DriveAxis<<"\t"<<Id;
	File.close();
	WriteIn(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id);
	cout << "Автомобиль успешно добавлен." << endl;
}
void Sedan::ShowCars()
{
	ifstream File;
	int countFile = 0;
	File.open("SedanCars.txt");//реализовать проверку на открытие файла
	if (File.is_open())
	{
		//try catch
	}
	cout << left << "Марка автомобиля" << "\t" << setw(10) << "Тип автомобиля" << "\t" << setw(10) << "Стоимость" << "\t" << setw(10) << "Объем двигателя" << "\t" << setw(10) << "Тип привода" << "\t" << setw(10) << "\t" << setw(15) << "Id автомобиля" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	while (File >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Id)
	{

		ViewAll(countFile++);
	}
	cout << "--------------------------------------------------------------------------------" << endl;
	if (countFile == 0)
	{
		cout << "К сожалению, в данный момент автомобили отсутствуют" << endl;
	}
	File.close();
}

