#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
struct node
{
    struct node *next;
    int data;
    struct node *prev;
};

struct node *Head = NULL;
struct node *Tail = NULL;

struct node *create_ll(struct node *Head)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while (num != -1)
    {
        if (Head == NULL)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->prev = NULL;
            new_node->data = num;
            new_node->next = NULL;
            Head = new_node;
        }
        else
        {
            ptr = Head;
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node -> data = num;
            while (ptr -> next != NULL)
                ptr = ptr -> next;
            ptr -> next = new_node;
            Tail = new_node;
            Tail -> prev = ptr;
            Tail -> next = NULL;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return Head;
}

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
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->prev = NULL;
    new_node->next = Head;
    /* 
    Head->prev = new_node;
    Head = new_node; 
    */
    /*
    Head = new_node;
    new_node->next->prev = Head
    */
    return Head;
}

struct node *insert_end(struct node *Head)
{
struct node *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    new_node->prev = Tail;
    /* 
    Tail->next = new_node;
    Tail = new_node; 
     */
    /*
        Tail = new_node;
        new_node->prev->next = Tail;
    */
    return Head;
}

struct node *insert_before(struct node *Head)
{
    struct node *new_node, *ptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted:");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = Head;
    while (ptr->data != val)
        ptr = ptr->next;
    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;
    return Head;
}

struct node *insert_after(struct node *Head)
{
    struct node *new_node, *ptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted:");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = Head;
    while (ptr->data != val)
        ptr = ptr->next;
    new_node->prev = ptr;
    new_node->next = ptr->next;
    ptr->next->prev = new_node;
    ptr->next = new_node;
    return Head;
}

struct node *delete_beg(struct node *Head)
{
    struct node *ptr;
    ptr = Head;
    Head = Head->next;
    Head->prev = NULL;
    free(ptr);
    return Head;
}

struct node *delete_end(struct node *Head)
{
    struct node *ptr;
    ptr = Head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->prev->next = NULL;
    free(ptr);
    return Head;
}

struct node *delete_after(struct node *Head)
{
    struct node *ptr, *temp;
    int val;
    printf("\n Enter the value after which the node has to deleted : ");
    scanf("%d", &val);
    ptr = Head;
    while (ptr->data != val)
        ptr = ptr->next;
    temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);
    return Head;
}

struct node *delete_before(struct node *Head)
{
    struct node *ptr, *temp;
    int val;
    printf("\n Enter the value before which the node has to deleted:");
    scanf("%d", &val);
    ptr = Head;
    while (ptr->data != val)
        ptr = ptr->next;
    temp = ptr->prev;
    if (temp == Head)
        Head = delete_beg(Head);
    else
    {
        ptr->prev = temp->prev;
        temp->prev->next = ptr;
    }
    free(temp);
    return Head;
}

struct node *delete_list(struct node *Head)
{
    while (Head != NULL)
        Head = delete_beg(Head);
    return Head;
}



int main()
{
    int option;
    clrscr();
    do
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a node before a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: Delete the entire list");
        printf("\n 12: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            Head = create_ll(Head);
            printf("\n DOUBLY LINKED LIST CREATED");
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
            Head = delete_before(Head);
            break;
        case 10:
            Head = delete_after(Head);
            break;
        case 11:
            Head = delete_list(Head);
            printf("\n DOUBLY LINKED LIST DELETED");
            break;
        }
    } while (option != 12);
    return 0;
}