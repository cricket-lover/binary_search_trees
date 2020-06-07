#include "tree.h"

int main(void)
{
  int numbers[] = {10, 8, 20, 5, 1, 9};
  int length = sizeof(numbers) / sizeof(int);
  Tree_ptr tree = create_node(&numbers[0]);
  for (int i = 1; i < length; i++)
  {
    insert_without_recurssion(tree, &numbers[i], &compare_int);
  }

  printPreOrder(tree, &display_int);
  return 0;
}