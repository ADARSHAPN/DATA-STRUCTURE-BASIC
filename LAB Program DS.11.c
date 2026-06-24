#include <stdio.h>

#define MAX 10

int main()
{
    int graph[MAX][MAX];
    int vertices, edges;
    int i, j, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    // Initialize matrix with 0
    for(i = 0; i < vertices; i++)
    {
        for(j = 0; j < vertices; j++)
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

    // Display adjacency matrix
    printf("\nAdjacency Matrix:\n");

    for(i = 0; i < vertices; i++)
    {
        for(j = 0; j < vertices; j++)
        {
            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }

    return 0;
}

Using adjacency List

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Node structure
struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *adjList[MAX];

// Create new node
struct Node* createNode(int v)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->vertex = v;
    newNode->next = NULL;

    return newNode;
}

// Add edge
void addEdge(int src, int dest)
{
    struct Node *newNode;

    // Add edge src -> dest
    newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    // Add edge dest -> src (Undirected graph)
    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

// Display adjacency list
void display(int vertices)
{
    int i;
    struct Node *temp;

    printf("\nAdjacency List:\n");

    for(i = 0; i < vertices; i++)
    {
        printf("%d -> ", i);

        temp = adjList[i];

        while(temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    int vertices, edges;
    int i, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    // Initialize adjacency list
    for(i = 0; i < vertices; i++)
    {
        adjList[i] = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Input edges
    for(i = 0; i < edges; i++)
    {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);

        addEdge(src, dest);
    }

    display(vertices);

    return 0;
}
OUTPUT
Vertices: 4
Edges: 4
0 1
0 2
1 2
2 3
Adjacency Matrix:
0 1 1 0
1 0 1 0
1 1 0 1
0 0 1 0
Adjacency List:
0 -> 2 -> 1 -> NULL
1 -> 2 -> 0 -> NULL
2 -> 3 -> 1 -> 0 -> NULL
3 -> 2 -> NULL
