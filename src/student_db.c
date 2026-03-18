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
        printf("========== Student %d ==========\n", student_number);
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
		printf("========== Student %d ==========\n", index+1);
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
            char g1 = students[j].grade;
            char g2 = students[j + 1].grade;

            if (g1 >= 'a' && g1 <= 'z')
			{
				g1 = g1 - 'a' + 'A';
			}
			else{;}
          
            if (g2 >= 'a' && g2 <= 'z')
			{
				g2 = g2 - 'a' + 'A';
			}
			else{;}  

            if (g1 > g2)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;

                swapped = 1;
            }
        }
    }
}
void call_student(int student_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    if (student_number < 1 || student_number > student_count)
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
        printf("Invalid student number\n");
    }
	else
	{
		  printf("Calling %s's father at: %s\n",
           students[student_number - 1].name,
           students[student_number - 1].father.phone);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void call_student_by_name(char *name)
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
		printf("Calling %s's father at: %s\n",
           students[index].name,
           students[index].father.phone);
	} 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void delete_student_by_number(int student_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    int i;

    if (student_number < 1 || student_number > student_count)
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
        printf("Invalid student number\n");
    }
	else
	{
		int index = student_number - 1;

		free(students[index].brothers);

		for (i = index; i < student_count - 1; i++)
		{
			students[i] = students[i + 1];
		}

		student_count--;

		printf("Student deleted successfully\n");
		
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void delete_student_by_name(char *name)
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
		free(students[index].brothers);

		for (int i = index; i < student_count - 1; i++)
		{
			students[i] = students[i + 1];
		}

		student_count--;

		printf("Student deleted successfully\n");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void update_student_name(std_t *s)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    printf("Enter new name: ");
    scan_string(s->name);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void update_student_age(std_t *s)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    printf("Enter new age: ");
    scanf("%d", &s->age);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void update_student_grade(std_t *s)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    printf("Enter new grade: ");
    scanf(" %c", &s->grade);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);

    if (s->grade >= 'a' && s->grade <= 'z')
    {
        s->grade = s->grade - 'a' + 'A';
    }
	else{;}
}
void update_person_name(per_t *p)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    printf("Enter new name: ");
    scan_string(p->name);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void update_person_phone(per_t *p)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    printf("Enter new phone: ");
    scan_string(p->phone);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void update_person_age(per_t *p)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    printf("Enter new age: ");
    scanf("%d", &p->age);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void update_person(per_t *p)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    int choice;

    printf("\nUpdate Person:\n");
    printf("1- Name\n");
    printf("2- Phone\n");
    printf("3- Age\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        update_person_name(p);
        break;

    case 2:
        update_person_phone(p);
        break;

    case 3:
        update_person_age(p);
        break;

    default:
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
        printf("Invalid choice\n");
    }
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void update_student_father(std_t *s)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    printf("Updating Father Info:\n");
    update_person(&s->father);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void update_student_mother(std_t *s)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    printf("Updating Mother Info:\n");
    update_person(&s->mother);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void update_student_brother(std_t *s)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    int index;

    if (s->number_OfBrothers == 0)
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
        printf("No brothers available\n");
    }
	else
	{
		printf("Enter brother number (1-%d): ", s->number_OfBrothers);
		scanf("%d", &index);

		if (index < 1 || index > s->number_OfBrothers)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			printf("Invalid index\n");
		}
		else
		{
			update_person(&s->brothers[index - 1]);
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void add_brother(std_t *s)
{
    per_t *temp;

    temp = (per_t*)realloc(s->brothers, (s->number_OfBrothers + 1) * sizeof(per_t));

    if (temp == NULL)
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
        printf("Memory allocation failed\n");
    }
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
		s->brothers = temp;

		printf("Enter new brother info:\n");
		scan_personStruct(&s->brothers[s->number_OfBrothers]);

		s->number_OfBrothers++;

		printf("Brother added successfully\n");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
}
void delete_brother(std_t *s)
{
    int index, i;

    if (s->number_OfBrothers == 0)
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
        printf("No brothers to delete\n");
    }
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
		printf("Enter brother number (1-%d): ", s->number_OfBrothers);
		scanf("%d", &index);

		if (index < 1 || index > s->number_OfBrothers)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			printf("Invalid index\n");
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
			index--; 
			for (i = index; i < s->number_OfBrothers - 1; i++)
			{
				s->brothers[i] = s->brothers[i + 1];
			}

			s->number_OfBrothers--;

			if (s->number_OfBrothers == 0)
			{
				free(s->brothers);
				s->brothers = NULL;
			}
			else
			{
				s->brothers = (per_t*)realloc(s->brothers, s->number_OfBrothers * sizeof(per_t));
			}

			printf("Brother deleted successfully\n");
			
		}	
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);  
}