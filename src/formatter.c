/**
 * @file    formatter.c
 * @brief   The formatter for tree.
 * @author  Steyn van Litsenborgh
 */

#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include "boolean.h"
#include "formatter.h"

/* --- constants ------------------------------------------------------------ */
wchar_t HORIZONTAL_LINE = 0x2500;
wchar_t VERTICAL_LINE   = 0x2502;
wchar_t DOWN_RIGHT_DOWN = 0x251c;
wchar_t DOWN_RIGHT      = 0x2514;

#define ESC               "\033["
#define BOLD              "1;"
#define ASCII_RESET       ESC "m"
#define BLUE              "34m"
#define ASCII_BOLD_BLUE   ESC BOLD BLUE

#define LEVEL_WIDTH       (3)

/* --- function prototypes -------------------------------------------------- */
static void print_til_level(int level, Boolean last);
static char* extract_dir_name(char *full_path);

void print_dir(char *name, int level)
{
    if (level > 1) {
        print_til_level(level, FALSE);
        printf(" ");
    }

    printf("%s%s%s\n", ASCII_BOLD_BLUE, extract_dir_name(name), ASCII_RESET);
}

void print_files(char **files, size_t num_of_files, int level)
{
    size_t i;

    for (i = 0; i < num_of_files; i++) {
        print_til_level(level, i == num_of_files - 1);
        printf(" %s\n", files[i]);
    }
}

void print_report(int num_dirs, int num_files)
{
    printf("\n%d directories, %d files\n", num_dirs, num_files);
}

static void print_til_level(int level, Boolean last)
{
    Boolean at_last_level;
    size_t i, depth;

    for (depth = 1; depth < level; depth++) {
        at_last_level = depth == level - 1;

        if (depth > 1) {
            printf(" ");
        }

        at_last_level ? printf("%lc", last ? DOWN_RIGHT : DOWN_RIGHT_DOWN)
                      : printf("%lc", VERTICAL_LINE);

        for (i = 1; i <= LEVEL_WIDTH; i++) {
            at_last_level ? printf("%lc", HORIZONTAL_LINE) : printf(" ");
        }

    }
}

static char* extract_dir_name(char *full_path)
{
    char *dir_name;
    dir_name = strrchr(full_path, '/');
    return dir_name == NULL ? full_path : dir_name + 1;
}