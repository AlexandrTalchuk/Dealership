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
	static string Encryption(const string);//шифровка пароля
	static string DeCryprion(const string&);//расшифровка пароля
	bool CheckAuthorization(string, string, int);//проверка на правильность регистрации
	bool Registr(string, string, int);//регистрация
	
};
