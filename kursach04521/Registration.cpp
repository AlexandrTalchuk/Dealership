#include "Registration.h"
string Registration::Encryption(const string Pass)
{
	string parol = "";
	char p;
	int key = Pass.length();//узнаю длину пароля
	if (key % 2 == 0)
		key += 3;
	else key *= 2;
	for (size_t i = 0; i < Pass.length(); i++)
	{
		p = Pass[i] + key;//шифрую с помощью key
		parol += p;
	}
	return parol;
}
string Registration::DeCryprion(const string& Pass)
{
	string parol;
	char p;
	int key = Pass.length();
	if (key % 2 == 0)
		key += 3;
	else key *= 2;
	for (size_t i = 0; i < Pass.length(); i++)
	{
		p = Pass[i] - key;
		parol += p;
	}
	return parol;
}
bool Registration::CheckAuthorization(string login, string pass, int who)
{
	ifstream iof;
	string log, passw, passw1;
	int c = 0;
	if (who == 0)//если входит покупатель
		iof.open("customer.txt");
	if (who == 1)//если входит сотрудник
		iof.open("employee.txt");
	while (!iof.eof())
	{
		iof >> log >> passw;

		if (login == log)
		{
			passw1 = passw;
			Login = login;
			c++;
			break;
		}
	}
	if (c == 0)
	{
		cout << "Логины не совпали!" << endl; return false;
	}

	iof.close();
	passw = DeCryprion(passw1);
	if (pass == passw)
	{
		Password = pass;
		this->who = who;
		cout << "Вход успешно завершен." << endl;
		return true;
	}
	else
	{
		cout << "Введен неверный пароль" << endl;
		return false;
	}
	return false;
}
bool Registration::Registr(string login, string pass, int who)
{
	ifstream iof;
	string log, passw, passw1;
	if (who == 0)
		iof.open("customer.txt");
	if (who == 1)
		iof.open("employee.txt");
	while (iof >> log >> passw)
	{

		if (pass != DeCryprion(passw))
		{

			Login = login;
			continue;

		}
		else { cout << "Такой логин уже существует, придумайте другой!" << endl; return false; }
	}
	iof.close();

	if (passw == "")
	{
		Login = login;

	}
	if (login != log)
	{
		Password = Encryption(pass);
		this->who = who;
		//запись в файл
		ofstream ofs;
		if (who == 0)
		{
			ofs.open("customer.txt", ios::app);
		}
		if (who == 1)
		{
			ofs.open("employee.txt", ios::app);
		}
		ofs << endl;
		ofs << Login << "\t" << Password;
		ofs.close();
		cout << "Регистрация успешно завершена. Теперь введите свои личные данные: " << endl;
		return true;
	}
	else
	{
		cout << "Введенный пароль уже существует в базе, придумайте другой." << endl;
		return false;
	}
	return false;
}

