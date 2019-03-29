#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){

    int i, j, totalNode, totalEdge, p1, p2, w;
    int adjacncyMatrix[50][50];

    scanf("%d",&totalNode);
    scanf("%d",&totalEdge);

    for(i=0;i<=totalNode;i++){
        for(j=0;j<=totalNode;j++){
            adjacncyMatrix[i][j] = -1;
        }
    }

    for(i=0;i<totalEdge;i++){
        scanf("%d",&p1);
        scanf("%d",&p2);
        scanf("%d",&w);

        adjacncyMatrix[p1][p2] = w;
    }

    printf("Adjacency Matrix:\n");

    for(i=1;i<=totalNode;i++){
        for(j=1;j<=totalNode;j++){
            printf("%d ", adjacncyMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
