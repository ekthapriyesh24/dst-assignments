#include<stdio.h>
#include<limits.h>
struct s
{
    int data;
    struct s *next;
};
void print(struct s** a)
{
    struct s* node=(struct s*)(malloc(sizeof(struct s)));
    node=*a;
    while(node)
    {
        printf("%d ",node->data);
        node=node->next;
    }
    printf("\n");
}
/*
void find(struct s** a,struct s** b,struct s** c)
{
    struct s* node=(struct s*)(malloc(sizeof(struct s)));
    node=*a;
    while(node)
    {
        if(node->data%2==0)
        {
            *max=node->data;
        }
        if(node->data<*min)
        {
            *min=node->data;
        }
        node=node->next;
    }
}

void del(struct s** a,int *value)
{
    struct s* node=(struct s*)(malloc(sizeof(struct s)));
    struct s* temp=(struct s*)(malloc(sizeof(struct s)));
    node=*a;
    if(node)
    {
    if(node->data==*value)
    {
        *a=node->next;
        return;
    }
    else
    {
    while(node)
    {
        if((node->next)->data==*value)
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
struct s* insert(struct s** head,struct s** prev,int val)
{
    struct s* temp=(struct s*)(malloc(sizeof(struct s)));
    temp->data=val;
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
    int t,n,val,sum;

    scanf("%d",&t);
    while(t--)
    {
        struct s *head,*prev,*preve,*prevo,*x,*heade,*heado;
        head=NULL;
        prev=NULL;
        preve=NULL;
        prevo=NULL;
        heade=NULL;
        heado=NULL;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&val);
            insert(&head,&prev,val);
        }
        //print(&head);
        x=head;
        while(x)
        {
            if(x->data%2==0)
            {
                insert(&heade,&preve,x->data);
            }
            else
            {
                insert(&heado,&prevo,x->data);
            }
            x=x->next;
        }
        //print(&heado);
        x=heade;
        while(x)
        {
            insert(&heado,&prevo,x->data);
            x=x->next;
        }
        print(&heado);
    }
}
