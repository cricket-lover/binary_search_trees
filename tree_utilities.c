#include "tree_utilities.h"

Tree_ptr create_node(Object a)
{
  Tree_ptr tree = malloc(sizeof(Tree));
  tree->value = a;
  tree->left = NULL;
  tree->right = NULL;
  return tree;
}

Bool compare_int(Object a, Object b)
{
  return *(int *)a < *(int *)b;
}

Tree_ptr get_node(Tree_ptr tree, Object value, Comparator compare_less_than)
{
  if (tree == NULL || tree->value == value)
  {
    return tree;
  }
  if (compare_less_than(value, tree->value))
  {
    return get_node(tree->left, value, &compare_int);
  }
  else
  {
    return get_node(tree->right, value, &compare_int);
  }
}

Tree_ptr get_min_of_right(Tree_ptr tree)
{
  if (tree->left == NULL)
  {
    return tree;
  }
  return get_min_of_right(tree->left);
}
