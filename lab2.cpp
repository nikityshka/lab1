#include "stdafx.h"
#include <cmath>
#include <time.h>
#include <cstdlib>
#include <iostream>
const int f = 100000;

void selection(int *ar, int size)
{



	int i, j, mx, nmx;

	for (i = 0; i < size - 1; i++)
	{
		mx = ar[i];
		nmx = i;
		for (j = i + 1; j < size; j++)
		{
			if (ar[j]<mx)
			{
				mx = ar[j];
				nmx = j;
			}
		}
		ar[nmx] = ar[i];
		ar[i] = mx;
	}

}

void merge(int *a, int n)
{
	int mid = n / 2; // находим середину сортируемой последовательности
	if (n % 2 == 1)
		mid++;
	int h = 1; // шаг
			   // выдел€ем пам€ть под формируемую последовательность
	int *c = (int*)malloc(n * sizeof(int));
	int step;
	while (h < n)
	{
		step = h;
		int i = 0;   // индекс первого пути
		int j = mid; // индекс второго пути
		int k = 0;   // индекс элемента в результирующей последовательности
		while (step <= mid)
		{
			while ((i < step) && (j < n) && (j < (mid + step)))
			{ // пока не дошли до конца пути
			  // заполн€ем следующий элемент формируемой последовательности
			  // меньшим из двух просматриваемых
				if (a[i] < a[j])
				{
					c[k] = a[i];
					i++; k++;
				}
				else {
					c[k] = a[j];
					j++; k++;
				}
			}
			while (i < step)
			{ // переписываем оставшиес€ элементы первого пути (если второй кончилс€ раньше)
				c[k] = a[i];
				i++; k++;
			}
			while ((j < (mid + step)) && (j<n))
			{  // переписываем оставшиес€ элементы второго пути (если первый кончилс€ раньше)
				c[k] = a[j];
				j++; k++;
			}
			step = step + h; // переходим к следующему этапу
		}
		h = h * 2;
		// ѕереносим упор€доченную последовательность (промежуточный вариант) в исходный массив
		for (i = 0; i<n; i++)
			a[i] = c[i];
	}
}


void radix(long int *ar, int *br, int *cr, int sizeC,long int sizeAB)
{
	int i, k;
	long int n;
	k = sizeC;
	n = sizeAB;
	for (i = 0; i <= k; i++)
		cr[i] = 0;
	for (i = 0; i < n; i++)
		cr[ar[i]] += 1;
	for (i = 1; i < k + 1; i++)
		cr[i] += cr[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		br[cr[ar[i]] - 1] = ar[i];
		cr[ar[i]] -= 1;
	}
}

using namespace std;

int main()
{
	cout << "1 - Puzir'kovaya" << endl;
	cout << "2 - Porazryadnaya" << endl;
	cout << "3 - Sliyaniem" << endl;
	cout << "4 - Viborom" << endl;

	int q;
	cin >> q;


	
	if (q == 1) /* ѕузырькова€ сортировка */
	{
		/* ”становим размер массива */
		int n; //  ол-во элементов
		cout << "kol-vo elementov: ";
		cin >> n;

			   /* «аполним массив значени€ми */
		int *mass = new int[n];
		for (int i = 0; i < n; ++i)
		{

			mass[i] = rand() % 100;
		}

		

		clock_t start = clock();
		getchar();


		/* ќтсортируем массив по убыванию */
		for (int i = 1; i < n; ++i)
		{
			for (int r = 0; r < n - i; r++)
			{
				if (mass[r] < mass[r + 1])
				{
					// ќбмен местами
					int temp = mass[r];
					mass[r] = mass[r + 1];
					mass[r + 1] = temp;
				}
			}
		}
		cout << endl << " VREMYA RABOTY" << endl << " ================================== " << endl;
		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The time: %f seconds\n", seconds);
		system("pause");

		/* ¬ыведем отсортированный массив */
		cout << "Massiv: ";
		for (int i = 0; i < n; ++i)
		{
			cout << mass[i] << " ";
		}
		cout << endl;


		system("pause");
		return 0;
	}



	if (q == 2) /*ѕоразр€дна€ сортировка*/
	{
		long int sizeAB = 0;
		cout << "VVEDITE RAZMER" << endl;
		cin >> sizeAB;
		int sizeC = 100;

		long int *ar = new long int[sizeAB];
		int *br = new int[sizeAB];
		int *cr = new int[sizeC];

		for (int i = 0; i < sizeAB; i++)
		{
			ar[i] = rand() % sizeC;
		}

		clock_t start = clock();
		getchar();


		radix(ar, br, cr, sizeC, sizeAB);

		cout << endl << " VREMYA RABOTY" << endl << " ================================== " << endl;
		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The time: %f seconds\n", seconds);

		system("pause");
		cout << endl << "RADIX" << endl;
		for (int i = 0; i< sizeAB; i++) {
			cout << br[i] << ",";
		}


		system("pause");
		return 0;
	}

	if (q == 3) /*—ортировка сли€нием*/
	{
		int a[f];
		// «аполнение массива случайными числами
		for (int i = 0; i < f; i++)
		{
			a[i] = rand() % 100;
		}

		clock_t start = clock();
		getchar();

		printf("\n");
		merge(a, f); // вызов функции сортировки
					 // ¬ывод элементов массива после сортировки

		cout << endl << " VREMYA RABOTY" << endl << " ================================== " << endl;
		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The time: %f seconds\n", seconds);


		system("pause");
		
		for (int i = 0; i < f; i++)
		{
			cout << a[i] << ",";
		}
		

		system("pause");
		return 0;
	}

	if (q == 4) /*сортировка выбором */
	{
		cout << "VVEDITE RAZMER" << endl;
		int size = 0;
		cin >> size;
		int *ar = new int[size];

		for (int i = 0; i < size; i++)

			ar[i] = rand() % 100;

		clock_t start = clock();
		getchar();

		selection(ar, size);

		cout << endl << " VREMYA RABOTY" << endl << " ================================== " << endl;
		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The time: %f seconds\n", seconds);

		system("pause");
		
		cout << endl << "SORTIROVKA" << endl; cout << " ================================== " << endl;
		
		
		
		for (int i = 0; i< size; i++) {
			cout << ar[i] << ",";
		}
		
		system("pause");
		return 0;
	}

	return 0;

	}


