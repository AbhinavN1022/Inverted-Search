#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"

sub_node_t *create_sub_node(char *filename)
{
    sub_node_t *new=malloc(sizeof(sub_node_t));  // Allocate memory for new node
    if(new==NULL)   // Check if memory allocation failed
    {
        return FAILURE;
    }
    new->word_count=1;                // Initialize word count to 1
    strcpy(new->filename,filename);   // Copy given filename into node
    new->link=NULL;                    // Initialize new link to NULL

    return new;    // Return newly created node
}
