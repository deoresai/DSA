//      counting leaf nodes from BST
/*Write a program which counts the total nodes and total 
leaf nodes in the tree. 
int count(T) – returns the total number of nodes from BST 
int countLeaf(T) – returns the total number of leaf nodes from BST
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
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}
int countleaf(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return countleaf(root->left) + countleaf(root->right);
}
int countallnode(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + countallnode(root->left) + countallnode(root->right);
}
int main()
{
    struct node *root;
    root = NULL;
    root = insert(root, 10);
    root = insert(root, 9);
    root = insert(root, 20);
    inorder(root);
    int k, r;
    k = countleaf(root);
    printf("\nTotal leaf nodes are: %d", k);
    r = countallnode(root);
    printf("\nTotal nodes are: %d", r);
    return 0;
}
