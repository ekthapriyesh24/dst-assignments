#include<stdio.h>
#include<string.h>
#include<limits.h>
#define pp(x) printf("%s\n",x)
struct ll
{
    char data[20];
    struct ll *next;
};
struct lol
{
    struct ll *sec;
    struct ll *roll;
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
void insertn(struct ll** head,char ch[])
{
    struct ll* p;
    p=*head;
    struct ll* temp=(struct ll*)(malloc(sizeof(struct ll)));
    strcpy(temp->data,ch);
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
void insert1(struct lol** head,int l)
{
    struct lol* temp=(struct lol*)(malloc(sizeof(struct lol)));
    struct ll* sec=NULL;
    insert(&sec,l);
    temp->sec=sec;
    temp->next=NULL;
    struct lol* p;
    p=*head;
    if((*head)==NULL)
    {
      (*head)=temp;
      return;
    }
    while(p->next!=NULL)
    {
      p=p->next;
    }
     p->next=temp;
}
void print(struct ll** a)
{
    struct ll* node;
    node=*a;
    while(node)
    {
        printf("%s",node->data);
        node=node->next;
    }
    printf("\n");
}
/*
void print2(struct lol** a)
{
    struct lol* node;
    node=*a;
    while(node)
    {
        printf("%s ",node->name);
        printf("%s ",node->roll);
        node=node->next;
    }
    printf("\n");
}
*/
void find(struct lol** a)
{
    int i;
    char roll[20],sec[20];
    scanf("%s",roll);
    for(i=0;i<7;i++)
    sec[i]=roll[i];
    sec[i]='\0';
    struct lol* node=(struct lol*)(malloc(sizeof(struct lol)));
    node=*a;
    while(node)
    {
        struct ll* node1=node->sec;
        while(node1)
        {
         if(!(strcmp(sec,node1->data)))
         {
            //pp(node1->data);
            insertn(&(node->roll),roll);
            return;
         }
         node1=node1->next;
        }
        node=node->next;
    }
}
void print1(struct lol** a)
{
    struct lol* node;
    node=*a;
    struct ll* node1;
    while(node!=NULL)
    {
        node1=node->roll;
        while(node1!=NULL)
        {
          printf("%s ",(node1->data));
          node1=node1->next;
        }
        printf("\n");
        node=node->next;
    }
}
int main()
{
    char ch[200];
    int t,n,val,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        struct lol* hlol=NULL;
        for(i=0;i<k;i++)
        {
            int l;
            scanf("%d",&l);
            insert1(&hlol,l);
        }
        for(i=0;i<n;i++)
        {
            find(&hlol);
        }
        print1(&hlol);
        //printf("\n");
    }
}
