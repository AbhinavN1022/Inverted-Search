#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"

main_node_t *create_main_node(char *word)
{
    main_node_t *new=malloc(sizeof(main_node_t)); //Allocate memory for new node
    if(new==NULL)                   // Check if memory allocation failed
    {
        return FAILURE;
    }
    new->file_count=1;          // Initialize file count to 1
    strcpy(new->word,word);     // Copy given word into node
    new->sublink=NULL;          // Initialize sublink to NULL
    new->link=NULL;              // Initialize next main link to NULL

    return new;     // Return newly created node
}