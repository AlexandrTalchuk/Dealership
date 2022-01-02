#include "Registration.h"
string Registration::Encryption(const string Pass)
{
	string parol = "";
	char p;
	int key = Pass.length();//����� ����� ������
	if (key % 2 == 0)
		key += 3;
	else key *= 2;
	for (size_t i = 0; i < Pass.length(); i++)
	{
		p = Pass[i] + key;//������ � ������� key
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
	if (who == 0)//���� ������ ����������
		iof.open("customer.txt");
	if (who == 1)//���� ������ ���������
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
		cout << "������ �� �������!" << endl; return false;
	}

	iof.close();
	passw = DeCryprion(passw1);
	if (pass == passw)
	{
		Password = pass;
		this->who = who;
		cout << "���� ������� ��������." << endl;
		return true;
	}
	else
	{
		cout << "������ �������� ������" << endl;
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
		else { cout << "����� ����� ��� ����������, ���������� ������!" << endl; return false; }
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
		//������ � ����
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
		cout << "����������� ������� ���������. ������ ������� ���� ������ ������: " << endl;
		return true;
	}
	else
	{
		cout << "��������� ������ ��� ���������� � ����, ���������� ������." << endl;
		return false;
	}
	return false;
}

