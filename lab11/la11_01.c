#include <stdio.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int degree[MAX_VERTICES];

int main()
{
    int numVertices, numEdges;
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            graph[i][j] = 0;
        }
        degree[i] = 0;
    }

    printf("Enter the edges (vertex1 vertex2):\n");
    for (i = 0; i < numEdges; i++)
    {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);

        graph[vertex1][vertex2] = 1;
        graph[vertex2][vertex1] = 1;

        degree[vertex1]++;
        degree[vertex2]++;
    }

    printf("Degree of each vertex:\n");
    for (i = 0; i < numVertices; i++)
    {
        printf("Vertex %d: %d\n", i, degree[i]);
    }

    return 0;
}