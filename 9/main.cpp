#include "pch.h"
#include <iostream>

char* getFileText(int& fileSize)
{
	FILE *fp;
	fp = fopen("./../../in.txt", "r");

	if (fp == NULL)
	{
		printf("Error! File not found.");
		return NULL;
	}

	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	if (size == NULL)
	{
		printf("Error! File is empty.\n");
		return NULL;
	}

	char* text = new char[size];
	fread(text, 1, size, fp);
	text[size] = '\0';
	fclose(fp);

	fileSize = size + 1;

	return text;
}

int getIntCount(char* text, int size)
{
	int intCounter = 0;

	int inBrackets = 0;
	int inQuotes = 0;

	for (int i = 0; i < size; i++)
	{
		if (text[i] == '(')
		{
			inBrackets++;
		} 
		else if (text[i] == ')')
		{
			inBrackets--;
		}

		if (text[i] == '"' && text[i-1] != '\\')
		{
			inQuotes = !inQuotes;
			printf("%d", inQuotes);
		}

		if (!inBrackets && !inQuotes && text[i] == 'i' && text[i + 1] == 'n' && text[i + 2] == 't' && text[i + 3] == ' ')
		{
			intCounter++;
		}
	}

	printf("int count: %d\n", intCounter);
	return intCounter;
}

int main()
{
	int fileSize;
	char* fileText = getFileText(fileSize);

	int i = getIntCount(fileText, fileSize);

    std::cout << "Hello World!\n"; 
}