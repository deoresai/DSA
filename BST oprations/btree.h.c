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
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}
struct node *search(struct node*root,int data)
{
            if (root==NULL || root->data==data)
            {
                return root;
            }
            if (data<root->data)
            {
               return search(root->left,data);
            }
            else
            {
                return search(root->left,data);
            }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
    if (root!=NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
