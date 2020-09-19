#ifndef struct_Apartment
#define struct_Apartment
struct Apartment
{
	char address[100];
	int roomCount;
	int livingSpace;
	bool hasBalcony;
	bool isFamilySuitable; // roomCount >= 2 && livingSpace >= 50
	bool isLast;
};
#endif

bool isFamilySuitable(int roomCount, int livingSpace)
{
	return roomCount >= 2 && livingSpace >= 50 ? 1 : 0;
}

Apartment *createArr (int size)
{
	Apartment *arr;
	arr = new Apartment[size];

	return arr;
}

Apartment *appendArr (Apartment *arr, int size, char* address, int roomCount, int livingSpace, bool hasBalcony)
{
	Apartment* newArr;
	newArr = new Apartment[size+1];

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