/*
Name        : Abhinav N
Date        : 28-02-2026

Description :

This project implements an Inverted Search System using 
Hashing and Singly Linked Lists in C. It creates an indexed 
database of words from multiple input files and allows 
efficient searching of words.

The system reads words from files, stores each unique word 
in a main node, and maintains file-specific details using 
sub-nodes. A hash table of size 27 (a–z and special index) 
is used to optimize search performance.

Each word is stored only once in the main node. For every 
file containing that word, a sub-node is created that 
stores the filename and word count.

The following functions are implemented:

- insert_at_last()      : Inserts filename into file list
- create_main_node()    : Creates a main node for a word
- create_sub_node()     : Creates a sub node for file details
- create()              : Creates the inverted index database
- display()             : Displays the database content
- search()              : Searches for a word in database
- update()              : Updates database from backup file
- save()                : Saves database into a file
- sl_delete_element()   : Deletes a file from file list

*/



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"


int main(int argc, char *argv[])
{
    if(argc==1)   // Check if no files are passed
    {
        printf(RED "Insufficient arguments\n" RESET);
        return 0;
    }
    Slist *head=NULL;  // Initialize file linked list

    for(int i=1 ; i<argc ; i++)   // Traverse command-line files
    { 
        char *ptr=strstr(argv[i],".");  // Check file extension
        if(ptr==NULL || strcmp(ptr,".txt")!=0)
        {
            printf("%s is not .txt file\n",argv[i]);
            continue;  // Skip invalid files
        }
        FILE *fptr=fopen(argv[i],"r");  // Open file in read mode
        if(fptr==NULL)
        {
            printf(RED "File is not present\n" RESET);
            continue;  // Skip if file not found
        }
        fseek(fptr,0,SEEK_END); // Move to end of file
        long size=ftell(fptr);  // Get file size
        if(size==0)    // Check if file is empty
        { 
           printf("%s file is empty\n",argv[i]);
           fclose(fptr);   
           continue; 
        }
        fclose(fptr);   // Close file
        insert_at_last(&head,argv[i]);   // Insert valid file into list
    }
    print_list(head);   // Display file list

    hash_t arr[27];   // Hash table of size 27
    for(int i=0 ; i<27 ; i++)
    {
        arr[i].index=i;   // Initialize index
        arr[i].link=NULL;  // Initialize link
    }

    int opt;
    int db_created=0;  // Flag to check DB creation
    while(1)
    {
        printf("╔══════════════════════════════════════════════╗\n");
        printf("║          INVERTED SEARCH MAIN MENU           ║\n");
        printf("╠══════════════════════════════════════════════╣\n");
        printf("║  1.  Create Database                         ║\n");
        printf("║  2.  Search Database                         ║\n");
        printf("║  3.  Update Database                         ║\n");
        printf("║  4.  Display Database                        ║\n");
        printf("║  5.  Save Database                           ║\n");
        printf("║  6.  Exit                                    ║\n");
        printf("╚══════════════════════════════════════════════╝\n");
        printf(YELLOW "👉 Enter Your Choice: " RESET);
        scanf("%d",&opt); // Read user choice

       switch(opt)
       {
         case 1:
            if(create(head,arr)==SUCCESS)   // Create database
            {
                printf(GREEN "Database Created Successfully ✅\n" RESET);
                db_created = 1; // Set flag
            }
            else
            {
                 printf(RED "Database Creation Failed\n" RESET);
            }
            break;

        case 2:
            if(db_created)
                    search(arr);  // Search Database
                else
                    printf(RED "Create database first\n" RESET);
                break;

        case 3:
              update(&head,arr); // Update Database
              break;
             
        
         case 4:
            if(db_created)
                    display(head, arr);  // Display Databse
                else
                    printf(RED "Create database first\n" RESET);
                break;

        case 5:
           if(db_created)
                  save(arr);   // Save Database
              else
                printf(RED "Created Database first\n" RESET);
              break;
           

         case 6:
            printf(GREEN "Exiting...\n" RESET);
            return 0;

         default:
            printf(RED "Invalid Input\n" RESET);
            break;
      }

    }
    
}