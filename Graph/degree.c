#include <stdio.h>
void degree(int mat[10][10],int n)
{
        int i,j,indegree,outdegree;
        for ( i = 0; i < n; i++)
        {
            indegree=0;
            outdegree=0;
            for ( j = 0; j < n; j++)
            {
                if (mat[j][i]==1)
                {
                    indegree++;
                }
                if (mat[i][j]==1)
                {
                    outdegree++;
                }
                
            }
            printf("%d vertex have indegree %d   outdegree %d \n",i+1,indegree,outdegree);
        }
}
void matrix(int mat[10][10], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            mat[i][j] = 0;
            if (i != j)
            {
                printf("if there is a edge between %d -> %d (1/0)", i + 1, j + 1);
                scanf("%d", &mat[i][j]);
            }
        }
    }
}
void displaymat(int mat[10][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int mat[10][10], n;
    printf("enter a number of vertices\n");
    scanf("%d", &n);
    matrix(mat,n);
    displaymat(mat,n);
    degree(mat,n);
    return 0;
}
