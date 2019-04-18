/*Given n elements, inserted in the same order at the end of the linked list. Delete the largest integer in the linked list and move it to a new linked list. Do this n times, at each iteration, moving the largest integer at the rear of the new linked list. Print the new linked list.

Input format: Number of test cases. Each test case followed by the number of elements (n) and the list of elements.

Output format: For each test case 1 line with all the elements separated by a space.
SAMPLE INPUT
2
3
4 6 3
5
1 4 2 1 4
SAMPLE OUTPUT
6 4 3 
4 4 2 1 1 */
#include<stdio.h>
#include<limits.h>
struct s
{
    int data;
    struct s *next;
};
void del(struct s** a,int value)
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
}
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

int find(struct s** a)
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
}
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
            insert(&head,&prev,val);
        }
        //print(&head);
        x=head;
        while(head)
        {
            max=find(&head);
            insert(&heade,&preve,max);
        }
        print(&heade);
    }
}
