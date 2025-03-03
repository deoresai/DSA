#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int ver;
    struct node *next;

} NODE;
void caldegree(NODE *adjlist[10], int vertex)
{
    int indegree[10] = {0};
    int outdegree[10] = {0};
    int totaldegree[10] = {0};
    int i;
    NODE *temp;
    for (i = 1; i <= vertex; i++)
    {
        temp = adjlist[i];
        while (temp)
        {
            outdegree[i]++;
            indegree[temp->ver]++;
            temp = temp->next;
        }
    }
    for (i = 1; i < vertex; i++)
    {
        totaldegree[i] = indegree[i] + outdegree[i];
    }
    printf("vertexes\tindegree's\toutdegres's\ttotaldegree\n");
    for (i = 1; i < vertex; i++)
    {
        printf("VERTEX:%d\t", i);
        printf("%d\t\t", indegree[i]);
        printf("%d\t\t", outdegree[i]);
        printf("%d\n", totaldegree[i]);
    }
}
NODE *create(int ver)
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->ver = ver;
    newnode->next = NULL;
    return newnode;
}
int main()
{
    int vertex, edges, i, sor, dest;
    printf("how many number of vertex there?\n");
    scanf("%d", &vertex);
    NODE *adjlist[vertex];
    for (i = 1; i <= vertex; i++)
    {
        adjlist[i] = NULL;
    }
    printf("How many number of edges?\n");
    scanf("%d", &edges);
    for (i = 1; i <= vertex; i++)
    {
        printf("enter edge's source and destination\n");
        scanf("%d%d", &sor, &dest);
        NODE *newnode = create(dest);
        newnode->next = adjlist[sor];
        adjlist[sor] = newnode;
    }
    caldegree(adjlist, vertex);

    return 0;
}
