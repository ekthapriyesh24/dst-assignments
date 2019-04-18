/*Instructions are given to your program, which are of 3 types. “add 3 4 5 3” means “add” a new linked list with 3 elements, namely 4 5 3 to the end of the “linked list of linked lists”. “delete 3” means delete the first occurrence of 3 in the “linked list of linked lists” and “print”, which means print the linked list of linked lists, 1 linked list at every line in a space separated format.

Input Format: The first line is the number of test cases. Each test case starts with n, the number of commands, followed by n commands.  

SAMPLE INPUT
1
8
add 4 1 4 6 2
add 2 13 12
add 3 8 10 2
print
delete 4
delete 10
delete 8
print 
SAMPLE OUTPUT
1 4 6 2 
13 12 
8 10 2 
1 6 2 
13 12 
2*/ 
#include<stdio.h>
#include<limits.h>
struct ll
{
    int data;
    struct ll *next;
};
struct lol
{
    struct ll *data;
    struct lol *next;
};
int del(struct ll** a,int value)
{
    struct ll* node=(struct ll*)(malloc(sizeof(struct ll)));
    struct ll* temp=*a,*prev;
    node=*a;
    if(temp!=NULL && temp->data==value)
    {
        *a=temp->next;
        free(temp);
        return -1;
    }
    while(temp!=NULL && temp->data!=value)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
    return 0;
    }
    prev->next=temp->next;
    free(temp);
    return -1;
}
void del1(struct lol** a,int value)
{
    int c=0;
    struct lol* node1=*a;
    while(node1 && c!=-1)
    {
        c=del(&(node1->data),value);
        node1=node1->next;
    }
}
void print1(struct lol** a)
{
    struct lol* node=(struct lol*)(malloc(sizeof(struct lol)));
    node=*a;
    struct ll* node1=(struct ll*)(malloc(sizeof(struct ll)));
    while(node)
    {
        node1=node->data;
        while(node1)
        {
        printf("%d ",node1->data);
        node1=node1->next;
        }
         printf("\n");
        node=node->next;
    }

}
void insert(struct ll** head,struct ll** prev,int val)
{
    struct ll* temp=(struct ll*)(malloc(sizeof(struct ll)));
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
void insert1(struct lol** head,struct lol** prev,struct ll** val)
{
    struct lol* temp=(struct lol*)(malloc(sizeof(struct lol)));
    temp->data=*val;
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
void print(struct ll** a)
{
    struct ll* node=(struct ll*)(malloc(sizeof(struct ll)));
    node=*a;
    while(node)
    {
        printf("%d ",node->data);
        node=node->next;
    }
    printf("\n");
}
int main()
{
    int t,n,val,i,j;
    char ch[6];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        struct lol *hlol=NULL;
        struct lol *plol=NULL;
        for(i=0;i<n;i++)
        {
        	struct ll *hl=NULL;
            struct ll *pl=NULL;
            int l;
            scanf("%s",ch);
            if(ch[0]=='a')
            {
            	scanf("%d",&l);
             for(j=0;j<l;j++)
             {
               scanf("%d",&val);
               insert(&hl,&pl,val);
             }
             insert1(&hlol,&plol,&hl);
            }
            else if(ch[0]=='p')
            {
                print1(&hlol);
            }

            else if(ch[0]=='d')
            {
                scanf("%d",&val);
                del1(&hlol,val);
            }
        }
      //  h-data
    }
}
