#include "tree.h"

Tree_ptr insert(Tree_ptr tree, Object value, Comparator compare_less_than)
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

Tree_ptr insert_without_recurssion(Tree_ptr tree, Object value, Comparator compare_less_than)
{
  if (tree == NULL)
  {
    return create_node(value);
  }
  Tree_ptr p_walk = tree;
  Tree_ptr temp = NULL;
  while (p_walk != NULL)
  {
    if (compare_less_than(value, p_walk->value))
    {
      temp = p_walk;
      p_walk = p_walk->left;
    }
    else
    {
      temp = p_walk;
      p_walk = p_walk->right;
    }
  }

  if (compare_less_than(value, temp->value))
  {
    temp->left = create_node(value);
  }
  else
  {
    temp->right = create_node(value);
  }

  return tree;
};

Bool search(Tree_ptr tree, Object value, Comparator compare_less_than)
{
  if (tree == NULL || tree->value == value)
  {
    return tree == NULL ? False : True;
  }
  if (compare_less_than(value, tree->value))
  {
    return search(tree->left, value, &compare_int);
  }
  else
  {
    return search(tree->right, value, &compare_int);
  }
}

Tree_ptr delete (Tree_ptr tree, Object value, Comparator compare_less_than)
{
  if (tree == NULL)
  {
    return tree;
  }
  if (compare_less_than(tree->value, value))
  {
    tree->right = delete (tree->right, value, compare_less_than);
    return tree;
  }
  if (compare_less_than(value, tree->value))
  {
    tree->left = delete (tree->left, value, compare_less_than);
    return tree;
  }

  if (tree->left == NULL || tree->right == NULL)
  {
    Tree_ptr temp = tree->left == NULL ? tree->right : tree->left;
    free(tree);
    return temp;
  }

  Tree_ptr min = get_min_of_right(tree->right);
  tree->value = min->value;
  tree->right = delete (tree->right, min->value, compare_less_than);
  return tree;
}

Tree_ptr right_rotation(Tree_ptr tree, Object value_to_rotate, Comparator compare_less_than)
{
  if (tree == NULL)
  {
    return tree;
  }
  if (compare_less_than(tree->value, value_to_rotate))
  {
    tree->right = right_rotation(tree->right, value_to_rotate, compare_less_than);
    return tree;
  }
  if (compare_less_than(value_to_rotate, tree->value))
  {
    tree->left = right_rotation(tree->left, value_to_rotate, compare_less_than);
    return tree;
  }

  Tree_ptr pivot = tree->left;
  if (pivot == NULL)
  {
    return tree;
  }
  tree->left = pivot->right;
  pivot->right = tree;
  tree = pivot;

  return tree;
}

Tree_ptr left_rotation(Tree_ptr tree, Object value_to_rotate, Comparator compare_less_than)
{
  if (tree == NULL)
  {
    return tree;
  }
  if (compare_less_than(tree->value, value_to_rotate))
  {
    tree->right = left_rotation(tree->right, value_to_rotate, compare_less_than);
    return tree;
  }
  if (compare_less_than(value_to_rotate, tree->value))
  {
    tree->left = left_rotation(tree->left, value_to_rotate, compare_less_than);
    return tree;
  }

  Tree_ptr pivot = tree->right;
  if (pivot == NULL)
  {
    return tree;
  }
  tree->right = pivot->left;
  pivot->left = tree;
  tree = pivot;

  return tree;
}

Tree_ptr balance_tree(Tree_ptr tree, Comparator compare_less_than)
{
  int no_of_values = get_node_count(tree, 0);
  Array_void_ptr array = malloc(sizeof(Array_void));
  array->elements = malloc(sizeof(Object) * no_of_values);
  array->length = 0;
  get_list_of_nodes(tree, array);
  int middle_index = (int)array->length / 2;
  Tree_ptr new_tree = create_node(array->elements[middle_index]);
  for (int i = 0; i < array->length; i++)
  {
    if (i != middle_index)
    {
      new_tree = insert_without_recurssion(new_tree, array->elements[i], compare_less_than);
    }
  }
  return new_tree;
}
