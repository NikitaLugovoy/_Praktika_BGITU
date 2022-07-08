// praktikacoop.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;
struct cheloveki //структура
{
	char F[50];//переменная
	char I[50];
	char O[50];
	int Age;

}chel[200];


void vvodstrucktur(cheloveki* chel, int kolvocheloveki)
{
	cout << "\n\nВвод с клавиатуры структуры:\n\n";//вывод

	for (int i = 0; i < kolvocheloveki; i++)//цикл для ввода данных в струтуру
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

void menu()
{   // Функция вызова меню 
	cout << "Главное меню\n" << endl;
	cout << "1. Заполнение структуры с клавиатуры:\n"
		<< "2. Сортировка по возрасту:\n"
		<< "3. Сортировать по алфавиту:\n"
		<< "4. Выход\n"
		<< "Введите пункт: " << endl;
}

void sort(cheloveki* chel, int kolvocheloveki) // сортировка
{
	for (int i = 0; i < kolvocheloveki; i++) // итерация по всем элементам 
	{
		for (int j = kolvocheloveki - 1; j > i; j--) // цикл по неотсортированной части.
			if (chel[j - 1].Age > chel[j].Age)  // Сравниваем текущий, (j-1)-ый элемент// со следующим.
				swap(chel[j - 1], chel[j]); // меняем предшествующий элемент со следующим
		cout << chel[i].F <<" "<< chel[i].I <<" "<< chel[i].O <<"\n";
	}

}

void vizovsort(cheloveki* chel, int kolvocheloveki) // сортировка
{
	cout <<"Сортировка людей по возрасту(возрастание):"<<"\n";
	sort(chel, kolvocheloveki);
}

void alphabetSort(cheloveki* chel, int first, int kolvocheloveki)
{
	if (first >= kolvocheloveki - 1) return;
	int med = (first + kolvocheloveki) / 2; // вычисление среднего элемента
	alphabetSort(chel, first, med); // сортировка левой части
	alphabetSort(chel, med, kolvocheloveki); // сортировка правой части
	cheloveki* b = new cheloveki[kolvocheloveki - first];
	for (int i = first; i < kolvocheloveki; ++i) b[i - first] =chel[i]; // выполняется от начала до конца
	int levo = 0, pravo = med - first;
	for (int i = first; i < kolvocheloveki; ++i) // возвращение результата в список
	{
		if (levo == med - first)
			chel[i] = b[pravo++];
		else if (pravo == kolvocheloveki - first)
			chel[i] = b[levo++];
		else if (strcmp(b[levo].F, b[pravo].F) < 0)
			chel[i] = b[levo++];
		else
			chel[i] = b[pravo++];
	}
	delete[] b;
}

void vizovsortalph(cheloveki* chel, int kolvocheloveki)
{
	cout <<"Сортировка по алфавиту "<<"\n";
	int first = 0;
	alphabetSort(chel, first, kolvocheloveki);
	for (int i = 0; i < kolvocheloveki; i++)
	{
		cout << chel[i].F <<" "<< chel[i].I <<" "<< chel[i].O <<"\n";
	}
}

int _tmain()
{
	SetConsoleCP(1251);//руссификация ввода
	SetConsoleOutputCP(1251);//руссификация вывода 

	cout << "Практика в команде \n\n\n";//вывод


	int kolvocheloveki;
	cout << "Введите количество людей:";//вывод
	cin >> kolvocheloveki;//ввод
	int n;
	for (; ; )
	{
		menu();
		cin >> n;

		switch (n) { //выбор пунктов
		case 1:
			vvodstrucktur(chel, kolvocheloveki);
			break;
		case 2:
			vizovsort(chel, kolvocheloveki);
			break;
		case 3:
			vizovsortalph(chel, kolvocheloveki);
			break;
		case 4:
			system("exit");  // выход 
			return 0;
		default:
			cout << "Введите пункт из представленных!!! \n";
			break;
		}
	}

	system("pause");
	return 0;
}
				
