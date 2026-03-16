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