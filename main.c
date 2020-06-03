#include "tree.h"

int main(void)
{
  int num_1 = 5;
  int num_2 = 3;
  int num_3 = 6;
  int num_4 = 7;
  int num_5 = 1;
  Node_ptr tree = create_node(&num_1);
  insert(tree, &num_2, &compare_int);
  insert(tree, &num_3, &compare_int);
  insert(tree, &num_4, &compare_int);
  insert(tree, &num_5, &compare_int);
  printInOrder(tree, &display_int);

  return 0;
}