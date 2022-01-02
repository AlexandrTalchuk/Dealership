#include "SUV.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
using namespace std;

void SUV::WritePurchaseToFile()
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
	File.open("SUVCars.txt", ios::app);
	File << NameOfCar << "\t" << Type << "\t" << Cost << "\t" << EngineValue << "\t" << DriveAxis<<"\t"<<Id;
	File.close();
	WriteIn(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id);
	cout << "���������� ������� ��������." << endl;
}
void SUV::ShowCars()
{
	ifstream File;
	int countFile = 0;
	File.open("SUVCars.txt");//����������� �������� �� �������� �����
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

//void SUV::SetData(string NameOfCar, string Type, int Cost, int EngineValue, string DriveAxis, int Count)
//{
//	this->NameOfCar = NameOfCar;
//	this->Cost = Cost;
//	this->Type = Type;
//	this->EngineValue = EngineValue;
//	this->DriveAxis = DriveAxis;
//	this->Count = Count;
//}
//
//void SUV::ViewAll()
//{
//	ifstream File;
//	int countFile = 0;
//	File.open("SUV.txt");//����������� �������� �� �������� �����
//	if (File.is_open())
//	{
//		//try catch
//	}
//	cout << "�����������:" << endl;
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
//void SUV::AddCars()
//{
//	ofstream File;
//	File.open("SUV.txt", ios::app);
//	File << endl;
//	File << NameOfCar << "\t" << Type << "\t" << Cost << "\t" << EngineValue << "\t" << DriveAxis << "\t" << Count;
//	File.close();
//}
//
//void SUV::View(int countFile) const
//{
//	cout << left << countFile++ << ". " << setw(15) << NameOfCar << "\t" << setw(10) << Type << "\t" << setw(10) << Cost << "\t" << setw(10) << EngineValue << "\t" << setw(10) << DriveAxis << "\t" << setw(10) << Count << endl;
//}
//
//
//void SUV::DeleteCars(int countTodel)
//{
//	ifstream File;
//	int newCounter = 0;
//	SUV carsToDel;
//	vector<SUV> card;
//	File.open("SUV.txt");
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
//	FileNew.open("SUV.txt");
//	FileNew.close();
//	for (auto i = 0; i < card.size(); i++) {
//		card[i].AddCars();
//	}
//	card.clear();
//	cout << "����� ������� ������!" << endl;
//}
//
//
//void SUV::AddPurchase(string userName)
//{
//
//	SUV procAdded;
//	vector<SUV> reWrite;
//	int countToAdd = 0;
//	int justCount = 0;
//	ifstream File;
//	File.open("SUV.txt");
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
//	reWriteFile.open("SUV.txt");
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
//bool comS(const SUV& a, const SUV& b)
//{
//	return a.Cost < b.Cost;
//}
//
//bool camS(const SUV& a, const SUV& b)
//{
//	return toupper(a.NameOfCar[0]) < toupper(b.NameOfCar[0]);
//}
//
//
//void SUV::SortByCost()
//{
//	ifstream FileToSort;
//	SUV proc;
//	list<SUV> procToSort;
//	string userName;
//	string NameOfCar;
//	string Type;
//	int newCount = 0;
//	int EngineValue;
//	string DriveAxis;
//	int  Cost;
//	int  Count;
//	FileToSort.open("SUV.txt");
//	while (FileToSort >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Count)
//	{
//		newCount++;
//		proc.SetData(NameOfCar, Type, Cost, EngineValue, DriveAxis, Count);
//		procToSort.push_back(proc);
//	}
//	FileToSort.close();
//	procToSort.sort(comS);
//	ofstream sorterFile;
//	sorterFile.open("SortedSUVCost.txt");
//	for (auto iter = procToSort.begin(); iter != procToSort.end(); iter++)
//	{
//		sorterFile << iter->NameOfCar << "\t" << iter->Type << "\t" << iter->Cost << "\t" << iter->EngineValue << iter->DriveAxis << "\t" << iter->Count;
//	}
//	sorterFile.close();
//
//}
//
//void SUV::SortByName()
//{
//	ifstream FileToSort;
//	SUV card;
//	list<SUV> procToSort;
//	string UserName;
//	string NameOfCar;
//	string Type;
//	int newCount = 0;
//	int EngineValue;
//	string DriveAxis;
//	int  Cost;
//	int  Count;
//	FileToSort.open("SUV.txt");
//	while (FileToSort >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Count)
//	{
//		newCount++;
//		card.SetData(NameOfCar, Type, Cost, EngineValue, DriveAxis, Count);
//		procToSort.push_back(card);
//	}
//	FileToSort.close();
//	procToSort.sort(camS);
//	ofstream sorterFile;
//	sorterFile.open("SortedSUVName.txt");
//	for (auto iter = procToSort.begin(); iter != procToSort.end(); iter++)
//	{
//		sorterFile << iter->NameOfCar << "\t" << iter->Type << "\t" << iter->Cost << "\t" << iter->EngineValue << iter->DriveAxis << "\t" << iter->Count;
//	}
//	sorterFile.close();
//}
//
//bool SUV::Search(string NameofCar, string UserName)
//{
//	ifstream File;
//	Cars proc;
//	int i;
//	File.open("SUV.txt");
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
//bool SUV::ViewSorted(int i)
//{
//	ifstream File;
//	int countFile = 0;
//	if (i == 1)
//	{
//		File.open("SortedSUVCost.txt");
//	}
//	else
//	{
//		File.open("SortedSUVName.txt");
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