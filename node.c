#include "node.h"

struct node* create_node(char* name, char* artist){
  struct node* newNode = malloc(sizeof(struct node));
  strcpy(newNode->name, name);
  strcpy(newNode->artist, artist);
  newNode->nextNode = NULL;
  return newNode;
}

struct node* insert_front(struct node* head, char* name, char* artist){
  struct node* newNode = create_node(name, artist);
  newNode->nextNode = head;
  return newNode;
}

int get_size(struct node* head){
  int size = 0;
  struct node* currentNode = head;
  while(currentNode != NULL){
    size++;
    currentNode = currentNode->nextNode;
  }

  return size;
}

void print_node(struct node* n){
  if(n == NULL) printf("NULL\n");
  else printf("Song name: [%s] Artist: [%s]\n", n->name, n->artist);
}

void print_list(struct node* head){
  if(head == NULL) print_node(head);
  else{
    struct node* currentNode = head;
    while(currentNode != NULL){
      print_node(currentNode);
      currentNode = currentNode->nextNode;
    }
  }
  printf("\n");
}

struct node* insert_order(struct node* head, char* name, char* artist){
  struct node* currentNode = head;
  if(head == NULL || strcmp(currentNode->artist, artist) > 0){
    return insert_front(head, name, artist);
  }

  struct node* newNode = create_node(name, artist);

  while(currentNode->nextNode != NULL && strcmp(currentNode->nextNode->artist, newNode->artist) < 0 ) currentNode = currentNode->nextNode;
  if(currentNode->nextNode == NULL) {
    currentNode->nextNode = newNode;
    return head;
  }

  while(currentNode->nextNode != NULL && strcmp(currentNode->nextNode->name, newNode->name) <= 0 && strcmp(currentNode->nextNode->artist, newNode->artist) == 0) currentNode = currentNode->nextNode;
  if(currentNode->nextNode == NULL) {
    currentNode->nextNode = newNode;
  }
  else{
    struct node* nextNode = currentNode->nextNode;
    newNode->nextNode = nextNode;
    currentNode->nextNode = newNode;
  }

  return head;
}

struct node* find_node(struct node* head, char* name, char* artist){
  struct node* currentNode = head;
  while(currentNode != NULL){
    if(strcmp(currentNode->name, name) == 0 && strcmp(currentNode->artist, artist) == 0) return currentNode;
    currentNode = currentNode->nextNode;
  }

  return NULL;
}

struct node* find_node_artist(struct node* head, char* artist){
  struct node* currentNode = head;
  while(currentNode != NULL){
    if(strcmp(currentNode->artist, artist) == 0) return currentNode;
    currentNode = currentNode->nextNode;
  }

  return NULL;
}

struct node* find_node_random(struct node* head){
  srand(time(0));
  struct node* n = head;

  for(int x = 0; x < rand() % get_size(head); x++){
    n = n->nextNode;
  }

  return n;
}

struct node* remove_node(struct node* head, char* name, char* artist){
  if(strcmp(head->name, name) == 0 && strcmp(head->artist,artist) == 0) {
    struct node* nextNode = head->nextNode;
    free(head);
    return head->nextNode;
  }
  struct node* currentNode = head;
  while(currentNode->nextNode != NULL){
    if(strcmp(currentNode->nextNode->name, name) == 0 && strcmp(currentNode->nextNode->artist,artist) == 0){
      struct node* newNext = currentNode->nextNode->nextNode;
      free(currentNode->nextNode);
      currentNode->nextNode = newNext;
      return head;
    }
    currentNode = currentNode->nextNode;
  }

  return head;
}

struct node* free_nodes(struct node* head){
  struct node* currentNode = head;

  if(currentNode->nextNode == NULL){
    free(head);
    return NULL;
  }

  struct node* nextNode = head->nextNode;
  while(nextNode != NULL){
    free(currentNode);
    currentNode = nextNode;
    nextNode = currentNode->nextNode;
  }

  free(currentNode);
  return NULL;
}
