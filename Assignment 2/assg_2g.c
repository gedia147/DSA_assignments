//min number of large boxes (kinda sort and greedy)
#include <stdio.h>
#include <stdlib.h>
int min_count(int n,int small_box[],int big_box)
{
  for(int i=0;i<n-1;i++)
   {
       for(int j=0;j<n-1-i;j++)
       {
           if(small_box[j]<small_box[j+1])
           {
               int temp=small_box[j];
               small_box[j]=small_box[j+1];
               small_box[j+1]=temp;
           }
       }
   }

  int *check=(int *)malloc(n*sizeof(int));
  for (int i = 0; i < n; i++)
        check[i] = 0;
  int min=0;
  int countofcheck=1;
  int index=0;
  while(countofcheck<n)
  {

    for(int i=0;i<n;i++)
    {
      if (check[i]==0)
          {
            check[i]=1;
            countofcheck++;
            min++;
            for(int j=i+1;i<n;i++)
              {
                if(small_box[i]+small_box[j]<=big_box)
                {
                  check[j]=1;
                  countofcheck++;
                  break;
                }
              }
          }
        }
      }
  return min;
}


int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n,big_box;
  scanf(" %d ",&n);
  int *small_box=(int *)malloc(n*sizeof(int));
  for(int i =0;i<n;i++)
      scanf(" %d ",&(small_box[i]));
  scanf(" %d ",&big_box);

  printf("%d",min_count(n,small_box,big_box));
	return 0;
}
