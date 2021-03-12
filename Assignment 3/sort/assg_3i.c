//min cost of fuel mergesort and compare
#include <stdio.h>
#include <stdlib.h>
void merge(int arr[],int l,int mid,int r)
{
  int n1= mid-l +1;
  int n2= r-mid;
  int  *left= (int *)malloc(n1*sizeof(int));
  int  *right= (int *)malloc(n2*sizeof(int));
  for(int i=0;i<n1;i++)
    left[i]=arr[l+i];
  for(int i=0;i<n2;i++)
    right[i]=arr[mid+1+i];
    int i=0;
    int j=0;
    int k=0;
    while(i<n1&&j<n2)
    {
      if(left[i]<=right[j])
      {
        arr[l+k]=left[i];
        i++;
      }
      else
      {
        arr[l+k]=right[j];
        j++;
      }
      k++;
    }
    while(i<n1)
    {
        arr[l+k]=left[i];
        i++;k++;
    }
    while(j<n2)
    {
        arr[l+k]=right[j];
        j++;k++;
    }
    free(left);
    free(right);
}
void mergesort(int arr[],int l,int r)
{
  if(l<r)
  {
    int mid = l + (r-l)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
  }
}
int min_cost(int tg[],int gs[],int a,int b,int k,int len,int l)
{
  int mc=0;int flag;
  for(int i=0;i<len-1;i++)
  {
    int dist=tg[i+1]-tg[i];
    flag=0;
    for(int j=0;j<l;j++)
    {
      if(a*gs[j]+b>=dist)
      {
        mc+=k*gs[j];
        flag=1;
        break;
      }
    }
    if(flag==0)
      return -1;
  }
  return mc;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n,m,l;//cities,tollgates ,gascontainers
  scanf(" %d %d %d ",&n,&m,&l);
  int s,d,a,b,k;
  int  *tg= (int *)malloc(m*sizeof(int));//tollgates from s to d
  int  *gs= (int *)malloc(l*sizeof(int));// gas containers
  int len=0;//length of tg array without dtations less than s or more than d
  int temp;
  scanf(" %d %d %d %d %d ",&s,&d,&a,&b,&k);
  for(int i=0;i<m;i++)
    {
      scanf(" %d ",&temp);
      if(temp>=s&&temp<=d)
        {
          tg[len]=temp;
          len++;
        }
      }
    for(int i=0;i<l;i++)
        scanf(" %d ",&(gs[i]));
    mergesort(tg,0,len-1);
    mergesort(gs,0,l-1);

      int mc= min_cost(tg,gs,a,b,k,len,l);
      if(mc==-1)
        printf("NOT POSSIBLE");
      else
        printf("%d",mc);
      free(gs);
      free(tg);
 return 0;
}
