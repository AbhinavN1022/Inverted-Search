#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"

int insert_at_last(Slist **head,char *data)
{
     //Create the node
     Slist *new=malloc(sizeof(Slist));
     if(new==NULL)  //Check the memory is allocated or not
     {
         return FAILURE;
     }
     strcpy(new->filename,data);  //Assign the data 
     new->link=NULL;  //Assign the node link with NULL
    
     //check the list is empty or not
     if(*head==NULL)
     {
         //Update head with new node
         *head=new;
         return SUCCESS;
     }
     else
     {
         //list is non empty
         Slist *temp=*head;  //Create a temp node
         while(temp->link !=NULL)  //Run the loop upto last node
         {
            if(strcmp(temp->filename,data)==0)
            {
                printf("Duplicate File Name Present\n");
                free(new);
                return FAILURE;
            }
            if(temp->link==NULL)
            {
                break;
            }
            temp=temp->link;
         }
         //Update the last node link with new
         temp->link=new;
     }
     return SUCCESS;
     
}