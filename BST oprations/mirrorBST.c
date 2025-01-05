//mirror elements of same tree (doing all oprations on same tree)
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
    else if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}
struct node *mirror(struct node *root)
{
       struct node *temp;
       if (root==NULL)
       {
            return 0;
       }
       else
            temp=root->right;
            root->right=root->left;
            root->left=temp;

            mirror(root->left);
            mirror(root->right);
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
int main()
{
    struct node *root;
    int k;
    root = NULL;
    root = insert(root, 10);
    root = insert(root, 9);
    root = insert(root, 20);
    inorder(root);
    root=mirror(root);
    printf("\n");
    inorder(root);
    return 0;
}
