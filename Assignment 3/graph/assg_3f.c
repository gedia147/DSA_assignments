// the number of antivirus doses needed to infect strictly greater than
// 80% of the population
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
void DFS(int v,int visited[],struct Graph* graph,int *ts)
{
    // Mark the current node
    visited[v] = 1;
    // Recur for all the vertices adjacent to this vertex
  struct node* temp = graph->adjLists[v];
  while (temp)
  {

    if (!visited[temp->vertex])
      {
        *ts = *ts +1;
        DFS(temp->vertex, visited,graph,ts);
      }
      temp = temp->next;
  }
}
void merge(int arr[],int l,int mid,int r)
{
  int n1= mid-l +1;
  int n2= r-mid;
  int  *left= (int *)malloc(n1*sizeof(int));
  int  *right= (int *)malloc(n2*sizeof(int));
  for(int i=0;i<n1;i++)
    left[i]=arr[l+i];
  for(int i=0;i<n2;i++)
    right[i]=arr[mid+1+i];
    int i=0;
    int j=0;
    int k=0;
    while(i<n1&&j<n2)
    {
      if(left[i]>=right[j])
      {
        arr[l+k]=left[i];
        i++;
      }
      else
      {
        arr[l+k]=right[j];
        j++;
      }
      k++;
    }
    while(i<n1)
    {
        arr[l+k]=left[i];
        i++;k++;
    }
    while(j<n2)
    {
        arr[l+k]=right[j];
        j++;k++;
    }
    free(left);
    free(right);
}
void mergesort(int arr[],int l,int r)
{
  if(l<r)
  {
    int mid = l + (r-l)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
  }
}

int count(int len,int sizeofcomp[],int e)
{
  int sum=0;
  int c=0;
  for(int i=0;i<len;i++)
  {
    sum+=sizeofcomp[i];
    c++;
    if(sum>=e)
      return c;
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
    addEdge(graph,s,d);
  }
  int  *visited= (int *)malloc(v*sizeof(int));
  for (int i = 0; i < v; i++)
        visited[i] = 0;
  int countofcomponents=0;
  int  *sizeofcomp= (int *)calloc(v,sizeof(int));
  int tempsize=1;//for size of each;
  int *ts=&tempsize;
  for (int i = 0; i < v; i++)
      {
        if (visited[i] == 0)
            {
              DFS(i, visited,graph,ts);
              countofcomponents++;
              sizeofcomp[countofcomponents-1]=*ts;
              *ts=1;
            }
          }
    int temp= 0.2*v;
    int ey=v-temp;//minimum people needed
    mergesort(sizeofcomp,0,countofcomponents-1);//in decreasing order
    printf("%d", count(countofcomponents,sizeofcomp,ey));

  // printGraph(graph);

  return 0;
}
