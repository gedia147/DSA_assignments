//quicksort to find manhatten distance of all points

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
 int mod(int a)
 {  return a>0?a:-a ; }

 int manhatten_dist(int x1,int y1,int x2,int y2)
 { return mod(x2-x1) + mod(y2-y1) ; }

int partition(int a[], int b[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++) {
	if(a[j] < pivot) {
	    i++;
	    swap(&a[i],&a[j]);
	    swap(&b[i],&b[j]);
	}
    }
    swap(&a[i+1],&a[high]);
    swap(&b[i+1],&b[high]);
    return (i+1);
}
void quicksort(int a[], int b[], int low, int high) {
    if(low < high) {
	int pivot = partition(a,b,low,high);
	quicksort(a,b,low,pivot-1);
	quicksort(a,b,pivot+1,high);
    }
    return;
}
int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
    int n, e, s;
    scanf("%d ",&n);
    int  *a1= (int *)malloc(n*sizeof(int));
    int  *a2= (int *)malloc(n*sizeof(int));
    int  *b1= (int *)malloc(n*sizeof(int));
    int  *b2= (int *)malloc(n*sizeof(int));
    int len1=0,len2=0;
    for(int i = 0; i < n; i++)
    {
	   int x,y;
	   scanf("%d %d ",&x,&y);
     if(y>=0)
     {
       a1[len1]=x;a2[len1]=y;len1++;
     }
     else
     {
       b1[len2]=x;b2[len2]=y;len2++;
     }
    }
    quicksort(a1,a2,0,len1-1);
    quicksort(b1,b2,0,len2-1);

    int total_md=0;
    for(int i = 0; i < len1-1; i++)
      total_md+= manhatten_dist(a1[i],a2[i],a1[i+1],a2[i+1]);
    for(int i = 0; i < len2-1; i++)
      total_md+= manhatten_dist(b1[i],b2[i],b1[i+1],b2[i+1]);
    total_md+= manhatten_dist(a1[0],a2[0],b1[0],b2[0]);
    total_md+= manhatten_dist(a1[len1-1],a2[len1-1],b1[len2-1],b2[len2-1]);
	   printf("%d ",total_md);

    return 0;
}
