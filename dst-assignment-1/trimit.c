/*Given n elements, inserted in the same order at the end of the linked list. Delete the first occurrence of the largest and the smallest element of the linked list. Print the linked list after deletions.

Input format: Number of test cases. Each test case followed by the number of elements (n) and the list of elements.

Output format: For each test case 1 line with all the elements separated by a space.
SAMPLE INPUT
2
3
4 6 3
5
1 4 2 1 4
SAMPLE OUTPUT
4 
2 1 4*/ 
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
void find(struct s** a,int *max,int *min)
{
    struct s* node=(struct s*)(malloc(sizeof(struct s)));
    node=*a;
    while(node)
    {
        if(node->data>*max)
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
}
int main()
{
    int t,n,val,sum;

    scanf("%d",&t);
    while(t--)
    {
        struct s* head=NULL;
        struct s* temp=NULL;
        struct s* x=NULL;
        head=(struct s*)(malloc(sizeof(struct s)));
        x=(struct s*)(malloc(sizeof(struct s)));
    	int max=INT_MIN,min=INT_MAX;
        scanf("%d",&n);
        scanf("%d",&val);
        head->data=val;
        head->next=NULL;
        //printf("y");
        x=head;
        for(int i=1;i<n;i++)
        {
            scanf("%d",&val);
            temp=(struct s*)(malloc(sizeof(struct s)));
            temp->data=val;
            temp->next=NULL;
            x->next=temp;
            x=x->next;
           // printf("y");
        }
        find(&head,&max,&min);
        //printf("%d",min);
        del(&head,&max);
        del(&head,&min);
        print(&head);
    }
}
