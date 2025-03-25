// toposort
#include <stdio.h>
int indegree[10] = {0};
int indegreee(int ajmat[10][10], int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (ajmat[i][j] == 1)
            {
                indegree[i]++;
            }
        }
    }

    return 0;
}
int toposort(int mat[10][10], int n)
{
    int visited[10] = {0};
    indegreee(mat, n);
    while (1)
    {
        int found = 0;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0 && indegree[i] != 1)
            {
                visited[i] = 1;
                found++;
                printf("%d\n", i);
                for (int j = 1; j <= n; j++)
                {
                    if (mat[i][j] == 1)
                    {
                        indegree[i]--;
                    }
                }
            }
        }
        if (found == 0)
        {
            break;
        }
    }

    return 0;
}
int main()
{
    int n, i, j;
    printf("enter a how many number of vertice are there\n");
    scanf("%d", &n);
    int ajmat[10][10];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            ajmat[i][j] = 0;
            if (i != j)
            {
                printf("there is edge between %d --> %d\n", i, j);
                scanf("%d", &ajmat[i][j]);
            }
        }
    }
    printf("adjacency mat is:=\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d\t", ajmat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    toposort(ajmat, n);

    return 0;
}
