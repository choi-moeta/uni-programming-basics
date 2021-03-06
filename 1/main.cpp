#include "pch.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  

/*!
\file
\brief Программа для для вычесления х по заданной формуле.
\autor я
\version 1.0
\data 12.2.2018
\example Выводит значение х вычесленного по формуле.
*/

/*!
\brief Функция, точка входа в программу.
\version 1.0
\return
Функция возвращяет значение с кодом ошибки, 0 если ошибок нет 
*/

int main()
{
	printf("Welcome, input a number please.\n");

	float input;
	char char_;
	while ((scanf_s("%f%c", &input, &char_, 1) != 2) || (char_ != '\n') || (input < 0)) {
		if (input < 0)
			printf("Input's wrong, the number of the square root must be positive, input valid number");
		else
			printf("Input's wrong, input valid number.\n");

		rewind(stdin); // clear scanf
	}

	float x = input; // for better reading
	double result = (1 / sqrt(pow(x, 9))) + (3 * x / cos(x));
	printf("The result is: %f", result);

	return 0;
}


