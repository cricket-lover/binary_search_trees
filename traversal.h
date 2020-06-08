#ifndef DISPLAY_H
#define DISPLAY_H

#include "tree_utilities.h"
#define COUNT 5
typedef void (*Displayer)(Object);
void display_int(Object a);
void print_tree_structure(Tree_ptr tree, int space, Displayer display_data);
void print_in_order(Tree_ptr tree, Displayer display_data);
void print_pre_order(Tree_ptr tree, Displayer display_data);
void print_post_order(Tree_ptr tree, Displayer display_data);

#endif
