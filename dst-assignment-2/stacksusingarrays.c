/*Program a stack of integers. The stack should be implemented by using arrays.

Input Format: The first input is the number of test cases. Thereafter each test case starts with n, the number of inputs. Thereafter, each test case starts with n, the number of commands and s, the maximum stack size (the maximum number of elements that can be stored in the stack at any point of time). Thereafter, each of the following n lines have commands “push a” meaning push integer a in the stack; “pop” meaning pop an item from the stack and print on the screen; and “top”, meaning print the element at the top of the stack on the screen.

An attempt to add an element in an already full stack gives a “stack overflow” error printed on the screen. An attempt to pop or access an element in an already empty stack gives a “stack underflow” error printed on the screen.

Output Format: As above
SAMPLE INPUT
1
6 2
push 1
push 2
push 3
pop
pop
top
SAMPLE OUTPUT
stack overflow
2
1
stack underflow*/
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
