#include"../include/student.h"
#include"../include/student_db.h"
#include "../include/storage.h"
#include "../include/ui.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>

int main(void)
{
    int choice;

    load_students_from_file();

    while (1)
    {
        choice = run_menu();  

        system("cls");

        switch (choice)
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
            return 0;
        }

        printf("\nPress any key...");
        getch();
    }

    return 0;
}
