// minimum cost of flight
#include <stdio.h>
#include <stdlib.h>

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

  // Add edge from d to s
  newNode = createNode(s);
  newNode->next = graph->adjLists[d];
  graph->adjLists[d] = newNode;
}

// Print the graph
// void printGraph(struct Graph* graph) {
//   int v;
//   for (v = 0; v < graph->vertices; v++) {
//     struct node* temp = graph->adjLists[v];
//     printf("\n Vertex %d\n: ", v);
//     while (temp) {
//       printf("%d -> ", temp->vertex);
//       temp = temp->next;
//     }
//     printf("\n");
//   }
// }
void BFS(int v,int s,int d,int visited[],int dist[],struct Graph* graph)
{
    // Mark the current node
  visited[s] = 1;
  dist[s]=0;
  int front=0,rear=0,size=0;;
  int  *queue= (int *)malloc(v*sizeof(int));
  queue[rear]=s;//enqueue
  rear++;
  size++;
  while (size)
  {
    int u = queue[front];//dequque
    front++;
    size--;

    struct node* temp = graph->adjLists[u];
    while(temp)
    {
      if (visited[temp->vertex]==0)
      {
        visited[temp->vertex]=1;
        dist[temp->vertex]=1+dist[u];
        queue[rear]=temp->vertex;//enqueue
        rear++;
        size++;
        if(temp->vertex==d)
          return;
      }
      temp = temp->next;
  }
}
}


int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int v,e,s,d,source,dest;
  scanf("%d %d %d %d ",&v,&e,&source,&dest);
    struct Graph* graph = createAGraph(v);
  for(int i=1;i<=e;i++)
  {
    scanf(" %d ",&s);
    scanf(" %d ",&d);
    addEdge(graph,s,d);
  }
  int  *visited= (int *)malloc(v*sizeof(int));
  int  *dist= (int *)malloc(v*sizeof(int));//distance of v from source
  for (int i = 0; i < v; i++)
        visited[i] = 0;
  BFS(v,source,dest,visited,dist,graph);
  printf("%d",dist[dest]*100);
// printGraph(graph);
  return 0;
}
