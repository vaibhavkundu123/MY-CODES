#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};

struct node *Head = NULL;

struct node *create_ll(struct node *Head)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter - 1 to end");
    printf("\n Enter the data: ");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (Head == NULL)
        {
            new_node->next = NULL;
            Head = new_node;
        }
        else
        {
            ptr = Head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = NULL;
        }
        printf("\n Enter the data: ");
        scanf("%d", &num);
    }
    return Head;
}

/*
struct node *temp = NULL;
struct node *prev = NULL;
struct node *create_ll(struct node *Head)
{
	char choice;
	do {
		temp = (struct node *)malloc(sizeof(struct node));
		if(temp == NULL) {
			printf("Memory allocation failed\n");
			return NULL;
		}
		printf("\n Enter the data: ");
    	scanf("%d", &(temp -> data));
    	temp -> next = NULL;
    	if(Head == NULL) {
    		Head = temp;
    	}
    	else {
    		prev -> next = temp;
    	}
    	prev = temp;
    	fflush(stdin);
    	printf("Do you want to create more nodes? (y/n):");
    	scanf("%c", &choice);
	}while(choice == 'y' || choice == 'Y');
	return Head;
}
*/

struct node *display(struct node *Head)
{
    struct node *ptr;
    ptr = Head;
    while (ptr != NULL)
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    return Head;
}

struct node *insert_beg(struct node *Head)
{
    struct node *new_node;
    int num;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = Head;
    Head = new_node;
    return Head;
}

struct node *insert_end(struct node *Head)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    ptr = Head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;
    return Head;
}

struct node *insert_before(struct node *Head)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = Head;
    while (ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return Head;
}

struct node *insert_after(struct node *Head)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = Head;
    preptr = ptr;
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return Head;
}

struct node *delete_beg(struct node *Head)
{
    struct node *ptr;
    ptr = Head;
    Head = Head->next;
    free(ptr);
    return Head;
}

struct node *delete_end(struct node *Head)
{
    struct node *ptr, *preptr;
    ptr = Head;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return Head;
}

struct node *delete_node(struct node *Head)
{
    struct node *ptr, *preptr;
    int val;
    printf("\n Enter the value of the node which has to be deleted: ");
    scanf("%d", &val);
    ptr = Head;
    if (ptr->data == val)
    {
        Head = delete_beg(Head);
        return Head;
    }
    else
    {
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        return Head;
    }
}

struct node *delete_after(struct node *Head)
{
    struct node *ptr, *preptr;
    int val;
    printf("\n Enter the value after which the node has to deleted: ");
    scanf("%d", &val);
    ptr = Head;
    preptr = ptr;
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return Head;
}

struct node *delete_list(struct node *Head)
{
    struct node *ptr;
    if (Head != NULL)
    {
        ptr = Head;
        while (ptr != NULL)
        {
            printf("\n %d is to be deleted next", ptr->data);
            Head = delete_beg(ptr);
            ptr = Head;
        }
    }
    return Head;
}

struct node *sort_list(struct node *Head)
{
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = Head;
    while (ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return Head;
}

int main(int argc, char *argv[])
{
    int option;
    do
    {
        printf("\n\n * ****MAIN MENU * ****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: Delete the entire list");
        printf("\n 12: Sort the list");
        printf("\n 13: EXIT");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            Head = create_ll(Head);
            printf("\n LINKED LIST CREATED");
            break;
        case 2:
            Head = display(Head);
            break;
        case 3:
            Head = insert_beg(Head);
            break;
        case 4:
            Head = insert_end(Head);
            break;
        case 5:
            Head = insert_before(Head);
            break;
        case 6:
            Head = insert_after(Head);
            break;
        case 7:
            Head = delete_beg(Head);
            break;
        case 8:
            Head = delete_end(Head);
            break;
        case 9:
            Head = delete_node(Head);
            break;
        case 10:
            Head = delete_after(Head);
            break;
        case 11:
            Head = delete_list(Head);
            printf("\n LINKED LIST DELETED");
            break;
        case 12:
            Head = sort_list(Head);
            break;
        }
    } while (option != 13);
    return 0;
}
