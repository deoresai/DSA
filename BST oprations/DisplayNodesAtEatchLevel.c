/*Write a C program which uses Binary search tree library and displays nodes at each level, 
count of node at each level and total levels in the tree. */
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *create(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        return create(data);
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}
int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        if (leftheight > rightheight)
        {
            return leftheight + 1;
        }
        else
            return rightheight + 1;
    }
}
int printlevelnodes(struct node *root, int level)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (level == 1)
    {
        printf(" %d ", root->data);
    }
    else
    {
        printlevelnodes(root->left, level - 1);
        printlevelnodes(root->right, level - 1);
    }
}
int totalnodes(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root != NULL)
    {
        return totalnodes(root->left) + totalnodes(root->right) + 1;
    }
}
int countlevelnode(struct node *root, int level)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (level == 1)
        return 1;
    return countlevelnode(root->left, level - 1) + countlevelnode(root->right, level - 1);
}
int main()
{
    struct node *root;
    root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 9);
    root = insert(root, 13);
    root = insert(root, 16);
    int k, i, Totalnodes;
    k = height(root);
    printf("height is : %d", k);
    for (i = 1; i <= k; i++)
    {
        printf("\nlevel %d:", i);
        printlevelnodes(root, i);
        printf("\nTotal nodes at level '%d'are %d", i, countlevelnode(root, i));
    }
    Totalnodes = totalnodes(root);
    printf("\nall nodes are %d:\n", Totalnodes);
    return 0;
}
