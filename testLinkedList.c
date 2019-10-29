#include "node.h"
#include "library.h"

int main(){
  struct node* test = NULL;
  test = insert_front(test, "b","b");
  printf("TESTING LINKED LIST:\n\n");

  printf("Testing print_list:\n");
  print_list(test);

  printf("Testing insert_front for song a by artist a\n");
  test = insert_front(test, "a", "a");
  printf("New list:\n");
  print_list(test);

  printf("Testing insert_order for song b by artist a and song a by artist b\n");
  test = insert_order(test, "b","a");
  test = insert_order(test, "a","b");
  printf("New list:\n");
  print_list(test);

  printf("Testing find_node for song b by artist a\n", );
  print_node(test);
  print_node(find_node(test, "b", "a"));
  printf("\n");
  print_list(find_node_artist(test, "b"));
  return 0;
}
