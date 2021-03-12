// h-index
#include <stdio.h>
#include <stdlib.h>
void min(int **temp,int *leneach,int *hi,int a)
{
  for(int i=0;i<a;i++)
  {
    int min =temp[i][0];
    for(int j=1;j<leneach[i];j++)
    {
      if(temp[i][j]<min)
        min=temp[i][j];
    }
    hi[i]=min;
  }
}
int * hindex(int a,int p,int authors[],int citations[])
{
  int  *hi= (int *)malloc(a*sizeof(int));//hi of each a
  int  **temp= (int **)malloc(a*sizeof(int*));
    for(int i=0;i<a;i++)
      temp[i]= (int *)malloc(p*sizeof(int));
  int *si=(int *)calloc(a,sizeof(int));//second index of temp

  for(int i=0;i<p;i++)
  {
    temp[authors[i]][si[authors[i]]]=citations[i];
    si[authors[i]]++;
  }
  min(temp,si,hi,a);
  return hi;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int a,p,c;//authors,publications,citations
  int p1,p2;
  scanf(" %d %d %d ",&a,&p,&c);
  int  *authors= (int *)malloc(p*sizeof(int));//a of each p
  int  *citations= (int *)calloc(p,sizeof(int));//no. of c per p
  for(int i=0;i<p;i++)
    scanf(" %d ",&(authors[i]));
  for(int i=0;i<c;i++)
    {
      scanf(" %d %d  ",&p1,&p2);
      citations[p2]++;
    }

    int *hi= hindex(a,p,authors,citations);
    for(int i=0;i<a;i++)
      printf("%d ",hi[i]);
      free(authors);
      free(citations);
      free(hi);
	return 0;
}
