#include "tree.h"

Node_ptr create_node(Object a)
{
  Node_ptr tree = malloc(sizeof(Int_node));
  tree->value = a;
  tree->left = NULL;
  tree->right = NULL;
  return tree;
}

void display_int(Object a)
{
  printf("%d\n", *(int *)a);
}

Bool compare_int(Object a, Object b)
{
  return *(int *)a < *(int *)b;
}

Node_ptr insert(Node_ptr tree, Object value, Comparator compare_less_than)
{
  if (tree == NULL)
  {
    return create_node(value);
  }
  if (compare_less_than(value, tree->value))
  {
    tree->left = insert(tree->left, value, &compare_int);
  }
  else
  {
    tree->right = insert(tree->right, value, &compare_int);
  }
  return tree;
};

void printInOrder(Node_ptr tree, Displayer display_data)
{
  if (tree == NULL)
  {
    return;
  }
  printInOrder(tree->left, display_data);
  display_data(tree->value);
  printInOrder(tree->right, display_data);
};

void printPreOrder(Node_ptr tree, Displayer display_data)
{
  if (tree == NULL)
  {
    return;
  }
  display_data(tree->value);
  printPreOrder(tree->left, display_data);
  printPreOrder(tree->right, display_data);
};

void printPostOrder(Node_ptr tree, Displayer display_data)
{
  if (tree == NULL)
  {
    return;
  }
  printPostOrder(tree->left, display_data);
  printPostOrder(tree->right, display_data);
  display_data(tree->value);
};
