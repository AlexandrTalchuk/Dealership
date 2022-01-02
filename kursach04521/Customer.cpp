#include "Customer.h"

Customer::Customer(string login, string name, string surname, string phone)
{

	this->login = login;
	this->name = name;
	this->surname = surname;
	this->phone = phone;
}
Customer::Customer(const Customer& obj)
{

	login = obj.login;
	name = obj.name;
	surname = obj.surname;
	phone = obj.phone;
}
void Customer::SetLog(string login)
{
	this->login = login;
}
string Customer::GetLog()
{
	return login;
}
void Customer::NewSurname(const string& log, const string& surname1)
{
	login = log;
	surname = surname1;
}
void Customer::NewName(const string& log, const string& name1)
{
	login = log;
	name = name1;
}
void Customer::NewPhone(const string& log, const string& phone1)
{
	login = log;
	phone = phone1;
}
void Customer::FindRecordC(string& log)
{
	ifstream iof;
	iof.open("customData.txt");//открытие файла
	while (iof >> login >> name >> surname >> phone)//чтение данных из файла в переменные
	{

		if (login == log)
		{
			break;
		}

	}
	iof.close();
}
void Customer::WriteInC()
{
	ofstream ofs;
	ofs.open("customData.txt", ios::app);//открытие файла
	ofs << login << "\t" << name << "\t" << surname << "\t" << phone << endl;// чтение из переменных в файл
	ofs.close();
}
void Customer::WriteR()
{
	ofstream ofs;
	ofs.open("reserve.txt", ios::app);
	ofs << "\t" << login << endl;
	ofs.close();
}
void Customer::WriteB()
{
	ofstream ofs;
	ofs.open("bought.txt", ios::app);
	ofs << "\t" << login << endl;
	ofs.close();
}
void Customer::SetAll(string login, string name, string surname, string phone)
{
	this->login = login;
	this->name = name;
	this->surname = surname;
	this->phone = phone;
}
void Customer::EditCust(int e, string log)
{
	Customer cust;
	vector <Customer> c;
	int i = 0;
	fstream file;
	file.open("customData.txt", ios::app | ios::out | ios::in);//открытие и для записи, и для чтения
	while (file >> login >> name >> surname >> phone)//чтение данных из файла
	{

		if (login != log)//если логины не совпали, эти данные изменяться не будут

			c.push_back(Customer(login, name, surname, phone));//поэтому записываем из в вектор
		if (login == log)//проверка на существование логина
		{
			i++;
			if (e == 1)
			{
				cout << "Введите новое имя" << endl;
				cin >> name;
				NewName(log, name);
				cust.SetAll(log, name, surname, phone);
			}
			else if (e == 2)
			{
				cout << "Введите новую фамилию" << endl;
				cin >> surname;
				NewSurname(log, surname);
				cust.SetAll(log, name, surname, phone);
			}
			else if (e == 3)
			{
				cout << "Введите новый телефон" << endl;
				cin >> phone;
				NewPhone(log, phone);
				cust.SetAll(log, name, surname, phone);
			}
		}
	}
	file.close();
	if (i == 0)
	{
		cout << "Такого логина не существует" << endl;
		return;
	}


	//очистка файла
	file.open("customData.txt", ios::out);

	file.close();

	for (Customer cust : c)//записываем данные из вектора обратно в файл

	{

		cust.WriteInC();


	}

	cust.WriteInC();//запись измененных данных в файл покупателя
	cout << "Данные успешно изменены." << endl;
	cout << cust;//вывод измененных данных
}
