#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

#define MAX 100

int minDistance(int dist[], bool visited[], int V)
{
    int min = INT_MAX, min_index = -1;
    int v,i;
    for(v = 0; v < V; v++)
    {
        if(!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX][MAX], int V, int src)
{
	int v,i,count;
    int dist[MAX];
    bool visited[MAX];

    for(i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for(count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited, V);
        visited[u] = true;

        for(v = 0; v < V; v++)
        {
            if(!visited[v] &&
               graph[u][v] != 0 &&
               dist[u] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nVertex \tDistance from Source\n");
    for(i = 0; i < V; i++)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main()
{
    int V, src;
    int graph[MAX][MAX];
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < V; i++)
    {
        for(j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex (0 to %d): ", V-1);
    scanf("%d", &src);

    dijkstra(graph, V, src);

    return 0;
}
