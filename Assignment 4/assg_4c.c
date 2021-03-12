//transform one word to completely diff word with adj diff

#include <stdio.h>
#include <string.h>
int diff_by_one(char a[],char b[])
{
  int diff=0;
  if(strlen(a)!=strlen(b))
    return 0;
  for (int i = 0; i < strlen(a); i++)
  {
    if(a[i]!=b[i])
      diff++;
    if(diff>1)
    break;

  }
  if(diff==1)
    return 1;
  else
    return 0;
}

int distinct(char a[],char b[])
{
  if(strlen(a)!=strlen(b))
    return 0;
  for (int i = 0; i < strlen(a); i++)
  {
    if(a[i]==b[i])
      return 0;
  }
  return 1;
}
int transform(char start[],char inter[],int c,char dict[][12],int n,int t,int visited[])
{
  if(visited[c])
    return 0;
  visited[c]=1;
  if(distinct(start,inter))
      return t;
  int min =-1;
  for (int i=0;i<n;i++)
  {
    if(diff_by_one(inter,dict[i]))
    {
      int len = transform(start,dict[i],i,dict,n,t+1,visited);
      if(len)
      {if(min==-1 || len<min)
        min=len;}
    }
  }
  return min==-1?0:min;
}
int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf(" %d ",&n);
    char start[12];
    char dict[n][12];
    int visited[n];
    	for(int i = 0; i < n; i++)
    		visited[i] = 0;
    scanf(" %s ",&start);
    for (int i =0;i<n;i++)
      scanf(" %s ",&(dict[i]));
      int min=-1;
    for (int i=0;i<n;i++)
    {
      if(diff_by_one(start,dict[i]))
      {
        int len = transform(start,dict[i],i,dict,n,0,visited);
        if(len)
        {if(min==-1 || len<min)
          min=len;}
      }
    }
    printf("%d",min);
    return 0;
}
