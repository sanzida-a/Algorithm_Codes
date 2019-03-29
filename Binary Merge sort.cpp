#include<stdio.h>
#include<conio.h>
#include<limits.h>
void merge(int[], int, int, int);
void part(int[], int, int);
void merge(int arr[], int min, int mid, int max)
{
	int n1,n2,i,j,k;
	n1=mid-min+1;
	n2=max-mid;
    int l[100],r[100];
	for(i=0;i<n1;i++)
	{
		l[i]=arr[min+i];
	}
    for(j=0;j<n2;j++)
	{
		r[j]=arr[mid+1+j];
	}
	i=0,j=0,l[n1] = INT_MAX,r[n2] = INT_MAX;
	for(k=min;k<=max;k++)
	{
		if(l[i]<=r[j]){
			arr[k]=l[i];
		    i++;
        }
		else{
			arr[k]=r[j];
			j++;
		}
	}
}

void part(int arr[], int min, int max)
{
	int mid;
	if (min<max)
	{
		mid = (min + max) / 2;
		part(arr, min, mid);
		part(arr, mid + 1, max);
		merge(arr, min, mid, max);
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
	for (i = 0; i<size; i++){
		printf("%d ", arr[i]);
	}
	_getch();
	return 0;
}



