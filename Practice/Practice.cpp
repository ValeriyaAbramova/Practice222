// Practice.cpp 
// КОДИРОВКА ТЕКСТОВОГО ФАЙЛА ДОЛЖНА БЫТЬ ANSI

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <conio.h>

#define _CRT_SECURE_NO_WARNINGS
#define M1 256
#define M2 128

char println();
char search();
void Display();
char split_for_depth(char& line);
char split_line(char& line);
const char delimetr = ';';
const char* filename = "D://data2.txt";
char split_for_depth2(char& line);

FILE* fp;

void Display()

{
    printf("+----------------------------------------------------------+\n");
    printf("|                           Меню                           | \n");
    printf("|              Введите номер опции:                        | \n");
    printf("|             1. Вывод списка                              | \n");
    printf("|             2. Вывод суммарной длины рек,                | \n|         глубина которых меньше 50 метров                 | \n");
    printf("|             3. Очистить                                  | \n");
    printf("+----------------------------------------------------------+\n");

}

int main(void)
{
    setlocale(LC_ALL, "rus");
    char opts;
    bool Complete = false;

    for (;;)
    {
        Display();
        printf("\nВведите Ваш выбор: ");
        scanf_s(" %c", &opts);
        printf("\n");
        switch (opts)
        {
        case '1':
            system("CLS");
            println();
            printf("\n");
            Complete = true;
            break;
        case '2':
            system("CLS");
            search();
            printf("\n");
            Complete = true;
            getchar();
            break;
        case '3':
            system("CLS");
            Complete = false;
            break;
        default:
            system("cls");  //For Windows
            printf("Повторите свой ввод!\n");

        }
    }
    printf("\n");
}


char println()
{
    char line[M2][M1];
    int k = 0;
    fp = fopen(filename, "r");
    // чтение из файла
    if (fp == NULL)
    {
        perror("Ошибка");
        return 1;
    }
    else
    {
        while (fgets(line[k], M1, fp) != NULL)
        {
            k++;
        }
    }
    fclose(fp);
    printf("+----------------------------------------------------------+\n");
    printf("|   Название реки   |   Длина реки     |   Средняя глубина |\n");
    printf("+----------------------------------------------------------+\n");
    for (int i = 0; i < k; ++i)
    {
        split_line(*line[i]);
    }
    return 0;
}
char split_line(char& line)
{
    char* lines[3];
    int i = 0;
    char* piece = strtok(&line, ";");
    while (piece != NULL)
    {

        lines[i] = piece;
        piece = strtok(NULL, ";");
        i++;
    }
    for (int k = 0; k < i; ++k)
    {
        printf("   %13s", lines[k]);
    }
    return 0;
}
char search()
{
    char line[M2][M1];
    int k = 0;
    char* lines[3];
    int i = 0;
    fp = fopen(filename, "r");
    // чтение из файла
    if (fp == NULL)
    {
        perror("Ошибка");
        return 1;
    }
    else
    {
        while (fgets(line[k], M1, fp) != NULL)
        {
            k++;
        }
    }
    fclose(fp);
    for (int i = 0; i < k; ++i)
    {
        split_for_depth2(*line[i]);
    }
    return 0;
}
char split_for_depth(char& line)
{
    char* lines[3];
    char a;
    int i = 0, k = 0, max = 3;
    int var;
    char* depth[M1];
    char* piece = strtok(&line, ";");
    while (piece != NULL)
    {

        lines[i] = piece;
        piece = strtok(NULL, ";");
        i++;
        if (i == 2)
        {
            depth[k] = piece;
            k++;
        }
    }
    for (int j = 0; j < k; j++)
    {
        //if((int)depth[j] < 50)
        printf("%d\n", (depth[j] - '0'));
    }
    return 0;
}