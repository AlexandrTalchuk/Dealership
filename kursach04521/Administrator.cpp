#include "Administrator.h"

Administrator::Administrator(string login, string name, string surname, string phone, int id)
{
	this->login = login;
	this->name = name;
	this->surname = surname;
	this->phone = phone;
	this->id = id;
}
Administrator::Administrator(const Administrator& obj)
{

	login = obj.login;
	name = obj.name;
	surname = obj.surname;
	phone = obj.phone;
	id = obj.id;
}
void Administrator::NewSurname(const string& log, const string& surname1)
{
	login = log;
	surname = surname1;
}
void Administrator::NewName(const string& log, const string& name1)
{
	login = log;
	name = name1;
}

void Administrator::NewPhone(const string& log, const string& phone1)
{
	login = log;
	phone = phone1;
}

string Administrator::GetLog()
{
	return login;
}
void Administrator::FindRecordE(string& log)
{
	ifstream iof;
	iof.open("employeeData.txt");
	while (iof >> login >> id >> name >> surname >> phone)//чтение данных из файла в переменные
	{

		if (login == log)
		{
			break;
		}

	}
	iof.close();
}
void  Administrator::WriteInE()
{
	ofstream ofs;
	ofs.open("employeeData.txt", ios::app);
	ofs << login << "\t" << name << "\t" << surname << "\t" << phone << "\t" << id << endl;
	ofs.close();
}

void Administrator::SetAll(string login, string name, string surname, string phone, long int id)
{
	this->login = login;
	this->name = name;
	this->surname = surname;
	this->phone = phone;
	this->id = id;
}
void Administrator::EditEmp(string log, int e)
{


	Administrator emp;
	vector <Administrator> ee;

	fstream file;
	file.open("employeeData.txt", ios::app | ios::out | ios::in);
	while (file >> login >> name >> surname >> phone >> id)
	{
		if (login != log)
			ee.push_back(Administrator(login, name, surname, phone, id));
		if (login == log)
		{
			if (e == 1)
			{
				cout << "Введите новое имя" << endl;
				cin >> name;
				NewName(log, name);
				emp.SetAll(log, name, surname, phone, id);
			}
			else if (e == 2)
			{
				cout << "Введите новую фамилию" << endl;
				cin >> surname;
				NewSurname(log, surname);
				emp.SetAll(log, name, surname, phone, id);
			}
			else if (e == 3)
			{
				cout << "Введите новый телефон" << endl;
				cin >> phone;
				NewPhone(log, phone);
				emp.SetAll(log, name, surname, phone, id);
			}
		}
	}
	file.close();


	file.open("employeeData.txt", ios::out);

	file.close();

	for (Administrator emp : ee)

	{

		emp.WriteInE();


	}

	emp.WriteInE();
	cout << "Данные успешно изменены." << endl;
	cout << emp;
}