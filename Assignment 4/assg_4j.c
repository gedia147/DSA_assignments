//ternary search to find max of inc dec array and then binary search
#include <stdio.h>
#include <stdlib.h>
int ternary_search(int arr[],int l,int r)
{
  int m1= l+ (r-l)/3;
  int m2 = r- (r-l)/3;
  while(m2-m1>2 || l!=m1 ||r!=m2)
  {
    if(arr[m1]<arr[m2])
      l=m1;
    else if (arr[m1]>arr[m2])
      r=m2;
    else
    {
      l=m1;r=m2;
    }
    m1= l+ (r-l)/3;
    m2 = r- (r-l)/3;
  }
  if(m2-m1==2)
  return (m1+m2)/2;
  else if(m2-m1==1)
  return arr[m2]>arr[m1]?m2:m1;
  else
  return m1;
}
int binary_search(int arr[],int l,int r,int key)
{
  int m= l+ (r-l)/2;
  while(l<=r)
  {
    if(arr[m]==key)
      return 1;
    else if (arr[m]>key)
      r=m-1;
    else
      l=m+1;
    m= l+ (r-l)/2;
  }
  return 0;
}
int binary_searchdec(int arr[],int l,int r,int key)
{
  int m= l+ (r-l)/2;
  while(l<=r)
  {
    if(arr[m]==key)
      return 1;
    else if (arr[m]<key)
      r=m-1;
    else
      l=m+1;
    m= l+ (r-l)/2;
  }
  return 0;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n,q,num;
  scanf(" %d %d ",&n,&q);
  int  *arr= (int *)malloc(n*sizeof(int));
  int  *arrq= (int *)malloc(q*sizeof(int));

  for(int i=0;i<n;i++)
    scanf(" %d ",&(arr[i]));
  int argmax= ternary_search(arr,0,n-1);
    for(int i=0;i<q;i++)
        scanf(" %d ",&arrq[i]);
    // printf("%d",argmax);
    for(int i=0;i<q;i++)
      {
        int found = binary_search(arr,0,argmax,arrq[i])||binary_searchdec(arr,argmax+1,n-1,arrq[i]);
        if(found)
          printf("YES\n");
        else
        printf("NO\n");
      }
    free(arr);
    free(arrq);
 return 0;
}
