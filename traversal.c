#include "traversal.h"

void display_int(Object a)
{
  printf("%d\n", *(int *)a);
}

void print_tree_structure(Tree_ptr tree, int space, Displayer display_data)
{
  if (tree == NULL)
  {
    return;
  }
  space += COUNT;
  print_tree_structure(tree->right, space, display_data);
  printf("\n");
  for (int i = COUNT; i < space; i++)
  {
    printf(" ");
  }
  display_data(tree->value);
  print_tree_structure(tree->left, space, display_data);
}

void print_in_order(Tree_ptr tree, Displayer display_data)
{
  if (tree == NULL)
  {
    return;
  }
  print_in_order(tree->left, display_data);
  display_data(tree->value);
  print_in_order(tree->right, display_data);
};

void print_pre_order(Tree_ptr tree, Displayer display_data)
{
  if (tree == NULL)
  {
    return;
  }
  display_data(tree->value);
  print_pre_order(tree->left, display_data);
  print_pre_order(tree->right, display_data);
};

void print_post_order(Tree_ptr tree, Displayer display_data)
{
  if (tree == NULL)
  {
    return;
  }
  print_post_order(tree->left, display_data);
  print_post_order(tree->right, display_data);
  display_data(tree->value);
};
