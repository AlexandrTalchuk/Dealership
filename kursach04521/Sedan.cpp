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
	cout << "������� �������� ���������� " << endl;
	cin >> NameOfCar;
	cout << "������� ��� ����������: " << endl;
	cin >> Type;
	cout << "������� ��������� ����������: " << endl;
	cin >> Cost;
	cout << "������� ����� ���������: " << endl;
	cin >> EngineValue;
	cout << "������� ��� �������: " << endl;
	cin >> DriveAxis;
	cout << "������� Id ����������: " << endl;
	cin >> Id;
	ofstream File;
	File.open("Sedan.txt", ios::app);
	File << NameOfCar << "\t" << Type << "\t" << Cost << "\t" << EngineValue << "\t" << DriveAxis<<"\t"<<Id;
	File.close();
	WriteIn(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id);
	cout << "���������� ������� ��������." << endl;
}
void Sedan::ShowCars()
{
	ifstream File;
	int countFile = 0;
	File.open("SedanCars.txt");//����������� �������� �� �������� �����
	if (File.is_open())
	{
		//try catch
	}
	cout << left << "����� ����������" << "\t" << setw(10) << "��� ����������" << "\t" << setw(10) << "���������" << "\t" << setw(10) << "����� ���������" << "\t" << setw(10) << "��� �������" << "\t" << setw(10) << "\t" << setw(15) << "Id ����������" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	while (File >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Id)
	{

		ViewAll(countFile++);
	}
	cout << "--------------------------------------------------------------------------------" << endl;
	if (countFile == 0)
	{
		cout << "� ���������, � ������ ������ ���������� �����������" << endl;
	}
	File.close();
}

