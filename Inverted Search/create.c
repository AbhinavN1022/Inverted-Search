#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#include"header.h"

int create(Slist *head,hash_t arr[])
{
    char word[25];      // Buffer to store each word from file
    Slist *temp=head;   //Store head in a temporary pointer

    while(temp!=NULL)  // Traverse through each file node
    {

        FILE *fptr=fopen(temp->filename,"r");   // Open file in read mode
        if(fptr==NULL)    // Check if file opened successfully
        {
            printf("Unable to open %s\n", head->filename);
             return FAILURE;   // Return failure if file cannot open
        }
           
        while(fscanf(fptr,"%s",word) ==1)   // Read words one by one
        {
            char ch=tolower(word[0]);  // Convert first character to lowercase
            int index;

            if(ch>='a' && ch<='z')  // If alphabet
            {
                index=ch -'a';   // Calculate index 
            }
            else
              index=26;    // Non-alphabet words at index 26

            if(arr[index].link==NULL)  // If no word at this index
            {
                main_node_t *main=create_main_node(word);  // Create main node
                if(main==NULL)
                {
                    return FAILURE;
                }

                sub_node_t *sub=create_sub_node(temp->filename);  // Create sub node
                if(sub==NULL)
                {
                    return FAILURE;   
                }

                main->sublink=sub;   // Link sub node to main node
                arr[index].link=main;  // Attach main node to hash table
            }
            else
            {
                main_node_t *main_temp=arr[index].link;
                main_node_t *prev_main=NULL;

                while(main_temp != NULL)  //Check if word is present
                {
                    if(strcmp(main_temp->word,word)==0)
                    {
                        break;
                    }
                    prev_main=main_temp;
                    main_temp=main_temp->link;
                }

                if(main_temp != NULL)  //if word present
                {
                    sub_node_t *sub_temp=main_temp->sublink;
                    sub_node_t *prev_sub=NULL;

                    while(sub_temp != NULL)
                    {
                        if(strcmp(sub_temp->filename,temp->filename)==0)
                        {
                            break;
                        }
                        prev_sub=sub_temp;
                        sub_temp=sub_temp->link;
                    }
                    if(sub_temp != NULL) 
                    { 
                        //same file increment word cound
                        sub_temp->word_count++;
                    }
                    else
                    {
                        sub_node_t *sub=create_sub_node(temp->filename);
                        if(sub==NULL)
                        {
                            return FAILURE;
                        }
                        if(prev_sub==NULL)
                        {
                            main_temp->sublink=sub;  // Insert at beginning
                        }
                        else
                           prev_sub->link=sub;  // Insert at end

                        main_temp->file_count++;  // Increase file count
                    }
                }
                else
                {
                    //word not found
                    main_node_t *main=create_main_node(word);
                    if(main==NULL)
                    {
                        return FAILURE;
                    }

                    sub_node_t *sub =create_sub_node(temp->filename);
                    if(sub==NULL)
                    {
                        return FAILURE;
                    }
                    main->sublink=sub;   // Attach sub node

                   if(prev_main==NULL)
                   {
                    arr[index].link=main;   // Insert at head
                   }
                   else
                    prev_main->link=main; // Insert at end
                }
            }
        }
        fclose(fptr);  // Close file after reading
        temp=temp->link;    // Move to next file
    }
    return SUCCESS;
}