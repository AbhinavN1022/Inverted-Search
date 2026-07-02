#include<stdio.h>
#include"header.h"

void print_list(Slist *head)
{
	if (head == NULL)  
	{
		printf(RED "INFO : List is empty\n" RESET);
	}
    else
    {
	    while (head)		
	    {
		    printf("%s -> ", head -> filename);
		    head = head -> link;
	    }

	    printf("NULL\n");
    }
}