#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "../include/student.h"
#include "../include/utils.h"


void print_stdStruct(std_t* s)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	printf("the name is : ");
    print_string(s->name);
    printf("the age is : %d\n",s->age);
    printf("the grade is : %c\n",s->grade);
    printf("his father informations is :\n");
    print_personStruct(&(s->father));
    printf("his mother informations is :\n");
    print_personStruct(&(s->mother));
    printf("his brother informations : \n");
    if((s->number_OfBrothers)!=0)
    {
        printf("the number of brothers is %d\n",s->number_OfBrothers);
        print_arrOfpersonStruct(s->brothers,s->number_OfBrothers);
    }
    else
    {
        printf("he has no brothers \n");
    }
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void scanOf_stdStruct(std_t* s)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	int x=0;
    printf("enter the name : ");
    scan_string(s->name);
    printf("enter the age : ");
    scanf("%d",&(s->age));
    printf("enter the grade : ");
    fflush(stdin);
    scanf("%c",&(s->grade));
	if (s->grade >= 'a' && s->grade <= 'z')
    {
        s->grade = s->grade - 'a' + 'A';
    }
	else{;}
    printf("enter the father information :\n");
    scan_personStruct(&(s->father));
    printf("enter the mother information :\n");
    scan_personStruct(&(s->mother));
    printf("please enter the number of brothers : ");
    fflush(stdin);
    scanf("%d",&(s->number_OfBrothers));
    s->brothers=(per_t*)calloc(s->number_OfBrothers,sizeof(per_t));
    if((s->number_OfBrothers)!=0)
    {
        printf("enter the brothers informations : \n");
        scan_arrOfpersonStruct(s->brothers,s->number_OfBrothers);
    }
    else {;}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void scan_personStruct(per_t* p)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	printf("enter the person name : ");
    scan_string(p->name);
    printf("enter the person phone number : ");
    scan_string(p->phone);
    printf("enter the person age : ");
    scanf("%d",&(p->age));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void print_personStruct(per_t* p)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	printf("the person name is : ");
    print_string(p->name);
    printf("the person phone number is : ");
    print_string(p->phone);
    printf("the person age is : %d \n",p->age);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void print_arrOfstdStruct(std_t* s, int size)
{
	int i=0;
    for(; i<size; i++)
    {
		printf("========== Student %d ==========\n", i+1);
        print_stdStruct(&s[i]);
        printf("\n");
    }
}
void scan_arrOfstdStruct(std_t* s, int size)
{
	int i=0;
    for(; i<size; i++)
    {
        printf("enter the %d student \n",i+1);
        scanOf_stdStruct(&s[i]);
    }
}
void search_NameStdStruct(std_t* s, int size, char* str, int* pindex)
{
	int i=0,index=-1;
    for(; (i<size)&&(-1==index); i++)
    {
        if(string_comp((s[i].name),str)==same)
        {
            index=i;
        }
        else {;}
    }
    *(pindex)=index;
}
void scan_arrOfpersonStruct(per_t* p, int size)
{
	int i=0;
    for(; i<size; i++)
    {
        printf("enter the %d person : \n",i+1);
        scan_personStruct(&p[i]);
    }
}
void print_arrOfpersonStruct(per_t* p, int size)
{
	int i=0;
    for(; i<size; i++)
    {
        print_personStruct(&p[i]);
        printf("\n");
    }
}