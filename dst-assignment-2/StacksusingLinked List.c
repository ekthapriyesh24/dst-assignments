/*Stacks using Linked List
SAMPLE INPUT
1
6
push 1
push 2
push 3
pop
pop
top
SAMPLE OUTPUT
3
2
1*/
#include<stdio.h>
#include<stdlib.h>
#define ppd(x) printf("%d\n",x)
#define pp(x) printf("%s\n",x)
#define scd(x) scanf("%d",&x)
#define sc(x) scanf("%s",x)
#define lol struct s* 
struct s
{
    int data;
    lol next;
};
lol create(int n)
{
    lol a=(lol)(malloc(sizeof(struct s)));
    a->data=n;
    a->next=NULL;
    return a;
}
void pop(lol* h)
{
    if(*h==NULL)
    {
        pp("stack underflow");
    }
    else
    {
        lol temp;
        temp=*h;
        ppd((*h)->data);
        (*h)=(*h)->next;
        free(temp);
    }
}
void top(lol* h)
{
    if(*h==NULL)
    {
        pp("stack underflow");
    }
    else
    {
        ppd((*h)->data);
    }
}
void push(lol* h,int x)
{
    lol temp=create(x);
    temp->next=(*h);
    (*h)=temp;
}
int main()
{
    int t,n,x;
    char ch[10];
    scd(t);
    while(t--)
    {
        scd(n);
        lol h=NULL;
        for(int i=0;i<n;i++)
        {
            sc(ch);
            if(ch[1]=='u')
            {
                scd(x);
                push(&h,x);
            }
            else if(ch[0]=='p')
            {
                pop(&h);
            }
            else
            {
                top(&h);
            }
            //ppd((h->data)[h->top]);
        }
    }
}
