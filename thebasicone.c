#include<stdio.h>
struct s
{
    int data;
    struct s *next;
};
/*void print(struct s** a)
{
    struct s* node=(struct s*)(malloc(sizeof(struct s)));
    node=*a;
    int sum=0;
    while(!node)
    {
        printf("%d ",node->data);
        sum+=node->data;
        node=node->next;
    }
    printf("\n%d",sum);
}*/
int main()
{  //priyesh...........






    int t,n,val,sum;
    struct s* head=NULL;
    struct s* temp=NULL;
    struct s* x=NULL;
    head=(struct s*)(malloc(sizeof(struct s)));
    x=(struct s*)(malloc(sizeof(struct s)));
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d",&val);
        head->data=val;
        head->next=NULL;
        x=head;
        for(int i=1;i<n;i++)
        {   //priyesh.....






            scanf("%d",&val);
            temp=(struct s*)(malloc(sizeof(struct s)));
            temp->data=val;
            temp->next=NULL;
            x->next=temp;
            x=x->next;
            //printf("%d ",x->data);
        }
        x=head;
        sum=0;
        //printf("%dy",x->data);
        while(x)
    {
        printf("%d ",x->data);
        sum+=x->data;
        x=x->next;
    }
    printf("%d\n",sum);
        //print(&head);






        // oh priyesh......







    }
}
