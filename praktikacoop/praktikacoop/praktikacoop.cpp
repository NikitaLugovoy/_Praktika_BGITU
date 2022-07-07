// praktikacoop.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "iostream"
#include "windows.h"

using namespace std;
struct cheloveki //структура
{
	char F[50];//переменная
	char I[50];
	char O[50];
	int Age;

}chel[200];


void vvodstrucktur(cheloveki* chel, int kolvostudentov)
{
	cout << "\n\nВвод с клавиатуры структуры:\n\n";//вывод

	for (int i = 0; i < kolvostudentov; i++)//цикл для ввода данных в струтуру
	{
		cout << "Введите фамилию :";
		cin >> chel[i].F;

		cout << "Введите имя :";
		cin >> chel[i].I;

		cout << "Введите отчество :";
		cin >> chel[i].O;

		cout << "Введите возраст:";
		cin >> chel[i].Age;
		cout << "\n";

	}
	cout << "\n\n";

}

void menu() {   // Функция вызова меню 
	cout << "Главное меню\n" << endl;
	cout << "1. Заполнение структуры с клавиатуры:\n"
		<< "2. Сортировка по возрасту:\n"
		<< "3. Сортировать по алфавиту:\n"
		<< "4. Выход\n"
		<< "Введите пункт: " << endl;
}


int _tmain()
{
	SetConsoleCP(1251);//руссификация ввода
	SetConsoleOutputCP(1251);//руссификация вывода 

	cout << "Курсовая работа!!! \n\n\n";//вывод


	int kolvostudentov;
	cout << "Введите количество людей:";//вывод
	cin >> kolvostudentov;//ввод
	int n;
	for (; ; )
	{
		menu();
		cin >> n;

		switch (n) { //выбор пунктов
		case 1:
			vvodstrucktur(chel, kolvostudentov);
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:
			system("pause");  // выход 
			return 0;
		default:
			cout << "Введите пункт из представленных!!! \n";
			break;
		}
	}

	system("pause");
	return 0;
}

