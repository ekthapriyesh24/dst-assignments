/*Use the following sequence/node values:
19, 22, 13, 7, 24, 17, 11, 3, 39, 51 
3. Generate the Max Heap for the above sequence. Write the nodes of this heap in preorder sequence.*/
#include<stdio.h>
#include<stdlib.h>
#define ppd(x) printf("%d\n",x)
void swap(int a[],int k)
{
	int parent=(k-1)/2;
	if (parent<0)
	{
		return;
	}
	if (a[k]>a[parent])
	{
		int t=a[k];
		a[k]=a[parent];
		a[parent]=t;
		swap(a,parent);
	}
}
void insert(int a[],int size,int* parent,int* k,int x,int* c)//construct tree in level order
{
	if ((*k)==-2)//for 0th index
	{
		a[0]=x;
		(*k)=-1;
		(*c)++;
		return;
	}
	if ((*k)==-1)
	{
		(*k)=2*(*parent)+1;
		if ((*k)>=size)
		{
			return;
		}
		a[(*k)]=x;
		(*c)++;
		swap(a,*k);
		return;
	}
	if ((*k)==(2*(*parent)+1))
	{
		(*k)=(*k)+1;
		if ((*k)>=size)
		{
			return;
		}
		a[(*k)]=x;
		(*c)++;
		swap(a,*k);
		(*k)=-1;
		(*parent)=(*parent)+1;
	}
}
void preorder(int a[],int i,int c)//print in preorder
{
	if (i>=c)
	{
		return;
	}
	ppd(a[i]);
	preorder(a,2*i+1,c);
	preorder(a,2*i+2,c);
}
int main()
{
	int a[10];
	int parent=0,k=-2,c=0;
	insert(a,10,&parent,&k,19,&c);
	insert(a,10,&parent,&k,22,&c);
	insert(a,10,&parent,&k,13,&c);
	insert(a,10,&parent,&k,7,&c);
	insert(a,10,&parent,&k,24,&c);
	insert(a,10,&parent,&k,17,&c);
	insert(a,10,&parent,&k,11,&c);
	insert(a,10,&parent,&k,3,&c);
	insert(a,10,&parent,&k,39,&c);
	insert(a,10,&parent,&k,51,&c);
	preorder(a,0,c);
}