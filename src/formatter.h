#ifndef TREE_FORMATTER_H
#define TREE_FORMATTER_H

#include <wchar.h>

void new_dir(char *name, int level);

void print_file(char *name, int level);

void print_report(int num_dirs, int num_files);

#endif
