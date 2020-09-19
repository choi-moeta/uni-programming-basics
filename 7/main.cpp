#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int getInt() {
	long input;
	char symbol;
	while (scanf_s("%d%c", &input, &symbol, 1) != 2 || symbol != '\n' || input < 1) {
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

char* getText()
{
	FILE *fp;

	fp = fopen("./../../test.txt", "r");

	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char* text = new char[size];

	fread(text, 1, size, fp);
	text[size - 1] = '\0';

	fclose(fp);

	return text;
}

char** split(char* str, int* len, int max)
{
	char** words = nullptr;
	char* newStr = new char[1];
	newStr[0] = '\0';

	char delim[2];
	delim[0] = '\n';
	delim[1] = ' ';
	char* token = nullptr;
	int strCount = 0;
	int wordCount = 0;

	token = strtok(str, delim);
	while (token != NULL)
	{
		char* tmp = new char[strlen(token) + 1];
		strcpy_s(tmp, strlen(token) + 1, token);

		char** tmpWords = new char*[strCount + 1];

		for (int i = 0; i < strCount; i++)
		{
			tmpWords[i] = words[i];
		}
		tmpWords[strCount] = tmp;

		delete[] words;

		strCount++;
		words = tmpWords;
		token = strtok(NULL, delim);
		wordCount++;
	}

	*len = wordCount;

	delete[] token;
	delete[] newStr;

	char** cutWords = new char*[max];

	for (int i = 0; i < max; i++)
	{
		cutWords[i] = words[i];
	}

	return words;
}

void proccess(char** words, int size)
{
	int val = 0;
	int sum = 0;

	printf("Numbers:\n");

	for (int i = 0; i < size; i++)
	{
		val = atoi(words[i]);

		if (val)
		{
			printf("%s%d", sum ? ", " : "", val);
			sum += val;
		}
	}

	printf("\nThe sum of numbers is: %d\n", sum);
}

void printWords(char** words, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d. %s\n", (i + 1), words[i]);
	}
}

void menu()
{
	bool menu = 1;

	while (menu)
	{
		int size = 0;

		printf("Input maximum number of words: ");
		int maxSize = getInt();

		printf("\nText from file:\n");
		char* text = getText();
		printf("%s\n", text);

		char** words = split(text, &size, maxSize);

		size = size > maxSize ? maxSize : size;

		printf("\nWords:\n");
		printWords(words, size);

		printf("\n");
		proccess(words, size);

		printf("Do you want to run program again?\n(y/n): ");
		menu = getBoolStr();

		for (int i = 0; i < size; i++)
		{
			delete[] words[i];
		}
		delete[] words;
		delete[] text;
	}
}

int main()
{
	menu();

	return 0;
}