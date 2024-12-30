//  copying BST1 into BST2 and compair
/*Write a C program which uses Binary search tree library and implements following function 
with recursion: 
T copy(T) – create another BST which is exact copy of BST which is passed as parameter.   
int compare(T1, T2) – compares two binary search trees and returns 1 if they are equal and 0 
otherwise.
*/
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
    if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}
struct node *copy(struct node *root)
{
    struct node *newroot;
    if (root == NULL)
    {
        return NULL;
    }
    newroot = create(root->data);
    newroot->left = copy(root->left);
    newroot->right = copy(root->right);
    return newroot;
}
int compair(struct node *root1, struct node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return 0;
    }
    return compair(root1->left, root2->left) && compair(root1->right, root2->right);
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}
int main()
{
    struct node *root, *root2;
    int k;
    root = NULL;
    root = insert(root, 10);
    root = insert(root, 9);
    root = insert(root, 20);
    inorder(root);
    root2 = copy(root);
    printf("\n");
    inorder(root2);
    k = compair(root, root2);
    if (k == 1)
    {
        printf("\nbooth are same\n");
    }
    else
        printf("\nbooth are not same\n");
    return 0;
}
