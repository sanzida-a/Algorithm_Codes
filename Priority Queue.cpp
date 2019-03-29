#include <stdio.h>
#include <limits.h>//INT_MAX
#include <math.h>//ceil()
#define Size 5
int a[Size],heapsize=0;
int Parent(int i)
{
    int p;
    p=ceil(i/2.0)-1;
    return p;
}
int Left_Child(int i)
{
    return (2*i)+1;
}
int Right_Child(int i)
{
    return (2*i)+2;
}
int Maximum()
{
    return a[0];
}
void Max_Heapify(int i)
{
    int l,r,largest,t;
    l=Left_Child(i);
    r=Right_Child(i);
    if (l<heapsize&&a[l]>a[i])
        largest=l;
    else
        largest=i;
    if (r<heapsize&&a[r]>a[largest])
        largest=r;
    if (largest!=i)
    {
        t=a[i];
        a[i]=a[largest];
        a[largest]=t;
        Max_Heapify(largest);
    }
}
int Extract_Max()
{
    int max;
    if (heapsize<=0)
    {
        printf("Heap Underow!\n");
        return 0;
    }
    else
    {
        max=a[0];
        a[0]=a[heapsize-1];
        heapsize--;
        Max_Heapify(0);
        return max;
    }
}
void Increase_Key(int i,int key)
{
    int t;
    if (key<a[i])
        printf("New key is smaller than current key!\n");
    a[i]=key;
    while(i>0 && a[Parent(i)]<a[i])
    {
        t=a[i];
        a[i]=a[Parent(i)];
        a[Parent(i)]=t;
        i=Parent(i);
    }
}
void Max_Heap_Insert(int key)
{
    heapsize++;
    a[heapsize-1]=-INT_MAX;
    Increase_Key(heapsize-1,key);
}
void display()
{
    int i;
    for(i=0;i<heapsize;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int main()
{
    int i=1,j,key,ch;
    while(i)
    {
        printf("Press 1: Insert\nPress 2: Maximum\nPress 3: Extract-Max\nPress 4: Increase-Key\nPress 5: Display(Array)\nPress 6: Exit\nEnter: ");
        scanf_s("%d",&ch);
        if (ch>=0&&ch<=9)
            switch(ch)
            {
                case 1:
                        printf("Enter Data: ");
                        scanf_s("%d",&key);
                        Max_Heap_Insert(key);
                        break;
                case 2:
                        key=Maximum();
                        printf("%d\n",key);
                        break;
                case 3:
                        key=Extract_Max();
                        printf("%d\n",key);
                        break;
                case 4:
                        printf("Enter Index: ");
                        scanf_s("%d",&j);
                        printf("Enter Key: ");
                        scanf_s("%d",&key);
                        Increase_Key(j,key);
                        break;
                case 5:
                        display();
                        break;
                case 6: i=0;
                        break;
                default:
                        printf("Wrong Input!\n");
                        break;
            }
        else
        {
            i=0;
            printf("Wrong Input!\n");
        }
    }
}
