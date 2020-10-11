#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "request.h"

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code. Includes request.h       *
 *       --Brandon Yates                                  *
 **********************************************************/
int main(void)
{
  char code;

  struct request *new_list = NULL;
  printf("Operation Code: a for appending to the list, u for updating a request"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': new_list = append_to_list(new_list);
                break;
      case 'u': update(new_list);
                break;
      case 'p': printList(new_list);
                break;
      case 'q': clearList(new_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}



