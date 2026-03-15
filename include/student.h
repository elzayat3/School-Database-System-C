#ifndef STUDENT_H
#define STUDENT_H

/**
 * @file student.h
 * @brief Data structures and operations for managing students.
 *
 * This module defines the core data types and APIs used to
 * represent and manipulate student records in the School
 * Database system.
 *
 * @author Abdelrahman Elzayat
 */

/**
 * @struct per_t
 * @brief Represents a person related to the student.
 *
 * This structure is used for storing information about
 * parents or siblings.
 */
typedef struct
{
    char name[20];   /**< Person name */
    char phone[12];  /**< Phone number */
    int age;         /**< Person age */
} per_t;

/**
 * @struct std_t
 * @brief Represents a student in the school database.
 *
 * Contains personal information about the student and
 * information about family members.
 */
typedef struct
{
    char name[20];            /**< Student name */
    int age;                  /**< Student age */
    char grade;               /**< Student grade */
    per_t father;             /**< Father information */
    per_t mother;             /**< Mother information */
    int number_OfBrothers;    /**< Number of brothers */
    per_t* brothers;          /**< Dynamic array of brothers */
} std_t;

/**
 * @brief Print a student structure.
 *
 * Displays all information related to a student including
 * personal data and family members.
 *
 * @param[in] s Pointer to the student structure.
 */
void print_stdStruct(std_t* s);

/**
 * @brief Read student information from user input.
 *
 * Prompts the user to enter student data and fills
 * the provided structure.
 *
 * @param[out] s Pointer to the student structure to fill.
 */
void scanOf_stdStruct(std_t* s);

/**
 * @brief Print an array of students.
 *
 * Iterates through a student array and prints
 * each student's information.
 *
 * @param[in] s Pointer to the student array.
 * @param[in] size Number of students.
 */
void print_arrOfstdStruct(std_t* s, int size);

/**
 * @brief Read an array of students from user input.
 *
 * Prompts the user to enter information for multiple students.
 *
 * @param[out] s Pointer to the student array.
 * @param[in] size Number of students to read.
 */
void scan_arrOfstdStruct(std_t* s, int size);

/**
 * @brief Search for a student by name.
 *
 * Performs a search in the student array and returns
 * the index of the student if found.
 *
 * @param[in] s Pointer to the student array.
 * @param[in] size Number of students in the array.
 * @param[in] str Name to search for.
 * @param[out] pindex Pointer to the index where the student was found.
 *                   Returns -1 if not found.
 */
void search_NameStdStruct(std_t* s, int size, char* str, int* pindex);

/**
 * @brief Read person information from user input.
 *
 * Used for parents or siblings.
 *
 * @param[out] p Pointer to the person structure.
 */
void scan_personStruct(per_t* p);

/**
 * @brief Print person information.
 *
 * Displays the person's name, phone number, and age.
 *
 * @param[in] p Pointer to the person structure.
 */
void print_personStruct(per_t* p);

/**
 * @brief Read an array of persons from input.
 *
 * Used to read multiple sibling records.
 *
 * @param[out] p Pointer to the person array.
 * @param[in] size Number of persons.
 */
void scan_arrOfpersonStruct(per_t* p, int size);

/**
 * @brief Print an array of persons.
 *
 * Displays all persons in the provided array.
 *
 * @param[in] p Pointer to the person array.
 * @param[in] size Number of persons.
 */
void print_arrOfpersonStruct(per_t* p, int size);

#endif