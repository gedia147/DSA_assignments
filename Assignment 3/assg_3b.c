// max gold each assasin can get
#include <stdio.h>
#include <stdlib.h>

int * max_gold(int n,int m,int askill[],int bgskill[],int gold[])
{
  int *ass_gd =(int *)calloc(n,sizeof(int));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(askill[i]>=bgskill[j])
          ass_gd[i]+=gold[j];
    }
  }
  return ass_gd;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n,m;//assasin,noble
  scanf(" %d %d ",&n,&m);
  int  *askill= (int *)malloc(n*sizeof(int));//assasinskill
  int  *bgskill= (int *)malloc(m*sizeof(int));//bodyguard skill
  int  *gold= (int *)malloc(m*sizeof(int));
  for(int i=0;i<n;i++)
    scanf(" %d ",&(askill[i]));
  for(int i=0;i<m;i++)
    scanf(" %d %d ",&(bgskill[i]),&(gold[i]));
      int *mg= max_gold(n,m,askill,bgskill,gold);
    for(int i=0;i<n;i++)
      printf("%d ",mg[i]);
      free(askill);
      free(bgskill);
      free(gold);
      free(mg);
	return 0;
}
