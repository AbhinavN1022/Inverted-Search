#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"

void display(Slist *head, hash_t arr[])
{
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                         📚 DATABASE                          ║\n");
    printf("╠════════╦════════════╦════════╦════════════════╦══════════════╣\n");
    printf("║ %-6s ║ %-10s ║ %-6s ║ %-14s ║ %-12s ║\n",
           "Index", "Word", "Files", "File Name", "Word Count");
    printf("╠════════╬════════════╬════════╬════════════════╬══════════════╣\n");

    for(int i = 0; i < 27; i++) // Traverse hash table (0–26)
    {
        if(arr[i].link != NULL)  // Check if index has data
        {
            main_node_t *main_temp = arr[i].link; // Traverse main nodes

            while(main_temp != NULL)
            {
                sub_node_t *sub_temp = main_temp->sublink; // Traverse sub nodes

                while(sub_temp != NULL)
                {
                    printf("║ %-6d ║ %-10s ║ %-6d ║ %-14s ║ %-12d ║\n",
                           arr[i].index,   // Print index
                           main_temp->word,  // Print word
                           main_temp->file_count,  // Print filecount
                           sub_temp->filename,  // Print filename
                           sub_temp->word_count);  // Print wordcount

                    sub_temp = sub_temp->link; // Move to next sub node
                }

                main_temp = main_temp->link; // Move to next main node
            }
        }
    }

    printf("╚════════╩════════════╩════════╩════════════════╩══════════════╝\n");
}