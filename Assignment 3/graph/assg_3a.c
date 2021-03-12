// max bipartite matching of bpgraph
#include <stdio.h>
#include <stdlib.h>
int n;
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

  // // Add edge from d to s
  // newNode = createNode(s);
  // newNode->next = graph->adjLists[d];
  // graph->adjLists[d] = newNode;
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

// A DFS based recursive function
// that returns true if a matching
// for vertex u is possible

int bpm(struct Graph* graph, int v,
         int seen[], int match[])
{
    // Try every icecream one by one
    struct node* temp = graph->adjLists[v];
    while (temp)
    {
        // If icecream v is not visited
        if (seen[temp->vertex -n] ==0)
        {
            // Mark icecream  as visited
            seen[temp->vertex - n] = 1;

            // If icecream 'temp->vertex' is not assigned to a
            // child OR previously assigned
            // child for icecream temp->vertex (which is match[temp->vertex])
            // has an alternate job available.
            // Since temp->vertex is marked as visited in
            // the above line, match[temp->vertex] in the following
            // recursive call will not get job 'temp->vertex' again
            if (match[temp->vertex-n] < 0 || bpm(graph, match[temp->vertex-n], seen, match))
            {
                match[temp->vertex-n] = v;
                return 1;
            }
        }
        temp=temp->next;
    }
    return 0;
}

// Returns maximum number
// of matching from n to m
int maxBPM(struct Graph* graph,int n,int m)//all children,icecreams
{
    // An array to keep track of the
    // applicants assigned to jobs.
    // The value of match[i] is the
    // child number assigned to icecream i,
    // the value -1 indicates nobody is
    // assigned.
    int  *match= (int *)malloc(m*sizeof(int));

    // Initially all icecreams are available
    for (int i = 0; i < m; i++)
          match[i] = -1;

    // Count of max icecreams assigned to children
    int result = 0;
    for (int v = 0; v < n; v++)
    {
        // Mark all icecreams as not seen
        // for next child.
        int  *seen= (int *)malloc(m*sizeof(int));
        for (int i = 0; i < m; i++)
              seen[i] = 0;

        // Find if the child 'u' can get a icecream
        if (bpm(graph, v, seen, match))
              result++;
        free(seen);
    }
    free(match);
    return result;
}


int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int m,k;
  scanf("%d %d %d ",&n,&m,&k);
  int  *preference= (int *)malloc(n*sizeof(int));
  int  *icsize= (int *)malloc(m*sizeof(int));//cone size
  for (int i = 0; i < n; i++)
    scanf(" %d ",&(preference[i]));
  for (int i = 0; i < m; i++)
    scanf(" %d ",&(icsize[i]));
  struct Graph* graph = createAGraph(n+m);// n*m bipartite direct graph
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(icsize[j]>= preference[i]-k && icsize[j]<= preference[i]+k )
            addEdge(graph,i,n+j);
    }
  }
  printf("%d",maxBPM(graph,n,m));
  free(preference);
  free(icsize);

// printGraph(graph);
  return 0;
}
