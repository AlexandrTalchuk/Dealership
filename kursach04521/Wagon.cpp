#include "Wagon.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
using namespace std;

void Wagon::WritePurchaseToFile()
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
	File.open("WagonCars.txt", ios::app);
	File << NameOfCar << "\t" << Type << "\t" << Cost << "\t" << EngineValue << "\t" << DriveAxis<<"\t"<<Id;
	File.close();
	WriteIn(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id);
	cout << "���������� ������� ��������." << endl;
}
void Wagon::ShowCars()
{
	ifstream File;
	int countFile = 0;
	File.open("WagonCars.txt");//����������� �������� �� �������� �����
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



//void Wagon::SetData(string NameOfCar, string Type, int Cost, int EngineValue, string DriveAxis, int Count)
//{
//	this->NameOfCar = NameOfCar;
//	this->Cost = Cost;
//	this->Type = Type;
//	this->EngineValue = EngineValue;
//	this->DriveAxis = DriveAxis;
//	this->Count = Count;
//}
//
//void Wagon::ViewAll()
//{
//	ifstream File;
//	int countFile = 0;
//	File.open("Wagon.txt");//����������� �������� �� �������� �����
//	if (File.is_open())
//	{
//		//try catch
//	}
//	cout << "����:" << endl;
//	cout << left << "����� ����������" << "\t" << setw(10) << "��� ����������" << "\t" << setw(10) << "���������" << "\t" << setw(10) << "����� ���������" << "\t" << setw(10) << "��� �������" << "\t" << setw(10) << "\t" << setw(15) << "���������� �����������" << endl;
//	cout << "--------------------------------------------------------------------------------" << endl;
//	while (File >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Count)
//	{
//
//		View(countFile++);
//	}
//	cout << "--------------------------------------------------------------------------------" << endl;
//	if (countFile == 0)
//	{
//		cout << "� ���������, � ������ ������ ���������� �����������" << endl;
//	}
//	File.close();
//}
//
//void Wagon::AddCars()
//{
//	ofstream File;
//	File.open("Wagon.txt", ios::app);
//	File << endl;
//	File << NameOfCar << "\t" << Type << "\t" << Cost << "\t" << EngineValue << "\t" << DriveAxis << "\t" << Count;
//	File.close();
//}
//
//void Wagon::View(int countFile) const
//{
//	cout << left << countFile++ << ". " << setw(15) << NameOfCar << "\t" << setw(10) << Type << "\t" << setw(10) << Cost << "\t" << setw(10) << EngineValue << "\t" << setw(10) << DriveAxis << "\t" << setw(10) << Count << endl;
//}
//
//
//void Wagon::DeleteCars(int countTodel)
//{
//	ifstream File;
//	int newCounter = 0;
//	Wagon carsToDel;
//	vector<Wagon> card;
//	File.open("Wagon.txt");
//	while (File >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Count)
//	{
//
//		if (newCounter != countTodel) {
//			carsToDel.SetData(this->NameOfCar, Type, Cost, EngineValue, DriveAxis, Count);
//			card.push_back(carsToDel);
//		}
//		newCounter++;
//	}
//	File.close();
//	ofstream FileNew;
//	FileNew.open("Wagon.txt");
//	FileNew.close();
//	for (auto i = 0; i < card.size(); i++) {
//		card[i].AddCars();
//	}
//	card.clear();
//	cout << "����� ������� ������!" << endl;
//}
//
//
//void Wagon::AddPurchase(string userName)
//{
//
//	Wagon procAdded;
//	vector<Wagon> reWrite;
//	int countToAdd = 0;
//	int justCount = 0;
//	ifstream File;
//	File.open("Wagon.txt");
//	procAdded.ViewAll();
//	cout << "������� ����� ���������� ��� ��� �������" << endl;
//	cin >> countToAdd;
//	while (File >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Count)
//	{
//		if (countToAdd == justCount++)
//		{
//			//��������� ���������� ������� ���������
//			procAdded.SetData(NameOfCar, Type, Cost, EngineValue, DriveAxis, Count);
//			reWrite.push_back(procAdded);
//		}
//
//	}
//	File.close();
//	//������� ���� 
//	ofstream reWriteFile;
//	reWriteFile.open("Wagon.txt");
//	reWriteFile.close();
//
//	for (auto i = 0; i < reWrite.size(); i++)
//	{
//		reWrite[i].AddCars();
//	}
//
//	ofstream basketFile;
//	basketFile.open("UserPurchase.txt", ios::app);
//	basketFile << endl;
//	basketFile << procAdded.NameOfCar << "\t" << procAdded.Type << "\t" << procAdded.Cost << "\t" << procAdded.EngineValue << "\t" << procAdded.DriveAxis << "\t" << userName;
//	basketFile.close();
//	cout << "���������� ������ �������!" << endl;
//
//
//
//
//	//p = "all";
//	//cout << "������� ����-��� ������:" << endl;
//	////cin >> id;
//	//ErrorVvod(&id);
//	//cout << "������� ������������:" << endl;
//	////cin >> name;
//	//ErrorVvod(&name);
//	//cout << "������� ������: " << endl;
//	////cin >> size;
//	//ErrorVvod(&size);
//	//cout << "������� ��������� ������:" << endl;
//	////cin >> price;
//	//ErrorVvod(&price);
//	//cout << "������� ���������� ������ � ����� ��������:" << endl;
//	////cin >> count;
//	//ErrorVvod(&count);
//	//cout << "������� ����/��� ������" << endl;
//	////cin >> color;
//	//ErrorVvod(&color);
//	//ofstream ofs;
//	//ofs.open("closes.txt", ios::app);
//
//	//ofs << p << "\t" << id << "\t" << name << "\t" << size << "\t" << price << "\t" << count << "\t" << color << endl;
//	//ofs.close();
//	//cout << "����� ������� ��������." << endl;
//}
//
//bool comW(const Wagon& a, const Wagon& b)
//{
//	return a.Cost < b.Cost;
//}
//
//bool camW(const Wagon& a, const Wagon& b)
//{
//	return toupper(a.NameOfCar[0]) < toupper(b.NameOfCar[0]);
//}
//
//
//void Wagon::SortByCost()
//{
//	ifstream FileToSort;
//	Wagon proc;
//	list<Wagon> procToSort;
//	string userName;
//	string NameOfCar;
//	string Type;
//	int newCount = 0;
//	int EngineValue;
//	string DriveAxis;
//	int  Cost;
//	int  Count;
//	FileToSort.open("Wagon.txt");
//	while (FileToSort >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Count)
//	{
//		newCount++;
//		proc.SetData(NameOfCar, Type, Cost, EngineValue, DriveAxis, Count);
//		procToSort.push_back(proc);
//	}
//	FileToSort.close();
//	procToSort.sort(comW);
//	ofstream sorterFile;
//	sorterFile.open("SortedWagonCost.txt");
//	for (auto iter = procToSort.begin(); iter != procToSort.end(); iter++)
//	{
//		sorterFile << iter->NameOfCar << "\t" << iter->Type << "\t" << iter->Cost << "\t" << iter->EngineValue << iter->DriveAxis << "\t" << iter->Count;
//	}
//	sorterFile.close();
//
//}
//
//void Wagon::SortByName()
//{
//	ifstream FileToSort;
//	Wagon card;
//	list<Wagon> procToSort;
//	string UserName;
//	string NameOfCar;
//	string Type;
//	int newCount = 0;
//	int EngineValue;
//	string DriveAxis;
//	int  Cost;
//	int  Count;
//	FileToSort.open("Coups.txt");
//	while (FileToSort >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Count)
//	{
//		newCount++;
//		card.SetData(NameOfCar, Type, Cost, EngineValue, DriveAxis, Count);
//		procToSort.push_back(card);
//	}
//	FileToSort.close();
//	procToSort.sort(camW);
//	ofstream sorterFile;
//	sorterFile.open("SortedCoupsName.txt");
//	for (auto iter = procToSort.begin(); iter != procToSort.end(); iter++)
//	{
//		sorterFile << iter->NameOfCar << "\t" << iter->Type << "\t" << iter->Cost << "\t" << iter->EngineValue << iter->DriveAxis << "\t" << iter->Count;
//	}
//	sorterFile.close();
//}
//
//bool Wagon::Search(string NameofCar, string UserName)
//{
//	ifstream File;
//	Cars proc;
//	int i;
//	File.open("Coups.txt");
//	while (File >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Count)
//	{
//		if (NameOfCar == NameofCar)
//		{
//			View(NULL);
//			cout << "����������?\n1. ��\n2. ���" << endl;
//			cin >> i;
//			switch (i)
//			{
//			case 1:
//				proc.SetData(this->NameOfCar, Type, Cost, EngineValue, DriveAxis, Count, UserName);
//				proc.AddPurchase();
//				File.close();
//				return true;
//				break;
//			case 2:
//				File.close();
//				return false;
//			default:
//				File.close();
//				return false;
//				break;
//			}
//		}
//	}
//	cout << "������� ���������� ��� � �������, ���������� � ��������������" << endl;
//	return false;
//
//}
//
//bool Wagon::ViewSorted(int i)
//{
//	ifstream File;
//	int countFile = 0;
//	if (i == 1)
//	{
//		File.open("SortedCoupsCost.txt");
//	}
//	else
//	{
//		File.open("SortedCoupsName.txt");
//	}
//	cout << left << "����� ����������" << "\t" << setw(10) << "��� ����������" << "\t" << setw(10) << "���������" << "\t" << setw(10) << "����� ���������" << "\t" << setw(10) << "��� �������" << "\t" << setw(10) << "\t" << setw(15) << "���������� �����������" << endl;
//	cout << "--------------------------------------------------------------------------------" << endl;
//	while (File >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Count)
//	{
//
//		View(countFile++);
//	}
//	cout << "--------------------------------------------------------------------------------" << endl;
//	File.close();
//	if (countFile != 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}