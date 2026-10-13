#include <stdio.h>

int graph[10][10];
int visited[10];
int n;

// DFS
void DFS(int vertex)
{
    int i;

    printf("%d ", vertex);
    visited[vertex] = 1;

    for (i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

// BFS
void BFS(int start)
{
    int queue[10];
    int front = 0, rear = 0;
    int i;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int vertex = queue[front++];

        printf("%d ", vertex);

        for (i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int i, j;

    n = 5;

    
    int temp[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            graph[i][j] = temp[i][j];
        }
    }

    // DFS
    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(0);

    // BFS
    printf("\nBFS Traversal: ");
    BFS(0);

    return 0;
}