#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "request.h"
#include "readline.h"
/*
    request.c contains all the functions for laundry_list.c
    includes request.h and readline.h.
    --Brandon Yates
*/
/*
APPEND FUNCTION:
Gets the room number, first name, last name, and the number of items the user wants to wash.
Creates a new node and appends it to the end of the linked list.
*/
struct request *append_to_list(struct request *list)
{
 struct request *new_node, *last_node, *search;


    new_node = malloc(sizeof(struct request));
    //new_node->next = NULL;

    if(new_node == NULL)
    {
        printf("Error allocating memory.\n");
        return list;
    }

    //get room number
    printf("Enter room number: ");
    scanf("%d\n", &new_node->room_number);

    //search to see if the room number already exists in the LL.
    for(search = list; search != NULL; search = search->next)
    {
        if(search->room_number == new_node->room_number)
        {
            printf("Room request already exists. Update request using main menu.\n");
            return list;
        }
    }

    //get first and last name
     printf("Enter first name: ");
    read_line(new_node->first, NAME_LEN+1);
    printf("\nEnter last name: ");
    read_line(new_node->last, NAME_LEN+1);

    //get the number of items.
    printf("\nEnter the number of items you wish to wash: ");
    scanf("%d\n", &new_node->num_items);

    new_node->next = NULL;


    //if list is empty, return pointer to newly created linked list.
    if(list == NULL)
    {
        list = new_node;
        return list;
    }
    //else add request to the end of the LL and return pointer to the LL.
    else
    {
        last_node = list;
        while(last_node->next!=NULL)
            last_node = last_node->next;
    }
    last_node->next = new_node;


 return list;

}

/*
UPDATE FUNCTION:
User enters their room number and the node containing the room number is updated with the number of items the user wants to add on.
*/
void update(struct request *list)
{


    struct request *search;
    int add_items;

    //ask to enter room num
    printf("Enter room number: ");
    int room;
    scanf("%d\n", &room);

    //find matching room num
    for(search = list; search != NULL; search = search->next)
    {

        if(search->room_number == room)
        {
            //ask to enter num of items to be added and update num of items


            printf("How many items would you like to add:\n ");
            scanf("%d\n", &add_items);
            printf("Updated request.\n");
            search->num_items = search->num_items + add_items;
            return;

        }
    }
    //if room num is not found, print a message.

    printf("Could not find request.");
    return;
}

/*
PRINTLIST FUNCTION:
Prints all the nodes in list.
*/
void printList(struct request *list)
{
  //print room num, first and last name, and num of items for all requests on the list.
    while(list != NULL)
    {
        printf("%d ", list->room_number);
        printf("%s ", list->first);
        printf("%s ", list->last);
        printf("%d\n ", list->num_items);
        list = list->next;
    }
}

/*
CLEARLIST FUNCTION:
Deallocates all memory set aside for the linked list.
*/
void clearList(struct request *list)
{
 //when the user exits the program, all the memory allocates for the LL should be deallocated.
  struct request *p;
  while(list != NULL)
  {
	 p = list;
     list = list->next;
     if( p!= NULL)
           free(p);
  }

}
