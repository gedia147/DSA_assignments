//max seats occupied during dinner (max of array) input tricky
#include <stdio.h>
int max_students(int n)
{
  int ts_em[500];//tota students each minute
  char c;
  int student,temp;
  scanf(" %c ",&c);
  scanf(" %d ",&(ts_em[0]));
  int max = ts_em[0] ;
  for (int i=1;i<n;i++)
  {
    scanf(" %c ",&c);
    if (c=='E')
    {
      scanf(" %d ",&student);
      ts_em[i]=ts_em[i-1] + student;
      if(max<ts_em[i])
         max=ts_em[i];
    }
    else
    {
      scanf(" %d ",&student);
      for (int j=1;j<=student;j++)
        scanf(" %d ",&temp);

      ts_em[i]=ts_em[i-1] - student;
      if(max<ts_em[i])
        max=ts_em[i];
    }
  }
  return max;

}



int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n;
  scanf(" %d ",&n);
  int max = max_students(n);
  printf("%d",max);
	return 0;
}
