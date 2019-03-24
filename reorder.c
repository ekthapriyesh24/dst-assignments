#include<stdio.h>
#include<limits.h>
struct s
{
    int data;
    int index;
    struct s *next;
};
/*void del(struct s** a,int value)
{
    struct s* node=(struct s*)(malloc(sizeof(struct s)));
    struct s* temp=(struct s*)(malloc(sizeof(struct s)));
    node=*a;
    if(node)
    {
    if(node->data==value)
    {
        *a=node->next;
        return;
    }
    else
    {
    while(node)
    {
        if((node->next)->data==value)
        {
            temp=node->next;
            node->next=temp->next;
            free(temp);
            break;
        }
        node=node->next;
    }
    }
    }
}*/
void print(struct s** a,int index)
{
    struct s* node=(struct s*)(malloc(sizeof(struct s)));
    node=*a;
    while(node)
    {
        if(node->index==index)
        {
        printf("%d ",node->data);
        break;
        }
        node=node->next;
    }
}

/*int find(struct s** a)
{
    int max=INT_MIN;
    struct s* node=(struct s*)(malloc(sizeof(struct s)));
    node=*a;
    while(node)
    {
        if(node->data>max)
        {
            max=node->data;
        }
        node=node->next;
    }
    del(a,max);
    return max;
}*/
struct s* insert(struct s** head,struct s** prev,int val,int i)
{
    struct s* temp=(struct s*)(malloc(sizeof(struct s)));
    temp->data=val;
    temp->index=i;
    temp->next=NULL;
    if(*head==NULL)
    {
      *head=temp;
    }
    else
    {
      (*prev)->next=temp;
    }
    (*prev)=temp;
}
int main()
{
    int t,n,val,sum,max;

    scanf("%d",&t);
    while(t--)
    {
        struct s *head,*prev,*preve,*x,*heade;
        head=NULL;
        prev=NULL;
        preve=NULL;
        heade=NULL;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&val);
            insert(&head,&prev,val,i);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&val);
            insert(&heade,&preve,val,i);
        }
        //print(&head);
        x=heade;
        while(x)
        {
            print(&head,x->data);
            x=x->next;
        }
        printf("\n");
    }
}
