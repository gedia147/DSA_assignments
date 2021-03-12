// topological sorting and find if DG is cyclic or not
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
  // newNode = createNode(s);
  // newNode->next = graph->adjLists[d];
  // graph->adjLists[d] = newNode;
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
int DFS_checkcycle(int v,int visited[],int recstack[],struct Graph* graph)
{
    // Mark the current node
    visited[v] = 1;
    recstack[v]=1;
    // Recur for all the vertices adjacent to this vertex
  struct node* temp = graph->adjLists[v];
  while (temp)
  {

    if (!visited[temp->vertex] && DFS_checkcycle(temp->vertex, visited,recstack,graph))
      {
        return 1;
      }
      else if(recstack[temp->vertex])
        return 1;
      temp = temp->next;
  }
recstack[v]=0;
return 0;

}

void DFS_TS(int v,int visited[],int recstack[],struct Graph* graph,int *n)
{
  visited[v] = 1;
  // Recur for all the vertices adjacent to this vertex
struct node* temp = graph->adjLists[v];
while (temp)
{

  if (!visited[temp->vertex])
    DFS_TS(temp->vertex, visited,recstack,graph,n);
    temp = temp->next;
}

    recstack[*n]=v;
    *n=*n+1;
}
int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int E;
  char s,d;
  scanf(" %d ",&E);
    struct Graph* graph = createAGraph(26);
      int  *vertex= (int *)malloc(E*2*sizeof(int));
      int temp=0;
  for(int i=1;i<=E;i++)
  {
    scanf(" %c ",&s);
    vertex[temp]=s-'A';temp++;
    scanf(" %c ",&d);
    vertex[temp]=d-'A';temp++;
    addEdge(graph,(s-'A'),(d-'A'));
  }
  int  *visited= (int *)malloc(26*sizeof(int));
  int  *recstack= (int *)malloc(26*sizeof(int));

  for (int i = 0; i < 26; i++)
      {
        visited[i] = 0;recstack[i]=0;
      }
//check if cyclic or not
  for (int i = 0; i < 26; i++)
      {
        if (visited[i] == 0)
            {
              if(DFS_checkcycle(i,visited,recstack,graph))
              {
                 printf("ALIENS BE CRAZY");
                 return 0;
              }
            }
          }
  //NOW FOR topological sort
  for (int i = 0; i < 26; i++)
      {
        visited[i] = 0;recstack[i]=-1;
      }
int n=0;//size of stack
      for (int i = 0; i < E*2; i++)
          {
            if (visited[vertex[i]] == 0)
                DFS_TS(vertex[i],visited,recstack,graph,&n);
              }
      for(int i=n-1;i>=0;i--)
      printf("%c",recstack[i]+65);
  //   printf("%d", count(countofcomponents,sizeofcomp,ey));

  // printGraph(graph);
  free(visited);
  free(recstack);
  free(vertex);
  return 0;
}
