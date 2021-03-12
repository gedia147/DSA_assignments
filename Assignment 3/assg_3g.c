// max restaurants that can be visited each day
#include <stdio.h>
#include <stdlib.h>

void max_res(int n,int m,int r[],int d[],int final[])
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(d[i]>=r[j])
          final[i]++;
    }
  }
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n,m;//restaurants,days
  scanf(" %d %d ",&m,&n);
  int  *r= (int *)malloc(m*sizeof(int));//cost of each restaurant
  int  *d= (int *)malloc(n*sizeof(int));//money on each day
  int  *final= (int *)calloc(n,sizeof(int));//final asnswer
  for(int i=0;i<m;i++)
    scanf(" %d ",&(r[i]));
  for(int i=0;i<n;i++)
    scanf(" %d ",&(d[i]));
    max_res(n,m,r,d, final);
    for(int i=0;i<n;i++)
      printf("%d ",final[i]);
      free(r);
      free(d);
      free(final);
	return 0;
}
