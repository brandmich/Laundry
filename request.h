/*
    header file that contains the declaration of the structure and function declarations used in request.c
    --Brandon Yates
*/

#ifndef REQUEST_H
#define REQUEST_H
#define NAME_LEN 30

//struct definition
struct request{
	int room_number;
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	int num_items;
	struct request *next;
};

//Function Declarations
struct request *append_to_list(struct request *list);
void update(struct request *list);
void printList(struct request *list);
void clearList(struct request *list);
#endif // REQUEST_H
