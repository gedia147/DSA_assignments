//sum of large numbers using strings
#include <stdio.h>
int length(char arr[]);
char * add(char A[],char B[]);
void reverse(char arr[],int len);

int length(char arr[])
{ int len=0;
  while(arr[len]!='\0')
    len++;
  return len;
}

void reverse(char arr[],int len)
{
  for(int i=0;i<len/2;i++)
  {
    char temp = arr[i];
    arr[i]=arr[len-i-1];
    arr[len-i-1]=temp;
    }
}
char * add(char A[],char B[])
{ static char C[1000];
  int len1=length(A);
  int len2=length(B);
  int i,j,k=0;
  int carry=0;
  for(i =len1-1,j= len2-1;j>=0;i--,j--,k++)
  {
      int sum= (int)(A[i] -'0') + (int)(B[j] -'0') + carry;
      carry=sum/10;
      C[k]= (char)(sum%10 + 48);
  }
    for(;i>=0;i--,k++)
    {
        int sum= (int)(A[i] -'0') + carry;
        carry =sum/10;
        C[k]= (char)(sum%10 + 48);
    }
    if (carry==1)
          C[k]= (char)(carry + 48);
   int lenc= length(C);
  reverse(C,lenc);
  return C;
}

int main()
{
  // #ifndef ONLINE_JUDGE
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  // #endif
  char A[1000] ;
  char B[1000];
  scanf(" %s ",A);
  scanf(" %s ",B);
  // fgets(A,1000,stdin);
  // fgets(B,1000,stdin);
  char *C = add(A,B);
  printf("%s",C);
	return 0;
}
