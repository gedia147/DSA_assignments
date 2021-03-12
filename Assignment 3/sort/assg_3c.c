// mergesort + binary search finding largest min distance
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
int feasible(int m,int k,int n ,int fs[])
{
  int temp =1;
  int tree=fs[0];
  for (int i=1;i<n;i++)
  {
    if(fs[i]-tree>=m)//if consecutive distance between trees chosen is >= mark
    //then m is feasible min distance
    {
      temp++;
      tree=fs[i];//next tree;
    }
  }
  if(temp==k)//of k trees chosen then feasible
    return 1;
  return 0;
}
int largest_mindis(int k,int n,int fs[])
{
  int result=-1;
  int l=1;
  int r=fs[n-1];//final answer between 1 and fs[n-1]
  while(l<r)
  {
    int mid=l + (r-l)/2;
    //mid assumed to feasible mimimum distance between the k trees
    if(feasible(mid,k,n,fs))
    {
      //then largest min distance is >=largest_mind
      l=mid+1;
      result=mid>result?mid:result;
    }
    else
    r=mid;
  }
  return result;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n,k;//trees,fertile spots
  scanf(" %d %d ",&k,&n);
  int  *fs= (int *)malloc(n*sizeof(int));
  for(int i=0;i<n;i++)
    scanf(" %d ",&(fs[i]));
    mergesort(fs,0,n-1);
      int lm= largest_mindis(k,n,fs);
      printf("%d",lm);
      free(fs);
 return 0;
}
