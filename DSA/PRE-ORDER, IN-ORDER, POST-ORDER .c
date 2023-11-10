#include <stdio.h>
#include <stdlib.h>

struct btreenode {
    struct btreenode *leftchild;
    int data;
    struct btreenode *rightchild;
};

void insert(struct btreenode **sr, int num)
{
    if (*sr == NULL)
    {
        *sr = malloc(sizeof(struct btreenode));
        (*sr)->leftchild = NULL;
        (*sr)->data = num;
        (*sr)->rightchild = NULL;
    }
    else
    {
        if (num < (*sr)->data)
            insert(&((*sr)->leftchild), num);
        else
            insert(&((*sr)->rightchild), num);
    }
    return;
}

void preorder(struct btreenode *sr)
{
    if (sr != NULL)
    {
        printf("%d ", sr->data);
        preorder(sr->leftchild);
        preorder(sr->rightchild);
    }
    return;
}

void inorder(struct btreenode *sr)
{
    if (sr != NULL)
    {
        inorder(sr->leftchild);
        printf("%d ", sr->data);
        inorder(sr->rightchild);
    }
    return;
}

void postorder(struct btreenode *sr)
{
    if (sr != NULL)
    {
        postorder(sr->leftchild);
        postorder(sr->rightchild);
        printf("%d ", sr->data);
    }
    return;
}

int main()
{
    struct btreenode *bt;
    int req, i = 1, num;
    bt = NULL;
    printf("Enter the number of elements: ");
    scanf("%d", &req);
    while (i++ <= req)
    {
        printf("Enter the data: ");
        scanf("%d", &num);
        insert(&bt, num);
    }
    printf("Preorder traversal: ");
    preorder(bt);
    printf("\nInorder traversal: ");
    inorder(bt);
    printf("\nPostorder traversal: ");
    postorder(bt);
    return 0;
}