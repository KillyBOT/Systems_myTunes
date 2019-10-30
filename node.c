#include "node.h"

struct node* create_node(char* name, char* artist){
  struct node* newNode = malloc(sizeof(struct node));
  strcpy(newNode->name, name);
  strcpy(newNode->artist, artist);
  return newNode;
}

struct node* insert_front(struct node* head, char* name, char* artist){
  if(head == NULL) return create_node(name, artist);
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
  struct node* currentNode = head;
  while(currentNode != NULL){
    print_node(currentNode);
    currentNode = currentNode->nextNode;
  }
  printf("\n");
}

struct node* insert_order(struct node* head, char* name, char* artist){
  struct node* currentNode = head;
  struct node* newNode = create_node(name, artist);
  if(currentNode == NULL) return newNode;
  while(currentNode->nextNode != NULL && strcmp(currentNode->nextNode->artist, newNode->artist) < 0 ) currentNode = currentNode->nextNode;
  //print_node(currentNode->nextNode);
  //printf("\n");
  if(currentNode->nextNode == NULL) {
    currentNode->nextNode = newNode;
    return head;
  }

  while(currentNode->nextNode != NULL && strcmp(currentNode->nextNode->name, newNode->name) <= 0 && strcmp(currentNode->nextNode->artist, newNode->artist) == 0) currentNode = currentNode->nextNode;
  //print_node(currentNode->nextNode);
  //printf("\n");
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
  if(strcmp(head->name, name) == 0 && strcmp(head->artist,artist) == 0) return NULL;

  struct node* currentNode = head;
}
