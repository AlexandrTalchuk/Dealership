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
	Customer() {};//����������� �� ���������
	Customer(string, string, string, string); // ����������� � �����������
	Customer(const Customer&);//���������� �����������
	void SetLog(string);//����� ����������� �������� ����������
	string GetLog();//���������� �������� ����������
	void NewSurname(const string&, const string&);//����������� ����� �������� ����������
	void NewName(const string&, const string&);//����������� ����� �������� ����������
	void NewPhone(const string&, const string&);//����������� ����� �������� ����������
	void FindRecordC(string&);//����� ������� ��������
	void WriteInC();//������ � ���� � ������� �����������
	void WriteR();//������ � ���� ��������������� �������
	void WriteB();// ������ � ���� ��������� �������
	void SetAll(string, string, string, string);//������������ �������� ���� ���������� ������
	void EditCust(int, string);//��������� ������ ������
	friend ostream& operator<<(ostream& os, const Customer& cust)//���������� ��������� << � ����� ������ �� �����
	{
		cout << "���" << setw(30) << "�������" << setw(30) << "�������" << endl;
		os << cust.name << setw(25) << cust.surname << setw(30) << cust.phone << endl;
		return os;
	}

};

