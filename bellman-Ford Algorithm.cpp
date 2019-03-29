#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
int bellman(int g[20][20],int nV,int E,int e[20][20])
{
    int i,u,v,k,d[20],p[20],s,flag=1;
    for(i=0;i<nV;i++)
        d[i] = 1000 ;
	    p[i] = -1 ;
 scanf("%d",&s);
    d[s-1]=0 ;
    for(i=0;i<nV-1;i++)
    {
        for(k=0;k<E;k++)
        {
            u = e[k][0] ;
			v = e[k][1] ;
            if(d[u]+g[u][v]<d[v])
                d[v] = d[u] + g[u][v] ;
			    p[v]=u ;
        }
    }
    for(k=0;k<E;k++){
        {
            u = e[k][0] ;
            v = e[k][1] ;
            if(d[u]+g[u][v]<d[v]){
                flag = 0 ;
            }
        }

        }
        if(flag==1){
            for(i=0;i<nV;i++)
                printf("Vertex %d ->  parent = %d\n",i+1,p[i]+1);
        }


     }


}
int main()
{
    int nV,e[20][20],g[20][20],i,j,k=0;
    printf("Enter no. of vertices: ");
    scanf("%d",&nV);
    printf("Enter graph in matrix form:\n");
    for(i=0;i<nV;i++)
        for(j=0;j<nV;j++)
        {
            scanf("%d",&g[i][j]);
            if(g[i][j]!=0)
                e[k][0]=i,
				e[k++][1]=j;
        }

    bellman(g,nV,k,e);
	_getch();
    return 0;
}



