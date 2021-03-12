// minimum number of fights between dinasours
#include <stdio.h>
#include <stdlib.h>
int NC2(int n)
{
  if(n<2)
    return 0;
  return (n*(n-1))/2;
}
int minimum_fights(int n,int c,char first[])
{
  int min_fights=0;
  int freq[36]={0};//letters then digits A-Z0-9
  for(int i=0;i<n;i++)
    {
      if(first[i]-'A'<0)
        freq[first[i]-'0' +26]++;
      else
        freq[first[i]-'A']++;
      }
  int temp=0;
  int count[36];//count of tags whose first character matches
  for(int i=0;i<36;i++)
    {
      if(freq[i]>1)
      {
        count[temp]=freq[i];
        temp++;
      }
      }
    for(int i=0;i<temp;i++)
      {
        if(count[i]<=c)
          continue;
        int quotient=count[i]/c;
        int remainder=count[i]%c;
        min_fights+=remainder*NC2(quotient+1) + (c-remainder)*NC2(quotient);
      }
      return min_fights;
}
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n,c;//species,cages
  scanf(" %d ",&n);
  scanf(" %d ",&c);
  char *tag= (char *)malloc(20*sizeof(char));
  char *first= (char *)malloc(n*sizeof(char));//first letter of tags
  for(int i=0;i<n;i++)
      {
        scanf(" %s ",tag);
        first[i]=tag[0];
      }
    printf("%d",minimum_fights(n,c,first));
    free(tag);
    free(first);
	return 0;
}
