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
	int mid = n / 2; // ������� �������� ����������� ������������������
	if (n % 2 == 1)
		mid++;
	int h = 1; // ���
			   // �������� ������ ��� ����������� ������������������
	int *c = (int*)malloc(n * sizeof(int));
	int step;
	while (h < n)
	{
		step = h;
		int i = 0;   // ������ ������� ����
		int j = mid; // ������ ������� ����
		int k = 0;   // ������ �������� � �������������� ������������������
		while (step <= mid)
		{
			while ((i < step) && (j < n) && (j < (mid + step)))
			{ // ���� �� ����� �� ����� ����
			  // ��������� ��������� ������� ����������� ������������������
			  // ������� �� ���� ���������������
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
			{ // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
				c[k] = a[i];
				i++; k++;
			}
			while ((j < (mid + step)) && (j<n))
			{  // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
				c[k] = a[j];
				j++; k++;
			}
			step = step + h; // ��������� � ���������� �����
		}
		h = h * 2;
		// ��������� ������������� ������������������ (������������� �������) � �������� ������
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


	
	if (q == 1) /* ����������� ���������� */
	{
		/* ��������� ������ ������� */
		int n; // ���-�� ���������
		cout << "kol-vo elementov: ";
		cin >> n;

			   /* �������� ������ ���������� */
		int *mass = new int[n];
		for (int i = 0; i < n; ++i)
		{

			mass[i] = rand() % 100;
		}

		

		clock_t start = clock();
		getchar();


		/* ����������� ������ �� �������� */
		for (int i = 1; i < n; ++i)
		{
			for (int r = 0; r < n - i; r++)
			{
				if (mass[r] < mass[r + 1])
				{
					// ����� �������
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

		/* ������� ��������������� ������ */
		cout << "Massiv: ";
		for (int i = 0; i < n; ++i)
		{
			cout << mass[i] << " ";
		}
		cout << endl;


		system("pause");
		return 0;
	}



	if (q == 2) /*����������� ����������*/
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

	if (q == 3) /*���������� ��������*/
	{
		int a[f];
		// ���������� ������� ���������� �������
		for (int i = 0; i < f; i++)
		{
			a[i] = rand() % 100;
		}

		clock_t start = clock();
		getchar();

		printf("\n");
		merge(a, f); // ����� ������� ����������
					 // ����� ��������� ������� ����� ����������

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

	if (q == 4) /*���������� ������� */
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


