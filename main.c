#include "tree.h"

int main(void)
{
  int numbers[] = {3, 3, 4, 12, 14, 10, 5, 1, 8, 2, 7, 9, 11, 6, 18};
  int length = sizeof(numbers) / sizeof(int);
  Tree_ptr tree = create_node(&numbers[0]);
  for (int i = 1; i < length; i++)
  {
    insert_without_recurssion(tree, &numbers[i], &compare_int);
  }
  printInOrder(tree, &display_int);

  return 0;
}