// Huk-Jivs.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

const int lim = 10;

int i, j, n;
double h, fi, fb, fz;
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
	//��������� �� ���
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
			//��������� �� ���
			x[j] = y[j] - h;
			fz = func(x);
			if (fz < fi)
			{
				y[j] = x[j];
				fz = func(x);
			}
			else
			{
				//�������� ��������� ��������
				x[j] = y[j];
				fz = func(x);
			}
		}
	}
	fi = fz;
}

void vvod()
{
	cout << "������� ��������� ����� x1,x2,...,xN:\n";
	for (i = 0; i < n; i++)
		cin >> x[i];
	
	cout << "������� ����� ����:\n";
	cin >> h;
}

void znachbazt() 
{
	//��������� �������� �������  � �������� �����
	for(i = 0; i < n; i++)
	{
		y[i] = x[i];
		p[i] = x[i];
		b[i] = x[i];
	}

	fi = func(x);

	cout << "��������� �������� �������: " << fi << endl;
	for (i = 0; i < n; i++)
		cout << x[i] << " ";
	cout << endl;
}

void isledovanie()
{
	//��������� ������������
	flag = false;
	j = 0;
	fb = fi;

	while(true)
	{
		research();
		cout << "������� ��� " << fz << endl;
		for (i = 0; i < n; i++)
			cout << x[i] << " ";
		cout << endl;
		//���� ����������� ��� ������� ����������
		if (j == n)
		{
			//������� �������� ������ �������� � �������� �����?
			if (fi < (fb - 1e-08))
			{
				//����� �������� �����
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

				cout << "����� �� �������: " << fz << endl;
				for (i = 0; i < n; i++)
					cout << x[i] << " ";
				cout << endl;
				j = 0;
					//����� ������������
				continue;
			}
			else
			{
				if (flag) //���� �������� ����� �������� �����


				{
					//������ �������� �����
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
					cout << "������ �������� �����: " << fz << endl;
					for (i = 0; i < n; i++)
						cout << x[i] << " ";
					cout << endl;
					j = 0;
					continue;
				}
				else
				{
					//��������� ���
					h /= 10;
					cout << "��������� ����� ����" << endl;
					if (h < 1e-06) break; //��������� ������, ���� ��� ������� ���
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
	cout << "������� ������" << endl;
	for (i = 0; i < n; i++)
		cout << "x[" << i+1 << "] = " << p[i] << endl;
	cout << "������� ������� �����: " << fb << endl;
}

void menu() // ������� ������ ���� 
{   
	cout<< "������� ����\n" <<endl;
	cout<< "1. ������� ��������\n"
		<< "2. ����� �������� � ���\n"
		<< "3. ���������� �������� ������� � �������� �����\n"
		<< "4. ������������ ������� �������� �����\n"
		<< "5. �����\n"
		<< " >> " << endl;
}

int _tmain()
{
    setlocale(LC_ALL,"Russian");

	cout << "������� ����� ����������: ";
	cin >> n;

	for (; ; )
	{
		menu();
		int n;
		cin >> n;

		switch (n) //����� �������
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
			system("exit");  // ����� �� ���������
			return 0;
		default:
			cout<< "������ . ��������� ���� ����� \n";
			break;
		}		
	}	

    system("pause");
}