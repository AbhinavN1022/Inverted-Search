#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"

int update(Slist **head,hash_t arr[])
{
    char filename[30];
    printf("Enter the backup filename: ");
    scanf("%s",filename);  // Read file name from user

    char *fptr=strstr(filename,".");   // Find extension
    if(fptr==NULL || strcmp(fptr,".txt")!=0)  // Validate .txt file
    {
        printf(RED "Enter a valid file name\n" RESET);
        return FAILURE;
    }
    FILE *ptr=fopen(filename,"r");  // Open backup file in read mode
    if(ptr==NULL)    // Check if file exists
    {
        printf(RED "File not found\n" RESET);
        return FAILURE;
    }
    
    char line[100];  // Buffer to store each record
    while(fscanf(ptr, "%s" ,line)==1)   // Read each entry
    {
        int len=strlen(line);  // Get length of line
        if(line[0]=='#' && line[len-1]=='#')  // Validate record format
        {
            char *token=strtok(&line[1],";");  // Extract index
            int index=atoi(token);
            if(index < 0 || index >= 27)
            {
                continue;
            }
            token=strtok(NULL,";");   // Extract file count
            int filecount=atoi(token);

            token=strtok(NULL,";");  // Extract word
            char word[25];
            strcpy(word,token);

            main_node_t *main=create_main_node(word);  // Create main node
            if(main==NULL)
            {
                return FAILURE;
            }
            main->file_count=filecount;    // Set file count
            if(arr[index].link==NULL)  // Insert into hash table
                   arr[index].link=main;
            else
            {
                main_node_t *temp=arr[index].link;  // Traverse main list
                while(temp->link != NULL)
                     temp=temp->link;
                
                temp->link=main;

            }
            while((token = strtok(NULL,"#;"))!=NULL)
            {
                int word_count=atoi(token);  // Extract word count
                token=strtok(NULL,"#;");
                if(token==NULL)
                {
                    break;
                }
                char sub_filename[30];
                strcpy(sub_filename,token); // Extract file name
                sl_delete_element(head,filename);  // Delete from file list 
                sub_node_t *sub=create_sub_node(sub_filename);   // Create sub node
                if(sub==NULL)
                {
                    return FAILURE;
                }
                sub->word_count=word_count;  // Set word count
                sub->link=NULL;

                if(main->sublink==NULL)   // Insert first sub node
                     main->sublink=sub;

                else
                {
                    sub_node_t *temp=main->sublink;
                    while(temp->link != NULL)
                    {
                        temp=temp->link;
                    }
                    temp->link=sub;     // Insert at end 
                }
            }
        }
    }
    fclose(ptr);
    printf(GREEN "Database Updated Successfully ✅\n" RESET);
    return SUCCESS;
    
}