//finding substring only using recursion
#include <stdio.h>
int ind=0;
int n=0;
int count_ind=0;
void substringb(int i,char ch,int state);
void substringa(int i,char ch,int state);

void substringb(int i,char ch,int state)
{
  if(i==n)
  {
      if(ch=='b'&&state==3)
        {
          if(count_ind==0)
            printf("YES %d",ind );
          else
            printf(" %d",ind );
          count_ind++;
          return;
        }
    printf("NO");
    return;
  }
    else if(ch=='b'&&state==0)
    {
      scanf(" %c",&ch);
      ind=i;
      i++;
      state=1;
      substringa(i,ch,state);
    }
    else if(ch=='b'&&state==3)
    {
      if(count_ind==0)
        printf("YES %d",ind );
      else
        printf(" %d",ind );
      count_ind++;
      scanf(" %c",&ch);
      ind=i;
      i++;
      state=1;
      substringa(i,ch,state);
    }
    else
    {
      scanf(" %c",&ch);
      i++;
      state =0;
      substringb(i,ch,state);
    }

}
void substringa(int i,char ch,int state)
{
  if(i==n)
  {
    printf("NO");
    return;
  }
  else if(ch=='a'&&state==1)
  {
    scanf(" %c",&ch);
    i++;
    state=2;
    substringa(i,ch,state);
  }
  else if(ch=='a'&&state==2)
  {
    scanf(" %c",&ch);
    i++;
    state=3;
    substringb(i,ch,state);
  }
  else if(ch=='b')
  {
    scanf(" %c",&ch);
    ind=i;
    i++;
    state=1;
    substringa(i,ch,state);
  }
  else
  {
    scanf(" %c",&ch);
    i++;
    state=0;
    substringa(i,ch,state);
  }

}



int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  char ch;
  scanf("%d",&n);
  scanf(" %c",&ch);
  substringb(1,ch,0);

	return 0;
}
