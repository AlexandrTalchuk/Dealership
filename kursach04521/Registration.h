#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <conio.h>
using namespace std;
class Registration
{
protected:
	string Login, Password;
	int who;
public:
	static string Encryption(const string);//�������� ������
	static string DeCryprion(const string&);//����������� ������
	bool CheckAuthorization(string, string, int);//�������� �� ������������ �����������
	bool Registr(string, string, int);//�����������
	
};
