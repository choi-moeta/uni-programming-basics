#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

int getInt()
{
    char char_ = '\0';
    int input = 0;
    while (scanf_s("%i%c", &input, &char_, 1) != 2 || char_ != '\n' || input <= 0)
    {
        printf("Error. Input valid number: ");
        while (getchar() != '\n');
    }

    return input;
}


int getIntLess(int min, int max)
{
    char char_ = '\0';
    int input = 0;
    while (scanf_s("%i%c", &input, &char_, 1) != 2 || char_ != '\n' || input <= min || input >= max)
    {
        printf("Error. Input valid number: ");
        while (getchar() != '\n');
    }

    return input;
}


void getSize(int* wagons, int* seats)
{
    printf("How many WAGONS the train has: ");
    *wagons = getInt();
    printf("How many SEATS the wagon has: ");
    *seats = getInt();
}


int** createTrain(int wagons, int seats)
{
    int** train = new int*[wagons];
    for (int i = 0; i < wagons; i++)
    {
        train[i] = new int[seats]();
    }

    return train;
}


void showTrain(int** train, int wagons, int seats)
{
    for (int i = 0; i < wagons; i++) {
        printf("[ ");
        for (int j = 0; j < seats; j++) {
            printf("%i ", train[i][j]);
        }
        printf(i < wagons - 1 ? "], " : "]\n");
    }
}

int** fillRand(int** train, int wagons, int seats)
{
    for (int i = 0; i < wagons; i++) {
        for (int j = 0; j < seats; j++) {
            train[i][j] = rand() % 2;
        }
    }

    return train;
}

int** fillInput(int** train, int wagons, int seats)
{
    for (int i = 0; i < wagons; i++) {
        printf("%d wagon:\n", i + 1);
        for (int j = 0; j < seats; j++) {
            printf(" %d seat: ", j + 1);
            train[i][j] = getIntLess(-1,2);
        }
    }

    return train;
}


void fillTrain(int** train, int wagons, int seats)
{
    printf("What way to fill traint do you prefer?\n");
    printf(" 1. By hand\n");
    printf(" 2. Randomly\n ");

    switch (getIntLess(0, 3))
    {
    case 1:
    {
        train = fillInput(train, wagons, seats);
        showTrain(train, wagons, seats);

        break;
    }
    case 2:
    {
        train = fillRand(train, wagons, seats);
        showTrain(train, wagons, seats);

        break;
    }
    }
}


void showWagonInfo(int** train, int wagons, int seats)
{
    printf("Choose wagon to see free seats:\n");
    int wagon = getIntLess(0, wagons) - 1;

    int count = 0;
    for (int i = 0; i < seats; i++)
    {
        count = count + train[wagon][i];
    }
    printf("There is %d free seats in %d wagon.\n", seats - count, wagon + 1);
}


void showTrainInfo(int** train, int wagons, int seats)
{
    int count = 0;
    int average = 0;
    for (int i = 0; i < wagons; i++)
    {
        for (int j = 0; j < seats; j++)
        {
            count = count + train[i][j];
        }

    }
    printf("The train is %d percent full.\n", count / wagons * 100 / seats);
}


int main()
{
    bool program = 1;
    while (program)
    {
        printf("Hey, you know, I'm starting to recognize you.\n");
        printf("Anyway, can you setup the size of train?\n");

        int wagons = 0;
        int seats = 0;
        getSize(&wagons, &seats);
        int** train = createTrain(wagons, seats);

        fillTrain(train, wagons, seats);

        bool menu = 1;
        while (menu)
        {
            printf("Can I help you?\n");
            printf(" 1. Rewrite train\n");
            printf(" 2. Show train INFO\n");
            printf(" 3. Show train MAP\n");
            printf(" 4. Restart program\n");
            printf(" 5. Exit\n");

            switch (getIntLess(0, 6))
            {
            case 1:
            {
                fillTrain(train, wagons, seats);

                break;
            }
            case 2:
            {
                showWagonInfo(train, wagons, seats);
                showTrainInfo(train, wagons, seats);

                break;
            }
            case 3:
            {
                showTrain(train, wagons, seats);

                break;
            }
            case 4:
            {
                menu = 0;
                system("cls");

                for (int i = 0; i < wagons; i++)
                {
                    delete[] train[i];
                }
                delete[] train;

                break;
            }
            case 5:
            {
                menu = 0;
                program = 0;

                for (int i = 0; i < wagons; i++)
                {
                    delete[] train[i];
                }
                delete[] train;

                break;
            }
            }
        }

    }

    return 0;
}