#include<stdio.h>
#include<conio.h>
#include<vector>
#include<limits.h>
int arr[100];  
using namespace std;

int maxOverlapSum(int,int,int);
int maxSum(int,int);
int maxOverlapSum(int f,int m,int l)
{
	int m1=-9999999,m2=-999999,s=0,i,j;
	for(i=m;i>=f;i--)
	{
		s=s+arr[i];
		m1=max(m1,s);
	}
	s=0;
	for(j=m+1;j<=l;j++)
	{
		s=s+arr[j];
		m2=max(m2,s);
	}
	return m1+m2;
}
int maxSum(int f,int l)
{
	int mid,lmax,rmax,overlap;
	if(f==l){
		return arr[f];
	}
	else
	{
		
		mid=(f+l)/2;
		lmax=maxSum(f,mid);
		rmax=maxSum(mid+1,l);
		overlap=maxOverlapSum(f,mid,l);
		return max(max(lmax,rmax),overlap);
	}
	
}
int main()
{
	int i,n;
	scanf_s("%d", &n);
    for (i = 0;i<n;i++)
	{
		scanf_s("%d", &arr[i]);
	}
	int o=maxSum(0,n-1);
	printf("%d",o);
	_getch();
	return 0;
}


