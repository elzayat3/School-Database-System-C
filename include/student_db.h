#ifndef STUDENT_DB_H
#define STUDENT_DB_H

/**
 * @file student_db.h
 * @brief Student database operations.
 *
 * This module provides functions to manage the
 * student database such as adding students,
 * printing all students, and searching for
 * specific students.
 *
 * @author Abdelrahman Elzayat
 */

/**
 * @brief Add a new student to the database.
 *
 * Reads student information from the user and
 * stores it in the student array if there is
 * available space.
 */
void add_student(void);

/**
 * @brief Print all students stored in the database.
 *
 * Iterates through the student array and prints
 * the information of every stored student.
 */
void print_all_students(void);

/**
 * @brief Print a student by student number.
 *
 * The student number starts from 1 (not 0).
 *
 * @param[in] student_number Student index given by the user.
 */
void print_student_by_number(int student_number);

/**
 * @brief Print a student by name.
 *
 * Searches the student database for a student
 * with the given name and prints their data
 * if found.
 *
 * @param[in] name Name of the student to search for.
 */
void print_student_by_name(char *name);

/**
 * @brief Sort students by age using optimized Bubble Sort.
 *
 * This function sorts the student database in ascending order
 * based on the age field of each student.
 *
 * The algorithm used is Bubble Sort with an optimization that
 * stops the sorting process early if no swaps occur during a pass,
 * indicating that the array is already sorted.
 *
 * @note The function modifies the order of students inside
 *       the global student array.
 */
void sort_students_by_age(void);
/**
 * @brief Sort students alphabetically by name.
 *
 * This function sorts the student database in ascending
 * alphabetical order based on the student name.
 *
 * The sorting algorithm used is Bubble Sort with an
 * early-exit optimization that stops the sorting process
 * if no swaps occur during a pass.
 *
 * @note The comparison is case-insensitive and relies on
 *       the utility function string_compare_char().
 */
void sort_students_by_name(void);
/**
 * @brief Sort students by grade (A to F).
 *
 * This function sorts the student database in ascending
 * order based on the grade field.
 *
 * Grades are converted to uppercase during comparison
 * to ensure correct ordering regardless of input case.
 *
 * Uses optimized Bubble Sort with early exit.
 */
void sort_students_by_grade(void);
/**
 * @brief Simulate calling a student's father.
 *
 * This function prints the father's phone number
 * of a given student based on the student number.
 *
 * The student number starts from 1 (not 0).
 *
 * @param[in] student_number Student number (1-based index).
 *
 * @note Prints an error message if the student number is invalid.
 */
void call_student(int student_number);
/**
 * @brief Simulate calling a student's father by name.
 *
 * This function searches for a student using their name
 * and prints the father's phone number if found.
 *
 * @param[in] name Name of the student to search for.
 *
 * @note Prints an error message if the student is not found.
 */
void call_student_by_name(char *name);

#endif