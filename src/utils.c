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
int string_compare_char(const char *s1, const char *s2)
{
    int i = 0;
    int c = 0;
    char a, b;

    while ((s1[i] || s2[i]) && (c == 0))
    {
        a = s1[i];
        b = s2[i];

        if (a >= 'A' && a <= 'Z')
		{
			a = a - 'A' + 'a';
		}
		else{;}
        if (b >= 'A' && b <= 'Z')
		{
			b = b - 'A' + 'a';
		}
		else{;}
		
        if (a > b)
		{
			c = 1;
		}  
        else if (b > a)
		{
			c = 2;
		}
		else{;}
        i++;
    }
    return c;
}