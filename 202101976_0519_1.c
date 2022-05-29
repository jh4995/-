#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x,y,z) ( (z=x), (x=y), (y=z) )
#define MAX_SIZE 10

int list[MAX_SIZE];

void selection_sort(int list[], int n)
{
	int tmp;
	int minimum;
	for (int i = 0; i < n; i++)
	{
		minimum = i;

		for (int j = i+1; j < n; j++)
		{
			if (list[minimum] < list[j])
				minimum = j;
		}

		SWAP(list[i], list[minimum], tmp);
	}
}

void insertion_sort(int list[], int n)
{
	int i, j, key;

	for (int i = 1; i < n; i++)
	{
		key = list[i];

		for (j = i - 1; j >= 0 && list[j] > key; j--)
		{
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}
}

void bubble_sort(int list[], int n)
{
	int i, j, tmp;

	for (int i = n - 1; i > 0; i--)
	{

		for (int j = 0; j < n; j++)
		{
			if (list[j] < list[j + 1])
				SWAP(list[j], list[j + 1], tmp);
		}
	}
}

int main(void)
{
	int i;
	int n = MAX_SIZE;
	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		list[i] = rand() % 100;
		//selection_sort(list, n);
		//insertion_sort(list, n);
		//bubble_sort(list, n);
	}

	selection_sort(list, n);
	for (i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
	/*
	for (int i = 0; i < n; i++)
	{
		selection_sort(list, n);
		printf("%d ", list[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i++)
	{
		insertion_sort(list, n);
		printf("%d ", list[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i++)
	{
		bubble_sort(list, n);
		printf("%d ", list[i]);
	}
	*/
	return 0;
}