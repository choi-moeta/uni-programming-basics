//#include "stdafx.h"
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

void menu();
int getInt(int, int);
char* inputStr();
char** getWords(char*, int*);
int proccessSentences(char*, char*);


int main()
{
	menu();

	return 0;
}

void menu()
{
	char* str1 = NULL;
	char* str2 = NULL;

	bool menu = 1;
	bool isInp = 0;

	while (menu)
	{
		printf("       Actions.\n");
		printf(" 1. Input sentences\n");
		printf(" 2. Show sentences\n");
		printf(" 3. Process sentences\n");
		printf(" 4. Exit\n");
		printf(" ");

		switch (getInt(1, 4))
		{
		case 1:
		{
			if (isInp)
			{
				delete[] str1;
				delete[] str2;

				str1 = NULL;
				str2 = NULL;
			}

			printf(" 1st sentence: ");
			str1 = inputStr();

			printf(" 2nd sentence: ");
			str2 = inputStr();

			isInp = 1;

			break;
		}
		case 2:
		{
			if (isInp)
			{
				printf(" 1st sentence: %s\n", str1);
				printf(" 2nd sentence: %s\n", str2);
			}
			else
			{
				printf("Please input sentences first.\n");
			}

			break;
		}
		case 3:
		{
			if (isInp)
			{
				printf(" words from 1st sentence equal with words from 2nd sentence:  %d\n", proccessSentences(str1, str2));
			}
			else
			{
				printf("Please input sentences first.\n");
			}

			break;
		}
		case 4:
		{
			menu = 0;
		}
		}
	}

	delete[] str1;
	delete[] str2;
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

char* inputStr()
{
	int len = 1;
	char* tmpStr = NULL;
	char* resStr = new char[len];
	while (true)
	{
		resStr[len - 1] = getchar();
		if (resStr[len - 1] == '\b')
		{
			printf("%c", resStr[len - 1]);
			printf("%c", ' ');
			printf("%c", resStr[len - 1]);
			tmpStr = new char[len - 1];
			for (int i = 0; i < len - 2; i++)
			{
				tmpStr[i] = resStr[i];
			}
			delete[] resStr;
			resStr = tmpStr;
			len--;
		}
		if (resStr[len - 1] == '\n')
		{
			resStr[len - 1] = '\0';
			break;
		}
		tmpStr = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			tmpStr[i] = resStr[i];
		}
		delete[] resStr;
		resStr = tmpStr;
		len++;
	}

	return resStr;
}

char** getWords(char* str, int* len)
{
	char** words = nullptr;
	char* newStr = new char[1];
	newStr[0] = '\0';

	char delim[5] = " .!?";
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

	return words;
}

int proccessSentences(char* sent1, char* sent2)
{
	int wordCount1 = 0;
	int wordCount2 = 0;

	char** words1 = getWords(sent1, &wordCount1);
	char** words2 = getWords(sent2, &wordCount2);

	int equalCount = 0;

	for (int i = 0; i < wordCount2; i++)
	{
		for (int j = 0; j < wordCount1; j++)
		{
			if (!strcmp(words1[j], words2[i]))
			{
				equalCount++;
			}
		}
	}

	for (int i = 0; i < wordCount1; i++)
	{
		delete words1[i];
	}
	for (int i = 0; i < wordCount2; i++)
	{
		delete words2[i];
	}

	delete[] words1;
	delete[] words2;

	return equalCount;
}

//int isEqual(char* str1, char* str2, int)