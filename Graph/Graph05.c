#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 100

int adj[MAX_VERTEX][MAX_VERTEX];
int visited[MAX_VERTEX];
int num_vertices;

void create_graph(int vertices) 
{
    num_vertices = vertices;
    for (int i = 0; i < num_vertices; i++) 
    {
        for (int j = 0; j < num_vertices; j++) 
        {
            adj[i][j] = 0;
        }
    }
}
void add_edge(int u, int v) 
{
    adj[u][v] = 1;
    adj[v][u] = 1;
}
void print_graph() {
    for (int i = 0; i < num_vertices; i++) 
    {
        printf("Node %d: ", i);
        for (int j = 0; j < num_vertices; j++) 
        {
            if (adj[i][j] == 1) 
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}
void bfs(int start_vertex) 
{
    int queue[MAX_VERTEX];
    int front = -1, rear = -1;

    for (int i = 0; i < num_vertices; i++) 
    {
        visited[i] = 0;
    }
    visited[start_vertex] = 1;
    queue[++rear] = start_vertex;

    while (front != rear) 
    {

        int u = queue[++front];
        printf("Visited: %d\n", u);

        for (int v = 0; v < num_vertices; v++) 
        {
            if (adj[u][v] == 1 && visited[v] == 0) 
            {
                visited[v] = 1;
                queue[++rear] = v;
            }
        }
    }
}
int count_nuclear_points() 
{
    int count = 0;
    for (int i = 0; i < num_vertices; i++) 
    {
        int degree = 0;
        for (int j = 0; j < num_vertices; j++) 
        {
            if (adj[i][j] == 1) 
            {
                degree++;
            }
        }
        if (degree == 1) 
        {
            count++;
        }
    }
    return count;
}
void dfs(int start_vertex) 
{
    visited[start_vertex] = 1;
    printf("Visited: %d\n", start_vertex);

    for (int i = 0; i < num_vertices; i++) 
    {
        if (adj[start_vertex][i] == 1 && !visited[i]) 
        {
            dfs(i);
        }
    }
}
int has_at_least_two_neighbours(int node) 
{
    int degree = 0;
    for (int i = 0; i < num_vertices; i++) 
    {
        if (adj[node][i] == 1) 
        {
            degree++;
        }
    }
    return degree >= 2;
}
int is_north_node(int node) 
{
    printf("Warning: Node positions are not available to determine if a node is on the north side.\n");
    return 0;
}
int main() 
{

    create_graph(6);
    add_edge(0, 1);
    add_edge(0, 3);
    add_edge(1, 2);
    add_edge(1, 3);
    add_edge(2, 3);
    add_edge(2, 4);
    add_edge(3, 4);
    add_edge(3, 5);
    add_edge(4, 5);

    printf("Graph representation:\n");
    print_graph();

    printf("\nBFS traversal:\n");
    bfs(0);

    printf("\nNumber of nuclear points: %d\n", count_nuclear_points());

    printf("\nDFS traversal:\n");
    dfs(0);

    printf("\nNode 3 has at least two neighbours: %s\n", has_at_least_two_neighbours(3) ? "Yes" : "No");

    printf("\nNode 2 is on the north side: %s\n", is_north_node(2) ? "Yes" : "No");

    return 0;
}