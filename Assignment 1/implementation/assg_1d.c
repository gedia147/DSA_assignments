//max goods bought within budget (kinda sort and greedy)
#include <stdio.h>
#include <limits.h>
int max_goods(int b,int g,int p[])
{
  int check[25]={0};
  int min;;int sum;
  int index=0;
  int max_goods=0;
  while(b>0)
  { min =INT_MAX;
    for(int i=0;i<g;i++)
    {
      if (check[i]==1)
          continue;
      if(p[i]>b)
      {
        check[i]=1;
        continue;
      }
      if(p[i]<min)
      {
        min=p[i];
        index=i;
      }
    }
    b=b-min;
    if(b<0)
      break;
    check[index]=1;
    max_goods++;
    sum=0;
    for(int i=0;i<g;i++)
      sum+=check[i];
    if(sum==g)
      break;
  }
  return max_goods;
}


int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int budget,goods;
  scanf(" %d ",&budget);
  scanf(" %d ",&goods);
  int prices[25];
  for(int i =0;i<goods;i++)
      scanf(" %d ",&(prices[i]));
    int max = max_goods(budget,goods,prices);
  printf("%d",max);
	return 0;
}
