// Practice.cpp 
// КОДИРОВКА ТЕКСТОВОГО ФАЙЛА ДОЛЖНА БЫТЬ ANSI

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

char println();
char search();
void Display();

void Display()

{
    printf("+----------------------------------------------------------+\n");
    printf("|                           Меню                           | \n");
    printf("|              Введите номер опции:                        | \n");
    printf("|             1. Вывод списка                              | \n");
    printf("|              2. Вывод суммарной длины рек,               | \n|         глубина которых меньше 50 метров                 | \n");
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
            printf("Конец выполнения\n");

        }
    }
    printf("\n");
}


char println()
{
    const char* filename = "D://data5.txt";
    char cc[256];
    FILE* fp;
    // чтение из файла
    if ((fp = fopen(filename, "r")) == NULL)
    {
        perror("Ошибка");
        return 1;
    }
    while ((fgets(cc, 256, fp)) != NULL)
    {
        printf("%s", cc);
    }

    fclose(fp);
    return 0;
}

char search()
{
    const char* filename = "D://data2.txt";
    return 0;
}

