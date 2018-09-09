/**
 * @file tree.c
 *
 * A recursive directory listing program that produces a depth indented
 * listing of files.
 *
 * @author  Steyn van Litsenborgh
 */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <locale.h>
#include "boolean.h"
#include "formatter.h"

/* --- global variables ----------------------------------------------------- */
int num_directories; /* counts the number of directories we visit */
int num_files;       /* counts the number of files we visit */

#define MAX_INITIAL_DIR_SIZE (1024)

/* --- function prototypes -------------------------------------------------- */
void list_dirs(char *path, int level);
char* build_path(const char *p1, const char *p2);
Boolean is_directory(const char *path);

int main(int argc, char *argv[])
{
    char *base;

    if (argc == 2 && (strcmp(argv[1], "--help") == 0)) {
        printf("Usage: tree [directory]\n");
        exit(EXIT_SUCCESS);
    }

    setlocale(LC_CTYPE, "");
    num_directories = 0;
    num_files = 0;

    base = argc == 1 ? "." : argv[1];
    list_dirs(base, 1);

    print_report(num_directories, num_files);

    return EXIT_SUCCESS;
}

void list_dirs(char *path, int level)
{
    struct dirent *dir_entry;
    DIR *dir;
    char *full_path, **files_in_dir;
    size_t i, nfiles = MAX_INITIAL_DIR_SIZE;

    dir = opendir(path);

    if (dir == NULL) {
        if (level == 1) {
            fprintf(stderr, "Could not open directory '%s'\n", path);
            exit(EXIT_FAILURE);
        } else {
            return;
        }
    }

    i = 0;
    files_in_dir = malloc(sizeof(char *) * nfiles);

    print_dir(path, level);
    while ((dir_entry = readdir(dir)) != NULL) {
        if ((strcmp(dir_entry->d_name, ".") == 0) || (strcmp(dir_entry->d_name, "..") == 0)) {
            continue;
        }

        full_path = build_path(path, dir_entry->d_name);
        if (is_directory(full_path)) {
            num_directories++;
            list_dirs(full_path, level + 1);
        } else {
            if (i == nfiles - 1) {
                nfiles *= 2;
                if ((files_in_dir = realloc(files_in_dir, sizeof(char *) * nfiles)) == NULL) {
                    fprintf(stderr, "Realloc of %zu bytes failed", nfiles);
                    exit(EXIT_FAILURE);
                }
            }

            files_in_dir[i++] = dir_entry->d_name;
            num_files++;
        }

        free(full_path);
    }
    print_files(files_in_dir, i, level + 1);

    free(files_in_dir);

    closedir(dir);
}

Boolean is_directory(const char *path)
{
    struct stat ps;
    stat(path, &ps);
    return S_ISDIR(ps.st_mode);
}

char* build_path(const char *p1, const char *p2)
{
    char *fp;

    fp = malloc(strlen(p1) + strlen(p2) + 2);
    strcpy(fp, p1);

    if (p1[strlen(p1) - 1] != '/') {
        strcat(fp, "/");
    }

    strcat(fp, p2);

    return fp;
}
