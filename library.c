#include "library.h"

struct node** create_library(){
  struct node** newLibrary = malloc(sizeof(struct node) * 27);
  for(int x = 0; x < 27; x++){
    newLibrary[x] = malloc(sizeof(struct node));
  }

  return newLibrary;
}

struct node** add_song(struct node** library, char* name, char* artist){
  int artistPos = artist[0] - 97;
  library[artistPos] = insert_order(library[artistPos], name, artist);
  print_list(library[artistPos]);
  return library;
}

void print_library(struct node** library){
  for(int x = 0; x < 26; x++){
    printf("%c list:\n", x+97);
    print_list(library[x+97]);
  }
  printf("ETC list:\n");
  print_list(library[26]);
}
