#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_VERTICES 10 

struct AdjListNode 
{
    int dest;
    struct AdjListNode* next;
};

struct AdjList 
{
    struct AdjListNode* head;
};
struct Graph 
{
    int num_vertices;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest) 
{
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph(int num_vertices) 
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->num_vertices = num_vertices;
    graph->array = (struct AdjList*)malloc(num_vertices * sizeof(struct AdjList));
    for (int i = 0; i < num_vertices; ++i)
        graph->array[i].head = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) 
{
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void DFSUtil(int v, bool visited[], struct Graph* graph) 
{
    visited[v] = true;
    struct AdjListNode* pCrawl = graph->array[v].head;
    while (pCrawl != NULL) 
    {
        int adjacent_vertex = pCrawl->dest;
        if (!visited[adjacent_vertex])
            DFSUtil(adjacent_vertex, visited, graph);
        pCrawl = pCrawl->next;
    }
}

int countConnectedComponents(struct Graph* graph) 
{
    bool visited[NUM_VERTICES];
    int count = 0;
    for (int v = 0; v < NUM_VERTICES; v++)
        visited[v] = false;
    for (int v = 0; v < NUM_VERTICES; v++) 
    {
        if (!visited[v]) 
        {
            DFSUtil(v, visited, graph);
            count++;
        }
    }
    return count;
}
int main() 
{
    struct Graph* graph = createGraph(NUM_VERTICES);
    int friendships[][2] = {{0, 2}, {0, 3}, {0, 7}, {1, 8}, {1, 9},
                             {2, 3}, {2, 6}, {2, 7}, {3, 5}, {3, 6},
                             {4, 5}, {6, 7}};

    for (int i = 0; i < 12; i++)
        addEdge(graph, friendships[i][0], friendships[i][1]);
    int num_groups = countConnectedComponents(graph);
    printf("Number of friendship groups in the locality: %d\n", num_groups);

    return 0;
}