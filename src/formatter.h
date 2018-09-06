#ifndef TREE_FORMATTER_H
#define TREE_FORMATTER_H

#include <stdlib.h>

void print_dir(char *name, int level);

void print_files(char **files, size_t num_of_files, int level);

void print_report(int num_dirs, int num_files);

#endif
