// printing winner and loser ranker of codeforces //directed graph
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
        DFS(temp->vertex, visited,graph);
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
  e=(v*(v-1))/2 -1;
  int  *count= (int *)malloc(v*sizeof(int));//count of each player w/l with other
  for (int i = 0; i < v; i++)
        count[i] = 0;
    struct Graph* graph = createAGraph(v);
  for(int i=1;i<=e;i++)
  {
    scanf(" %d ",&s);
    scanf(" %d ",&d);
    count[s-1]++;
    count[d-1]++;
    addEdge(graph,s-1,d-1);
  }
    int player1,player2;
    for (int i = 0; i < v; i++)
          if(count[i]==v-2)
          {
            player1=i;
            for(int j=i+1;j<v;j++)
            {
              if(count[j]==v-2)
              {
                player2=j;
                break;
              }
            }
            break;
          }

  int  *visited= (int *)malloc(v*sizeof(int));
  for (int i = 0; i < v; i++)
        visited[i] = 0;

  DFS(player1, visited,graph);

  if(visited[player2]==1)
    printf("%d %d",player1+1,player2+1);
    else
    printf("%d %d",player2+1,player1+1);


  // printGraph(graph);

  return 0;
}
