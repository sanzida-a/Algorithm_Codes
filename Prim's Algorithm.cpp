#include<stdio.h>
#include<conio.h>
using namespace std;

int v[10],w[10][10],nw[10][10],pq[10],nV;
#define INF 1000

int cut(int i,int n1)
{
	int j;
	for(j=0;j<=n1;j++)
		if(pq[j]==i)
			return 1;
	return 0;
}
void tree()
{
	int i=0,j,c=0,min,k,v1=0,v2=0;
	pq[0]=0;
	while(c<nV-1)
	{
		min=INF;
		for(i=0;i<=c;i++)
			for(j=0;j<nV;j++)
				if(w[pq[i]][j]<min && !cut(j,c))
				{
					min=w[pq[i]][j];
					v1=pq[i];
					v2=j;
				}
				nw[v1][v2]=nw[v2][v1]=min;
				c++;
				pq[c]=v2;
	}
}
void main()
{
	int i,j,ed,sum=0;
	printf("Enter the No. of Nodes : ");
	scanf_s("%d",&nV);
	for(i=0;i<nV;i++)
	{
		v[i]=i+1;
		for(j=0;j<nV;j++)
		{
			w[i][j]=INF;
			nw[i][j]=INF;
		}
	}
	for(i=0;i<nV;i++)
		for(j=0;j<nV;j++)
		{
			printf("\n%d---%d : ",v[i],v[j]);
			scanf_s("%d",&ed);
			if(ed>=1)
				w[i][j]=w[j][i]=ed;
		}
		tree();
		printf("\nMinimum Spanning tree");
		for(i=0;i<nV;i++)
			for(j=i+1;j<nV;j++)
				if(nw[i][j]!=INF)
				{
					printf("\n%d---%d = %d ",v[i],v[j],nw[i][j]);
					sum+=nw[i][j];
				}
				printf("\nTotal Weight : %d ",sum);
				_getch();
}
