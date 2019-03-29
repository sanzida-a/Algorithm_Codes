#include<stdio.h>
#include<conio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int a,b,i,tm,count=0;
	vector<int> v1;
	vector<int> v2;
	printf("Enter the size of both array\n");
	scanf_s("%d %d",&a,&b);
	for(i=0;i<a;i++)
	{
		scanf_s("%d",&tm);
		v1.push_back(tm);
	}
	for(i=0;i<a;i++)
	{
		scanf_s("%d",&tm);
		v2.push_back(tm);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	if(a!=b){
		printf("not same");
	}
	else{
	for(i=0;i<a;i++)
	{
		if(v1[i]==v2[i])
			count++;
	
	}
	}
	if(count==a)
		printf("same");
	else
		printf("not same");
	_getch();
	return 0;
	}
	


