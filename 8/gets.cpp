char* getStr(void)
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
