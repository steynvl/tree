#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>


void list_dirs(char *, int);
char* build_path(const char *, const char *);
int is_directory(const char *);


int main(int argc, char *argv[])
{
    char *base;

    if (argc == 2 && (strcmp(argv[1], "--help") == 0)) {
        /* TODO */
        return 0;
    }

    base = argc == 1 ? "." : argv[1];
    list_dirs(base, 0);

    return 0;
}

void list_dirs(char *path, int level)
{
    struct dirent *dir_entry;
    DIR *dir;
    char *full_path;

    dir = opendir(path);

    if (dir == NULL) {
        if (level == 0) {
            fprintf(stderr, "Could not open directory '%s'\n", path);
            exit(1);
        } else {
            return;
        }
    }

    while ((dir_entry = readdir(dir)) != NULL) {
        if ((strcmp(dir_entry->d_name, ".") == 0) || (strcmp(dir_entry->d_name, "..") == 0)) {
            continue;
        }

        full_path = build_path(path, dir_entry->d_name);
        printf("[%d] -- %s\n", is_directory(full_path), full_path);
        if (is_directory(full_path)) {
            list_dirs(full_path, level + 1);
        }

        free(full_path);
    }

    closedir(dir);
}

int is_directory(const char *path)
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
