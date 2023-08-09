#include<stdio.h>

// LINEAR SEARCH FUNCTION
int linear_search(int arr[], int n, int key)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

// BINARY SEARCH FUNCTION
int binary_search(int arr[], int n, int key)
{
    int low = 0, high = n-1, mid;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] < key)
        {
            low = mid + 1;
        }
        else if(arr[mid] > key)
        {
            high = mid - 1;
        }
    }
    return -1;
}

// INTERPOLATION SEARCH ALGORITHM
int interpolation_search(int arr[], int n, int key)
{
    int low = 0, high = n-1, mid;
    while(low <= high)
    {
        mid = low + (((key - arr[low]) * (high - low)) / (arr[high] - arr[low]));
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] < key)
        {
            low = mid + 1;
        }
        else if(arr[mid] > key)
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, i, key, pos;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    printf("Enter 1 for Linear Search\nEnter 2 for Binary Search\nEnter 3 for Interpolation Search\n");
    int choice;
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            pos = linear_search(arr, n, key);
            if(pos == -1)
            {
                printf("Element not found\n");
            }
            else
            {
                printf("Element found at position %d\n", pos+1);
            }
            break;
        case 2:
            pos = binary_search(arr, n, key);
            if(pos == -1)
            {
                printf("Element not found\n");
            }
            else
            {
                printf("Element found at position %d\n", pos+1);
            }
            break;
        case 3:
            pos = interpolation_search(arr, n, key);
            if(pos == -1)
            {
                printf("Element not found\n");
            }
            else
            {
                printf("Element found at position %d\n", pos+1);
            }
            break;
        default:
            printf("Invalid Choice\n");
    }
    return 0;
}