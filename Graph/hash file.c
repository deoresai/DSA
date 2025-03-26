// hash table
#include <stdio.h>
#include <stdlib.h>
int hf(int key)
{
    return (key % 10);
}
void insert(int HT[10], int key)
{
    int index = hf(key);
    int original = index;

    if (HT[index] == -1)
    {
        HT[index] = key;
    }
    else
    {
        while (HT[index] != -1)
        {
            index = (index + 1);
            if (index == original)
            {
                printf("hash table is full\n");
                return;
            }
        }
        HT[index] = key;
    }
}
void delete(int HT[10], int key)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (HT[i] == key)
        {
            HT[i] = -1;
            printf("key is deleted\n");
            return;
        }
    }
    printf("key not found\n");
}
void search(int HT[10], int key)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (key == HT[i])
        {
            printf("key found in Hash table position\n");
            return;
        }
    }
    printf("key not found\n");
}
void show(int HT[10])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (HT[i] == -1)
        {
            printf("_\t");
        }
        else
            printf("%d\t", HT[i]);
    }
}
int main()
{
    int i, HT[10], key, choice;
    for (i = 0; i < 10; i++)
    {
        HT[i] = -1;
    }

    do
    {
        printf("\n1: insert\n");
        printf("2: for show\n");
        printf("3: delete\n");
        printf("4: search\n");
        printf("5: for exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter a element you want to enter(by linear probing)\n");
            scanf("%d", &key);
            insert(HT, key);
            break;
        case 2:
            printf("All elements are\n");
            show(HT);
            break;
        case 3:
            printf("enter a key you want to delete\n");
            scanf("%d", &key);
            delete (HT, key);
            break;
        case 4:
            printf("enter a key you  want to found\n");
            scanf("%d", &key);
            search(HT, key);
            break;
        case 5:
            exit(0);
        default:
            break;
        }

    } while (1);

    return 0;
}
