// number of ways input can be represented as a sum of power of 2.
#include <stdio.h>
int log_2(int n)
{
  int k=0;
  while(n/2!=0)
  {
    k++;
    n=n/2;
  }
  return k;
}
int power(int x,int y)//x^y
{
    int p=1;
    while(y>0)
    {
      p*=x;
      y--;
    }
    return p;
}
int sumofpower(int n,int k)
{
  if(k<0)
    return 0;
  if(k==0)
      return 1;
  if (n==0)
    return 1;
  if(n>=power(2,k))
    return sumofpower(n-power(2,k),k) + sumofpower(n,k-1);
  else
    return sumofpower(n,k-1);
}


int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n;
  scanf(" %d ",&n);
  int k=log_2(n);
  printf("%d",sumofpower(n,k));

	return 0;
}
