#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};

struct Graph {
  int numVertices;
  struct node** adjLists;
};

struct Graph* createGraph(int vertices) {
  struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = (struct node**) malloc(vertices * sizeof(struct node*));

  int i;
  for (i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;

  return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
  struct node* newNode = (struct node*) malloc(sizeof(struct node));
  newNode->vertex = dest;
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;
}

void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n Vertex %d\n: ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  struct Graph* graph = createGraph(4);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 1, 2);

  printGraph(graph);

  return 0;
}