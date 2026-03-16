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
 * @brief Sort students by age using Bubble Sort.
 *
 * This function sorts the student database in ascending order
 * based on the student age field.
 *
 * The sorting algorithm used is Bubble Sort, which repeatedly
 * compares adjacent students and swaps them if they are in
 * the wrong order.
 *
 * @note The function modifies the order of students in the
 *       global student array.
 */
void sort_students_by_age(void);

#endif