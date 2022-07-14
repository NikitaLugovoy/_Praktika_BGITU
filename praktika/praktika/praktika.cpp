// Rand0.cpp: определяет точку входа для консольного приложения.
//


#include <iostream>
#include "iomanip"
#include "ctime"
#include <stdlib.h>
#include "fstream"
#include "iostream"


using namespace std;


struct tabl //структура
{
	int b;

}tab[200];


void zap(int kol)
{
	cout << "Вывод результатов в файл: \n";
	fstream a;
	string fail;
	cout << "Введите название файла (вместе с расширением):";
	cin >> fail;
	a.open(fail, fstream::app | fstream::out);

	if (!a.is_open())
	{
		cout << "Не удалось открыть файл :(((";
	}
	else
	{
		for (int i = 0; i < kol; i++)
		{
			a << tab[i].b << '\t';
			// Если мы напечатали 5 чисел, начинаем новую строку
			if (i % 5 == 0)
				cout << '\n';
		}
	}
	a.close();

}


void zap1(int kol)
{
	cout << "Вывод результатов в файл: \n";
	fstream a;
	string fail;
	cout << "Введите название файла (вместе с расширением):";
	cin >> fail;
	a.open(fail, fstream::app | fstream::out);

	if (!a.is_open())
	{
		cout << "Не удалось открыть файл :(((";
	}
	else
	{
		for (int i = 1; i < kol + 1; i++)
		{
			a << tab[i].b << '\t';
			// Если мы напечатали 5 чисел, начинаем новую строку
			if (i % 5 == 0)
				a << '\n';
		}
	}
	a.close();
}




void rand1()
{
	int kol;
	kol = 1;
	srand(0);
	cout << "\n\nВывод случайного числа:" << endl;
	tab[0].b = rand();
	cout << tab[0].b << endl;
	//но в этом случае программа первый раз выводит
	//случайное число и запоминает его, для того чтобы
	//во всех последующих запусках выводить его же
	zap(kol);
}

void rand2()
{
	int kol;
	kol = 1;
	cout << "\n\nВывод каждый раз случайного числа" << endl;
	srand(time(0));
	tab[0].b = rand();
	cout << tab[0].b << endl;
	zap(kol);

}

void rand3()
{
	int kol;
	kol = 1;
	cout << "\n\nВывод рандомного числа в определённом диапазоне" << endl;
	int perv;
	int posl;
	cout << "Введите число от которого будет начинаться диапазон" << endl;
	cin >> perv;
	cout << "Введите число которым будет заканчиваться диапазон" << endl;
	cin >> posl;
	cout << "Вывод рандомного числа в заданном диапазоне:" << endl;
	tab[0].b = perv + rand() % posl;
	cout << tab[0].b << endl;
	zap(kol);

}

void rand4()
{
	
	srand(time(0));
	int kol;
	cout << "\n\nВведите количество рандомных чисел" << endl;
	cin >> kol;
	
	for (int i{ 1 }; i <= kol; ++i)
	{
		tab[i].b = rand();
		cout << tab[i].b << '\t';
					// Если мы напечатали 5 чисел, начинаем новую строку
		if (i % 5 == 0)
			cout << '\n';
	}

	zap1(kol);

}

void menu()
{
	cout << "\n\nМеню выбора" << endl;
	cout << "1.Вывод рандомного числа \n"
		<< "2.Вывод каждый раз разного числа \n"
		<< "3.Вывод рандомного числа в определённом диапазоне\n"
		<< "4.Вывод определённого количества рандомных чисел\n"
		<< "5.ВЫХОД\n"
		<< "Введите пункт:" << endl;


}
int main()
{
	setlocale(0, "");

	cout << "Индивидуальное задание на практику!!!";
	
	int n;
	for ( ; ; )
	{
		menu();
		cin >> n;

		switch (n) { //выбор пунктов
		case 1:
			rand1();
			break;
		case 2:
			rand2();
			break;
		case 3:
			rand3();
			break;
		case 4:
			rand4();
			break;
		case 5:
			system("pause");
			return 0;
		default:
			cout << "Введите пункт из представленных!!! \n";
			break;
		}

	}
	system("pause");
	return 0;
}
