
//СИСТЕМА УЧЁТА ПРОДАЖ АВТОМОБИЛЕЙ В АВТОСАЛОНАХ
//1) Разработка пользовательского меню, включающего следующие опции :
//­ разделение ролей, авторизация пользователя, хранение пароля в зашифрованном виде;
//­ просмотр необходимой информации;
//­ добавление, редактирование и удаление записей;
//­ поиск, сортировка и фильтрация записей;
//­ реализация заказа(вывод отчета);
//­ другие опции в зависимости от специфики задачи.
//2) Исходная и итоговая информация должна храниться в текстовых(бинарных) файлах.
//Для хранения данных в оперативной памяти использовать контейнеры библиотеки STL.
//3) Предусмотреть использование в программе следующих аспектов :
//­ реализация базовых принципов объектно - ориентированного программирования;
//­ использование стандартных, пользовательских, дружественных, виртуальных
//функции;
//­ использование пространств имен(стандартных и собственных);
//­ реализация обработки ошибок программы(средствами языка С++);
//­ использование механизмов абстракции;
//­ использование классов и наследования;
//­ использование перегрузки методов;
//­ использование шаблонов классов и методов;
//­ использование динамического выделения памяти и умных указателей(smart pointers).
//­ использование потоков С++, перегрузки операторов ввода / вывода, контролирования
//работы с потоком.
//4) Обязательно использовать сокрытие данных(инкапсуляцию), переопределение
//методов, абстрактные классы, передачу параметров по ссылке и по значению, статические
//методы и поля



#include <Windows.h>
#include "Registration.h"
#include "Cars.h"
#include "Sedan.h"
#include "Coupe.h"
#include "Wagon.h"
#include "SUV.h"
#include "Menu.h"
#include "Customer.h"
#include "Administrator.h"
#include "Reserve.h"
#include "Buy.h"

using namespace std;
using namespace Menu;

template<typename T>
	void ErrorVvod(T* w)// проверка на не числовой ввод
	{
		while (!(cin >> *w))
		{
			//system("cls");
			cin.clear();
			while (cin.get() != '\n')
			{
	
			}
			cout << "Вы ввели некорректно. Повторите ввод!" << endl;
	
		}
	}
string InputPassword()
{
	string s{};
	char c{};

	while (true)
	{
		c = _getch();//принимает значение введенных с клавиатуры символов
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))//только нужные символы
		{
			s += c;
			_putch('*');//вывод *
		}
		if (c == '\b')//если backspace
		{
			cout << "\b \b";
			s.erase(s.length() - 1);

		}
		if (c == '\r')// если enter
		{
			cout << endl;
			if (s.length() < 6) {
				cout << "В пароле должно быть не меньше 6 символов! \n" << endl;
				cout << "Введите пароль еще раз: ";
				//s = "";
			}
			else
				break;
		}
	}
	return s;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string pass = "";
	string log;
	long int id;
	int f;
	double price;
	string size, _name;
	string color, name;
	bool vhod = false; bool reg = false;
	Registration record;
	Customer cust, cust1;
	Administrator emp, emp1;
	Cars car;
	Coupe coupe;
	SUV suv;
	Wagon wagon;
	Sedan sedan;
	Reserv r;
	Buy b;
	string Login, Name, Surname, Phone, p;
	int sw = 0, e = 0;
	fstream file;
	vector<Customer> c1;
	vector<Customer> c;
	vector<Administrator> eee;
	vector <Cars> cars;
	unique_ptr<Cars> search(new Cars());
