#include<stdio.h>
#include<conio.h>
#include<algorithm>
using namespace std;
struct Product{
	double b;
	double w;
	double v;
};
bool compare(Product p1,Product p2)
{
	if(p1.v>p2.v)
	{
		return true;
	}
	else 
		return false;
}
int main()
{
	Product p[100];
	int n,i,f,t;
	double w,b,v;
	scanf_s("%d",&n);
	int des[50];
	for(i=0;i<n;i++)
	{
		
		scanf_s("%lf",&w);
		scanf_s("%lf",&b);
		p[i].w=w;
		p[i].b=b;
		p[i].v=b/w;
	}
	sort(p,p+n,compare);
	int ksack;
	scanf_s("%d",&ksack);
		for(i=0;i<n;i++)
	{
		printf("%lf %lf %lf\n", p[i].w, p[i].b, p[i].v);
	}
    f=0,t=0;
	i=0;

	while(f<ksack && i<n)
	{
		if(p[i].w<(ksack-f)){
        t=t+p[i].b;
		f=f+p[i].w;
		printf("%d - %lf - %lf\n",i+1,p[i].w,p[i].b);
		}
		else{
			printf("%d - %lf- %lf\n",i+1,((ksack-f)/p[i].w),p[i].b/((ksack-f)/p[i].w));
			f=f+(ksack-f);
			t=t+((ksack-f)*p[i].v);
			
		}
		i++;
	}


	_getch();
	return 0;
}