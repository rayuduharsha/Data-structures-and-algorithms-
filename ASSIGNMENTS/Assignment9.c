#include <stdio.h>

int graph[100][100];
int visited[100];
int n;

void DFS(int vertex)
{
    int i;

    visited[vertex] = 1;
    printf("%d ", vertex);

    for (i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS traversal: ");
    DFS(start);

    printf("\n");

    return 0;
}

/* Enter number of vertices: 5
Enter adjacency matrix:
0 1 1 0 0
1 0 1 1 0
1 1 0 0 1
0 1 0 0 1
0 0 1 1 0
Enter starting vertex: 0
DFS traversal: 0 1 2 4 3

Enter number of vertices: 5
Enter adjacency matrix:
0 1 1 0 0
1 0 1 0 0
1 1 0 0 0
0 0 0 0 0
0 0 0 0 0
Enter starting vertex: 0
DFS traversal: 0 1 2   */