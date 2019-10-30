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

  printf("Testing insert_order for songs b, d, and c by artist a and song a by artist b\n");
  test = insert_order(test, "b","a");
  //print_list(test);
  test = insert_order(test, "a","b");
  //print_list(test);
  test = insert_order(test, "d","a");
  //print_list(test);
  test = insert_order(test, "c","a");
  printf("New list:\n");
  print_list(test);

  printf("Testing find_node for song b by artist a\n");
  //print_node(test);
  print_node(find_node(test, "b", "a"));
  printf("\n");

  printf("Testing find_node_artist for artist b\n");
  print_list(find_node_artist(test, "b"));
  printf("\n");

  printf("Testing find_node_random\n");
  print_node(find_node_random(test));
  printf("\n");
  return 0;
}
