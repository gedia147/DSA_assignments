// print N^K lines, each line containing a distinct string of length K.
#include <stdio.h>
#include <stdlib.h>
int k;
  void printstring(int n,int x,char letters[],char string[])
  {
    for(int i=0;i<n;i++)
      {
        if(x==1)
        {
          string[k-x]=letters[i];
          printf("%s\n",string);
        }
        else
        {
          string[k-x]=letters[i];
          printstring(n,x-1,letters,string);
        }
      }
  }

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n;
  scanf(" %d ",&n);
  scanf(" %d ",&k);
  char *letters= (char *)malloc(n*sizeof(char));
  char *string= (char *)malloc(k*sizeof(char));
  for(int i=0;i<n;i++)
      scanf(" %c ",&(letters[i]));
      printstring(n,k,letters,string);
    free(letters);
    free(string);
	return 0;
}
