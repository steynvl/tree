/**
 * @file    formatter.h
 * @brief   Definitions for the exported functions for the
 *          formatter of tree.
 * @author  Steyn van Litsenborgh
 */

#ifndef TREE_FORMATTER_H
#define TREE_FORMATTER_H

#include <stdlib.h>

/**
 * Print the directory and does some pre-processing
 * before we can print all of the files and
 * sub-directories in the directory.
 *
 * @param name
 *     the name of the directory
 * @param level
 *     the directory depth
 */
void print_dir(char *name, int level);

/**
 * Prints the files in a directory at the correct indentation
 * level given the depth of the directory with respect to its
 * parent.
 *
 * @param files
 *     the files in the directory
 * @param num_of_files
 *     the size of the files array
 * @param level the current level
 *     the directory depth, the function uses this
 *     to know how far the given files should be
 *     indented when printing the tree
 */
void print_files(char **files, size_t num_of_files, int level);

/**
 * Prints a report. This function should be called
 * after the directory tree has been printed.
 *
 * @param num_dirs
 *     the number of directories that were discovered
 *     when performing the recursive descend
 * @param num_files
 *     the number of files that were discovered
 *     when performing the recursive descend
 */
void print_report(int num_dirs, int num_files);

#endif
