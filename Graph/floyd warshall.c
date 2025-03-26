#include <stdio.h>
#include <stdlib.h>

void floyd(int a[10][10], int n)
{
    int d[10][10], i, j, k;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            d[i][j] = a[i][j];
        }
    }

    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (d[i][k] != 999 && d[k][j] != 999 && d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    printf("the shortest distance from each vertex is:\n");
    for (i = 1; i <= n; i++)
    {
        printf("\n");
        for (j = 1; j <= n; j++)
        {
            printf("%d\t", d[i][j]);
        }
    }
}

void main()
{
    int cost[10][10], i, j, n;
    printf("how many elements\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i != j)
            {
                printf("enter cost of %d to %d\n", i, j);
                scanf("%d", &cost[i][j]);

                if (cost[i][j] == 0)
                    cost[i][j] = 999;
            }
            else
                cost[i][j] = 0;
        }
    }

    floyd(cost, n);
}
