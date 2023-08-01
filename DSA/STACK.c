#include<stdio.h>
#include<stdlib.h>
#define Max_Size 100

int stack[Max_Size];
int top = -1;

int Push(int value) {
    if(top == Max_Size - 1) {
        printf("Stack Overflow \n");
    }
    else {
        top++;
        stack[top] = value;
        printf("Element %d pushed into the stack \n", value);
    }
}

int Pop() {
    if(top == -1) {
        printf("Stack Underflow \n");
    }
    else {
        printf("Element %d popped from the stack \n", stack[top]);
        top--;
    }
}

int Display() {
    int i;
    if(top == -1) {
        printf("Stack is empty \n");
    }
    else {
        printf("Elements of the stack are: \n");
        for(i = top; i >= 0; i--) {
            printf("%d \n", stack[i]);
        }
    }
}

int main() {
    int choice, value;
    while(1) {
        printf("\n");
        printf("Enter 1 to push an element into the stack \n");
        printf("Enter 2 to pop an element from the stack \n");
        printf("Enter 3 to display the elements of the stack \n");
        printf("Enter 4 to exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice) {
            case 1:
                printf("Enter the value you want to push: ");
                scanf("%d", &value);
                Push(value);
                break;
            case 2:
                Pop();
                break;
            case 3:
                Display();
                break;
            case 4:
                printf("Exit...........");
                exit(0);
                break;
            default:
                printf("Invalid choice \n");
        }
    }
    return 0;
}