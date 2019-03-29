#include <stdio.h>
#include<conio.h>
#include<algorithm>
#include<vector>
using namespace std;
int c = 0;
int fun(int i, int n, int key, vector<int> a);
int main()
{
	int i, tm, n,key;
	vector<int> v;
	scanf_s("%d", &n);

	for (i = 0;i<n;i++)
	{
		scanf_s("%d", &tm);
		v.push_back(tm);
	}
	scanf_s("%d", &key);
	printf("frequency of %d is : %d",key, fun(0, n, key, v));
	_getch();
	return 0;
}


int fun(int i, int n, int key, vector<int> a)
{
	if (i<n) {
		if (a[i] == key)
			c++;
		return fun(i + 1, n,key, a);
	}
	return c;
}

