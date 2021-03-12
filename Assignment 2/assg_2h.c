// aggregate sum of binary tree
#include <stdio.h>
#include <stdlib.h>
int aggregate(int n, int element[],int level[])
{
  int sum=element[0]*level[0];
  for (int i=1;i<n;i++)
  {
    if(i%2==1)
      level[i]= level[(i-1)/2]+1;
    else
      level[i]= level[(i-2)/2]+1;
    sum+= element[i]*level[i];
  }
  return sum;
}
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n;
  scanf(" %d ",&n);
  int *element= (int *)malloc(n*sizeof(int));
  int *level= (int *)malloc(n*sizeof(int));
  for(int i=0;i<n;i++)
      scanf(" %d ",&(element[i]));
  level[0]=1;
  printf("%d",aggregate(n,element,level));
  free(element);
	return 0;
}
