#include "Reserve.h"
#include "Customer.h"
	Reserv::Reserv() 
	{}
	void Reserv:: Write()
	{
		ofstream ofs;
		ofs.open("reserve.txt", ios::app);
		ofs << NameOfCar << "\t" << Type << "\t" << Cost << "\t" << "\t" << EngineValue << "\t" << "\t" << "\t" << DriveAxis << "\t" << Id;
		ofs.close();
	}
	void Reserv:: Write1()
	{
		ofstream ofs;
		ofs.open("reserve.txt", ios::app);
		ofs << NameOfCar << "\t" << Type << "\t" << Cost << "\t" << "\t" << EngineValue << "\t" << "\t" << "\t" << DriveAxis << "\t" << Id << log << endl;;
		ofs.close();
	}
	Reserv::Reserv(string NameOfCar, string Type, int Cost, int EngineValue, string DriveAxis, int Id, string log)
	{
		this->NameOfCar = NameOfCar;
		this->Type = Type;
		this->Cost = Cost;
		this->EngineValue = EngineValue;
		this->DriveAxis = DriveAxis;
		this->Id = Id;
		this->log = log;
	}
	void Reserv::DelReserve(int id1, string log)
	{
		vector<Cars> c;
		vector <Reserv> r;
		Reserv res;
		Cars cl;
		ifstream ifs;
		string log1, l;
		Customer cust;
		int num = 0;

		ifs.open("Cars.txt");
		while (ifs >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Id)
		{
			c.push_back(Cars(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id));
		}
		ifs.close();
		//ifstream ifs;
		ifs.open("reserve.txt");
		while (ifs >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Id >> log1)
		{

			if (Id == id1 && log1 == log)
			{
			
				for (Cars cl : c)
				{
					if (cl.GetId() == id1 && log1 == log)
					{
						cl.SetData(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id);
						num++;
						break;
					}
				}
			}
			else {
				r.push_back(Reserv(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id, log1));
				l = log1;
			}

		}
		try {
			if (num == 0)
				throw " ошибка";
		}
		catch (const char* s) {
			cout << "В вашей корзине  нет такого автомобиля." << endl;
			return;
		}

		ifs.close();
		ofstream ofs;
		ofs.open("Cars.txt", ios::out);
		ofs.close();
		for (Cars cl : c)
		{
			cl.SortWrite();
		}
		ofstream ofs1;
		ofs1.open("reserve.txt", ios::out);
		ofs1.close();
		for (Reserv res : r)
		{
			res.Write();
			cust.SetLog(l);
			cust.WriteR();
		}
		cout << "Автомобиль удален из забронированных." << endl;

	}
	void Reserv::AddReserve(int id1, string log)
	{
		vector<Cars> c;
		Reserv r;
		Cars cl;
		fstream fs;
		Customer cust;
		int num = 0;
		fs.open("Cars.txt", ios::app | ios::out | ios::in);
		string s;
		cout << "Введите тип кузова:" << endl;
		cin >> s;
		while (fs >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Id)
		{
			if (id1 == Id && s == Type)
			{
				num++;
				c.push_back(Cars(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id));
				r.SetData(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id);
				r.Write();
				cust.SetLog(log);
				cust.WriteR();

			}
			else
			{
				c.push_back(Cars(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id));
			}
		}
		fs.close();
		if (num == 0)
		{
			cout << "Таких автомобилей в ассортименте нет." << endl;
			return;
		}
		//очищаю весь файл
		fs.open("Cars.txt", ios::out);
		fs.close();
		for (Cars cl : c)
		{
			cl.SortWrite();
		}
		cout << "Автомобиль забронирован." << endl;

	}
	void Reserv::ShowReserve(string log)
	{
		ifstream ifs;
		ifs.open("reserve.txt");
		string log1;
		string line = "";
		int n = 0;
		cout << left << "Марка" << "\t" << "Тип" << "\t" << "Стоимость" << "\t" << "Объем двигателя" << "\t" << "\t" << "Привод" << "\t" << "Id" <<"\t"<<"Логин"<< endl;
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		while (ifs >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Id >> log1)
		{
			
			if (log == log1)
			{
				n++;
				cout << NameOfCar << "\t" << Type << "\t" << Cost << "\t" << "\t" << EngineValue << "\t" << "\t" << "\t" << DriveAxis << "\t" << Id << endl;;
				

			}


		}
		if (n == 0)
		{
			cout << "У пользователя с таким логином нет забронированных автомобилей." << endl;
			return;
		}


		//ifstream ifs;
		//ifs.open("reserve.txt");
		//string log1;
		//int n = 0;
		//cout << left << "Марка" << "\t" << "Тип" << "\t" << "Стоимость" << "\t" << "Объем двигателя" << "\t" << "\t" << "Привод" << "\t" << "Id" << endl;
		//cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		//while (ifs >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Id >> log1)
		//{
		//	if (log == log1)
		//	{
		//		n++;
		//		cout << NameOfCar << setw(10) << "\t" << Type << setw(10) << Cost << setw(10) << EngineValue << setw(10) << DriveAxis << setw(10) << Id << endl;
		//	}


		//}
		//if (n == 0)
		//{
		//	cout << "У пользователя с таким логином нет забронированных автомобилей." << endl;
		//	return;
		//}

	}