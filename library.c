#include "library.h"

struct node** create_library(){
  struct node** newLibrary = malloc(sizeof(struct node) * 27);
  for(int x = 0; x < 27; x++){
    newLibrary[x] = NULL;
  }

  return newLibrary;
}

struct node** add_song(struct node** library, char* name, char* artist){
  struct node** newLibrary = library;
  int artistPos = artist[0] - 97;
  if(artistPos < 0 || artistPos > 25) newLibrary[26] = insert_order(newLibrary[26], name, artist);
  else newLibrary[artistPos] = insert_order(newLibrary[artistPos], name, artist);
  return newLibrary;
}

void print_library(struct node** library){
  if(library == NULL) printf("NULL\n");
  else{
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
  struct node* n = find_artist(library, artist);
  if( n == NULL) printf("Artist not found!\n");
  else print_list(n);
}

void print_library_shuffle(struct node** library, int n){
  struct node* shuffleList = NULL;
  struct node* randSong = NULL;
  srand(time(0));
  int temp;
  for(int x = 0; x < n; x++){
    temp = rand() % 26;
    while(library[temp] == NULL || find_node(shuffleList, library[temp]->name, library[temp]->artist)) temp = rand() % 26;
    randSong = find_node_random(library[temp]);
    shuffleList = insert_front(shuffleList, randSong->name, randSong->artist);
  }

  print_list(shuffleList);
  free_nodes(shuffleList);
}

struct node* find_song(struct node** library, char* name, char* artist){
  int pos = artist[0] - 97;
  if(pos < 0 || pos > 25){
    return find_node(library[26],name,artist);
  } else {
    return find_node(library[pos],name,artist);
  }
}

struct node* find_artist(struct node** library, char* artist){
  int pos = artist[0] - 97;
  if(pos < 0 || pos > 25){
    return find_node_artist(library[26],artist);
  } else {
    return find_node_artist(library[pos],artist);
  }
}

struct node** remove_song(struct node** library, char* name, char* artist){
  struct node** newLibrary = library;
  int artistPos = artist[0] - 97;
  if(artistPos < 0 || artistPos > 25) newLibrary[26] = remove_node(newLibrary[26], name, artist);
  else newLibrary[artistPos] = remove_node(newLibrary[artistPos], name, artist);
  return newLibrary;
}

struct node** clear_library(struct node** library){
  for(int x = 0; x < 27; x++){
    if(library[x] != NULL) library[x] = free_nodes(library[x]);
  }
  free(library);
  return NULL;
}
