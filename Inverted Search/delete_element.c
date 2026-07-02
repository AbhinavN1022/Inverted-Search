#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"

int sl_delete_element(Slist **head, char *filename)
{
    if(*head==NULL)    //Check the node is empty or not
      return FAILURE;
    
    Slist *temp=*head;   //Create a temp node and store head into the temp
    Slist *prev=NULL;     //Create a previous node
     
 
    while(temp != NULL)  //Run the loop upto last node
    {
        if(strcmp(temp->filename,filename)==0)   //checking for the node
        {
            if(prev==NULL)
            {
                *head=temp->link;
            }
            else
            {
                  prev->link=temp->link;//Update previous node link
            }
        free(temp);               //freeing the node
        return SUCCESS;
            
           
        }
        else
        {
             prev=temp;   
            temp=temp->link;   //Update temp with next node
        }
    }
    return DATA_NOT_FOUND;   //if node note found return data not found
  
}