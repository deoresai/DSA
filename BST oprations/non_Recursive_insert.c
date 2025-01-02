// NON recursive function for insert node in BST
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *left,*right;
};

struct node *insert(struct node *root,int data)
{
        struct node *temp,*newnode;
        temp=root;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->left=newnode->right=NULL;
        if (root==NULL)
        {
            root=newnode;
        }
        else
        {
            while(temp)
            {
                if (data<temp->data)
                {
                    if (temp->left==NULL)
                    {
                        temp->left=newnode;
                        break;
                    }
                    else
                    temp=temp->left;    
                }
                else if (data>temp->data)
                {
                    if (temp->right==NULL)
                    {
                        temp->right=newnode;
                        break;
                    }
                    else
                    temp=temp->right;   
                }
            }
            return root;
        }
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
    root=NULL;
    root=insert(root,10);
    root=insert(root,9);
    root=insert(root,15);
    root=insert(root,13);
    root=insert(root,5);
    inorder(root);
    int k;
    k=height(root);
    printf("height is : %d",k);
    return 0;
}
