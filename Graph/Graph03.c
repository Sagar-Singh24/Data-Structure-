#include <stdio.h>

#define MAX_VERTEX 9

int adj_matrix[MAX_VERTEX][MAX_VERTEX];

void initialize_matrix() 
{
  for (int i = 0; i < MAX_VERTEX; i++) 
  {
    for (int j = 0; j < MAX_VERTEX; j++) 
    {
      adj_matrix[i][j] = 0;
    }
  }
}

void add_edge(int u, int v) 
{
  adj_matrix[u][v] = 1;
  adj_matrix[v][u] = 1;
}

void print_matrix() 
{
  printf("Adjacency Matrix:\n");
  for (int i = 0; i < MAX_VERTEX; i++) 
  {
    for (int j = 0; j < MAX_VERTEX; j++) 
    {
      printf("%d ", adj_matrix[i][j]);
    }
    printf("\n");
  }
}

int count_vertices() 
{
  return MAX_VERTEX;
}

int count_edges() 
{
  int count = 0;
  for (int i = 0; i < MAX_VERTEX; i++) 
  {
    for (int j = 0; j < MAX_VERTEX; j++) 
    {
      if (adj_matrix[i][j] == 1) 
      {
        count++;
      }
    }
  }

  return count / 2;
}

int main() 
{
  initialize_matrix();

  add_edge(0, 1);
  add_edge(0, 7);
  add_edge(2, 1);
  add_edge(2, 3);
  add_edge(2, 8);
  add_edge(3, 4);
  add_edge(3, 6);
  add_edge(4, 5);
  add_edge(6, 7);
  add_edge(6, 8);

  print_matrix();

  int vertices = count_vertices();
  int edges = count_edges();

  printf("Number of vertices: %d\n", vertices);
  printf("Number of edges: %d\n", edges);

  return 0;
}