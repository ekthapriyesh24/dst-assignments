/*Sort an array of integers using 2 stacks only.

Input format: The first input is the number of test cases. Thereafter, each test case starts with n, the number of inputs, followed by n integers in a single line.

Output Format: For every input 1 line, the list of integers in a single line.

SAMPLE INPUT
1
7
7 4 9 7 2 5 1
SAMPLE OUTPUT
1 2 4 5 7 7 9*/
#include<stdio.h>
#include<stdlib.h>
#define ppd(x) printf("%d\n",x)
#define ppc(x) printf("%c ",x)
#define pp(x) printf("%s\n",x)
#define scd(x) scanf("%d",&x)
#define sc(x) scanf("%s",x)
#define lol struct ope* 
#define lola struct v* 
struct ope
{
    char data;
    lol next;
};
struct v
{
    int data;
    lola next;
};
lol createo(char n)
{
    lol a=(lol)(malloc(sizeof(struct ope)));
    a->data=n;
    a->next=NULL;
    return a;
}
char popo(lol* h)
{
    if(*h==NULL)
    {
        return 'n';
    }
    else
    {
        char temp;
        temp=(*h)->data;
        (*h)=(*h)->next;
        return (temp);
    }
}
char topo(lol* h)
{
    if(*h==NULL)
    {
        return 'n';
    }
    else
    {
        return ((*h)->data);
    }
}
void pusho(lol* h,char x)
{
    lol temp=createo(x);
    temp->next=(*h);
    (*h)=temp;
}
lola createv(int n)
{
    lola a=(lola)(malloc(sizeof(struct v)));
    a->data=n;
    a->next=NULL;
    return a;
}
int popv(lola* h)
{
    if(*h==NULL)
    {
        return -1;//check
    }
    else
    {
        int temp;
        temp=(*h)->data;
        (*h)=(*h)->next;
        return (temp);
    }
}
int topv(lola* h)
{
    if(*h==NULL)
    {
        return -1;
    }
    else
    {
        return ((*h)->data);
    }
}
void pushv(lola* h,int x)
{
    lola temp=createv(x);
    temp->next=(*h);
    (*h)=temp;
}
int num(int i,char ch[],lola* v)
{
    int l=strlen(ch);
    int k=1,d=0,ctr=0,z=i;
    while(ch[z]>='0' && ch[z]<='9' && z<l)
    {
        ctr++;
        z++;
    }
    k=pow(10,ctr-1);
    while(ch[i]>='0' && ch[i]<='9' && i<l)
    {
        d+=(ch[i]-'0')*k;
        k=k/10;
        i++;
    }
    pushv(v,d);
    return i;
}
int operate(char ch,int a,int b)
{
    switch(ch)
    {
        case '+':return (b+a);
        case '-':return (b-a);
        case '*':return (b*a);
        case '/':return (b/a);
    }
}
int pre(char a,char b)
{
    if(b=='(')
    {
        return -1;
    }
    else if(b=='*' || b=='/')
    {
        return 0;
    }
    else if(a=='*' || a=='/')
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int t,n,x,d,k;
    char ch[200];
    scd(t);
    while(t--)
    {
        sc(ch);
        int l=strlen(ch);
        lola v=NULL;
        lol o=NULL;
        for(int i=0;i<l;i++)
        {
            if(ch[i]>='0' && ch[i]<='9')
            {
               i=num(i,ch,&v);
               i--;
            }
            else if(ch[i]=='(')
            {
                pusho(&o,ch[i]);
            }
            else if(ch[i]==')')
            {
                while(topo(&o)!='(' && topo(&o)!='n')
                {
                    char op=popo(&o);
                    //printf("%c",topo(&o));
                    int a=popv(&v);
                    int b=popv(&v);
                    pushv(&v,operate(op,a,b));
                }
                char x=popo(&o);
            }
            else
            {
                while(topo(&o)!='n' && (pre(ch[i],topo(&o))==0))
                {
                    char op=popo(&o);
                    //ppc(op);
                    int a=popv(&v);
                    int b=popv(&v);
                    pushv(&v,operate(op,a,b));
                }
                pusho(&o,ch[i]);
            }
        }
        while(topo(&o)!='n')
        {
           char op=popo(&o);
           int a=popv(&v);
           int b=popv(&v);
           //printf("%d",b);
           pushv(&v,operate(op,a,b)); 
        }
        ppd(topv(&v));
    }
}
