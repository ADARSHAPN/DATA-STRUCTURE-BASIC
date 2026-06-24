#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int vertices;

// Queue operations for BFS
void enqueue(int value)
{
    queue[++rear] = value;
}

int dequeue()
{
    return queue[++front];
}

// BFS Traversal
void BFS(int start)
{
    int i;

    printf("BFS Traversal: ");

    visited[start] = 1;
    enqueue(start);

    while(front != rear)
    {
        int node = dequeue();

        printf("%d ", node);

        for(i = 0; i < vertices; i++)
        {
            if(graph[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

// DFS Traversal
void DFS(int start)
{
    int i;

    printf("%d ", start);

    visited[start] = 1;

    for(i = 0; i < vertices; i++)
    {
        if(graph[start][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int edges;
    int i, src, dest;
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    // Initialize graph
    for(i = 0; i < vertices; i++)
    {
        visited[i] = 0;

        for(int j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Input edges
    for(i = 0; i < edges; i++)
    {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);

        graph[src][dest] = 1;
        graph[dest][src] = 1; // Undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    // BFS
    BFS(start);

    // Reset visited array for DFS
    for(i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }

    printf("\nDFS Traversal: ");

    // DFS
    DFS(start);

    return 0;
}
OUYPUT
Enter number of vertices: 5
Enter number of edges: 5
Enter edge (source destination): 0 1
Enter edge (source destination): 0 2
Enter edge (source destination): 1 3
Enter edge (source destination): 1 4
Enter edge (source destination): 2 4
Enter starting vertex: 0
BFS Traversal: 0 1 2 3 4
DFS Traversal: 0 1 3 4 2
