#include <stdio.h>

#define INF 9999

int main()
{
    int n, graph[20][20], dist[20], visited[20];
    int source, i, j, count, min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for (i = 0; i < n; i++)
    {
        dist[i] = graph[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;

    for (count = 0; count < n - 1; count++)
    {
        min = INF;
        u = -1;

        for (i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < n; j++)
        {
            if (!visited[j] && graph[u][j] != INF &&
                dist[u] + graph[u][j] < dist[j])
            {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for (i = 0; i < n; i++)
    {
        printf("Destination %d : %d\n", i, dist[i]);
    }

    return 0;
}
/* Enter number of vertices: 5
Enter weighted adjacency matrix:
0 10 3 0 0
10 0 1 2 0
3 1 0 8 2
0 2 8 0 7
0 0 2 7 0
Enter source vertex: 0

Shortest distances from vertex 0:
Destination 0 : 0
Destination 1 : 4
Destination 2 : 3
Destination 3 : 6
Destination 4 : 5 */