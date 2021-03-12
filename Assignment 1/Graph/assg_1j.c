// if chromatic color 2 or not(if bipartite or not)
#include <stdio.h>
#include <stdlib.h>

int front;
int queue[500];
int rear;
int size;//size of queue
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
int is2color(int v,int colorarr[],struct Graph* graph)
{
    // Mark the current node
  colorarr[v] = 1;

  queue[rear]=v;//enqueue
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
      if (colorarr[temp->vertex]==-1)
      {
        colorarr[temp->vertex]=1-colorarr[u];
        queue[rear]=temp->vertex;//enqueue
        rear++;
        size++;

      }
      else if(colorarr[temp->vertex]==colorarr[u])
        return 0;
      temp = temp->next;
  }
}
return 1;
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
    addEdge(graph,s,d);
  }
  int colorarr[500];
  for (int i = 0; i < v; i++)
        colorarr[i] = -1;
        int check=1;
  for (int i = 0; i < v; i++)
      {
        if (colorarr[i] == -1)
            { front=0;
              rear=0;
              size=0;
              if(is2color(i, colorarr,graph)==0)
              {
                check=0;
                break;
              }
            }
        }

    if(check==0)
      printf("NEED MORE COLOURS");
      else
      {
        for(int i=0;i<v;i++)
          {
            if(i%2==0)
              printf("R");
            else
              printf("B");
          }

      }
// printGraph(graph);
  return 0;
}
