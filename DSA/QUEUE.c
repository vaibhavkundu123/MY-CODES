#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int queue[MAX];
int front = -1, rear = -1;

void insert()
{
    int num;
    printf("\n Enter the number to be inserted in the queue : ");
    scanf("%d", &num);
    if (rear == MAX - 1)
    {
        printf("\n OVERFLOW");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = num;
        printf("\n The inserted element inside the queue is : %d \n", num);
    }
    else
    {
        rear++;
        queue[rear] = num;
        printf("\n The inserted element inside the queue is : %d \n", num);
    }
}

void delete()
{
    int val;
    if (front == -1 || front > rear)
    {
        printf("\n UNDERFLOW");
    }
    else
    {
        val = queue[front];
        front++;
        printf("\n The deleted element from the queue is : %d \n", val);
    }
}

void display()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("\n QUEUE IS EMPTY");
    }
    else
    {
        printf("\n The elements in the queue are : \n");
        for (i = front; i <= rear; i++)
        {
            printf("%d \n", queue[i]);
        }
    }
    printf("\n");
}

int main()
{
    int ch;
    do
    {
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. DISPLAY");
        printf("\n 4. EXIT");
        printf("\n");
        printf("\n Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\n INVALID CHOICE");
        }
    } while (ch != 4);
    return 0;
}
