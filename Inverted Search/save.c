#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"

int save(hash_t arr[])
{
    char save[25];
    printf("Enter a file to save: ");
    scanf("%s",save);  // Read filename from user

    char *fptr=strstr(save,".");  // Find file extension
    if(fptr==NULL || strcmp(fptr,".txt")!=0)  // Validate .txt file
    {
        printf(RED "Enter a valid filename\n" RESET);
        return FAILURE;
    }

    FILE *ptr=fopen(save,"w"); // Open file in write mode
    if(ptr==NULL)   // Check if file opened successfully
    {
        return FAILURE;
    }
    for(int i=0 ; i<27 ; i++)  // Traverse hash table
    {
        if(arr[i].link != NULL)  // If index contains words
        {
            
            main_node_t *main_temp=arr[i].link;     // Traverse main nodes
            while(main_temp != NULL)
            {  
                
                sub_node_t *sub_temp=main_temp->sublink; // Traverse sub nodes
                while(sub_temp != NULL)   
                {
                   
                    fprintf(ptr,"#%d;%d;%s;%d;%s;#\n",arr[i].index,main_temp->file_count,main_temp->word,sub_temp->word_count,sub_temp->filename); 
                    sub_temp = sub_temp->link; // Move to next sub node
                    
                }
                main_temp = main_temp->link; // Move to next main node
            }                    
        }
        
    }
    fclose(ptr);   // Close file
    printf(GREEN "Database saved successfully ✅\n" RESET);
    return SUCCESS;
}