anyway:
	switch (GlavnoeMenu())
	{
	case 1://авторизация
		switch (MenuWho1())
		{
		case 1://регистрация покупателя
			cout << "Введите логин: ";
			while (!(cin >> log))
			{
				system("cls");
				cin.clear();
				while (cin.get() != '\n')
					cout << "Вы ввели некорректно. Повторите ввод!" << endl;

			}

			cout << "Введите пароль: ";
			pass = InputPassword();
			reg = record.Registr(log, pass, 0);
			while (reg == false)
			{
				cout << "Введите логин снова: ";
				while (!(cin >> log))
				{
					system("cls");
					cin.clear();
					while (cin.get() != '\n')
						cout << "Вы ввели некорректно. Повторите ввод!" << endl;

				}

				cout << "Введите пароль: ";
				pass = InputPassword();
				reg = record.Registr(log, pass, 0);
			}
			cout << "Введите Имя: ";
			cin >> Name;
			cout << "Введите Фамилию: ";
			cin >> Surname;
			cout << "Введите Телефон: ";
			cin >> Phone;
			cust.SetAll(log, Name, Surname, Phone);
			cust.WriteInC();
			cout << "Спасибо." << endl;
			sw = 1;
			//system("cls");
			break;
		case 2://регистрация сотрудника
			cout << "Введите логин: ";
			while (!(cin >> log))
			{
				system("cls");
				cin.clear();
				while (cin.get() != '\n')
					cout << "Вы ввели некорректно. Повторите ввод!" << endl;

			}

			cout << "Введите пароль: ";
			pass = InputPassword();
			reg = record.Registr(log, pass, 1);
			while (reg == false)
			{
				cout << "Введите логин снова: ";
				while (!(cin >> log))
				{
					system("cls");
					cin.clear();
					while (cin.get() != '\n')
						cout << "Вы ввели некорректно. Повторите ввод!" << endl;

				}

				cout << "Введите пароль: ";
				pass = InputPassword();
				reg = record.Registr(log, pass, 1);
			}
			cout << "Введите Имя: " << endl;
			cin >> Name;
			cout << "Введите Фамилию: " << endl;
			cin >> Surname;
			cout << "Введите Телефон: " << endl;
			cin >> Phone;
			cout << "Введите свой номер договора: " << endl;
			cin >> id;
			emp.SetAll(log, Name, Surname, Phone, id);
			emp.WriteInE();
			cout << "Спасибо." << endl;
			sw = 2;
			break;
		case 3:
			goto anyway;
		default:
			break;

		}
		break;


	case 2://вход
		switch (MenuWho())
		{
		case 1://вход как покупатель
			cout << "Введите логин: ";
			while (!(cin >> log))
			{
				system("cls");
				cin.clear();
				while (cin.get() != '\n')
					cout << "Вы ввели некорректно. Повторите ввод!" << endl;

			}

			cout << "Введите пароль: ";
			pass = InputPassword();
			vhod = record.CheckAuthorization(log, pass, 0);
			while (vhod == false)
			{
				cout << "Введите логин снова: ";
				while (!(cin >> log))
				{
					system("cls");
					cin.clear();
					while (cin.get() != '\n')
						cout << "Вы ввели некорректно. Повторите ввод!" << endl;

				}

				cout << "Введите пароль: ";
				pass = InputPassword();
				vhod = record.CheckAuthorization(log, pass, 0);
			}

			cust.FindRecordC(log);
			sw = 1;
			break;
		case 2://вход как сотрудник
			cout << "Введите логин: ";
			while (!(cin >> log))
			{
				system("cls");
				cin.clear();
				while (cin.get() != '\n')
					cout << "Вы ввели некорректно. Повторите ввод!" << endl;

			}

			cout << "Введите пароль: ";
			pass = InputPassword();
			vhod = record.CheckAuthorization(log, pass, 1);
			while (vhod == false)
			{
				cout << "Введите логин снова: ";
				while (!(cin >> log))
				{
					system("cls");
					cin.clear();
					while (cin.get() != '\n')
						cout << "Вы ввели некорректно. Повторите ввод!" << endl;

				}

				cout << "Введите пароль: ";
				pass = InputPassword();
				vhod = record.CheckAuthorization(log, pass, 1);
			}

			emp.FindRecordE(log);
			sw = 2;
			break;
		case 3:
			goto anyway;
		default:
			break;
		}
		break;
	case 3:
		return 0;

	default:
		break;

	}
	while (true)
	{
		switch (sw)

		{
		case 1://меню посетителя
		menuC:
			while (true)
			{
				switch (MenuCust())
				{
				case 1: cout << cust; break;
				case 2:
					cout << "Что бы вы хотели изменить? \n 1. Имя \n 2. Фамилию \n 3. Номер телефона \n 0. Вернуться в меню \n";
					ErrorVvod(&e);
					if (e == 0)
					{
						goto menuC;
					}
					cout << "Введите свой логин" << endl;
					cin >> log;
					cust.EditCust(e, log);

					break;
				case 3:
					car.ShowCars();
					break;
				case 4:
					cout << "Введите 1 для поиска по названию автомобиля, 2 - по типу кузова, 3 - по типу привода " << endl;
					ErrorVvod(&f);
					cout << "Введите поисковое слово:" << endl;
					ErrorVvod(&_name);
					search->Find(f, _name);
					break;
					case 5:
						car.Sortirovka();
						break;
					case 6:
						cout << "Введите от __ до __ какой цены вы хотите применить фильтр" << endl;
						cout << "От:";
						ErrorVvod(&f);
						cout << "До:";
						ErrorVvod(&e);
						car.Filtr(f, e);
						break;
					case 7:
						cout << "Введите Id автомобиля, который хотите купить" << endl;
						car.ShowCars();
						ErrorVvod(&e);
						cout << "Введите свой логин" << endl;
						cin >> log;
						r.AddReserve(e, log);
						break;
					case 8:
						cout << "Введите свой логин" << endl;
						cin >> log;
						cout << "Введите Id автомобиля, который хотите удалить из покупки" << endl;
						r.ShowReserve(log);
						ErrorVvod(&e);
						r.DelReserve(e, log);
						break;
					case 9:
						cout << "Введите свой логин" << endl;
						cin >> log;
						r.ShowReserve(log);
						break;
					case 10:
						cout << "Введите свой логин" << endl;
						cin >> log;
						cout << "Введите номер своей карты" << endl;
						ErrorVvod(&id);
					buu:
						cout << "Введите количество денег на карте:" << endl;
						ErrorVvod(&price);
						cout << "Введите Id автомобиля, который хотите приобрести" << endl;
						r.ShowReserve(log);
						ErrorVvod(&e);
						b.AddBuy(e, log, price);
						car.RemoveCars(e);
						cout << "Хотите приобрести что-нибудь еще? 1 - да, 2 - нет" << endl;
						ErrorVvod(&f);
						if (f == 1)
							goto buu;
						else
							break;
				case 0: return false;
				}
			}
		case 2://меню админа
		goemp:
			switch (MenuEmp())
			{

			case 1: cout << emp;
				break;
			case 2:
				cout << "Что бы вы хотели изменить? \n 1. Имя \n 2. Фамилию \n 3. Номер телефона \n 0. Вернуться в меню \n";
				ErrorVvod(&e);
				if (e == 0)
				{
					goto menuC;
				}
				cout << "Введите свой логин" << endl;
				cin >> log;
				emp.EditEmp(log, e);


				break;
			case 3: car.ShowCars(); break;
			case 4:
				switch (MenuAdd())
				{
				case 1: coupe.WritePurchaseToFile();
					break;
				case 2: wagon.WritePurchaseToFile();
					break;
				case 3: suv.WritePurchaseToFile();
					break;
				case 4: sedan.WritePurchaseToFile();
					break;
				case 5: car.WritePurchaseToFile();
					break;

				}
				break;
					case 5:
						cout << "Введите 1 для поиска по имени автомобиля, 2 - по типу автомобиля и 3 - по объему двигателя " << endl;
						ErrorVvod(&f);
						cout << "Введите поисковое слово:" << endl;
						ErrorVvod(&_name);
						search->Find(f, _name);
						break;
					case 6:
						car.Sortirovka();
					case 7:
						cout << "Введите от __ до __ какой цены вы хотите применить фильтр" << endl;
						cout << "От:";
						ErrorVvod(&f);
						cout << "До:";
						ErrorVvod(&e);
						car.Filtr(f, e);
						break;
					case 8:
						b.ShowBuy();
						break;
					case 9:
						cout << "Введите Id автомобиля, который хотите удалить" << endl;
						car.ShowCars();
						ErrorVvod(&f);
						car.RemoveCars(f);
						break;
					case 0: return false;

					
			}



		}

	}
}