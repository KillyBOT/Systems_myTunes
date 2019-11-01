#include "library.h"

struct node** create_library(){
  struct node** newLibrary = malloc(sizeof(struct node) * 27);
  for(int x = 0; x < 28; x++){
    newLibrary[x] = NULL;
  }

  return newLibrary;
}

struct node** add_song(struct node** library, char* name, char* artist){
  struct node** newLibrary = library;
  int artistPos = artist[0] - 97;
  if(artistPos < 0 || artistPos > 25) newLibrary[26] = insert_order(newLibrary[26], name, artist);
  else newLibrary[artistPos] = insert_order(newLibrary[artistPos], name, artist);
  //print_list(newLibrary[artistPos]);
  return newLibrary;
}

void print_library(struct node** library){
  for(int x = 0; x < 26; x++){
    if(library[x] != NULL){
      printf("%c list:\n", x+97);
      print_list(library[x]);
    }
  }
  if(library[26] != NULL){
    printf("ETC list:\n");
    print_list(library[26]);
  }
}

void print_library_letter(struct node** library, char c){
  int pos = c - 97;
  if(pos < 0 || pos > 25){
    printf("ETC list: \n");
    print_list(library[26]);
  } else {
    printf("%c list:\n",c);
    print_list(library[pos]);
  }
}

void print_library_artist(struct node** library, char* artist){
  int pos = artist[0] - 97;
  struct node* n;
  if(pos < 0 || pos > 25){
    n = find_node_artist(library[26],artist);
    if(n == NULL) printf("Artist [%s] not found!\n",artist);
    else print_list(n);
  } else {
    n = find_node_artist(library[pos],artist);
    if(n == NULL) printf("Artist [%s] not found!\n",artist);
    else print_list(n);
  }
}
