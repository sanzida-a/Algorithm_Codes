#include<stdio.h>
#include<utility>
#include<set>
using namespace std;

set< pair<int,int> > queue;
pair<int,int> p;

int main(){

    queue.insert( make_pair(30,3));
    queue.insert( make_pair(20,2));

    p = *queue.begin();
    printf("Before modification:\n");
    printf("Node number : %d\n",p.first);
    printf("Node Weight : %d\n",p.second);

    if(queue.find(make_pair(30,3)) != queue.end()){

        queue.erase(make_pair(30,3));
        queue.insert(make_pair(10,3));
    }
    p = *queue.begin();
    printf("After modification:\n");
    printf("Node number : %d\n",p.first);
    printf("Node Weight : %d\n",p.second);
}
