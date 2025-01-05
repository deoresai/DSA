// mirror of BST usinf Typedef structure
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left,*right;
} BSTNODE;
BSTNODE *insert(BSTNODE *root,int key)
{
        if (root==NULL)
        {
            root=(BSTNODE*)malloc(sizeof(BSTNODE));
            root->left=root->right=NULL;
            root->data=key;  
            return root;
        }
        else if(key<root->data)
        {
            root->left=insert(root->left,key);
        }
        else
            root->right=insert(root->right,key);
}

void inorder(BSTNODE *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}
int mirror(BSTNODE *root)
{
        BSTNODE *temp;
        if (root==NULL)
        {
            return 0;
        }
        else
            temp=root->left;
            root->left=root->right;
            root->right=temp;

            mirror(root->left);
            mirror(root->right);
        return root;
}
int main()
{
        BSTNODE *root;
        root=NULL;
        root=insert(root,10);
        root=insert(root,9);
        root=insert(root,11);
        inorder(root);
        root=mirror(root);
        printf("\n");
        inorder(root);
    return 0;
}
