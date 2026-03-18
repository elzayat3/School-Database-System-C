#ifndef STORAGE_H
#define STORAGE_H

/**
 * @file storage.h
 * @brief Storage and persistence operations for the student database.
 *
 * This module provides functions to save and load the
 * student database to/from a binary file, allowing
 * data persistence between program executions.
 *
 * @author Abdelrahman Elzayat
 */

/**
 * @brief Save all students to a binary file.
 *
 * This function writes the current student database
 * to a file, including all nested data such as
 * parents and dynamically allocated brothers.
 *
 * @note The data is stored in binary format.
 */
void save_students_to_file(void);

/**
 * @brief Load students from a binary file.
 *
 * This function reads student data from a file and
 * reconstructs the database in memory, including
 * allocating memory for dynamic fields such as brothers.
 *
 * @note If the file does not exist, the database
 *       will remain empty.
 */
void load_students_from_file(void);

#endif