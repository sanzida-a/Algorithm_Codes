#include<stdio.h>
#include<algorithm>

using namespace std;

struct node{
    int n1;
    int n2;
    int weight;
};

bool compare(node a, node b){
    if(a.weight<b.weight)
        return true;
    else{
        return false;
    }
}

int main(){

    int i, totalEdge, totalNode, p1, p2, w;
    node edgeList[50];

    scanf("%d",&totalNode);
    scanf("%d",&totalEdge);

    for(i=0;i<totalEdge;i++){
        scanf("%d",&p1);
        scanf("%d",&p2);
        scanf("%d",&w);

        edgeList[i].n1 = p1;
        edgeList[i].n2 = p2;
        edgeList[i].weight = w;
    }
    sort(edgeList,edgeList+totalEdge, compare);

    printf("Sorted List:\n");
    for(i=0;i<totalEdge;i++){
        printf("%d %d %d\n", edgeList[i].n1, edgeList[i].n2, edgeList[i].weight);
    }

    return 0;
}
