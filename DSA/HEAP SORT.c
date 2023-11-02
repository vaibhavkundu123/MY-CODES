#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right, *parent;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

void insertNode(struct Node** root, int value) {
    struct Node* newNode = createNode(value);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct Node* temp = *root;
    while (temp->left && temp->right) {
        temp = temp->left;
    }

    if (temp->left == NULL)
        temp->left = newNode;
    else
        temp->right = newNode;

    newNode->parent = temp;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct Node* root) {
    if (!root) return;

    struct Node *smallest = root;
    struct Node *left = root->left;
    struct Node *right = root->right;

    if (left != NULL && left->data < smallest->data)
        smallest = left;

    if (right != NULL && right->data < smallest->data)
        smallest = right;

    if (smallest != root) {
        swap(&root->data, &smallest->data);
        minHeapify(smallest);
    }
}

void maxHeapify(struct Node* root) {
    if (!root) return;

    struct Node *largest = root;
    struct Node *left = root->left;
    struct Node *right = root->right;

    if (left != NULL && left->data > largest->data)
        largest = left;

    if (right != NULL && right->data > largest->data)
        largest = right;

    if (largest != root) {
        swap(&root->data, &largest->data);
        maxHeapify(largest);
    }
}

void buildMinHeap(struct Node* root) {
    if (!root) return;

    if (root->left)
        buildMinHeap(root->left);

    if (root->right)
        buildMinHeap(root->right);

    minHeapify(root);
}

void buildMaxHeap(struct Node* root) {
    if (!root) return;

    if (root->left)
        buildMaxHeap(root->left);

    if (root->right)
        buildMaxHeap(root->right);

    maxHeapify(root);
}

void heapSort(struct Node* root, int order, int n) {
    if (root == NULL) return;

    if (order == 0) {
        buildMinHeap(root);
        printf("\nAscending Order (Min-Heap Sort): ");
        while (n != 0) {
            printf("%d ", root->data);
            swap(&root->data, &(root->parent->data));
            root = root->parent;
            minHeapify(root);
            n--;
        }
    } else {
        buildMaxHeap(root);
        printf("\nDescending Order (Max-Heap Sort): ");
        while (n != 0) {
            printf("%d \t", root->data);
            swap(&root->data, &(root->parent->data));
            root = root->parent;
            maxHeapify(root);
            n--;
        }
    }
}

int main() {
    struct Node* root = NULL;
    int n, data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertNode(&root, data);
    }

    int order;
    printf("Enter sorting order (0 for Ascending, 1 for Descending): ");
    scanf("%d", &order);

    printf("\nOriginal Tree: ");
    printf("\nTree built using Doubly Linked List:\n");
    heapSort(root, order, n);

    printf("\n");

    return 0;
}
