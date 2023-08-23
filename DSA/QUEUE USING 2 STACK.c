#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void push(int stack[], int *top, int element) {
    if (*top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    *top = *top + 1;
    stack[*top] = element;
}

int pop(int stack[], int *top) {
    if (*top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    int element = stack[*top];
    *top = *top - 1;
    return element;
}

int main() {
    int stack1[MAX_SIZE];
    int stack2[MAX_SIZE];
    int top1 = -1;
    int top2 = -1; 

    int n, element;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements for stack1:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        push(stack1, &top1, element);
    }

    int i;
    printf("Elements in stack1 are : \n");
    for(i = top1; i >= 0; i--) {
            printf("%d \n", stack1[i]);
        }

    printf("Moving elements from stack1 to stack2...\n");
    while (top1 >= 0) {
        element = pop(stack1, &top1);
        push(stack2, &top2, element);
    }

    printf("Queue formation is complete. Elements in stack2 (as a queue):\n");
    while (top2 >= 0) {
        element = pop(stack2, &top2);
        printf("%d \n", element);
    }
    printf("\n");

    return 0;
}