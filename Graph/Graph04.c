#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node 
{
  int data;
  struct Node* next;
} Node;

typedef struct Graph 
{
  int numVertices;
  Node* head[MAX_VERTICES]; 
} Graph;

Node* createNode(int data) 
{
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}
Graph* createGraph(int numVertices) 
{
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->numVertices = numVertices;

  for (int i = 0; i < numVertices; ++i) 
  {
    graph->head[i] = NULL;
  }
  return graph;
}
void addEdge(Graph* graph, int src, int dest) 
{
  Node* newNode = createNode(dest);
  newNode->next = graph->head[src];
  graph->head[src] = newNode;

  newNode = createNode(src);
  newNode->next = graph->head[dest];
  graph->head[dest] = newNode;
}
void printGraph(Graph* graph) 
{
  printf("Adjacency List: \n");
  for (int v = 0; v < graph->numVertices; ++v) 
  {
    printf("%d -> ", v);
    Node* temp = graph->head[v];
    while (temp) 
    {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}
Node* searchNode(Graph* graph, int value) 
{
  for (int v = 0; v < graph->numVertices; v++) 
  {
    Node* temp = graph->head[v];
    while (temp) {
      if (temp->data == value) 
      {
        return temp;
      }
      temp = temp->next;
    }
  }
  return NULL; 
}
void printNeighbors(Graph* graph, int value) 
{
  Node* foundNode = searchNode(graph, value);
  if (foundNode == NULL) {
    printf("Node not found\n");
  } 
  else 
  {
    printf("Neighbors of node %d: ", value);
    Node* temp = foundNode->next; 
    while (temp) 
    {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}
int main() 
{
  int numVertices = 7;
  Graph* graph = createGraph(numVertices);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 2, 5);
  addEdge(graph, 3, 4);
  addEdge(graph, 3, 6);
  addEdge(graph, 4, 5);
  addEdge(graph, 5, 6);

  printGraph(graph);

  int searchValue = 2;
  Node* foundNode = searchNode(graph, searchValue);
  if (foundNode == NULL) 
  {
    printf("Node with value %d not found\n", searchValue);
  } 
  else 
  {
    printf("Node with value %d found\n", searchValue);
    printNeighbors(graph, searchValue);
  }

  return 0;
}