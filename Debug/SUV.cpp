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
	File.open("SUVCars.txt", ios::app);
	File << NameOfCar << "\t" << Type << "\t" << Cost << "\t" << EngineValue << "\t" << DriveAxis<<"\t"<<Id;
	File.close();
	WriteIn(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id);
	cout << "Автомобиль успешно добавлен." << endl;
}
void SUV::ShowCars()
{
	ifstream File;
	int countFile = 0;
	File.open("SUVCars.txt");//реализовать проверку на открытие файла
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
//	File.open("SUV.txt");//реализовать проверку на открытие файла
//	if (File.is_open())
//	{
//		//try catch
//	}
//	cout << "Внедорожник:" << endl;
//	cout << left << "Марка автомобиля" << "\t" << setw(10) << "Тип автомобиля" << "\t" << setw(10) << "Стоимость" << "\t" << setw(10) << "Объем двигателя" << "\t" << setw(10) << "Тип привода" << "\t" << setw(10) << "\t" << setw(15) << "Количество автомобилей" << endl;
//	cout << "--------------------------------------------------------------------------------" << endl;
//	while (File >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Count)
//	{
//
//		View(countFile++);
//	}
//	cout << "--------------------------------------------------------------------------------" << endl;
//	if (countFile == 0)
//	{
//		cout << "К сожалению, в данный момент автомобили отсутствуют" << endl;
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
//	cout << "Товар успешно удален!" << endl;
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
//	cout << "Введите номер автомобиля для его покупки" << endl;
//	cin >> countToAdd;
//	while (File >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Count)
//	{
//		if (countToAdd == justCount++)
//		{
//			//оставляем количество сколько отсанется
//			procAdded.SetData(NameOfCar, Type, Cost, EngineValue, DriveAxis, Count);
//			reWrite.push_back(procAdded);
//		}
//
//	}
//	File.close();
//	//очищаем файл 
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
//	cout << "Добавление прошло успешно!" << endl;
//
//
//
//
//	//p = "all";
//	//cout << "Введите скан-код товара:" << endl;
//	////cin >> id;
//	//ErrorVvod(&id);
//	//cout << "Введите наименование:" << endl;
//	////cin >> name;
//	//ErrorVvod(&name);
//	//cout << "Введите размер: " << endl;
//	////cin >> size;
//	//ErrorVvod(&size);
//	//cout << "Введите стоимость товара:" << endl;
//	////cin >> price;
//	//ErrorVvod(&price);
//	//cout << "Введите количество товара с таким размером:" << endl;
//	////cin >> count;
//	//ErrorVvod(&count);
//	//cout << "Введите цвет/тон товара" << endl;
//	////cin >> color;
//	//ErrorVvod(&color);
//	//ofstream ofs;
//	//ofs.open("closes.txt", ios::app);
//
//	//ofs << p << "\t" << id << "\t" << name << "\t" << size << "\t" << price << "\t" << count << "\t" << color << endl;
//	//ofs.close();
//	//cout << "Товар успешно добавлен." << endl;
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
//			cout << "Приобрести?\n1. Да\n2. Нет" << endl;
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
//	cout << "Данного автомобиля нет в наличии, обратитесь к администратору" << endl;
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
//	cout << left << "Марка автомобиля" << "\t" << setw(10) << "Тип автомобиля" << "\t" << setw(10) << "Стоимость" << "\t" << setw(10) << "Объем двигателя" << "\t" << setw(10) << "Тип привода" << "\t" << setw(10) << "\t" << setw(15) << "Количество автомобилей" << endl;
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