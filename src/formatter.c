#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include "formatter.h"
#include "boolean.h"

wchar_t HORIZONTAL_LINE = 0x2500;
wchar_t VERTICAL_LINE   = 0x2502;
wchar_t DOWN_RIGHT_DOWN = 0x251c;
wchar_t DOWN_RIGHT      = 0x2514;

#define LEVEL_WIDTH 3

static void print_til_level(int level, Boolean last);

void new_dir(char *name, int level)
{
    if (level > 1) {
        print_til_level(level, FALSE);
    }

    printf("%s\n", name);
}

void print_file(char *name, int level)
{
    print_til_level(level, FALSE);
    printf("%s\n", name);
}

void print_report(int num_dirs, int num_files){
    printf("\n%d directories, %d files\n", num_dirs, num_files);
}

static void print_til_level(int level, Boolean last)
{
    int i, depth;

    for (depth = 1; depth < level; depth++) {
        if (depth == level - 1) {
            printf("%lc", last ? DOWN_RIGHT : DOWN_RIGHT_DOWN);
        } else {
            printf("%lc", VERTICAL_LINE);
        }

        for (i = 1; i <= LEVEL_WIDTH; i++) {
            if (depth == level - 1) {
                printf("%lc", HORIZONTAL_LINE);
            } else {
                printf(" ");
            }
        }
    }
}