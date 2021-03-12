// the number of possible permutations modulo 109 + 7
#include <stdio.h>
#include <stdlib.h>
#include<math.h>


int main(){
	int N,x,pos;

	scanf("%d %d %d",&N,&x,&pos);

	long int p=1;


	for(int i=1; i<=N-1; i++)
          p*=i;

	int l = pow(10,9)+7;

	printf("%ld",p%l);
}
