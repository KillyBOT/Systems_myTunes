#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node {
  char name[128];
  char artist[128];
  struct node *nextNode;
};

int get_size(struct node* head);
struct node* create_node(char* name, char* artist);
struct node* insert_front(struct node* head, char* name, char* artist);
struct node* insert_order(struct node* head, char* name, char* artist);
void print_node(struct node* n);
void print_list(struct node* head);
struct node* find_node(struct node* head, char* name, char* artist);
struct node* find_node_artist(struct node* head, char* name);
struct node* find_node_random(struct node* head);
struct node* remove_node(struct node* head, char* name, char* artist);
struct node* free_nodes(struct node* head);
