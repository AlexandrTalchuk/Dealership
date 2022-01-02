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
	long int id;//����� ��������
public:
	Administrator() {}
	Administrator(string, string, string, string, int);
	Administrator(const Administrator&);
	void NewSurname(const string&, const string&);
	void NewName(const string&, const string&);
	void NewPhone(const string&, const string&);
	string GetLog();
	void FindRecordE(string&);
	void WriteInE();//������ � ���� � ������� � ����������
	void SetAll(string, string, string, string, long int);
	void EditEmp(string, int);//��������� ������ ������ ����������
	friend ostream& operator<<(ostream& os, const Administrator& emp)//���������� ��������� << � ����� ������ � ����������
	{
		cout << "���" << setw(30) << "�������" << setw(30) << "�������" << setw(30) << "����� ��������" << endl;
		os << emp.name << setw(25) << emp.surname << setw(30) << emp.phone << setw(30) << emp.id << endl;
		return os;
	}
};

