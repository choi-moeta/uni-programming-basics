#include "pch.h"

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

char* getStr()
{
	int len = 1;

	char* str = new char[len];
	char* tmp = NULL;

	while (true)
	{
		str[len - 1] = getchar();

		if (str[len - 1] == '\b')
		{
			printf("%c", str[len - 1]);
			printf("%c", ' ');
			printf("%c", str[len - 1]);

			tmp = new char[len - 1];

			for (int i = 0; i < len - 2; i++)
			{
				tmp[i] = str[i];
			}

			delete[] str;
			str = tmp;
			len--;
		}

		if (str[len - 1] == '\n')
		{
			str[len - 1] = '\0';
			break;
		}

		tmp = new char[len + 1];

		for (int i = 0; i < len; i++)
		{
			tmp[i] = str[i];
		}

		delete[] str;
		str = tmp;
		len++;
	}

	char* resStr = new char[60];

	strncpy(resStr, str, 60);
	resStr[60] = '\0';

	delete[] str;

	return resStr;
}

int getInt(int min, int max) {
	long input;
	char symbol;
	while (scanf_s("%d%c", &input, &symbol, 1) != 2 || symbol != '\n' || input < min || input > max) {
		printf("Error. Input correct number.\n");
		while (getchar() != '\n');
	}
	return input;
}

int getPositiveInt() {
	long input;
	char symbol;
	while (scanf_s("%d%c", &input, &symbol, 1) != 2 || symbol != '\n' || input < 0) {
		printf("Error. Input correct number.\n");
		while (getchar() != '\n');
	}
	return input;
}

int getBoolStr()
{
	char symbol;
	while (scanf_s("%c", &symbol, 1) && symbol != 'n' && symbol != 'y') {
		printf("Error. Input correct answer(y/n).\n");
		while (getchar() != '\n');
	}
	return symbol == 'y' ? 1 : 0;
}


bool isFamilySuitable(int roomCount, int livingSpace)
{
	return roomCount >= 2 && livingSpace >= 50 ? 1 : 0;
}

struct Apartment
{
	char address[100];
	int roomCount;
	int livingSpace;
	bool hasBalcony;
	bool isFamilySuitable; // roomCount >= 2 && livingSpace >= 50
	bool isLast;
};

Apartment *createArr(int size)
{
	Apartment *arr;
	arr = new Apartment[size];

	return arr;
}

Apartment *appendArr(Apartment *arr, int size, char* address, int roomCount, int livingSpace, bool hasBalcony)
{
	Apartment* newArr;
	newArr = new Apartment[size + 1];

	for (int i = 0; i < size; i++)
	{
		newArr[i].roomCount = arr[i].roomCount;
		newArr[i].livingSpace = arr[i].livingSpace;
		newArr[i].hasBalcony = arr[i].hasBalcony;
		newArr[i].isFamilySuitable = arr[i].isFamilySuitable;
		strcpy(newArr[i].address, arr[i].address);

		newArr[i].isLast = 0;
	}

	newArr[size].roomCount = roomCount;
	newArr[size].livingSpace = livingSpace;
	newArr[size].hasBalcony = hasBalcony;
	newArr[size].isFamilySuitable = isFamilySuitable(roomCount, livingSpace);
	strcpy(newArr[size].address, address);

	newArr[size].isLast = 1;

	//delete[] address;
	delete[] arr;

	return newArr;
}

Apartment *removeArr(Apartment *arr, int size, int index)
{
	Apartment* newArr;
	newArr = new Apartment[size - 1];

	for (int i = 0; i < index; i++)
	{
		newArr[i].roomCount = arr[i].roomCount;
		newArr[i].livingSpace = arr[i].livingSpace;
		newArr[i].hasBalcony = arr[i].hasBalcony;
		newArr[i].isFamilySuitable = arr[i].isFamilySuitable;
		strcpy(newArr[i].address, arr[i].address);

		newArr[i].isLast = 0;
	}

	for (int i = index; i < size - 1; i++)
	{
		newArr[i].roomCount = arr[i + 1].roomCount;
		newArr[i].livingSpace = arr[i + 1].livingSpace;
		newArr[i].hasBalcony = arr[i + 1].hasBalcony;
		newArr[i].isFamilySuitable = arr[i + 1].isFamilySuitable;
		strcpy(newArr[i].address, arr[i + 1].address);

		newArr[i].isLast = 0;
	}

	newArr[size - 2].isLast = 1;

	delete[] arr;

	return newArr;
}

