#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

struct node{
    int neighbour;
    int weight;
};

int main(){

    int i, j, totalNode, totalEdge, p1, p2, w;
    vector<node> adjacencyList[50];

    scanf("%d",&totalNode);
    scanf("%d",&totalEdge);

    for(i=0;i<totalEdge;i++){
        scanf("%d",&p1);
        scanf("%d",&p2);
        scanf("%d",&w);

        node temp;
        temp.neighbour = p2;
        temp.weight = w;

        adjacencyList[p1].push_back(temp);
    }

    printf("Adjacency Matrix:\n");

    for(i=1;i<=totalNode;i++){

        int len = (int) adjacencyList[i].size();
        printf("Node %d: ",i);
        for(j=0;j<len;j++){
            printf("%d ", adjacencyList[i][j].neighbour);
        }
        printf("\n");
    }

    return 0;
}
