#include "tree.h"

int main(void)
{
  int numbers[] = {7, 3, 5, 2, 1, 4, 6, 7};
  int length = sizeof(numbers) / sizeof(int);
  Tree_ptr tree = create_node(&numbers[0]);
  for (int i = 1; i < length; i++)
  {
    insert_without_recurssion(tree, &numbers[i], &compare_int);
  }
  print_tree_structure(tree, 0, &display_int);
  // printf("Tree before balancing\n");
  // print_tree_structure(tree, 0, &display_int);
  // tree = left_rotation(tree, &numbers[0], &compare_int);
  // tree = balance_tree(tree, &compare_int);
  // printf("Tree after balancing\n");
  // print_tree_structure(tree, 0, &display_int);

  return 0;
}