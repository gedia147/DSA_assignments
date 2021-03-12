// max frq of digit in prime numbers between A and B
#include <stdio.h>
// #include <string.h>
// #include <limits.h>
#define int long long
// typedef long long int;
void freqeachdig(int *digit_freq,int p)
{ int dig;
  while(p>0)
  {
    dig=p%10;
    digit_freq[dig]++;
    p=p/10;
  }
}

int * max_digfreq(int c,int d)
  {
    static int digit_freq[10]={0};
    int flag;
    // memset(prime,0,(b+1)*sizeof(int));
    if (c==1)
      c++;
    for (int i = c; i <=d; i++)//not used seive coz d very large
    {
       flag=1;

      for(int j=2;j*j<=i;j++)
      {
        if(i%j==0)
        {
          flag=0;
          break;
        }
      }
      if(flag==1)
        freqeachdig(digit_freq,i);
    }
    return digit_freq;
  }
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int a,b;
  scanf(" %lld ",&a);
  scanf(" %lld ",&b);
  int *digit_freq=max_digfreq(a,b);
  int maxfreq=digit_freq[0];
  int dig=0;
  for(int i =0;i<10;i++)
      {
        if(digit_freq[i]>maxfreq)
        {
          maxfreq=digit_freq[i];
          dig=i;
        }
      }
  printf("%d ",dig);
   printf("%d",maxfreq);
	return 0;
}
