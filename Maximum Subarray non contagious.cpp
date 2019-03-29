#include <cmath>
#include<conio.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<limits.h>
using namespace std;
long int arr[100];
long int maxOverlapSum(int f,int m,int l)
{
	int m1=INT_MIN,m2=INT_MIN,s=0,i,j;
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
long int maxSum(int f,int l)
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
long int maxsumNons(long int arr[],long int n){
	 long int sum3;
     long int sum1 = arr[0];
     long int sum2 = 0;
     for(int i = 1; i  < n; i++){
     
         sum3 = max(sum1,sum2);
         sum2 = sum3;
         sum1 = sum2 + arr[i];
     }
     return max(sum1, sum2);
 }
int main()
{
	int i,t,j=0;
	long int n;
	scanf_s("%d",&t);
	while(j<t){
	scanf_s("%ld", &n);
    for (i=0;i<n;i++)
	{
		scanf_s("%ld",&arr[i]);
	}
	if(n>0){
    long int o=maxSum(0,n-1);
	long int p=maxsumNons(arr,n);
	printf("%ld %ld",o,p);
	j++;
	}
	else{
		printf("Empty array");
	    break;
	}
	printf("\n");
	}
	_getch();
	return 0;
}
