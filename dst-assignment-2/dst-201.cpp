#include<stdio.h>
#include<stdlib.h>
#define ppd(x) printf("%d\n",x)
#define pp(x) printf("%s\n",x)
#define scd(x) scanf("%d",&x)
#define sc(x) scanf("%s",x)
#define lol struct s* 
struct s
{
    int capacity;
    int top;
    int *data;
};
lol create(int n)
{
    lol a=(lol)(malloc(sizeof(struct s)));
    a->top=-1;
    a->data=(int*)(malloc(sizeof(int)*n));
    a->capacity=n;
    return a;
}
void pop(lol h)
{
    if(h->top==(-1))
    {
        pp("stack underflow");
    }
    else
    {
        ppd((h->data)[(h->top)--]);
    }
}
void top(lol h)
{
    if(h->top==(-1))
    {
        pp("stack underflow");
    }
    else
    {
        ppd((h->data)[(h->top)]);
    }
}
void push(lol h,int x)
{
    if(h->top==(h->capacity-1))
    {
        pp("stack overflow");
    }
    else
    {
        (h->data)[++(h->top)]=x;
    }
}
int main()
{
    int t,n,k,x;
    char ch[10];
    scd(t);
    while(t--)
    {
        scd(n);
        scd(k);
        lol h=create(k);
        for(int i=0;i<n;i++)
        {
            sc(ch);
            if(ch[1]=='u')
            {
                scd(x);
                push(h,x);
            }
            else if(ch[0]=='p')
            {
                pop(h);
            }
            else
            {
                top(h);
            }
            //ppd((h->data)[h->top]);
        }
    }
}
