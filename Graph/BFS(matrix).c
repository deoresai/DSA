// BFS
#include <stdio.h>
void bfs(int a[10][10], int n)
{
    int queue[10], front = -1, rare = -1, node;
    int visited[10] = {0};
    printf("enter a vertice to start\n");
    scanf("%d", &node);
    printf("%d\t", node);
    visited[node] = 1;
    queue[++rare] = node;
    while (front < rare)
    {
        node = queue[++front];
        for (int i = 1; i <= n; i++)
        {
            if (a[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rare] = i;
                printf("%d\t", i);
            }
        }
    }
}
int main()
{
    int i, j, a[10][10], n;
    printf("how many vertices are there\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            a[i][j] = 0;
            if (i != j)
            {
                printf("is edge is between %d and %d(0/1)\n", i, j);
                scanf("%d", &a[i][j]);
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        printf("\n");
        for (j = 1; j <= n; j++)
        {
            printf("%d\t", a[i][j]);
        }
    }
    bfs(a, n);
    return 0;
}
