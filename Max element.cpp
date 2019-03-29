#include <stdio.h>
#include<conio.h>
#include<algorithm>
#include<vector>
using namespace std;

int fun(int i, int n,int max,vector<int> a);
int main()
{
	int i, tm, n,max;
	vector<int> v;
	scanf_s("%d", &n);

	for (i = 0;i<n;i++)
	{
		scanf_s("%d", &tm);
		v.push_back(tm);
	}
	max = v[0];
	printf("max element : %d", fun(0, n, max, v));
	_getch();
	return 0;
}


int fun(int i, int n,int max, vector<int> a)
{
	
	if(i<n){
		if (max<a[i]) 
			max = a[i];
		return fun(i + 1,n, max, a);
	}
	return max;
}

