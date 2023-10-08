#include<stdio.h>
#include<conio.h>
#define MAX 5
int deque[MAX];
int front = -1, rear = -1;

void insert()
{
    int num;
    printf("\n Enter the number to be inserted in the queue : ");
    scanf("%d", &num);
    if(front == 0 && rear == MAX-1)
    {
        printf("\n OVERFLOW");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[rear] = num;
    }
    else if(rear == MAX-1 && front != 0)
    {
        rear = 0;
        deque[rear] = num;
    }
    else
    {
        rear++;
        deque[rear] = num;
    }
}

int delete()
{
    int num;
    if(front == -1 && rear == -1)
    {
        printf("\n UNDERFLOW");
        return -1;
    }
    num = deque[front];
    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        if(front == MAX-1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    return num;
}

int peek()
{
    if(front == -1 && rear == -1)
    {
        printf("\n QUEUE IS EMPTY");
        return -1;
    }
    else
    {
        return deque[front];
    }
}

void display()
{
    int i;
    printf("\n");
    if(front == -1 && rear == -1)
    {
        printf("\n QUEUE IS EMPTY");
    }
    else
    {
        if(front < rear)
        {
            for(i = front; i <= rear; i++)
            {
                printf("\t %d", deque[i]);
            }
        }
        else
        {
            for(i = front; i < MAX; i++)
            {
                printf("\t %d", deque[i]);
            }
            for(i = 0; i <= rear; i++)
            {
                printf("\t %d", deque[i]);
            }
        }
    }
}

int main()
{
    int choice, num;
    do
    {
        printf("\n\n *****MAIN MENU*****");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                num = delete();
                if(num != -1)
                {
                    printf("\n The number deleted is : %d", num);
                }
                break;
            case 3:
                num = peek();
                if(num != -1)
                {
                    printf("\n The first value in queue is : %d", num);
                }
                break;
            case 4:
                display();
                break;
        }
    }while(choice != 5);
    return 0;
}
