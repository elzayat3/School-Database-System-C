#include"../include/utils.h"
#include"../include/student.h"
#include"../include/student_db.h"
#include "../include/storage.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define MENU_SIZE 9
#define GREEN  10
int get_input(void);
void print_menu(int selected);
void call_menu(void);
void update_menu(void);
void sort_menu(void);
void run_menu(void);
void search_menu(void);
void delete_menu(void);
int run_submenu(const char **menu, int size);
void print_one_student_menu(void);
int main()
{
	load_students_from_file();

	run_menu();
	
	save_students_to_file();
    
}
int get_input(void)
{
    int ch = getch();

    if (ch == 224)
    {
        ch = getch();

        if (ch == 72) return 1; // UP
        if (ch == 80) return 2; // DOWN
    }
    else if (ch == 13)
    {
        return 3; // ENTER
    }

    return 0;
}
void print_menu(int selected)
{
    const char *menu[] =
	{
		"Add Student",
		"Print All Students",
		"Print One Student",   
		"Search Student",
		"Update Student",
		"Delete Student",
		"Sort Students",
		"Call Student",
		"Save & Exit"
	};
    system("cls");

    for (int i = 0; i < MENU_SIZE; i++)
    {
        if (i == selected)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            printf("> %s\n", menu[i]);
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            printf("  %s\n", menu[i]);
        }
    }
}
void update_menu()
{
    int num;
    std_t *s;

    printf("Enter student number: ");
    scanf("%d", &num); /* دي ممكن نخليها arrows بعدين */

    s = get_student_by_number(num);

    if (s == NULL)
    {
        return;
    }

    const char *menu[] =
    {
        "Name",
        "Age",
        "Grade",
        "Father",
        "Mother",
        "Brother",
        "Back"
    };

    int choice = run_submenu(menu, 7);

    switch (choice)
    {
    case 0: update_student_name(s); break;
    case 1: update_student_age(s); break;
    case 2: update_student_grade(s); break;
    case 3: update_student_father(s); break;
    case 4: update_student_mother(s); break;
    case 5: update_student_brother(s); break;
    case 6: return;
    }
}
void call_menu()
{
    const char *menu[] =
    {
        "By Number",
        "By Name",
        "Back"
    };

    int choice = run_submenu(menu, 3);

    if (choice == 0)
    {
        int num;
        printf("Enter number: ");
        scanf("%d", &num);
        call_student(num);
    }
    else if (choice == 1)
    {
        char name[20];
        printf("Enter name: ");
        scan_string(name);
        call_student_by_name(name);
    }
}
void sort_menu()
{
    const char *menu[] =
    {
        "By Age",
        "By Name",
        "By Grade",
        "Back"
    };

    int choice = run_submenu(menu, 4);

    switch (choice)
    {
    case 0: sort_students_by_age(); break;
    case 1: sort_students_by_name(); break;
    case 2: sort_students_by_grade(); break;
    case 3: return;
    }
}
void run_menu(void)
{
    int selected = 0;
    int input;

    while (1)
    {
        print_menu(selected);

        input = get_input();

        if (input == 1) /* UP */
        {
            selected--;
            if (selected < 0) selected = MENU_SIZE - 1;
        }
        else if (input == 2) /* DOWN */
        {
            selected++;
            if (selected >= MENU_SIZE) selected = 0;
        }
        else if (input == 3) /* ENTER */
        {
            system("cls");

            switch (selected)
				{
				case 0:
					add_student();
					break;

				case 1:
					print_all_students();
					break;

				case 2:
					print_one_student_menu();   
					break;

				case 3:
					search_menu();
					break;

				case 4:
					update_menu();
					break;

				case 5:
					delete_menu();
					break;

				case 6:
					sort_menu();
					break;

				case 7:
					call_menu();
					break;

				case 8:
					save_students_to_file();
					return;
				}

            printf("\nPress any key to continue...");
            getch();
        }
    }
}
void search_menu(void)
{
    const char *menu[] =
    {
        "By Number",
        "By Name",
        "Back"
    };

    int choice = run_submenu(menu, 3);

    if (choice == 0)
    {
        int num;
        printf("Enter student number: ");
        scanf("%d", &num);   /* ممكن نطورها بعدين */
        print_student_by_number(num);
    }
    else if (choice == 1)
    {
        char name[20];
        printf("Enter student name: ");
        scan_string(name);
        print_student_by_name(name);
    }
    else
    {
        return;
    }
}
void delete_menu()
{
    const char *menu[] =
    {
        "By Number",
        "By Name",
        "Back"
    };

    int choice = run_submenu(menu, 3);

    if (choice == 0)
    {
        int num;
        printf("Enter number: ");
        scanf("%d", &num);
        delete_student_by_number(num);
    }
    else if (choice == 1)
    {
        char name[20];
        printf("Enter name: ");
        scan_string(name);
        delete_student_by_name(name);
    }
}
int run_submenu(const char **menu, int size)
{
    int selected = 0;
    int input;

    while (1)
    {
        system("cls");

        for (int i = 0; i < size; i++)
        {
            if (i == selected)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
                printf("> %s\n", menu[i]);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
                printf("  %s\n", menu[i]);
            }
        }

        input = get_input();

        if (input == 1) /* UP */
        {
            selected--;
            if (selected < 0) selected = size - 1;
        }
        else if (input == 2) /* DOWN */
        {
            selected++;
            if (selected >= size) selected = 0;
        }
        else if (input == 3) /* ENTER */
        {
            return selected;
        }
    }
}
void print_one_student_menu(void)
{
    const char *menu[] =
    {
        "By Number",
        "By Name",
        "Back"
    };

    int choice = run_submenu(menu, 3);

    system("cls");

    if (choice == 0)
    {
        int num;
        printf("Enter student number: ");
        scanf("%d", &num);
        print_student_by_number(num);
    }
    else if (choice == 1)
    {
        char name[20];
        printf("Enter student name: ");
        scan_string(name);
        print_student_by_name(name);
    }
    else
    {
        return;
    }

    printf("\nPress any key...");
    getch();
}