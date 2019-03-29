#include<stdio.h>
#include<conio.h>
#include<limits.h>
void merge(int[], int, int,int, int);
void part(int[], int, int);
void merge(int arr[], int min, int mid1,int mid2, int max)
{
    int i,j,e;
    int n1 = mid1 - min + 1;
    int n2 = mid2 - mid1;
    int n3 = max - mid2;
	int l[100],r[100],c[100];

	for(i=0;i<n1;i++)
	{
		l[i]=arr[min+i];
	}
		for(j=0;j<n2;j++)
	{
		r[j]=arr[mid1+1+j];
	}
    for(e=0;e<n1;e++)
	{
		c[e]=arr[mid2+1+e];
	}

    i=0,j=0, l[n1] = INT_MAX,r[n2] = INT_MAX,c[n3] = INT_MAX;
    int p = 0,k =min;
 
    for(; k <=max; ++k){
        if(l[i] <= r[j] && l[i] <= c[p]){
            arr[k] = l[i];
            ++i;
        }else if(r[j] <= c[p]){
            arr[k] = r[j];
            ++j;
        }else{
            arr[k] = c[p];
            ++p;
        }
    }
}
void part(int arr[], int min, int max)
{
	int mid1,mid2,p;
	if (min<max)
	{
		p = (max-min+1) / 3;
		mid1=min+p;
		mid2=mid1+p;
		part(arr, min, mid1);
		part(arr, mid1 + 1, mid2);
	    part(arr, mid2 + 1,max);
		merge(arr, min, mid1,mid2, max);
	}
}
int main()
{
	int arr[30];
	int i, size;
	printf("Enter the elements : ");
	scanf_s("%d", &size);
	for (i = 0; i<size; i++)
	{
		printf("%d element : ", i + 1);
		scanf_s("%d", &arr[i]);
	}
	part(arr, 0, size - 1);
	for (i = 0; i<size; i++)
		printf("%d ", arr[i]);
	_getch();
	return 0;
}



