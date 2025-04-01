#include <stdio.h>
#include <stdlib.h>
void dij(int cost[10][10], int n)
{
    int min, i, j, count = 1, u, visited[10] = {0}, v = 1;
    visited[v] = 1;
    int d[10];
    for (i = 1; i <= n; i++)
        d[i] = cost[v][i];

    while (count < n)
    {
        min = 999;
        u = -1;
        for (i = 1; i <= n; i++)
        {
            if (visited[i] != 1 && d[i] < min)
            {
                min = d[i];
                u = i;
            }
        }
        if (u == -1)
            break;  
        visited[u] = 1;
        count++;

        for (j = 1; j <= n; j++)
        {
            if (visited[j] != 1 && d[j] > d[u] + cost[u][j])
                d[j] = d[u] + cost[u][j];
        }   
    }

    for (i = 1; i <= n; i++)
    {
        printf("distance form %d to %d is:%d\n", v, i, d[i]);
    }
}

void main()
{
    int n, i, j, cost[10][10];
    printf("how many nodes:\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i != j)
            {
                printf("the cost of %d--->%d edge\n", i, j);
                scanf("%d", &cost[i][j]);

                if (cost[i][j] == 0)
                    cost[i][j] = 999;
            }
            else
                cost[i][j] = 0;
        }
    }
    dij(cost, n);
}
