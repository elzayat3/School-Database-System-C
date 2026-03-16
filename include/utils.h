#ifndef UTILS_H
#define UTILS_H

/**
 * @file utils.h
 * @brief Utility functions for string handling and comparison.
 *
 * This module provides helper functions used across the project,
 * mainly for string input/output and string comparison.
 *
 * @author Abdelrahman Elzayat
 */
 
 /**
 * @def RED
 * @brief Console text color code for red.
 *
 * This macro defines the color value used with
 * SetConsoleTextAttribute to display red text
 * in the Windows console.
 */
#define RED 4

/**
 * @def YELLOW
 * @brief Console text color code for yellow.
 *
 * This macro defines the value used with
 * SetConsoleTextAttribute to display yellow text
 * in the Windows console.
 */
#define YELLOW 14

/**
 * @def NORMAL
 * @brief Default console text color.
 *
 * This macro defines the default color used to reset
 * the console text color after applying other colors.
 */
#define NORMAL 7

/**
 * @enum comp_t
 * @brief Result of comparing two strings.
 */
typedef enum
{
    same,      /**< Strings are identical */
    notSame    /**< Strings are different */
} comp_t;

/**
 * @brief Print a null-terminated string.
 *
 * This function prints a string character by character
 * until the null terminator '\0' is reached.
 *
 * @param[in] s Pointer to the string to print.
 */
void print_string(const char* s);

/**
 * @brief Read a string from standard input.
 *
 * Reads characters from the user until a newline is encountered,
 * then terminates the string with '\0'.
 *
 * @param[out] s Pointer to the destination buffer.
 */
void scan_string(char* s);

/**
 * @brief Compare two strings.
 *
 * Performs a character-by-character comparison between
 * two null-terminated strings.
 *
 * @param[in] s1 Pointer to the first string.
 * @param[in] s2 Pointer to the second string.
 *
 * @return comp_t
 * @retval same     If the two strings are identical.
 * @retval notSame  If the strings are different.
 */
comp_t string_comp(const char* s1, const char* s2);

/**
 * @brief Print an array of strings.
 *
 * Iterates through an array of string pointers
 * and prints each string.
 *
 * @param[in] s    Array of string pointers.
 * @param[in] size Number of strings in the array.
 */
void print_arrOfString(const char** s, int size);

/**
 * @brief Compare two strings alphabetically ignoring case.
 *
 * This function compares two null-terminated strings in a
 * case-insensitive manner (i.e., 'A' is treated the same as 'a').
 * The comparison is performed character by character until a
 * difference is found or both strings terminate.
 *
 * @param[in] s1 Pointer to the first string.
 * @param[in] s2 Pointer to the second string.
 *
 * @return int
 * @retval 0 The two strings are equal.
 * @retval 1 The first string is greater than the second string.
 * @retval 2 The second string is greater than the first string.
 */
int string_compare_char(const char *s1, const char *s2);

#endif