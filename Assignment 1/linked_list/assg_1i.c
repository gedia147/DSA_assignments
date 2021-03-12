//reverse input only using singly ll
#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node* next;
};
struct Node* head =NULL;
void append(int new_data)
{
  struct Node* new_node =(struct Node*)malloc(sizeof(struct Node));
  new_node->data=new_data;
  new_node->next=NULL;
  struct Node* temp=head;
  if(head==NULL)
      head=new_node;
  else
  {
    while (temp->next!=NULL)
     {
       temp=temp->next;
     }
     temp->next=new_node;
  }

}
void reverse(int n)
{
  int swap;

  for(int i=1;i<=n/2;i++)
   {
     struct Node* temp1=head;
     struct Node* temp2=head;
     for(int j =1;j<i;j++)
       temp1=temp1->next;

     for(int j =1;j<=n-i;j++)
        temp2=temp2->next;
      swap =temp1->data;
      temp1->data=temp2->data;
      temp2->data=swap;
   }
  }

void printList(struct Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int num;
  int n=0;
  scanf(" %d ",&num);
  while(num!=-1)
  {
    append(num);
    scanf(" %d ",&num);
    n++;
  }
  reverse(n);
  printList(head);

	return 0;
}
