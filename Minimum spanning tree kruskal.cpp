#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int parent[9];
int findset(int i)
{
	while(parent[i])
		i=parent[i];
	return i;
}
int unionset(int u,int v)
{
	if(u!=v)
	{
		parent[v]=u;
		return 1;
	}
	return 0;
}
void main()
{
	int i,j,k,a,b,u,v,totaledge,x=1,min,minweight=0,w[15][15];
	printf("Enter the number of nodes....");
	scanf_s("%d",&totaledge);
	printf("\nEnter the weight of each adjacency vertex:\n");
	for(i=1;i<=totaledge;i++)
	{
		for(j=1;j<=totaledge;j++)
		{
			scanf_s("%d",&w[i][j]);
			if(w[i][j]==0)
				w[i][j]=999;
		}
	}
	printf("The edges of Minimum Spanning Tree are\n");
	while(x<totaledge)
	{
		min=999;
		for(i=1;i<=totaledge;i++)
		{
			for(j=1;j<=totaledge;j++)
			{
				if(w[i][j] < min)
				{
					min=w[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=findset(u);
		v=findset(v);
		if(unionset(u,v))
		{
			printf("%d,%d edge = %d\n",x++,a,b,min);
			minweight=minweight+min;
		}
		w[a][b]=w[b][a]=999;
	}
	printf("\nMinimum spanning tree weight = %d.",minweight);
	_getch();
}
