// multiplication of n powers with m multipliers
#include <stdio.h>
#include <stdlib.h>
#define int long long
int M=1000000007;
// typedef long long int;
  void multiplication(int n,int m,int multipliers[],int powers[])
  {
    for(int i=0;i<n-m+1;i++)
    {
      for(int j=0;j<m;j++)
        powers[i+j]=(powers[i+j]*multipliers[j])%M;
    }
  }

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n,m;
  scanf(" %lld ",&n);
  scanf(" %lld ",&m);
  int *multipliers= (int *)malloc(m*sizeof(int));
  int *powers= (int *)malloc(n*sizeof(int));
  for(int i=0;i<n;i++)
      scanf(" %lld ",&(powers[i]));
  for(int i=0;i<m;i++)
      scanf(" %lld ",&(multipliers[i]));
      multiplication(n,m,multipliers,powers);
  for(int i=0;i<n;i++)
    printf("%lld ",powers[i]);
    free(multipliers);
    free(powers);
	return 0;
}
