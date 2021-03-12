//max-min cost of array
#include <stdio.h>
void rotate(int n,int arr[])
{
  int temp=arr[n-1];
  for(int i=n-1;i>0;i--)
    arr[i]=arr[i-1];
  arr[0]=temp;
}
int max_min(int n,int cost_arr[])
{
  int max=cost_arr[0];
  int min=cost_arr[0];
  for(int i=1;i<n;i++)
  {
    if(cost_arr[i]>max)
      max=cost_arr[i];
    else if(cost_arr[i]<min)
      min =cost_arr[i];
  }
  return max-min;
}
int cost(int n,int arr[])
{
  int c;
  if(n%2==0)
  {
    int sum1=0;
    int sum2=0;
    for(int i=0;i<n;i++)
    {
      if(i%2==0)
      sum1+=arr[i]*arr[i];
      else
      sum1-=arr[i]*arr[i]*arr[i];
    }
    for(int i=0;i<n;i++)
    {
      if(i%2==1)
      sum2+=arr[i]*arr[i];
      else
      sum2-=arr[i]*arr[i]*arr[i];
    }
    c=sum1>sum2?sum1-sum2:sum2-sum1;
    return c;
  }
  else
  {
    int cost_arr[500];
    int sum;
    for (int j=0;j<n;j++)
    { sum=0;
      for(int i=0;i<n;i++)
      {
        if(i%2==0)
        sum+=arr[i]*arr[i];
        else
        sum-=arr[i]*arr[i]*arr[i];
      }
      cost_arr[j]=sum;
      rotate(n,arr);
    }
    return max_min(n,cost_arr);
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
  int arr[500];
  for(int i =0;i<n;i++)
      scanf(" %d ",&(arr[i]));
    int c = cost(n,arr);
  printf("%d",c);
	return 0;
}
