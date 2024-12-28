            // BINARY TREE IMPLIMENTATION
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
struct node *preorder(struct node *root)
{
            if (root==0)
            {
                return 0;
            }
            printf("%d\t",root->data);
            preorder(root->left);
            preorder(root->right);
}
struct node *create()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("enter a data(-1 if no data)\n");
    scanf("%d",&x);
    if (x==-1)
    {
        return 0;
    }
    newnode->data=x;
    printf("for left child of %d\n",x);
    newnode->left=create();
    printf("for right child of %d\n",x);
    newnode->right=create();
    return newnode;
}
int main()
{
    struct node *root;
    root=0;
    root=create();
    preorder(root);
    return 0;
}
