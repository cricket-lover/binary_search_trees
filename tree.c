#include "tree.h"

Tree_ptr create_node(Object a)
{
  Tree_ptr tree = malloc(sizeof(Tree));
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

Tree_ptr right_rotation(Tree_ptr tree, Object node_to_rotate, Comparator compare_less_than)
{
  if (tree == NULL)
  {
    return tree;
  }
  if (compare_less_than(tree->value, node_to_rotate))
  {
    tree->right = right_rotation(tree->right, node_to_rotate, compare_less_than);
    return tree;
  }
  if (compare_less_than(node_to_rotate, tree->value))
  {
    tree->left = right_rotation(tree->left, node_to_rotate, compare_less_than);
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

Tree_ptr left_rotation(Tree_ptr tree, Object node_to_rotate, Comparator compare_less_than)
{
  if (tree == NULL)
  {
    return tree;
  }
  if (compare_less_than(tree->value, node_to_rotate))
  {
    tree->right = left_rotation(tree->right, node_to_rotate, compare_less_than);
    return tree;
  }
  if (compare_less_than(node_to_rotate, tree->value))
  {
    tree->left = left_rotation(tree->left, node_to_rotate, compare_less_than);
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

void printInOrder(Tree_ptr tree, Displayer display_data)
{
  if (tree == NULL)
  {
    return;
  }
  printInOrder(tree->left, display_data);
  display_data(tree->value);
  printInOrder(tree->right, display_data);
};

void printPreOrder(Tree_ptr tree, Displayer display_data)
{
  if (tree == NULL)
  {
    return;
  }
  display_data(tree->value);
  printPreOrder(tree->left, display_data);
  printPreOrder(tree->right, display_data);
};

void printPostOrder(Tree_ptr tree, Displayer display_data)
{
  if (tree == NULL)
  {
    return;
  }
  printPostOrder(tree->left, display_data);
  printPostOrder(tree->right, display_data);
  display_data(tree->value);
};
