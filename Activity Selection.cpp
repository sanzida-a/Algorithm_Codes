#include<stdio.h>
#include<conio.h>
#include<algorithm>
using namespace std;
struct time{
	int s;
	int f;
};
bool compare(time t1,time t2)
{
	if(t1.f<t2.f)
	{
		return true;
	}
	else 
		return false;
}
void activity(int start[],int finish[],int n)
{
	int check=0;
	check= finish[0];
	printf("Taken activities are:\n");
    printf("%d to %d\n",start[0],finish[0]);
    for(int i=1;i<n;i++)
    {
        if(check<=start[i])
        {
            printf("%d to %d\n",start[i],finish[i]);
            check=finish[i];
        }
    }

}
int main()
{
	time t[15];
	int n,i,s,f,st[15],fi[15];
	scanf_s("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf_s("%d %d",&s,&f);
		t[i].s=s;
		t[i].f=f;
	}
	sort(t,t+n,compare);
	for(i=0;i<n;i++)
	{
		st[i]=t[i].s;
		fi[i]=t[i].f;
		printf("%d--------%d\n",st[i],fi[i]);
	}
	 activity(st,fi,n);
	_getch();
	return 0;
}

