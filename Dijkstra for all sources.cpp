#include<stdio.h>
#include<conio.h>
#define INF 9999
int main()
{
	int i,j,nV,s,graph[20][20],w[20][20],d[20],p[20],pq[20],c,min,v;
	printf("Enter the num of vertices:");
	scanf("%d",&nV);
	printf("\nAdjacency matrix:\n");

	for(i=0;i<nV;i++)
		for(j=0;j<nV;j++)
			scanf("%d",&graph[i][j]);
	for(i=0;i<nV;i++)
		for(j=0;j<nV;j++)
			if(graph[i][j]==0)
				w[i][j]=INF;
			else
				w[i][j]=graph[i][j];
	for(s=0;s<nV;s++)
    {
        printf("\nFor sourse %d\n",s);
	for(i=0;i<nV;i++)
	{
		d[i]=w[s][i];
		p[i]=s;
		pq[i]=0;
	}

	d[s]=0;
	pq[s]=1;
	c=1;

	while(c<nV-1)
	{
		min=INF;
		for(i=0;i<nV;i++)
			if(d[i]<min && !pq[i])
			{
				min=d[i];
				v=i;
			}

			pq[v]=1;
			for(i=0;i<nV;i++)
				if(!pq[i])
					if(min+w[v][i]<d[i])
					{
						d[i]=min+w[v][i];
						p[i]=v;
					}
					c++;
	}
	for(i=0;i<nV;i++)
		if(i!=s)
		{
			printf("\nNode's distance %d = %d\nPath = %d ",i,d[i],i);
			j=i;
			while(j!=s){
				j=p[j];
				printf("<-%d ",j);
			}
		}
    }
		_getch();
		return 0;
}
