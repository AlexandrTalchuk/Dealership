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
	File.open("WagonCars.txt", ios::app);
	File << NameOfCar << "\t" << Type << "\t" << Cost << "\t" << EngineValue << "\t" << DriveAxis<<"\t"<<Id;
	File.close();
	WriteIn(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id);
	cout << "Автомобиль успешно добавлен." << endl;
}
void Wagon::ShowCars()
{
	ifstream File;
	int countFile = 0;
	File.open("WagonCars.txt");//реализовать проверку на открытие файла
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
//	File.open("Wagon.txt");//реализовать проверку на открытие файла
//	if (File.is_open())
//	{
//		//try catch
//	}
//	cout << "Купе:" << endl;
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
//	cout << "Товар успешно удален!" << endl;
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