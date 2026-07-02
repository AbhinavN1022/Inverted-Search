#ifndef HEADER_H
#define HEADER_H
#include<stdio.h>

typedef struct node
{
    char filename[30];
    struct node *link;
}Slist;

typedef struct subnode
{
    int word_count;
    char filename[30];
    struct subnode *link;
}sub_node_t;

typedef struct main_node
{
   int file_count;
   char word[50];
   sub_node_t *sublink;
   struct main_node *link;  
}main_node_t;

typedef struct hashnode
{
    int index;
    main_node_t *link;
}hash_t;


#define SUCCESS 1
#define FAILURE 0
#define DATA_NOT_FOUND -2


int insert_at_last(Slist **head,char *data);
void print_list(Slist *head);
main_node_t *create_main_node(char *word);
sub_node_t *create_sub_node(char *word);
int create(Slist *head,hash_t arr[]);
void display(Slist *head,hash_t arr[]);
int update(Slist **head,hash_t arr[]);
int sl_delete_element(Slist **head, char *filename);
int search(hash_t arr[]);
int save(hash_t arr[]);

#define GREEN   "\033[0;32m"
#define RED     "\033[0;31m"
#define YELLOW  "\033[0;33m"
#define RESET   "\033[0m"

#endif