void sortMenu(Apartment *arr, int arrSize);

void showApartments(Apartment *arr, int size);

void showSortedApartments(Apartment *arr, int* sortPattern, int size);

int* sortArrMax(Apartment *arr, int len, int value);

int* sortArrMin(Apartment *arr, int len, int value);

void menu()
{
	Apartment *arr = NULL;

	arr = createArr(1);
	int arrSize = 0;

	bool dataEntered = 0; // TODO toggle
	int ApartmentCount = 0;

	bool menu = 1;
	while (menu)
	{
		printf("Actions.\n");
		printf("1. Add Apartment\n");
		printf("2. Remove Apartment\n");
		printf("3. Show Apartments\n");
		printf("\n");
		printf("4. Save to file\n");
		printf("5. Open from file\n");
		printf("6. Clear apartment list\n");
		printf("\n");
		printf("7. Exit\n");
		printf("\n");

		switch (getInt(1, 7))
		{
		case 1:
		{
			dataEntered = 1;

			printf("  Please input Apartment info:\n");

			printf("1. Address (only 60 symbols): ");
			char* adr = getStr();

			printf("\n2. Number of rooms: ");
			int count = getPositiveInt();

			printf("\n3. Living space (m^2): ");
			int space = getPositiveInt();

			printf("\n4. Balcony existance (y/n): ");
			bool balcony = getBoolStr();

			arr = appendArr(arr, arrSize++, adr, count, space, balcony);

			break;
		}
		case 2:
		{
			if (!dataEntered)
			{
				printf("Error! Please input data first.\n");
			}
			else
			{
				printf("Which Apartment do you want to remove?\n");
				int index = getInt(1, arrSize);

				arr = removeArr(arr, arrSize--, index - 1);
			}

			break;
		}
		case 3:
		{
			if (!dataEntered)
			{
				printf("Error! Please input data first.\n");
			}
			else
			{
				sortMenu(arr, arrSize);
			}

			break;
		}
		case 4:
		{
			if (!dataEntered)
			{
				printf("Error! Please input data first.\n");
			}
			else
			{
				FILE *file;

				file = fopen("../../data.dat", "wb");
				fwrite(arr, sizeof(Apartment), arrSize, file);
				fclose(file);

				printf("Saved successfully.\n");
			}

			break;
		}
		case 5:
		{
			dataEntered = 1;

			FILE *file;

			int i = 1;

			bool isLast = 0;
			while (!isLast)
			{
				delete[] arr;
				arr = createArr(i);

				file = fopen("../../data.dat", "rb");
				fread(arr, sizeof(Apartment), i, file);
				fclose(file);

				isLast = arr[i - 1].isLast;

				i++;
			}

			arrSize = i - 1;

			printf("Loaded successfully.\n");

			break;
		}
		case 6:
		{
			if (!dataEntered)
			{
				printf("Error! Please input data first.\n");
			}
			else
			{
				delete[] arr;

				arr = createArr(1);

				arrSize = 0;

				dataEntered = 0;
			}

			break;
		}
		case 7:
		{
			delete[] arr;

			menu = 0;

			break;
		}
		}
	}
}

void sortMenu(Apartment *arr, int arrSize)
{
	printf("Do you want to sort results? (y/n)\n");

	switch (getBoolStr())
	{
	case 0:
	{
		showApartments(arr, arrSize);

		break;
	} 
	case 1:
	{
		printf("Which way do you want to sort results?\n");

		printf("1. From max to min\n");
		printf("2. From min to max\n");

		int sortType = getInt(1, 2);

		printf(" Sort options:\n");
		printf("1. Address\n");
		printf("2. Number of rooms\n");
		printf("3. Living space(m^2)\n");
		printf("4. Balcony existance(m^2)\n");
		printf("5. Family suitability\n");

		int sortOption = getInt(1, 5);

		int* sortPattern = NULL;

		sortType == 1 ?
			sortPattern = sortArrMax(arr, arrSize, sortOption) :
			sortPattern = sortArrMin(arr, arrSize, sortOption);

		showSortedApartments(arr, sortPattern, arrSize);

		delete[] sortPattern;

		break;
	}
	}
}

