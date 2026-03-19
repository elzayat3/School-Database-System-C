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
/**
 * @brief Delete a student by student number.
 *
 * Removes a student from the database and shifts
 * the remaining students to maintain array order.
 *
 * The student number starts from 1 (not 0).
 *
 * @param[in] student_number Student number (1-based index).
 */
void delete_student_by_number(int student_number);

/**
 * @brief Delete a student by name.
 *
 * Searches for a student by name and removes them
 * from the database if found.
 *
 * @param[in] name Name of the student.
 */
void delete_student_by_name(char *name);
/**
 * @brief Update student's name.
 *
 * Prompts the user to enter a new name and updates
 * the student's name field.
 *
 * @param[in,out] s Pointer to student structure.
 */
void update_student_name(std_t *s);

/**
 * @brief Update student's age.
 *
 * Prompts the user to enter a new age and updates
 * the student's age field.
 *
 * @param[in,out] s Pointer to student structure.
 */
void update_student_age(std_t *s);

/**
 * @brief Update student's grade.
 *
 * Prompts the user to enter a new grade and updates
 * the student's grade field. Converts lowercase
 * letters to uppercase.
 *
 * @param[in,out] s Pointer to student structure.
 */
void update_student_grade(std_t *s);

/**
 * @brief Update person's name.
 *
 * Prompts the user to enter a new name and updates
 * the person's name field.
 *
 * @param[in,out] p Pointer to person structure.
 */
void update_person_name(per_t *p);

/**
 * @brief Update person's phone number.
 *
 * Prompts the user to enter a new phone number and updates
 * the person's phone field.
 *
 * @param[in,out] p Pointer to person structure.
 */
void update_person_phone(per_t *p);

/**
 * @brief Update person's age.
 *
 * Prompts the user to enter a new age and updates
 * the person's age field.
 *
 * @param[in,out] p Pointer to person structure.
 */
void update_person_age(per_t *p);

/**
 * @brief Update a person's data.
 *
 * Displays a menu to choose which field to update
 * (name, phone, or age) and applies the selected update.
 *
 * @param[in,out] p Pointer to person structure.
 */
void update_person(per_t *p);

/**
 * @brief Update student's father information.
 *
 * Calls the generic person update function for
 * the student's father.
 *
 * @param[in,out] s Pointer to student structure.
 */
void update_student_father(std_t *s);

/**
 * @brief Update student's mother information.
 *
 * Calls the generic person update function for
 * the student's mother.
 *
 * @param[in,out] s Pointer to student structure.
 */
void update_student_mother(std_t *s);

/**
 * @brief Update one of the student's brothers.
 *
 * Prompts the user to select a brother by index
 * and allows updating their information.
 *
 * @param[in,out] s Pointer to student structure.
 *
 * @note Prints an error message if no brothers exist
 *       or if an invalid index is provided.
 */
void update_student_brother(std_t *s);
/**
 * @brief Add a new brother to the student.
 *
 * Dynamically reallocates memory to append a new brother
 * and reads the brother's information from user input.
 *
 * @param[in,out] s Pointer to student structure.
 */
void add_brother(std_t *s);

/**
 * @brief Delete a brother from the student.
 *
 * Removes a brother by index and shifts remaining elements.
 * Memory is reallocated accordingly.
 *
 * @param[in,out] s Pointer to student structure.
 *
 * @note Frees memory if no brothers remain.
 */
void delete_brother(std_t *s);
/**
 * @brief Get pointer to the students array.
 *
 * This function returns a pointer to the internal
 * student database array.
 *
 * @return std_t*
 *         Pointer to the array of students.
 *
 * @note The returned pointer provides direct access
 *       to the internal storage. Modify with care.
 */
std_t* get_students(void);

/**
 * @brief Get current number of students.
 *
 * This function returns the current count of
 * students stored in the database.
 *
 * @return int
 *         Number of students.
 */
int get_student_count(void);
/**
 * @brief Get a pointer to a student by number.
 *
 * This function returns a pointer to the student
 * corresponding to the given student number.
 *
 * The student number is 1-based (starts from 1).
 *
 * @param[in] student_number Student number (1-based index).
 *
 * @return std_t*
 * @retval Pointer to the student if the number is valid.
 * @retval NULL if the student number is invalid.
 *
 * @note Prints an error message if the index is invalid.
 */
std_t* get_student_by_number(int student_number);
/**
 * @brief Set the current number of students in the database.
 *
 * Updates the internal counter representing how many
 * students are currently stored. This is mainly used
 * during deserialization (loading from file).
 *
 * @param[in] count Number of students.
 *
 * @warning Setting an incorrect value may lead to
 *          undefined behavior when accessing the database.
 */
void set_student_count(int count);

#endif