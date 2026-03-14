#ifndef STUDENT_H
#define STUDENT_H

/**
 * @file student.h
 * @brief Data structures representing students and related persons.
 *
 * This module defines the core data types used by the School Database
 * system to represent students and their family information.
 *
 * @author Abdelrahman Elzayat
 */

/**
 * @struct per_t
 * @brief Represents a person related to the student.
 *
 * This structure is used for parents or siblings.
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
 * Contains personal information about the student as well
 * as references to parents and siblings.
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

#endif