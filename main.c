#include "tree.h"

int main(void)
{
  int numbers[5] = {5, 3, 6, 7, 1};
  Tree_ptr tree = create_node(&numbers[0]);
  insert_without_recurssion(tree, &numbers[1], &compare_int);
  insert_without_recurssion(tree, &numbers[2], &compare_int);
  insert_without_recurssion(tree, &numbers[3], &compare_int);
  insert_without_recurssion(tree, &numbers[4], &compare_int);
  printInOrder(tree, &display_int);

  return 0;
}