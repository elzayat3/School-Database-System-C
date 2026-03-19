#include <stdio.h>
#include <stdlib.h>
#include "../include/utils.h"
#include "../include/student.h"
#include "../include/student.h"
#include"../include/student_db.h"
#include "../include/storage.h"


void save_students_to_file(void)
{
	int student_count =get_student_count();
	std_t* students = get_students();
    FILE *f = fopen("../data/students.dat", "wb");

    if (f == NULL)
    {
        printf("Error opening file\n");
    }
	else
	{
		fwrite(&student_count, sizeof(int), 1, f);

		for (int i = 0; i < student_count; i++)
		{
			fwrite(&students[i], sizeof(std_t), 1, f);

			fwrite(students[i].brothers, sizeof(per_t),
				   students[i].number_OfBrothers, f);
		}
		fclose(f);

		printf("Data saved successfully\n");	
	}  
}
void load_students_from_file(void)
{
    int student_count;
    std_t* students = get_students();

    FILE *f = fopen("../data/students.dat", "rb");

    if (f == NULL)
    {
        printf("No saved data found\n");
    }
    else
    {
        fread(&student_count, sizeof(int), 1, f);

        set_student_count(student_count);  

        for (int i = 0; i < student_count; i++)
        {
            fread(&students[i], sizeof(std_t), 1, f);

            if (students[i].number_OfBrothers > 0)
            {
                students[i].brothers = (per_t*)malloc(
                    students[i].number_OfBrothers * sizeof(per_t));

                fread(students[i].brothers, sizeof(per_t),
                      students[i].number_OfBrothers, f);
            }
            else
            {
                students[i].brothers = NULL;
            }
        }

        fclose(f);

        printf("Data loaded successfully\n");
    }
}