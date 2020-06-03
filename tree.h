#ifndef __TREE_H
#define __TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef void *Object;
typedef struct int_node
{
  Object value;
  struct int_node *left;
  struct int_node *right;
} Int_node;
typedef Int_node *Node_ptr;
typedef enum
{
  False,
  True
} Bool;
typedef Bool (*Comparator)(Object, Object);
typedef void (*Displayer)(Object);

void display_int(Object a);
Node_ptr create_node(Object a);
Bool compare_int(Object a, Object b);
Node_ptr insert(Node_ptr tree, Object value, Comparator compare_less_than);
void printInOrder(Node_ptr tree, Displayer display_data);
void printPreOrder(Node_ptr tree, Displayer display_data);
void printPostOrder(Node_ptr tree, Displayer display_data);
#endif