void showApartments(Apartment *arr, int size)
{
	printf("| n  | address                                                      | rooms | space(m^2) | balcony | family suitable |\n");
	printf("| -- | ------------------------------------------------------------ | ----- | ---------- | ------- | --------------- |\n");
	for (int i = 0; i < size; i++)
	{
		printf("| %-2d | %-60s | %-5d | %-10d | %-7s | %-15s |\n", i + 1, arr[i].address, arr[i].roomCount, arr[i].livingSpace, arr[i].hasBalcony ? "yes" : "no", arr[i].isFamilySuitable ? "yes" : "no");
	}
}

void showSortedApartments(Apartment *arr, int* sortPattern, int size)
{
	printf("| n  | address                                                      | rooms | space(m^2) | balcony | family suitable |\n");
	printf("| -- | ------------------------------------------------------------ | ----- | ---------- | ------- | --------------- |\n");
	for (int i = 0; i < size; i++)
	{
		printf("| %-2d | %-60s | %-5d | %-10d | %-7s | %-15s |\n", i + 1, arr[sortPattern[i]].address, arr[sortPattern[i]].roomCount, arr[sortPattern[i]].livingSpace, arr[sortPattern[i]].hasBalcony ? "yes" : "no", arr[sortPattern[i]].isFamilySuitable ? "yes" : "no");
	}
}

int* sortArrMax(Apartment *arr, int len, int value)
{
	int max = 0;

	int* sort = new int[len];
	for (int i = 0; i < len; i++)
	{
		sort[i] = i;
	}

	for (int i = 0; i < len; i++)
	{
		max = i;

		for (int j = i + 1; j < len; j++)
		{
			switch (value)
			{
			case 1:
			{
				max = strcmp(arr[sort[max]].address, arr[sort[j]].address) < 0 ? j : max;

				break;
			}
			case 2:
			{
				max = arr[sort[max]].roomCount < arr[sort[j]].roomCount ? j : max;

				break;
			}
			case 3:
			{
				max = arr[sort[max]].livingSpace < arr[sort[j]].livingSpace ? j : max;

				break;
			}
			case 4:
			{
				max = arr[sort[max]].hasBalcony < arr[sort[j]].hasBalcony ? j : max;

				break;
			}
			case 5:
			{
				max = arr[sort[max]].isFamilySuitable < arr[sort[j]].isFamilySuitable ? j : max;

				break;
			}
			}

		}

		int tmp = sort[max];
		sort[max] = sort[i];
		sort[i] = tmp;
	}

	return sort;
}

int* sortArrMin(Apartment *arr, int len, int value)
{
	int min = 0;

	int* sort = new int[len];
	for (int i = 0; i < len; i++)
	{
		sort[i] = i;
	}

	for (int i = 0; i < len; i++)
	{
		min = i;

		for (int j = i + 1; j < len; j++)
		{
			switch (value)
			{
			case 1:
			{
				min = (strcmp(arr[sort[min]].address, arr[sort[j]].address) > 0) ? j : min;

				break;
			}
			case 2:
			{
				min = arr[sort[min]].roomCount > arr[sort[j]].roomCount ? j : min;

				break;
			}
			case 3:
			{
				min = arr[sort[min]].livingSpace > arr[sort[j]].livingSpace ? j : min;

				break;
			}
			case 4:
			{
				min = arr[sort[min]].hasBalcony > arr[sort[j]].hasBalcony ? j : min;

				break;
			}
			case 5:
			{
				min = arr[sort[min]].isFamilySuitable > arr[sort[j]].isFamilySuitable ? j : min;

				break;
			}
			}

		}

		int tmp = sort[min];
		sort[min] = sort[i];
		sort[i] = tmp;
	}

	return sort;
}


int main()
{
	menu();

	return 0;
}
