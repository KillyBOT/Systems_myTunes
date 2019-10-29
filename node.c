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
  while(head != NULL){
    size++;
    currentNode = head->nextNode;
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
  while(currentNode->nextNode != NULL && strcmp(currentNode->artist, newNode->artist) > 0 && strcmp(currentNode->name, newNode->name) > 0) currentNode = currentNode->nextNode;

  if(currentNode->nextNode == NULL) currentNode->nextNode = newNode;
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
