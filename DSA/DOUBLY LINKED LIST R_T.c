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
    Head = new_node;
    new_node->next->prev = Head;
    /*
    Head->prev = new_node;
    Head = new_node;
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
    Tail = new_node;
    new_node->prev->next = Tail;
    /*
    Tail->next = new_node;
    Tail = new_node;
    */
    return Head;
}

struct node *insert_before(struct node *Head)
{
    struct node *new_node, *ptr;
    int num, pos, i = 0;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the position before which the data has to be inserted:");
    scanf("%d", &pos);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = Head;
    while (i != pos - 1)
    {
        ptr = ptr->next;
        i++;
    }
    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;
    return Head;
}

struct node *insert_after(struct node *Head)
{
    struct node *new_node, *ptr;
    int num, pos, i = 0;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the position after which the data has to be inserted:");
    scanf("%d", &pos);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = Head;
    while(i != pos - 1)
    {
        ptr = ptr->next;
        i++;
    }
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
    ptr = Tail;
    Tail = ptr->prev;
    Tail->next = NULL;
    free(ptr);
    return Head;
}

struct node *delete_node(struct node *Head)
{
    struct node *ptr;
    int pos, i = 0;
    printf("\n Enter the position of the node which has to deleted : ");
    scanf("%d", &pos);
    ptr = Head;
    while(i != pos - 1)
    {
        ptr = ptr->next;
        i++;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    return Head;
}

struct node *delete_list(struct node *Head)
{
    while (Head != NULL)
        Head = delete_beg(Head);
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

int count(struct node *Head) {
    struct node *current;
    int count = 0;
    current = Head;
    while (current != NULL) {
        current = current->next;
        count++;
    }
    return count;
}

struct node *reverse(struct node *Head) {
    struct node *current = Head;
    struct node *temp = NULL;
    if (Head == NULL) {
        printf("List is empty.\n");
    }
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        Head = temp->prev;
    }
    return Head;
}

int main()
{
    int option;
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
        printf("\n 9: Delete a given node");
        printf("\n 10: Delete the entire list");
        printf("\n 11: Sort the list");
        printf("\n 12: Search an element in the list");
        printf("\n 13: Count no. of nodes");
        printf("\n 14: Reverse the list");
        printf("\n 15: EXIT");
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
            Head = delete_node(Head);
            break;
        case 10:
            Head = delete_list(Head);
            printf("\n DOUBLY LINKED LIST DELETED");
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