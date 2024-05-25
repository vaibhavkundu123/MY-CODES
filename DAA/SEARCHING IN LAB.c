#include<stdio.h>
int arr[50];

int linear_search(int n, int key) {
	int i;
	for(i = 0;i < n; i++) {
		if(arr[i] == key) {
			return i;
			//break;
		}
	}
	return -1;
}

int BubbleSort(int size) {
    int i, j, temp;
    for(i = 0; i < size - 1; i++) {
        for(j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; 
            }
        }
    }
    printf("Array after sorting: \n");
    for(i = 0; i < size; i++) {
		printf("Arr[%d]: %d\n", i, arr[i]);
	}
}

int binary_search(int n, int key) {
	
	int low = 0, high = n - 1, mid;
	BubbleSort(n);
	while(low <= high) {
		mid = (low + high)/2;
		if(arr[mid] == key) {
			return mid;
			//break;
		}
		else if(arr[mid] < key) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}

int main() {
	int n, i, key, pos, choice;
	printf("Enter the size of the array: ");
	scanf("%d", &n);

	printf("Enter the elements of the array: \n");
	for(i = 0; i < n; i++) {
		printf("Arr[%d]: ", i);
		scanf("%d", &arr[i]);
	}
	printf("Enter the elements to be searched: ");
	scanf("%d", &key);
	printf("Enter 1 for linear search\nEnter 2 for binary search: \n");
	scanf("%d", &choice);
	
	switch(choice) {
		case 1:
			pos = linear_search(n, key);
			if(pos == -1) {
				printf("Element not found: ");
			}
			else {
				printf("Element found at position %d\n", pos + 1);
			}
			break;
		
		case 2:
			pos = binary_search(n, key);
			if(pos == -1) {
				printf("Element not found: ");
			}
			else {
				printf("Element found at position %d\n", pos + 1);
			}
			break;
			
		default:
			printf("Invalid Choice\n");
	}
	return 0;
}
