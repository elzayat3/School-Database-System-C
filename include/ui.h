#ifndef UI_H
#define UI_H

/**
 * @file ui.h
 * @brief Console User Interface for School Database System.
 *
 * This module handles all user interactions including:
 * - Main menu navigation
 * - Submenus
 * - User input handling (keyboard arrows & enter)
 * - Screen rendering and cursor control
 *
 * @author Abdelrahman Elzayat
 */

/* ========================== MACROS ========================== */

/**
 * @def MENU_SIZE
 * @brief Number of items in the main menu.
 */
#define MENU_SIZE 9

/**
 * @def GREEN
 * @brief Console color for highlighted menu item.
 */
#define GREEN 10

/* ========================== INPUT ========================== */

/**
 * @brief Read user input from keyboard.
 *
 * Supports arrow keys and enter key.
 *
 * @return int
 * @retval 1 Arrow Up
 * @retval 2 Arrow Down
 * @retval 3 Enter key
 * @retval 0 Any other key
 */
int get_input(void);

/* ========================== MAIN MENU ========================== */

/**
 * @brief Display the main menu.
 *
 * Highlights the currently selected item.
 *
 * @param[in] selected Index of the selected menu item.
 */
void print_menu(int selected);

/**
 * @brief Run the main menu loop.
 *
 * Handles navigation using arrow keys and returns
 * the selected option when Enter is pressed.
 *
 * @return int Selected menu index.
 */
int run_menu(void);

/* ========================== SUBMENUS ========================== */

/**
 * @brief Run a generic submenu.
 *
 * Displays a list of options and allows navigation
 * using arrow keys.
 *
 * @param[in] menu Array of menu strings.
 * @param[in] size Number of menu items.
 *
 * @return int Selected index.
 */
int run_submenu(const char **menu, int size);

/**
 * @brief Search menu for finding students.
 *
 * Allows searching by number or name.
 */
void search_menu(void);

/**
 * @brief Update menu for modifying student data.
 *
 * Allows selecting a student and updating specific fields.
 */
void update_menu(void);

/**
 * @brief Delete menu for removing students.
 *
 * Supports deletion by number or name.
 */
void delete_menu(void);

/**
 * @brief Sorting menu.
 *
 * Allows sorting students by:
 * - Age
 * - Name
 * - Grade
 */
void sort_menu(void);

/**
 * @brief Call student menu.
 *
 * Simulates calling a student by:
 * - Number
 * - Name
 */
void call_menu(void);

/**
 * @brief Print a single student menu.
 *
 * Allows printing student information by:
 * - Number
 * - Name
 */
void print_one_student_menu(void);

/* ========================== SCREEN CONTROL ========================== */

/**
 * @brief Move cursor to a specific position on console.
 *
 * @param[in] x Horizontal position (column).
 * @param[in] y Vertical position (row).
 */
void gotoxy(int x, int y);

/**
 * @brief Clear a specific area of the screen.
 *
 * Clears a number of lines starting from the top.
 *
 * @param[in] lines Number of lines to clear.
 */
void clear_menu_area(int lines);

#endif /* UI_H */