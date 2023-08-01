#include<stdio.h>
#include<stdlib.h>

int arr[50], n;

int InsertElement(int position, int value) {
    int i;
    for(i = n - 1; i >= position - 1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position - 1] = value;
    n++;
    printf("Element %d inserted at position %d \n", value, position);
}

int DeleteElement(int position) {
    int i;
    for(i = position - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("Element deleted from position %d \n", position);
}

int DisplayElement () {
    int i;
    for(i = 0; i < n; i++) {
        printf("Array[%d] = %d \n", i, arr[i]);
    }
    printf("\n");
}

int main() {
    int i, choice, position, value;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("\n");
    printf("Enter the elements of the array: \n");
    for(i = 0; i < n; i++) {
        printf("Array[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    while(1) {
        printf("\n");
        printf("Enter 1 to insert an element in the array \n");
        printf("Enter 2 to delete an element from the array \n");
        printf("Enter 3 to display the elements of the array \n");
        printf("Enter 4 to exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice) {
            case 1:
                printf("Enter the position where you want to insert an element: ");
                scanf("%d", &position);
                printf("Enter the value you want to insert: ");
                scanf("%d", &value);
                InsertElement(position, value);
                break;
            case 2:
                printf("Enter the position where you want to delete an element: ");
                scanf("%d", &position);
                DeleteElement(position);
                break;
            case 3:
                DisplayElement();
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