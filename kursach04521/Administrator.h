#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
class Administrator
{
	string login, name, surname, phone;
	long int id;//номер договора
public:
	Administrator() {}
	Administrator(string, string, string, string, int);
	Administrator(const Administrator&);
	void NewSurname(const string&, const string&);
	void NewName(const string&, const string&);
	void NewPhone(const string&, const string&);
	string GetLog();
	void FindRecordE(string&);
	void WriteInE();//запись в файл с данными о сотруднике
	void SetAll(string, string, string, string, long int);
	void EditEmp(string, int);//изменение личных данных сотрудника
	friend ostream& operator<<(ostream& os, const Administrator& emp)//перегрузка оператора << и вывод данных о сотруднике
	{
		cout << "Имя" << setw(30) << "Фамилия" << setw(30) << "Телефон" << setw(30) << "Номер договора" << endl;
		os << emp.name << setw(25) << emp.surname << setw(30) << emp.phone << setw(30) << emp.id << endl;
		return os;
	}
};

