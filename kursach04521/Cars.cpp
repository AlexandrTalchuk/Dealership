#include "Cars.h"
Cars::Cars()
{

}
int Cars::GetCost()
{
	return Cost;
}
int Cars::GetId()
{
	return Id;
}
Cars::Cars(const Cars& obj)
{
	NameOfCar = obj.NameOfCar;
	Type = obj.Type;
	Cost = obj.Cost;
	EngineValue = obj.EngineValue;
	DriveAxis = obj.DriveAxis;
	Id = obj.Id;
}
Cars::Cars(string NameOfCar, string Type, int Cost, int EngineValue, string DriveAxis, int Id)
{
	this->NameOfCar = NameOfCar;
	this->Type = Type;
	this->Cost = Cost;
	this->EngineValue = EngineValue;
	this->DriveAxis = DriveAxis;
	this->Id = Id;
}

void Cars::SetData(string NameOfCar, string Type, int Cost, int EngineValue, string DriveAxis, int Id)
{
	this->NameOfCar = NameOfCar;
	this->Type = Type;
	this->Cost = Cost;
	this->EngineValue = EngineValue;
	this->DriveAxis = DriveAxis;
	this->Id = Id;
}

void Cars::ViewAll(int CountFile) const
{
	cout << left<< setw(15) << NameOfCar << "\t" << setw(10) << Type << "\t" << setw(10) << Cost << "\t" << setw(10) << EngineValue << "\t" << setw(10) << DriveAxis << "\t" << setw(10) << Id << endl;
}

void Cars::ShowCars()
{
	ifstream ifs;
	ifs.open("Cars.txt");
	string line = "";
	cout << left << "Марка" << "\t" << "Тип"<<"\t" << "Стоимость" << "\t"<< "Объем двигателя" << "\t" << "\t" << "Привод" << "\t" << "Id" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------" <<endl;
	while (getline(ifs, line))
	{
		cout << line;
		cout << setw(10) << endl;
	}
}

void Cars::RemoveCars(int Id1)
{
	ifstream ifs;
	vector<Cars> c;
	ifs.open("Cars.txt");
	while (ifs >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis>>Id)
	{
		if (Id1 != Id)
			c.push_back(Cars(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id));
	}
	ifs.close();
	ofstream ofs;
	ofs.open("Cars.txt", ios::out);
	ofs.close();
	for (Cars cl : c)
	{
		cl.SortWrite();
	}
	cout << "Товар успешно удален." << endl;
}

void Cars::WriteIn(string NameOfCar, string Type, int Cost, int EngineValue, string DriveAxis, int Id)
{
	ofstream File;
	File.open("Cars.txt", ios::app);
	File << endl;
	File << NameOfCar << "\t" << Type << "\t" << Cost << "\t" << "\t" << EngineValue << "\t" << "\t" << "\t" << DriveAxis << "\t" << Id;
	File.close();
}

void Cars::SortWrite()
{
	ofstream File;
	File.open("Cars.txt", ios::app);
	File << endl;
	File << NameOfCar << "\t" << Type << "\t" << Cost << "\t"<<"\t"  << EngineValue << "\t" << "\t" << "\t" << DriveAxis << "\t" << Id;
	File.close();

}

void Cars::WritePurchaseToFile()
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
	File.open("Cars.txt", ios::app);
	File << NameOfCar << "\t" << Type << "\t" << Cost << "\t" << "\t" << EngineValue << "\t" << "\t" << "\t" << DriveAxis << "\t" << Id;
	File.close();
	cout << "Автомобиль успешно добавлен." << endl;
}

void Cars::Find(int f, string name1)
{
	ifstream ifs;
	ifs.open("Cars.txt");
	int count_ = 0;
	switch (f)
	{
	case 1:
		while (ifs >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Id)
		{

			if (NameOfCar == name1)
			{
				SetData(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id);
				ViewAll(count_);
				count_ = 1;

			}
		}
		break;
	case 2:
		while (ifs >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Id)
		{

			if (Type == name1)
			{
				SetData(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id);
				ViewAll(count_);
				count_ = 1;

			}
		}
		break;
	case 3:
		while (ifs >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Id)
		{

			if (DriveAxis == name1)
			{
				SetData(NameOfCar, Type, Cost, EngineValue, DriveAxis,Id);
				ViewAll(count_);
				count_ = 1;

			}
		}
		break;
	}
	if (count_ == 0)
	{
		cout << "Автомобили с такими критериями не найдены." << endl;
	}

}

void Cars::Sortirovka()
{
	Cars cl;
	fstream ifs;
	vector <Cars> c;
	int sort_;
	ifs.open("Cars.txt", ios::app | ios::out | ios::in);
	while (ifs >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Id)
	{

		c.push_back(Cars(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id));
	}
	ifs.close();
	cout << "Сортировать по убыванию цены нажмите  - 1, по возрастанию -2 " << endl;
	cin >> sort_;
	switch (sort_)
	{
	case 1:
		sort(c.begin(), c.end(), [](Cars p1, Cars p2)
			{
				return p1.GetCost() > p2.GetCost();

			}
		);
		ifs.open("Cars.txt", ios::out);

		ifs.close();
		for (Cars cl : c)
		{
			cl.SortWrite();
		}
		cl.ShowCars();
		break;
	case 2:
		sort(c.begin(), c.end(), [](Cars p1, Cars p2)
			{
				return p1.GetCost() < p2.GetCost();

			}
		);
		ifs.open("Cars.txt", ios::out);

		ifs.close();
		for (Cars cl : c)
		{
			cl.SortWrite();
		}
		cl.ShowCars();
		break;
	default:
		break;
	}
}

ostream& operator<<(ostream& os, const Cars& cl)
{

	os << cl.NameOfCar << "\t" << cl.Type << "\t" << cl.Cost << "\t" << cl.Cost << "\t" << cl.EngineValue << "\t" << cl.DriveAxis << "\t" << cl.Id << endl;
	return os;
}

void Cars::Filtr(int a, int b)
{
	ifstream ifs;
	Cars car;
	string line = "";
	ifs.open("Cars.txt");
	cout << left << "Марка" << "\t" << "Тип" << "\t" << "Стоимость" << "\t" << "Объем двигателя" << "\t" << "\t" << "Привод" << "\t" << "Id" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------" << endl;
	while (getline(ifs, line))//(ifs >> NameOfCar >> Type >> Cost >> EngineValue >> DriveAxis >> Id)
	{
		if (Cost > a && Cost < b)
		{
			car.SetData(NameOfCar, Type, Cost, EngineValue, DriveAxis, Id);
			cout << car;
		}
		cout << line;
		cout << setw(10) << endl;
	}
	ifs.close();	
	ofstream ofs;


	
	
	/*cout << left << "Марка" << "\t" << "Тип" << "\t" << "Стоимость" << "\t" << "Объем двигателя" << "\t" << "\t" << "Привод" << "\t" << "Id" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------" << endl;
	while (getline(ifs, line))
	{
		cout << line;
		cout << setw(10) << endl;
	}*/
}

