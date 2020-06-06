#include "tree.h"

int main(void)
{
  int numbers[] = {42, 16, 8};
  int length = sizeof(numbers) / sizeof(int);
  Tree_ptr tree = create_node(&numbers[0]);
  for (int i = 1; i < length; i++)
  {
    insert_without_recurssion(tree, &numbers[i], &compare_int);
  }

  printInOrder(tree, &display_int);
  tree = right_rotation(tree, &numbers[0], &compare_int);
  printInOrder(tree, &display_int);
  return 0;
}