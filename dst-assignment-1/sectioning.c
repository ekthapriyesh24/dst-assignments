/*In a university, the students have integer roll numbers. The roll number denotes the importance of the student. The students need to be divided into 3 sections, such that the total importance of the section (sum of the importances of all students in the section) is the same. This will be done in a greedy manner. The students come one by one, and every student is directed to the section which has the least importance (sum of all roll numbers) so far. In case of a tie, preferences are section A, followed by section B, followed by section C.

Input format: Number of test cases. Each test case followed by the number of elements (n), the list of elements and order. 

Output format: For each test case 3 lines, first printing section A students, 2nd printing section B students and 3rd printing section C students.
SAMPLE INPUT
2
6
7 8 3 1 4 9 
8
4 11 8 15 3 1 6 13
SAMPLE OUTPUT
7 9 
8 
3 1 4 
4 15 
11 1 13 
8 3 6 */
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
