#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "../include/utils.h"


void print_string(const char*s)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    int i=0;
    for(; s[i]; i++)
    {
        printf("%c",s[i]);
    }
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\n");
}
void scan_string(char*s)
{
    int i=0;
    fflush(stdin);
    scanf("%c",&s[i]);
    while(s[i]!='\n')
    {
        i++;
        scanf("%c",&s[i]);
    }
    s[i]=0;
}

comp_t string_comp(const char* s1, const char* s2)
{
    comp_t r=same;
    int i=0;
    for(; (s1[i]||s2[i])&&(same==r); i++)
    {
        if((s1[i])!=(s2[i]))
        {
            r=notSame;
        }
        else {;}
    }
    return r;
}
void print_arrOfSring(const char** s, int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        print_string(s[i]);
        //printf("\n");
    }
}
