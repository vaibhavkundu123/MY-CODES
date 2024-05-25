#include <stdio.h>

// BUBBLE SORT FUNCTION
int BubbleSort(int array[], int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// INSERTION SORT FUNCTION
int InsertionSort(int array[], int size)
{
    int i, j, temp;
    for (i = 1; i < size; i++)
    {
        temp = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

// SELECTION SORT FUNCTION
int SelectionSort(int array[], int size)
{
    int i, j, temp, min;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

// MERGE SORT FUNCTION
void merge(int arr[], int beg, int mid, int end)
{
    int i = beg, j = mid + 1, index = beg, temp[100], k;
    while ((i <= mid) && (j <= end))
    {
        if (arr[i] < arr[j])
        {
            temp[index] = arr[i];
            i++;
        }
        else
        {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }
    if (i > mid)
    {
        while (j <= end)
        {
            temp[index] = arr[j];
            j++;
            index++;
        }
    }
    else
    {
        while (i <= mid)
        {
            temp[index] = arr[i];
            i++;
            index++;
        }
    }
    for (k = beg; k < index; k++)
        arr[k] = temp[k];
}
void MergeSort(int arr[], int beg, int end)
{
    int mid;
    if (beg < end)
    {
        mid = (beg + end) / 2;
        MergeSort(arr, beg, mid);
        MergeSort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

// QUICK SORT FUNCTION
int partition(int arr[], int beg, int end)
{
    int left, right, temp, loc, flag;
    loc = left = beg;
    right = end;
    flag = 0;
    while (flag != 1)
    {
        while ((arr[loc] <= arr[right]) && (loc != right))
            right--;
        if (loc == right)
            flag = 1;
        else if (arr[loc] > arr[right])
        {
            temp = arr[loc];
            arr[loc] = arr[right];
            arr[right] = temp;
            loc = right;
        }
        if (flag != 1)
        {
            while ((arr[loc] >= arr[left]) && (loc != left))
                left++;
            if (loc == left)
                flag = 1;
            else if (arr[loc] < arr[left])
            {
                temp = arr[loc];
                arr[loc] = arr[left];
                arr[left] = temp;
                loc = left;
            }
        }
    }
    return loc;
}
void QuickSort(int arr[], int beg, int end)
{
    int loc;
    if (beg < end)
    {
        loc = partition(arr, beg, end);
        QuickSort(arr, beg, loc - 1);
        QuickSort(arr, loc + 1, end);
    }
}

// DISPLAY FUNCTION
int Display(int array[], int size)
{
    int i;
    printf("Sorted array is: \n");
    for (i = 0; i < size; i++)
    {
        printf("%d \n", array[i]);
    }
}

int main()
{
    int array[100], size, i, choice;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array: \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Enter 1 for Bubble Sort \n");
    printf("Enter 2 for Insertion Sort \n");
    printf("Enter 3 for Selection Sort \n");
    printf("Enter 4 for Merge Sort \n");
    printf("Enter 5 for Quick Sort \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        BubbleSort(array, size);
        Display(array, size);
        break;
    case 2:
        InsertionSort(array, size);
        Display(array, size);
        break;
    case 3:
        SelectionSort(array, size);
        Display(array, size);
        break;
    case 4:
        MergeSort(array, 0, size - 1);
        Display(array, size);
        break;
    case 5:
        QuickSort(array, 0, size - 1);
        Display(array, size);
        break;
    default:
        printf("Invalid choice \n");
    }
    return 0;
}
