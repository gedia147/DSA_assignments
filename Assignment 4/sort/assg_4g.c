// mergesort to find no of inversions (#inversions=adj swaps)
#include <stdio.h>
#include <stdlib.h>
#define int long long
int inversions=0;
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
        inversions+= n1-k+j;
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

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n;
  scanf(" %lld ",&n);
  int  *arr= (int *)malloc(n*sizeof(int));
  for(int i=0;i<n;i++)
    scanf(" %lld ",&(arr[i]));
    mergesort(arr,0,n-1);
      printf("%lld",inversions);
      free(arr);
 return 0;
}
