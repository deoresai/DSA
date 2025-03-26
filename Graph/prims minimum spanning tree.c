#include <stdio.h>
void prims(int ajmat[10][10], int n)
{
    int i, j, ne = 0, visited[10] = {0}, min, mincost = 0, u, v;
    visited[0] = 1;

    while (ne < n-1)
    {
        min = 999;
        u = -1;
        v = -1;

        for (i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (j = 0; j < n; j++) 
                {                              
                    if (!visited[j] && ajmat[i][j] < min)
                    {
                        min = ajmat[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1)
        {
            printf("\nEdge %d : (%d -> %d) Cost = %d", ne + 1, u, v, min);
            mincost += min;
            visited[v] = 1;
            ne++;

            ajmat[u][v] = ajmat[v][u] = 999;
        }
    }

    printf("\nMinimum cost = %d\n", mincost);
}

int main()
{
    int i, j, n, ajmat[10][10];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                printf("Enter the cost of edge (%d -> %d): ", i, j);
                scanf("%d", &ajmat[i][j]);
                if (ajmat[i][j] == 0)
                {
                    ajmat[i][j] = 999;
                }
            }
            else
            {
                ajmat[i][j] = 999;
            }
        }
    }

    prims(ajmat, n);
    return 0;
}
