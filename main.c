#include "tree.h"

int main(void)
{
  int numbers[] = {5, 3, 7, 6, 8};
  int length = sizeof(numbers) / sizeof(int);
  Tree_ptr tree = create_node(&numbers[0]);
  for (int i = 1; i < length; i++)
  {
    insert_without_recurssion(tree, &numbers[i], &compare_int);
  }
  printf("Tree before rotation\n");
  print_tree_structure(tree, 0, &display_int);
  tree = left_rotation(tree, &numbers[0], &compare_int);
  printf("Tree after rotation\n");
  print_tree_structure(tree, 0, &display_int);
  return 0;
}