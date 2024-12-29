#include <stdio.h>
#include "btree.h"

int main()
{

    struct node *root, *flag;
    root = NULL;
    int choice, k;
    do
    {
        printf("1: INSERT\n");
        printf("2: SEARCH\n");
        printf("3: INORDER\n");
        printf("4: PREORDER\n");
        printf("5: POSTORDER\n");
        printf("6: EXIT\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a data to insert\n");
            scanf("%d", &k);
            root = insert(root, k);
            break;
        case 2:
            printf("Enter a data to search\n");
            scanf("%d", &k);
            flag = search(root, k);
            if (flag == NULL)
            {
                printf("Data not found\n");
            }
            else
                printf("Data has founded\n");
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            exit(0);
        default:
            printf("invalid input\n");
        }
    } while (choice != 6);
    return 0;
}
