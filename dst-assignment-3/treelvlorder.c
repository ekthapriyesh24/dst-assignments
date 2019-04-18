/*Use the following sequence/node values:
19, 22, 13, 7, 24, 17, 11, 3, 39, 51 
1. Create a binary tree for the above node values and visit the tree in postorder sequence.*/
#include<stdio.h>
#include<stdlib.h>
#define ppd(x) printf("%d\n",x)
#define ch struct node*
struct node
{
	int data;
	ch left;
	ch right;
};
ch createnode(int i)
{
	ch temp=(ch)(malloc(sizeof(struct node)));
	temp->data=i;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void insert(ch* nn,int a[],int size,int i)//construct tree in level order
{
	if (i>=size)
	{
		return;
	}
	(*nn)=createnode(a[i]);
	insert(&((*nn)->left),a,size,2*i+1);
	insert(&((*nn)->right),a,size,2*i+2);
}
void postorder(ch* nn)//print in postorder
{
	if ((*nn)==NULL)
	{
		return;
	}
	postorder(&((*nn)->left));
	postorder(&((*nn)->right));
	ppd((*nn)->data);
}
int main()
{
	int a[10]={19, 22, 13, 7, 24, 17, 11, 3, 39, 51};
	ch nn=NULL;
	insert(&nn,a,10,0);
	postorder(&nn);
}
