#include "node.h"

struct node** create_library();
struct node** add_song(struct node** library, char* name, char* artist);
void print_library(struct node** library);
void print_library_letter(struct node** library, char* letter);
void print_library_artist(struct node** library, char* artist);
void print_library_shuffle(struct node** library, int n);
struct node* find_song(struct node** library, char* name, char* artist);
struct node* find_artist(struct node** library, char* artist);
struct node** remove_song(struct node** library, char* name, char* artist);
struct node** clear_library(struct node** library);
