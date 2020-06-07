#include "tree.h"

int main(void)
{
  int numbers[] = {1, 3, 2, 4, 5};
  int length = sizeof(numbers) / sizeof(int);
  Tree_ptr tree = create_node(&numbers[0]);
  for (int i = 1; i < length; i++)
  {
    insert_without_recurssion(tree, &numbers[i], &compare_int);
  }

  printPreOrder(tree, &display_int);
  tree = left_rotation(tree, &numbers[4], &compare_int);
  printf("\n");
  printPreOrder(tree, &display_int);
  return 0;
}