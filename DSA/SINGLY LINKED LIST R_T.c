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
    printf("\t NULL");
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
    struct node *new_node, *ptr;
    int num, pos, i = 1;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    printf("\n Enter the node before which the data has to be inserted: ");
    scanf("%d", &pos);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    ptr = Head;
    while (i != pos - 1)
    {
        ptr = ptr->next;
        i++;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
    return Head;
}

struct node *insert_after(struct node *Head)
{
    struct node *new_node, *ptr;
    int num, pos, i = 0;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    printf("\n Enter the node after which the data has to be inserted: ");
    scanf("%d", &pos);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    ptr = Head;
    while (i != pos - 1)
    {
        ptr = ptr->next;
        i++;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
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
    preptr = Head;
    ptr = preptr->next;
    while (ptr->next != NULL)
    {
        preptr = preptr->next;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return Head;
}

struct node *delete_node(struct node *Head)
{
    struct node *ptr, *preptr;
    int pos, i = 1;
    printf("\n Enter the node which has to be deleted: ");
    scanf("%d", &pos);
    preptr = Head;
    ptr = preptr->next;
    while (i != pos - 1)
    {
        preptr = preptr->next;
        ptr = ptr->next;
        i++;
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

struct node *search(struct node *Head)
{
    struct node *ptr;
    int num;
    ptr = Head;
    printf("\n Enter the data to be searched: ");
    scanf("%d", &num);
    while (ptr != NULL)
    {
        if (ptr->data == num)
        {
            printf("\n The given data %d is present", num);
            break;
        }
        else
            ptr = ptr->next;
    }
    return Head;
}

int count(struct node *Head)
{
    struct node *temp;
    int count = 1;
    temp = Head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

struct node *reverse(struct node *Head)
{
    struct node *prev = NULL;
    struct node *current = Head;
    struct node *next;
    if (Head == NULL) {
        printf("List is empty.\n");
    }
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main()
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
        printf("\n 10: Delete the entire list");
        printf("\n 11: Sort the list");
        printf("\n 12: Search an element in the list");
        printf("\n 13: Count no. of nodes");
        printf("\n 14: Reverse the list");
        printf("\n 15: EXIT");
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
            Head = delete_list(Head);
            printf("\n LINKED LIST DELETED");
            break;
        case 11:
            Head = sort_list(Head);
            break;
        case 12:
            Head = search(Head);
            break;
        case 13:
            printf("\n No. of nodes in the list = %d", count(Head));
            break;
        case 14:
            Head = reverse(Head);
        }
    } while (option != 15);
    return 0;
}
