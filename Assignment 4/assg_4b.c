// robowar sruvivor index and strength
#include <stdio.h>
#include <stdlib.h>
int abs(int n)
{
  if(n>0)
    return n;
  return -n;
}
void robo_winner(int *n,int a,int b,int strength[],int index[])
{
  if(*n>1)
  {
    if(*n %2==0)
    { int ind=0;
        for(int i=0;i< *n;i=i+2)
        {
          if(strength[i]>strength[i+1])
          {
            strength[ind]=abs(strength[i] - a*(strength[i]-strength[i+1]));
            index[ind]=index[i];
            ind++;
          }
          else if(strength[i]<strength[i+1])
          {
            strength[ind]=abs(strength[i+1] - a*(strength[i+1]-strength[i]));
            index[ind]=index[i+1];
            ind++;
          }
          else
          {
            if(*n==2)
            {
              strength[ind]=-1;
              index[ind]=-1;

            }
          }
        }
        robo_winner(&ind,a,b,strength,index);
    }
    else
    {
      int ind=0;
          for(int i=0;i< *n-1;i=i+2)
          {
            if(strength[i]>strength[i+1])
            {
              strength[ind]=abs(strength[i] - a*(strength[i]-strength[i+1]));
              index[ind]=index[i];
              ind++;
            }
            else if(strength[i]<strength[i+1])
            {
              strength[ind]=abs(strength[i+1] - a*(strength[i+1]-strength[i]));
              index[ind]=index[i+1];
              ind++;
            }
          }
          strength[ind]=strength[*n-1]+b;
          index[ind]=*n;
          ind++;
          robo_winner(&ind,a,b,strength,index);
    }
  }
}
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n,a,b;//robots,alpha,beta
  scanf(" %d %d %d ",&n,&a,&b);
  int *strength= (int *)malloc(n*sizeof(int));
  int  *index= (int *)malloc(n*sizeof(int));
  for(int i=0;i<n;i++)
  {
      scanf(" %d ",&(strength[i]));
      index[i]=i+1;
  }
  robo_winner(&n,a,b,strength,index);
  printf("%d %d",index[0],strength[0]);
  free(strength);
  free(index);
	return 0;
}
