#ifndef __TREE_H
#define __TREE_H

#include "tree_utilities.h"
#include "traversal.h"

Tree_ptr insert(Tree_ptr tree, Object value, Comparator compare_less_than);
Tree_ptr insert_without_recurssion(Tree_ptr tree, Object value, Comparator compare_less_than);
Bool search(Tree_ptr tree, Object value, Comparator compare_less_than);
Tree_ptr delete (Tree_ptr tree, Object value, Comparator compare_less_than);
Tree_ptr right_rotation(Tree_ptr tree, Object node_to_rotate, Comparator compare_less_than);
Tree_ptr left_rotation(Tree_ptr tree, Object node_to_rotate, Comparator compare_less_than);
Tree_ptr balance_tree(Tree_ptr tree, Comparator compare_less_than);

#endif