#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#include"header.h"

int search(hash_t arr[])
{
    char word[25];
    printf("Enter the word: ");
    scanf("%s", word);  //Read the word from user

    char ch=tolower(word[0]); // Convert to lowercase

    int index;
    if(ch>='a' && ch<='z')   // Validate alphabet
        index=ch-'a';
    else
      index=26;  // Non-alphabet index

    main_node_t *main_temp = arr[index].link;

    while (main_temp != NULL)
    {
        if (strcmp(main_temp->word, word) == 0)
        {
            printf("\n================================================\n");
            printf("                 SEARCH RESULT                 \n");
            printf("================================================\n");

            printf("  Word        : %s\n", main_temp->word);
            printf("  File Count  : %d\n", main_temp->file_count);

            printf("------------------------------------------------\n");

            sub_node_t *sub_temp = main_temp->sublink;
            while (sub_temp != NULL)
            {
                printf("  %-18s | %3d times\n",
                       sub_temp->filename,
                       sub_temp->word_count);

                sub_temp = sub_temp->link;
            }

            printf("================================================\n");
            return SUCCESS;
        }

        main_temp = main_temp->link;
    }

    printf("\n================================================\n");
    printf("                WORD NOT FOUND                 \n");
    printf("================================================\n");

    return FAILURE;
}