// f(x) = f(div1) + f(div2) if x has two or more distinct divisors other than 1 and itself
//        x if x has 1 divisor or less apart from 1 and itself
#include <stdio.h>
int arr[4];//prime,perfect square of prime ,highest divisor 1&2
void isprime(int x)
{ arr[0]=0;
  arr[1]=0;
  arr[2]=0;
  arr[3]=0;
  int primeflag=1;
  int i=2;
  for(;i*i<=x;i++)
  {
    if(x%i==0)
    {
      primeflag=0;
      break;
    }
  }
  if(primeflag==1)
  {
    arr[0]=primeflag;
    return ;
  }
  else if(i*i==x)
  {
    arr[1]=1;
    return ;
  }
  else
  {
    arr[2]=x/i;
    int j=i+1;
    while(x%j!=0)
      j++;
    arr[3]=x/j;
    return ;
  }
}
int func(int n)
  {
    isprime(n);
    if(arr[0]==1||arr[1]==1)//prime or perfect square of prime
      return n;
    else
    {
      int max1=arr[2];
      int max2=arr[3];
      return func(max1)+ func(max2);
    }

  }
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n;
  scanf(" %d ",&n);
  int output=func(n);
  printf("%d",output);
	return 0;
}
