// max number of islands that can be reached from any island
#include <stdio.h>
#include <stdlib.h>
int size=1;//number of islands reached

struct node {
  int vertex;
  struct node* next;
};
struct Graph {
  int vertices;
  struct node** adjLists;
};
// Create a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Create a graph
struct Graph* createAGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->vertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  int i;
  for (i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;

  return graph;
}

// Add edge
void addEdge(struct Graph* graph, int s, int d) {
  // Add edge from s to d
  struct node* newNode = createNode(d);
  newNode->next = graph->adjLists[s];
  graph->adjLists[s] = newNode;

}

// Print the graph
void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->vertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n Vertex %d\n: ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}
void DFS(int v,int visited[],struct Graph* graph)
{
    // Mark the current node
    visited[v] = 1;
    // Recur for all the vertices adjacent to this vertex
  struct node* temp = graph->adjLists[v];
  while (temp)
  {

    if (!visited[temp->vertex])
      {
        size++;
        DFS(temp->vertex, visited,graph);
      }
      temp = temp->next;
  }
}


int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int v,e,s,d;
  scanf(" %d ",&v);
  scanf(" %d ",&e);
    struct Graph* graph = createAGraph(v);
  for(int i=1;i<=e;i++)
  {
    scanf(" %d ",&s);
    scanf(" %d ",&d);
    addEdge(graph,s-1,d-1);
  }
  int  *visited= (int *)malloc(v*sizeof(int));
  int  *count= (int *)malloc(v*sizeof(int));
  for (int i = 0; i < v; i++)
        visited[i] = 0;
  for (int i = 0; i < v; i++)
      {
              DFS(i, visited,graph);
              count[i]=size;
              size=1;
              for (int i = 0; i < v; i++)//or use memset
                    visited[i] = 0;
      }
  int max=count[0];
    for(int i=1;i<v;i++)
      {
        if(count[i]>max)
          max=count[i];
      }
  printf("%d", max);
  // printGraph(graph);

  return 0;
}
