//palindrome  using only double linked list
#include <stdio.h>
#include <stdlib.h>
struct Node {
  char data;
  struct Node* next;
  struct Node* prev;
};
// void push(struct Node **headref,struct Node **tailref,char new_data)
// {
//   struct Node* new_node =(struct Node*)malloc(sizeof(struct Node));
//   new_node->data=new_data;
//   new_node->next=(*headref);
//   new_node->prev = NULL;
//
//   if((*headref)==NULL)
//     {
//       (*headref)=new_node;
//       (*tailref)=new_node;
//     }
//   else
//   {(*headref)->prev=new_node;
//   (*headref)=new_node;}
//
// }
void inserttail(struct Node **headref,struct Node **tailref,char new_data)
{
  struct Node* new_node =(struct Node*)malloc(sizeof(struct Node));
  new_node->data=new_data;
  new_node->next=NULL;
  new_node->prev = NULL;
  if((*tailref)==NULL)
    {
      (*headref)=new_node;
      (*tailref)=new_node;
    }
  else
  {
    new_node->prev = (*tailref);
    (*tailref)->next=new_node;
    (*tailref)=new_node;
  }

}
// void printList(struct Node* node)
// {
//     struct Node* last;
//     printf("\nTraversal in forward direction \n");
//     while (node != NULL) {
//         printf(" %c ", node->data);
//         last = node;
//         node = node->next;
//     }
//
//     printf("\nTraversal in reverse direction \n");
//     while (last != NULL) {
//         printf(" %c ", last->data);
//         last = last->prev;
//     }
// }

void check_palindrome(struct Node *head,struct Node *tail,int n)
{
  for (int i=1;i<=n/2;i++)
  {
    if(head->data != tail->data)
    {
      printf("NOT A PALINDROME");
      return;
    }
    head=head->next;
    tail=tail->prev;
  }
  printf("PALINDROME");
}
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n;
  char ch;
  struct Node* head =NULL;
  struct Node* tail =NULL;
  scanf("%d",&n);
  for (int i=1;i<=n;i++)
  {
      scanf(" %c",&ch);
      inserttail(&head,&tail,ch);
  }
  // printList(head);
check_palindrome(head,tail,n);
	return 0;
}
