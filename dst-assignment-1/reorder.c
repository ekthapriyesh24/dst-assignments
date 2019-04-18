/*Given n elements, inserted in the same order at the end of the linked list. You are also given another n integers called order, bearing a permutations of the sequence [0, 1, 2, 3, 4. … n-1]. Reorder the linked list as per the order. Print the new linked list. Consider the original linked list is X=23-> 64->16-> 86]. Suppose the order = [3, 1, 2, 0]. This means the new linked list with have the 3rd element (86), followed by 1st element (64), followed by 2nd element (16), followed by 0th element (23), that is 86->64->16->23. Note: you must store order as a separate linked list and not an array.

Input format: Number of test cases. Each test case followed by the number of elements (n), the list of elements and order. 

Output format: For each test case 1 line with all the elements separated by a space.
SAMPLE INPUT
2
3
4 6 3
2 1 0
5
1 4 2 1 4
3 1 0 2 4
SAMPLE OUTPUT
3 6 4 
1 4 1 2 4*/ 
#include<stdio.h>
#include<limits.h>
struct s
{
    int data;
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
        struct s *head,*prev,*preve,*x,*heade,*heado,*prevo;
        head=NULL;
        prev=NULL;
        preve=NULL;
        heade=NULL;
        prevo=NULL;
        heado=NULL;
        int i1=0,i2=0,i3=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&val);
            if(i1==i2 && i2==i3)
            {
            insert(&head,&prev,val);
            i1+=val;
            }
            else if(i1==i2)
            {
                if(i3<i1)
                {
                insert(&heado,&prevo,val);
                i3+=val;
                }
                else
                {
                insert(&head,&prev,val);
                i1+=val;
                }
            }
            else if(i2==i3)
            {
                if(i3<i1)
                {
                insert(&heade,&preve,val);
                i2+=val;
                }
                else
                {
                insert(&head,&prev,val);
                i1+=val;
                }

            }
            else if(i1==i3)
            {
                if(i3<i2)
                {
                insert(&head,&prev,val);
                i1+=val;
                }
                else
                {
                insert(&heade,&preve,val);
                i2+=val;
                }
            }
            else if(i1<i2 && i1<i3)
            {
                insert(&head,&prev,val);
                i1+=val;
            }
            else if(i2<i1 && i2<i3)
            {
                insert(&heade,&preve,val);
                i2+=val;
            }
            else if(i3<i1 && i3<i2)
            {
                insert(&heado,&prevo,val);
                i3+=val;
            }
        }

        print(&head);
        print(&heade);
        print(&heado);
    }
}
