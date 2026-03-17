#include"../include/student.h"
#include"../include/student_db.h"
#include"../include/utils.h"
#include <stdio.h> 
#include <stdlib.h>
#include <windows.h>

static std_t students[MAX_STUDENTS];

static int student_count = 0;

void add_student(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    if (student_count >= MAX_STUDENTS)
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
        printf("Database is full\n");
    }
	else
	{
		printf("Enter student data\n");

       scanOf_stdStruct(&students[student_count]);

       student_count++;	
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void print_all_students(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    if (student_count == 0)
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
        printf("No students in database\n");
    }
	else 
	{
		printf("Students List:\n\n");

        print_arrOfstdStruct(students, student_count);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void print_student_by_number(int student_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    if (student_number < 1 || student_number > student_count)
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
        printf("Invalid student number\n");
    }
	else
	{
		print_stdStruct(&students[student_number - 1]);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void print_student_by_name(char *name)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    int index;

    search_NameStdStruct(students, student_count, name, &index);

    if (index == -1)
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
        printf("Student not found\n");
    }
	else 
	{
		print_stdStruct(&students[index]);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void sort_students_by_age(void)
{
    int i, j;
    int swapped=1;
    std_t temp;

    for (i = 0;(i<student_count-1)&&(1 == swapped); i++)
    {
        swapped = 0;

        for (j = 0; j < student_count - i - 1; j++)
        {
            if (students[j].age > students[j + 1].age)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;

                swapped = 1;
            }
			else{;}
        }
    }
}
void sort_students_by_name(void)
{
    int i, j;
    int swapped = 1;
    std_t temp;

    for (i = 0; (i < student_count - 1) && ( 1 == swapped); i++)
    {
        swapped = 0;

        for (j = 0; j < student_count - i - 1; j++)
        {
            if (string_compare_char(students[j].name, students[j + 1].name) == 1)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;

                swapped = 1;
            }
        }
    }
}
void sort_students_by_grade(void)
{
    int i, j;
    int swapped = 1;
    std_t temp;

    for (i = 0; (i < student_count - 1) && (1==swapped); i++)
    {
        swapped = 0;

        for (j = 0; j < student_count - i - 1; j++)
        {
            if (students[j].grade > students[j + 1].grade)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;

                swapped = 1;
            }
        }
    }
}