// Huk-Jivs.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

const int lim = 10;

int i, j, n;
double h, fb, fi, fz;
double x[lim], y[lim], b[lim], p[lim];
bool flag;

double func(double *x)
{
	if (x[0] < 0. || x[1] < 0. || (x[0] + x[1] < 4.))
		return 1.7e+38;
	else
		return 3.*x[0]*x[0] + 4.*x[0]*x[1] + 5.*x[1]*x[1];
}

void research()
{
	//Увеличить на шаг
	x[j] = y[j] + h;
	fz = func(x);
	for(i = 0; i < n; i++)
	{
		if (fz < fi)
		{
			y[j] = x[j];
			fz = func(x);
		}
		else
		{
			//Уменьшить на шаг
			x[j] = y[j] - h;
			fz = func(x);
			if (fz < fi)
			{
				y[j] = x[j];
				fz = func(x);
			}
			else
			{
				//Оставить начальное значение
				x[j] = y[j];
				fz = func(x);
			}
		}
	}
	fi = fz;
}

void vvod()
{
	cout << "Введите начальную точку x1,x2,...,xN:\n";
	for (i = 0; i < n; i++)
		cin >> x[i];
	
	cout << "Введите длину шага:\n";
	cin >> h;
}

void znachbazt() 
{
	//Вычислить значение функции  в базисной точке
	for(i = 0; i < n; i++)
	{
		y[i] = x[i];
		p[i] = x[i];
		b[i] = x[i];
	}

	fi = func(x);

	cout << "Начальное значение функции: " << fi << endl;
	for (i = 0; i < n; i++)
		cout << x[i] << " ";
	cout << endl;
}

void isledovanie()
{
	//Выполнить исследование
	flag = false;
	j = 0;
	fb = fi;

	while(true)
	{
		research();
		cout << "Пробный шаг " << fz << endl;
		for (i = 0; i < n; i++)
			cout << x[i] << " ";
		cout << endl;
		//Если исследованы все текущие координаты
		if (j == n)
		{
			//Текущее значение меньше значения в базисной точке?
			if (fi < (fb - 1e-08))
			{
				//новая базисная точка
				for (i = 0; i < n; i++)
				{
					p[i] = 2.*y[i]-b[i];
					b[i] = y[i];
					x[i] = p[i];
					y[i] = x[i];
				}
				fz = func(x);
				fb = fi;
				flag = true;
				fi = fz;

				cout << "Поиск по образцу: " << fz << endl;
				for (i = 0; i < n; i++)
					cout << x[i] << " ";
				cout << endl;
				j = 0;
					//Новое исследование
				continue;
			}
			else
			{
				if (flag) //Если получена новая базисная точка


				{
					//Замена базисной точки
					for (i = 0; i < n; i++)
					{
						p[i] = b[i];
						y[i] = b[i];
						x[i] = b[i];
					}
					fz = func(x);
					flag = false;
					fi = fz;
					fb = fz;
					cout << "Замена базисной точки: " << fz << endl;
					for (i = 0; i < n; i++)
						cout << x[i] << " ";
					cout << endl;
					j = 0;
					continue;
				}
				else
				{
					//Уменьшить шаг
					h /= 10;
					cout << "Уменьшить длину шага" << endl;
					if (h < 1e-06) break; //Закончить работу, если шаг слишком мал
					j = 0;
					continue;
				}
			}
		}
		else
		{
			j++;
			continue;
		}
	}

}



void vivod()
{
	cout << "Минимум найден" << endl;
	for (i = 0; i < n; i++)
		cout << "x[" << i+1 << "] = " << p[i] << endl;
	cout << "Минимум функции равен: " << fb << endl;
}

void menu() // Функция вызова меню 
{   
	cout<< "Главное меню\n" <<endl;
	cout<< "1. Введите значение\n"
		<< "2. Вывод значений в ОКП\n"
		<< "3. Вычисление значения функции в базисной точке\n"
		<< "4. Исследование вокуруг базисной точки\n"
		<< "5. Выход\n"
		<< " >> " << endl;
}

int _tmain()
{
    setlocale(LC_ALL,"RUS");

	cout << "Введите количество переменных: ";
	cin >> n;

	for (; ; )
	{
		menu();
		int n;
		cin >> n;

		switch (n) //выбор пунктов
		{ 
		case 1:
			vvod();
			break;
		case 2:
			vivod();
			break;
		case 3:
			znachbazt();
			break;
		case 4:
			isledovanie();
			break;
		case 5:
			system("exit");  // выход из программы
			return 0;
		default:
			cout<< "Ошибка . повторите ввод снова \n";
			break;
		}		
	}	

    system("pause");
}
