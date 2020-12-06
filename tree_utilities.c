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

int get_height(Tree_ptr tree)
{
  if (tree == NULL)
  {
    return -1;
  }
  int left_height = get_height(tree->left);
  int right_height = get_height(tree->right);

  if (left_height > right_height)
    return (left_height + 1);
  else
    return (right_height + 1);
}

int get_node_count(Tree_ptr tree, int count)
{
  if (tree == NULL)
  {
    return count;
  }
  count = get_node_count(tree->left, count);
  count++;
  count = get_node_count(tree->right, count);
  return count;
}

void get_list_of_nodes(Tree_ptr tree, Array_void_ptr array)
{
  if (tree == NULL)
  {
    return;
  }
  get_list_of_nodes(tree->left, array);
  array->elements[array->length] = tree->value;
  array->length++;
  get_list_of_nodes(tree->right, array);
}
