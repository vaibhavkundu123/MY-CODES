#include<stdio.h>

// BUBBLE SORT FUNCTION
int BubbleSort(int array[], int size) {
    int i, j, temp;
    for(i = 0; i < size - 1; i++) {
        for(j = 0; j < size - i - 1; j++) {
            if(array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp; 
            }
        }
    }
}

// INSERTION SORT FUNCTION
int InsertionSort(int array[], int size) {
    int i, j, temp;
    for(i = 1; i < size; i++) {
        temp = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > temp) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

// SELECTION SORT FUNCTION
int SelectionSort(int array[], int size) {
    int i, j, temp, min;
    for(i = 0; i < size - 1; i++) {
        min = i;
        for(j = i + 1; j < size; j++) {
            if(array[j] < array[min]) {
                min = j;
            }
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

// MERGE SORT FUNCTION
int Merge(int array[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    
    for(i = 0; i < n1; i++) {
        L[i] = array[l + i];
    }
    for(j = 0; j < n2; j++) {
        R[j] = array[m + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = l;
    
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
    
    while(j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

int MergeSort(int array[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        
        MergeSort(array, l, m);
        MergeSort(array, m + 1, r);
        
        Merge(array, l, m, r);
    }
}

// QUICK SORT FUNCTION
int Partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    int j, temp;
    for(j = low; j <= high - 1; j++) {
        if(array[j] < pivot) {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
}

int QuickSort(int array[], int low, int high) {
    if(low < high) {
        int pi = Partition(array, low, high);
        
        QuickSort(array, low, pi - 1);
        QuickSort(array, pi + 1, high);
    }
}

// DISPLAY FUNCTION
int Display(int array[], int size) {
    int i;
    printf("Sorted array is: \n");
    for(i = 0; i < size; i++) {
        printf("%d \n", array[i]);
    }
}

int main() {
    int array[100], size, i, choice;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array: \n");
    for(i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter 1 for Bubble Sort \n");
    printf("Enter 2 for Insertion Sort \n");
    printf("Enter 3 for Selection Sort \n");
    printf("Enter 4 for Merge Sort \n");
    printf("Enter 5 for Quick Sort \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
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