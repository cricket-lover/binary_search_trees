#ifndef __TREE_H
#define __TREE_H

#include "tree_utilities.h"
#define COUNT 5
typedef void (*Displayer)(Object);

Tree_ptr insert(Tree_ptr tree, Object value, Comparator compare_less_than);
Tree_ptr insert_without_recurssion(Tree_ptr tree, Object value, Comparator compare_less_than);
Bool search(Tree_ptr tree, Object value, Comparator compare_less_than);
Tree_ptr delete (Tree_ptr tree, Object value, Comparator compare_less_than);
Tree_ptr right_rotation(Tree_ptr tree, Object node_to_rotate, Comparator compare_less_than);
Tree_ptr left_rotation(Tree_ptr tree, Object node_to_rotate, Comparator compare_less_than);

void print_tree_structure(Tree_ptr tree, int space, Displayer display_data);
void printInOrder(Tree_ptr tree, Displayer display_data);
void printPreOrder(Tree_ptr tree, Displayer display_data);
void printPostOrder(Tree_ptr tree, Displayer display_data);
#endif