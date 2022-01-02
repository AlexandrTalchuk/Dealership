#include "Buy.h"
#pragma once

	void Buy::ShowBuy()
	{
		ifstream ifs;
		ifs.open("bought.txt");
		string line = "";
		cout << left << "Марка" << "\t" << "Тип" << "\t" << "Стоимость" << "\t" << "Объем двигателя" << "\t" << "\t" << "Привод" << "\t" << "Id" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		while (getline(ifs, line))
		{
			cout << line << endl;
			cout << setw(10) << endl;
		}
	}
	void Buy::SetData(string NameOfCar, string Type, int Cost, int EngineValue, string DriveAxis, int Id, string log)
	{
		this->NameOfCar = NameOfCar;
		this->Type = Type;
		this->Cost = Cost;
		this->EngineValue = EngineValue;
		this->DriveAxis = DriveAxis;
		this->Id = Id;
		this->log = log;
	}
	void Buy::Write()
	{
		ofstream ofs;
		ofs.open("bought.txt", ios::app);
		ofs << NameOfCar << "\t" << Type << "\t" << Cost << "\t" << "\t" << EngineValue << "\t" << "\t" << "\t" << DriveAxis << "\t" << Id;
		ofs.close();
	}
	void Buy::AddBuy(int id1, string log, double money)
	{
		vector<Reserv> r;
		vector<Reserv> r1;
		Reserv res;
		//Closes cl; 
		Buy b;
		fstream fs;
		Customer cust;
		int num = 0;
		string log1;
		fs.open("reserve.txt", ios::app | ios::out | ios::in);
		while (fs >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Id >> log1)
		{
			if (id1 == Id)
			{
				if (money > Cost)
				{
					r.push_back(Reserv(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id, log1));
					b.SetData(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id, log1);
					b.Write();
					cust.SetLog(log);
					cust.WriteB();
					num++;
				}
				else
				{
					cout << "У вас недостаточно средств для покупки этого автомобиля" << endl;
					return;
				}
			}
			else
			{
				r1.push_back(Reserv(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id, log1));
			}
		}
		fs.close();
		if (num == 0)
		{
			cout << "Такого автомобиля в ассортименте нет." << endl;
			return;
		}
		//очищаю весь файл
		fs.open("reserve.txt", ios::out);
		fs.close();
		for (Reserv res : r1)
		{
			res.Write1();
		}


		cout << "Покупка автомобиля прошла успешно!" << endl;

	}


