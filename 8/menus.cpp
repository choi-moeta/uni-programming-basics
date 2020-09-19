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

				file = fopen("../../data.dat", "r+");
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