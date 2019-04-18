/*Use the following sequence/node values:
19, 22, 13, 7, 24, 17, 11, 3, 39, 51 
2. a. Create the BST for the above sequence and find the element 4.
b. Visit the BST in inorder sequence.*/
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
void insert(ch* nn,int i)//store in bst
{
	if ((*nn)==NULL)
	{
		(*nn)=createnode(i);
	}
	else if (((*nn)->data)>i)
	{
		insert(&((*nn)->left),i);
	}
	else
	{
		insert(&((*nn)->right),i);	
	}
}
int search(ch* nn,int x)
{
	if ((*nn)==NULL)
	{
		return 0;
	}
	else if ((*nn)->data==x)
	{
		return 1;
	}
	if (((*nn)->data)>x)
	{
		return search(&((*nn)->left),x);
	}
	else
	{
		return search(&((*nn)->right),x);	
	}
}
void inorder(ch* nn)//print in inorder
{
	if ((*nn)==NULL)
	{
		return;
	}
	inorder(&((*nn)->left));
	ppd((*nn)->data);
	inorder(&((*nn)->right));
}
int main()
{
	int a[10]={19, 22, 13, 7, 24, 17, 11, 3, 39, 51};
	ch nn=NULL;
	for (int i=0;i<10;++i)
	{
		insert(&nn,a[i]);	
	}
	int v=search(&nn,4);
	if (v)
	{
		printf("Found\n");
	}
	else
	{
		printf("Not Found\n");
	}
	inorder(&nn);
}