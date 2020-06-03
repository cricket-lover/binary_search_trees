#ifndef __TREE_H
#define __TREE_H

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
typedef Bool (*Comparator)(Object, Object);
typedef void (*Displayer)(Object);

void display_int(Object a);
Tree_ptr create_node(Object a);
Bool compare_int(Object a, Object b);
Tree_ptr insert(Tree_ptr tree, Object value, Comparator compare_less_than);
void printInOrder(Tree_ptr tree, Displayer display_data);
void printPreOrder(Tree_ptr tree, Displayer display_data);
void printPostOrder(Tree_ptr tree, Displayer display_data);
Tree_ptr insert_without_recurssion(Tree_ptr tree, Object value, Comparator compare_less_than);
#endif