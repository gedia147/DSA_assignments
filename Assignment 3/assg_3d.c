// number of pairs s.t. xi + xj + k1 > yi + yj + k2
#include <stdio.h>
#include <stdlib.h>

int max_pairs(int n,int k1,int k2,int a[],int b[])
{
  int mp=0;
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(a[i] + a[j] +k1 > b[i] + b[j] +k2)
          mp++;
    }
  }
  return mp;
}

int main()
{
  // #ifndef ONLINE_JUDGE
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  // #endif
  int n,k1,k2;
  scanf(" %d %d  %d ",&n,&k1,&k2);
  int  *a= (int *)malloc(n*sizeof(int));
  int  *b= (int *)malloc(n*sizeof(int));
  for(int i=0;i<n;i++)
    scanf(" %d ",&(a[i]));
  for(int i=0;i<n;i++)
    scanf(" %d ",&(b[i]));
      int mp= max_pairs(n,k1,k2,a,b);//max pairs
      printf("%d",mp);
      free(a);
      free(b);
	return 0;
}
