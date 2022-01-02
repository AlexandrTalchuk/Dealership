#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Customer
{
protected:
	string login;
	string name;
	string surname;
	string phone;
public:
	Customer() {};//конструктор по умолчанию
	Customer(string, string, string, string); // конструктор с параметрами
	Customer(const Customer&);//коструктор копирования
	void SetLog(string);//метод присваивает значение переменной
	string GetLog();//возвращает значение переменной
	void NewSurname(const string&, const string&);//присваивает новое значение переменной
	void NewName(const string&, const string&);//присваивает новое значение переменной
	void NewPhone(const string&, const string&);//присваивает новое значение переменной
	void FindRecordC(string&);//поиск нужного аккаунта
	void WriteInC();//запись в файл с данными покупателей
	void WriteR();//запись в файл забронированных товаров
	void WriteB();// запись в файл купленных товаров
	void SetAll(string, string, string, string);//присваивание значений всем переменным класса
	void EditCust(int, string);//езменение личных данных
	friend ostream& operator<<(ostream& os, const Customer& cust)//перегрузка оператора << и вывод данных из файла
	{
		cout << "Имя" << setw(30) << "Фамилия" << setw(30) << "Телефон" << endl;
		os << cust.name << setw(25) << cust.surname << setw(30) << cust.phone << endl;
		return os;
	}

};

