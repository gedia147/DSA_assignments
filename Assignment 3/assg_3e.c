// final position of turtle logo compiler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int totalinput;
char arr[32];
void FD(char arr[],int *pos,int loopitr[],int lv,int ln);
void END(char arr[],int *pos,int loopitr[],int lv,int ln);
void LOOP(char arr[],int *pos,int loopitr[],int lv,int ln);

void FD(char arr[],int *pos,int loopitr[],int lv,int ln)
{
  totalinput--;
  int l=strlen(arr);
  char temp[29];
  int i=0;
  while(l>0)
  {
    temp[i]=arr[3+i];
    i++;
    l--;
  }

  *pos+=lv*atoi(temp);

  if(totalinput>0)
  {
    scanf("%[^\n]%*c",arr);
      if(arr[0]=='F')
        FD(arr,pos,loopitr,lv,ln);
      else if (arr[0]=='L')
        LOOP(arr,pos,loopitr,lv,ln);
      else
      END(arr,pos,loopitr,lv,ln);

  }
}
void LOOP(char arr[],int *pos,int loopitr[],int lv,int ln)//loop value loop number
{
  totalinput--;
  int l=strlen(arr);
  char temp[27];
  int i=0;
  while(l>0)
  {
    temp[i]=arr[5+i];
    i++;
    l--;
  }
  int it =atoi(temp);//iteration of current loop
  loopitr[ln]=it;
  ln++;
  if(totalinput>0)
  {
    scanf("%[^\n]%*c",arr);
      if(arr[0]=='F')
        FD(arr,pos,loopitr,lv*it,ln);
      else if(arr[0]=='L')
        LOOP(arr,pos,loopitr,lv*it,ln);
      else //END case
        END(arr,pos,loopitr,lv*it,ln);
  }

}

void END(char arr[],int *pos,int loopitr[],int lv,int ln)
{
  totalinput--;
  ln--;
  lv /= loopitr[ln];
  if(totalinput>0)
  {
    scanf("%[^\n]%*c",arr);
      if(arr[0]=='F')
        FD(arr,pos,loopitr,lv,ln);
      else if(arr[0]=='L')
        LOOP(arr,pos,loopitr,lv,ln);
      else //END case
        END(arr,pos,loopitr,lv,ln);
  }
}
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int position=0;
  int *pos;
  pos=&position;
  scanf(" %d ",&totalinput);
  int *loopitr=(int *)malloc((totalinput/2)*sizeof(int));
  //value of each loop itr
  scanf("%[^\n]%*c",arr);
    if(arr[0]=='F')
      FD(arr,pos,loopitr,1,0);
    else
      LOOP(arr,pos,loopitr,1,0);

  printf("%d",*pos);
  free(loopitr);
	return 0;
}
