#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
void maxHeapify(int a[],int i,int n)
{
	int l,r,min;
    l=(2*i)+1;
	r=(2*i)+2;
	if(l<n && a[l]<a[i])
	    min=l;
	else
		min=i;
	if(r<n && a[r]<a[min])
	   min=r;
	if(min!=i)
	{
		swap(a[i],a[min]);
		maxHeapify(a,min,n);
	}
}
void buildheap(int a[],int n)
{
	int i;
	for( i=(n/2)-1;i>=0;i--)
	{
		maxHeapify(a,i,n);
	}
}
int main()
{
	int a[50],n,i,temp,heapsize;
	scanf_s("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf_s("%d",&a[i]);
	}
	buildheap(a,n);
	for(i=n-1;i>=0;i--)
	{
		swap(a[i],a[0]);
		maxHeapify(a,0,i);
	}
	for(i=0;i<n;i++)
	{
		printf("%d \n",a[i]);
	}
	_getch();
	return 0;
}


