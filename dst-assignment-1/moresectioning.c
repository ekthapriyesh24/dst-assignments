/*Solve the "sectioning" question for k sections instead of just 3. The inputs and outputs remain the same, except the first line of input is the number of elements followed by k. Use an array of linked lists.
SAMPLE INPUT
2
6 2
7 8 3 1 4 9 
8 4
4 11 8 15 3 1 6 13
SAMPLE OUTPUT
7 3 9 
8 1 4 
4 3 1 6 
11 
8 13 
15*/ 
#include<stdio.h>
#include<string.h>
#include<limits.h>
#define pp(x) printf("%s\n",x)
struct ll
{
    int data;
    struct ll *next;
};
struct lol
{
    int imp;
    struct ll *data;
    struct lol *next;
};
void insert(struct ll** head,int n)
{
    struct ll* p;
    p=*head;
    for(int i=0;i<n;i++)
    {
        struct ll* temp=(struct ll*)(malloc(sizeof(struct ll)));
        scanf("%s",temp->data);
        temp->next=NULL;
      if((*head)==NULL)
      {
        *head=temp;
        p=*head;
      }
     else
     {
        p->next=temp;
        p=p->next;
     }
    }
}
void insertn(struct ll** head,int val)
{
    struct ll* p;
    p=*head;
    struct ll* temp=(struct ll*)(malloc(sizeof(struct ll)));
    temp->data=val;
    temp->next=NULL;
      if((*head)==NULL)
      {
        *head=temp;
        p=*head;
      }
     else
     {
         while(p->next)
         p=p->next;
        p->next=temp;
     }
}
void insert1(struct lol** head,int k)
{
    struct lol* p;
    p=*head;
    for(int i=0;i<k;i++)
    {
        struct lol* temp=(struct lol*)(malloc(sizeof(struct lol)));
        temp->imp=0;
        temp->data=NULL;
        temp->next=NULL;
       if((*head)==NULL)
       {
        (*head)=temp;
        p=(*head);
       }
       else
       {
      p->next=temp;
      p=p->next;
       }
    }
}
void print(struct ll** a)
{
    struct ll* node;
    node=*a;
    while(node)
    {
        printf("%d ",node->data);
        node=node->next;
    }
    printf("\n");
}

void print2(struct lol** a)
{
    struct lol* node;
    node=*a;
    while(node)
    {
        printf("%d ",node->imp);
        node=node->next;
    }
    printf("\n");
}
void find(struct lol** a,int value)
{
    struct lol* node;
    struct ll** p;
    int  *q;
    node=*a;
    int imp=INT_MAX;
    while(node)
    {
         if((node->imp)<imp)
         {
             p=&(node->data);
             imp=node->imp;
             q=&(node->imp);
         }
        node=node->next;
    }
    insertn(p,value);
    (*q)+=value;
    /*node=*a;
    while(node)
    {
         if((node->imp)==imp)
         {
             (node->imp)+=value;
             insertn(&(node->data),value);
             return;
         }
        node=node->next;
    }*/
   // print(&node1);
}
void print1(struct lol** a)
{
    struct lol* node;
    node=*a;
    struct ll* node1;
    while(node!=NULL)
    {
        node1=node->data;
        while(node1!=NULL)
        {
          printf("%d ",(node1->data));
          node1=node1->next;
        }
        printf("\n");
        node=node->next;
    }
}
int main()
{
    int t,n,val,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        struct lol* hlol=NULL;
        insert1(&hlol,k);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&val);
            find(&hlol,val);
        }
        print1(&hlol);
        //printf("\n");
     }
}
