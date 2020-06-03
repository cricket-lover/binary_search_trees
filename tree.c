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
  Tree_ptr temp = p_walk;
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
