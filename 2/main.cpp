#include "pch.h"
#include <iostream>
#include <clocale>
#include <stdlib.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int getPositiveInt() {
	long input;
	char char_;
	while (scanf_s("%d%c", &input, &char_, 1) != 2 || char_ != '\n' || input < 0) {
		printf("Error. Input correct number.\n");
		while (getchar() != '\n');
	}
	return(input);
}

int showArray(int *arr, int length) {
	printf("[ ");
	for (int i = 0; i < length; i++) {
		printf("%d", arr[i]);
		printf(i == length - 1 ? " " : ", ");
	}
	printf("]\n");

	return 0;
}

int fill(int *arr, int length) {
	printf("How do you want to fill array?\n");
	printf("1. Randomly\n"); // randomly
	printf("2. By hand\n"); // by hand

	switch (getPositiveInt()) {
	case  1: { // randomly
		for (int i = 0; i < length; i++) {
			arr[i] = rand() % 100;
		}

		break;
	}
	case 2: { // by hand
		for (int i = 0; i < length; i++) {
			printf("%i: ", (i + 1));
			arr[i] = getPositiveInt();
		}

		break;
	}
	}
	printf("Your array: ");
	showArray(arr, length);

	return *arr;
}

int main()
{
	printf("Hey, welcome back, long time no see.\n");
	printf("Enter length of array (likely multiple of 3 and not less then 6): ");
	int monthsNumber = getPositiveInt();
	int *months = new int[monthsNumber];
	*months = fill(months, monthsNumber);

	bool menu = 1;
	while (menu) {
		printf("Actions of array.\n");
		printf("1. Fill the array\n");
		printf("2. Process the array\n");
		printf("3. Show the array\n");
		printf("4. Exit\n");

		switch (getPositiveInt()) {
		// fill array
		case 1: {
			*months = fill(months, monthsNumber);

			break;
		}
		// precess array
		case 2: {
			if (monthsNumber < 4) {
				printf("Not enough information for calculate total amount of precipitation by quartal.\n");
			}
			else {
				printf("Total amount of precipitation by quartal: \n");
				int totalQuartal = 0;
				for (int i = 0, n = 1; i < monthsNumber; i++) {
					totalQuartal += months[i];
					if ((i + 1) % 4 == 0) {
						printf("%d qurtal: ", n);
						printf("%d\n", totalQuartal);
						n++;
						totalQuartal = 0;
					}
				}
			}
			int totalHalf = 0;
			if (monthsNumber < 6) {
				printf("Not enough information for calculate total amount of precipitation by half.\n");
			}
			else {
				printf("Total amount of precipitation by half: \n");
				int totalHalf = 0;
				for (int i = 0, n = 1; i < monthsNumber; i++) {
					totalHalf += months[i];
					if ((i + 1) % 6 == 0) {
						printf("%d half: ", n);
						printf("%d\n", totalHalf);
						n++;
						totalHalf = 0;
					}
				}
			}

			int total = 0;
			for (int i = 0; i < monthsNumber; i++) {
				total += months[i];
			}
			printf("Avarage amount of precipitation:\n");
			printf("%i\n", (total / monthsNumber));

			break;

		// print array
		} case 3: {
			printf("Your array: ");
			showArray(months, monthsNumber);

			break;
		}
		// exit
		case 4: {
			printf("Are you sure you want to exist?\n"); // egg
			printf("1: No\n");
			printf("2: Yes\n");

			switch (getPositiveInt()) {
			case 1:
				break;
			case 2:
				menu = 0;
				break;
			}
		}
		}
	}
	delete[] months;
	return 0;
}