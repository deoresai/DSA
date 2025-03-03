// DFS
#include <stdio.h>
void dfs(int node, int a[10][10], int n, int visited[10])
{
    printf("%d\t", node);
    visited[node] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[node][i] == 1 && visited[i] == 0)
        {
            visited[i] = 1;
            dfs(i, a, n, visited);
        }
    }
}
int main()
{
    int i, j, a[10][10], n, node;
    printf("how many vertices are there\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            a[i][j] = 0;
            if (i != j)
            {
                printf("enter edge between %d -> %d (0\1)\n", i, j);
                scanf("%d", &a[i][j]);
            }
        }
    }
    printf("where to start\n");
    scanf("%d", &node);
    int visited[10] = {0};
    dfs(node,a,n,visited);
    return 0;
}
