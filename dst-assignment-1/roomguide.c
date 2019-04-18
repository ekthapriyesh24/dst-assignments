/*In a university, the students have roll number of the form abcpqrsxyz, where abc is the branch and level of study, pqrs is the year of entry and xyz is the numeric roll number (may be 0 prefixed). The students are outside CC-III and enter one by one. There are k classrooms. Each classroom has a number of prefixes (abcpqrs) whose student should occupy the classroom. Print the list of students in every classroom, in the order of classroom as per question and in the order of students they enter CC-III. Use an array of linked lists.

Input Format: The first input is the number of test cases. Thereafter, each test case starts with the number of students (n) and the number of classrooms (k). The next k lines state the number of prefixes and the list of prefixes associated with the k classrooms. The next line prints the list of all students.

Output Format: k lines, each stating the list of students in the classroom in the order they enter CC-III

SAMPLE INPUT
1
15 4
2 IIT2018 IEC2018
1 IIT2017
1 IEC2017
2 MIT2018 IIT2016
IIT2018021 IIT2016112 IEC2018025 IIT2016005 IIT2018001 IIT2017121 IEC2017125 MIT2018001 MIT2018021 IIT2017011 IEC2017005 MIT2018032 MIT2018011 IEC2018012 IIT2016002
SAMPLE OUTPUT
IIT2018021 IEC2018025 IIT2018001 IEC2018012 
IIT2017121 IIT2017011 
IEC2017125 IEC2017005 
IIT2016112 IIT2016005 MIT2018001 MIT2018021 MIT2018032 MIT2018011 IIT2016002 */
#include<stdio.h>
#include<string.h>
#include<limits.h>
#define pp(x) printf("%s\n",x)
struct ll
{
    char data[20];
    struct ll *next;
};
struct lol
{
    struct ll *sec;
    struct ll *roll;
    struct lol *next;
};
void insert(struct ll** head,int n)
{
    struct ll* p;
    p=*head;
    for(int i=0;i<n;i++)
    {
        struct ll* temp=(struct ll*)(malloc(sizeof(struct ll)));
        scanf("%s",temp->data);
        temp->next=NULL;
      if((*head)==NULL)
      {
        *head=temp;
        p=*head;
      }
     else
     {
        p->next=temp;
        p=p->next;
     }
    }
}
void insertn(struct ll** head,char ch[])
{
    struct ll* p;
    p=*head;
    struct ll* temp=(struct ll*)(malloc(sizeof(struct ll)));
    strcpy(temp->data,ch);
    temp->next=NULL;
      if((*head)==NULL)
      {
        *head=temp;
        p=*head;
      }
     else
     {
         while(p->next)
         p=p->next;
        p->next=temp;
     }
}
void insert1(struct lol** head,int l)
{
    struct lol* temp=(struct lol*)(malloc(sizeof(struct lol)));
    struct ll* sec=NULL;
    insert(&sec,l);
    temp->sec=sec;
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
        printf("%s",node->data);
        node=node->next;
    }
    printf("\n");
}
/*
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
*/
void find(struct lol** a)
{
    int i;
    char roll[20],sec[20];
    scanf("%s",roll);
    for(i=0;i<7;i++)
    sec[i]=roll[i];
    sec[i]='\0';
    struct lol* node=(struct lol*)(malloc(sizeof(struct lol)));
    node=*a;
    while(node)
    {
        struct ll* node1=node->sec;
        while(node1)
        {
         if(!(strcmp(sec,node1->data)))
         {
            //pp(node1->data);
            insertn(&(node->roll),roll);
            return;
         }
         node1=node1->next;
        }
        node=node->next;
    }
}
void print1(struct lol** a)
{
    struct lol* node;
    node=*a;
    struct ll* node1;
    while(node!=NULL)
    {
        node1=node->roll;
        while(node1!=NULL)
        {
          printf("%s ",(node1->data));
          node1=node1->next;
        }
        printf("\n");
        node=node->next;
    }
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
        for(i=0;i<k;i++)
        {
            int l;
            scanf("%d",&l);
            insert1(&hlol,l);
        }
        for(i=0;i<n;i++)
        {
            find(&hlol);
        }
        print1(&hlol);
        //printf("\n");
    }
}
