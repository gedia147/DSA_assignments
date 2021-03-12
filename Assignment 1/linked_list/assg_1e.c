//various operation on register using double ll
#include <stdio.h>
#include <stdlib.h>
struct Node {
  char data;
  struct Node* next;
  struct Node* prev;
};
struct Node* head =NULL;
struct Node* tail =NULL;
void left_rotate(int n)
{ struct Node* temp= head;
  char ch= head->data;
  while(n>1)
  {
    temp->data=temp->next->data;
    temp=temp->next;
    n--;
  }
  tail->data=ch;
}
void right_rotate(int n)
{
  struct Node* temp= tail;
    char ch= tail->data;
    while(n>1)
    {
      temp->data=temp->prev->data;
      temp=temp->prev;
      n--;
    }
    head->data=ch;

}
void right_shift(int n)
{
  struct Node* temp= tail;
    while(n>1)
    {
      temp->data=temp->prev->data;
      temp=temp->prev;
      n--;
    }
    head->data='0';
}
void left_shift(int n)
{
  struct Node* temp= head;
    while(n>1)
    {
      temp->data=temp->next->data;
      temp=temp->next;
      n--;
    }
    tail->data='0';
}
void increment(int n)
{
  struct Node* temp= tail;
  int carry=1;

    while(carry==1&&n>0)
    {
      char ch= temp->data;
      int sum= (ch-'0') +carry; //sum can be 1 or 2
      carry=sum/2;
      sum=sum%2;
      temp->data=sum+'0';
      temp=temp->prev;
      n--;
    }

  }
void decrement(int n)
{

    struct Node* temp= tail;
    int carry=0;

      while(n>0)
      {
        char ch= temp->data;
        int sum= (ch-'0') +1+carry; //sum can be 1 or 2 or 3
        carry=sum/2;
        sum=sum%2;
        temp->data=sum +'0';
        temp=temp->prev;
        n--;
      }

}


void insertatback(char new_data)
{
  struct Node* new_node =(struct Node*)malloc(sizeof(struct Node));
  new_node->data=new_data;
  new_node->next=NULL;
  new_node->prev = NULL;
  if(tail==NULL)
    {
      head=new_node;
      tail=new_node;
    }
  else
  {
    new_node->prev = tail;
    tail->next=new_node;
    tail=new_node;
  }

}
void printList(struct Node* node)
{
    while (node != NULL)
    {
        printf("%c", node->data);
        node = node->next;
    }
}
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n;
  char ch;
  int m=0;
  char operation[3];
  scanf("%c",&ch);
  while(ch!='\n')
  {
    insertatback(ch);
    scanf("%c",&ch);
    m++;
  }
  // printList(head);
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
    scanf(" %s ",operation);
    if(operation[0]=='L')
    {
      if(operation[1]=='R')
        {
          left_rotate(m);
          // printList(head);
        }
      else
        {
          left_shift(m);
         // printList(head);
        }
    }
    else if(operation[0]=='R')
    {
      if(operation[1]=='R')
        {
          right_rotate(m);
          // printList(head);
        }
      else
        {
          right_shift(m);
          // printList(head);
        }
    }
    else if(operation[0]=='I')
    {
        increment(m);
        // printList(head);
    }
    else
    {
        decrement(m);
        // printList(head);
    }
  }
  printList(head);
	return 0;
}
