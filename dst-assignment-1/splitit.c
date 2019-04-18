/*Given n elements, inserted in the same order at the end of the linked list. Split the linked list into 2 linked lists, first with all even numbers and the second with all odd numbers. Join the even numbered linked list after the odd numbered linked list. Print the resultant linked list.

Input format: Number of test cases. Each test case followed by the number of elements (n) and the list of elements.

Output format: For each test case 1 line with all the elements separated by a space.
SAMPLE INPUT
2
3
4 6 3
5
1 4 2 1 4
SAMPLE OUTPUT
3 4 6 
1 1 4 2 4 */
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
