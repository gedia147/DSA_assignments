//length of smallest possible contiguous subsegment with distinct element
// =distinct of whole segment
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct set{
  int distinct;
  int *count;
};
void add(struct set* s,char ch)
{
  s->count[ch-'A'] ++;
  if(s->count[ch-'A']==1)
    s->distinct ++;
}

int min_subseg(char arr[],int n,int k)
{
  int l=0;
  int r = n-1;
  int j=-1;
    struct set* s = malloc(sizeof(struct set));
    s->distinct =0;
    s->count=(int *)calloc(7,sizeof(int));
  for (int i=0;i<n;i++)
  {
    while(j<n)
    {
      j++;
      if(s->distinct<k)
        add(s,arr[j]);
      if(s->distinct==k && r-l>=j-i)
        {
          l=i;r=j;
          break;
        }
      }
    if(s->distinct!=k)
      break;
    while(s->distinct==k)
      {
        if(s->count[arr[i]-'A']==1)
          s->distinct--;
        s->count[arr[i]-'A']--;
        i++;
        if(s->distinct==k && r-l>=j-i)
          {
            l=i;r=j;
          }
      }
      if(s->count[arr[i]-'A']==1)
        s->distinct--;
      s->count[arr[i]-'A']--;
        //i increases after this
  }

return r-l+1;
}
int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf(" %d ",&n);
    char  *arr= (char *)malloc(n*sizeof(int));
    struct set* all = malloc(sizeof(struct set));
    all->distinct=0;
    all->count=(int *)calloc(7,sizeof(int));
    for (int i =0;i<n;i++)
      {
        scanf(" %s ",&(arr[i]));
        add(all,arr[i]);
      }
    int min = min_subseg(arr,n,all->distinct);
    printf("%d",min);
    return 0;
}
