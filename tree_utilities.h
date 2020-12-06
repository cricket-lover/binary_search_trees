#ifndef TREE_UTILITIES_H
#define TREE_UTILITIES_H

#include <stdio.h>
#include <stdlib.h>

typedef void *Object;
typedef struct tree
{
  Object value;
  struct tree *left;
  struct tree *right;
} Tree;
typedef Tree *Tree_ptr;
typedef enum
{
  False,
  True
} Bool;
typedef struct
{
  Object *elements;
  int length;
} Array_void;
typedef Array_void *Array_void_ptr;
typedef Bool (*Comparator)(Object, Object);

Tree_ptr create_node(Object a);
Bool compare_int(Object a, Object b);
Tree_ptr get_node(Tree_ptr tree, Object value, Comparator compare_less_than);
Tree_ptr get_min_of_right(Tree_ptr tree);
int get_height(Tree_ptr tree);
int get_node_count(Tree_ptr tree, int count);
void get_list_of_nodes(Tree_ptr tree, Array_void_ptr array);

#endif