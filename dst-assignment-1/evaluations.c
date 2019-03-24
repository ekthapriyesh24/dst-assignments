#include<stdio.h>
#include<string.h>
#include<limits.h>
struct ll
{
    int data;
    struct ll *next;
};
struct lol
{
    char roll[200];
    char name[200];
    struct ll *data;
    struct lol *next;
};
void insert(struct ll** head,int val)
{
    struct ll* temp=(struct ll*)(malloc(sizeof(struct ll)));
    temp->data=val;
    temp->next=NULL;
    struct ll* p;
    p=*head;
    if((*head)==NULL)
    {
      *head=temp;
     // printf("f");
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
      p->next=temp;
    }
}
void insert1(struct lol** head)
{
    struct lol* temp=(struct lol*)(malloc(sizeof(struct lol)));
    struct ll* hl=NULL;
    insert(&hl,-1);
   scanf("%s%s",temp->roll,temp->name);
    temp->data=hl;
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
        printf("%d",node->data);
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
        printf("%s ",node->name);
        printf("%s ",node->roll);
        node=node->next;
    }
    printf("\n");
}
void print1(struct lol** a)
{
    struct lol* node;
    node=*a;
    struct ll* node1;
    while(node!=NULL)
    {
        int sum=0;
        node1=node->data;
        printf("%s ",(node->roll));
        printf("%s ",(node->name));
        while(node1!=NULL)
        {
            if(node1->data!=-1)
            {
        printf("%d ",node1->data);
        sum+=node1->data;
            }
        node1=node1->next;
        }
        printf("%d\n",sum);
        node=node->next;
    }
}
struct ll* find(struct lol** a,char ch[])
{
    struct lol* node=(struct lol*)(malloc(sizeof(struct lol)));
    node=*a;
    while(node)
    {
        if(!(strcmp(ch,node->roll)))
        {
            return (node->data);
        }
        node=node->next;
    }
    return NULL;
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
        struct lol* plol=NULL;
        for(i=0;i<n;i++)
        {
            insert1(&hlol);
        }
        for(i=0;i<k;i++)
        {
            struct ll* hl=NULL;
            scanf("%s%d",ch,&val);
            hl=find(&hlol,ch);
            if(hl)
            insert(&hl,val);
        }
        print1(&hlol);
        //printf("\n");
    }
}
