#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void print_string(const char *s)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);

    for (int i = 0; s[i]; i++)
    {
        printf("%c", s[i]);
    }

   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
    printf("\n");
}

void scan_string(char *s)
{
    int i = 0;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    scanf(" %c", &s[i]);

    while (s[i] != '\n')
    {
        i++;
        scanf("%c", &s[i]);
    }

    s[i] = 0;
}

comp_t string_comp(const char *s1, const char *s2)
{
    comp_t r = same;

    for (int i = 0; (s1[i] || s2[i]) && (same == r); i++)
    {
        if (s1[i] != s2[i])
        {
            r = notSame;
        }
    }

    return r;
}

void print_arrOfSring(const char **s, int size)
{
    for (int i = 0; i < size; i++)
    {
        print_string(s[i]);
    }
}