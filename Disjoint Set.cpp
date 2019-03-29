#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
int findset(int u,int set[])
{
	if(set[u]==u)
		return set[u];
	else
	{
		set[u]=findset(set[u],set);
		return set[u];
	}
}
void unionset(int u,int v,int set[],int size[])
{
	int s1=findset(u,set);
	int s2=findset(v,set);
	if(s1!=s2){
		if(size[s1]>=size[s2])
		{
			set[s2]=s1;
			size[s1]=size[s1]+size[s2];
		}
		else{
			set[s1]=s2;
			size[s2]=size[s2]+size[s1];
		}
	}
}


int main()
{
	int set[50],size[50],n,choice,c=1;
	printf("Enter the number of sets.....\n");
	scanf_s("%d",&n);
	printf("your set elements are....\n");
	for(int i=0;i<n;i++)
	{
		set[i]=i;
		size[i]=1;
		printf("%d      ",i);
	}
	printf("\n");
	while(c>0){
	printf("Enter 1 to find element.\nEnter 2 to make union.\nEnter 0 to exit.\n");
	scanf_s("%d",&choice);
	switch(choice)
	{
	case 1:{
		int el;
		printf("Enter an element between 0 to %d to find set.\n",n-1);
		scanf_s("%d",&el);
		findset(el,set);
		printf("The element is in %d.\n",findset(el,set));
		break;
		   }
	case 2:{
		int x,y;
		printf("Enter two elements between 0 to %d to unite set\n",n-1);
		scanf_s("%d %d",&x,&y);
		unionset(x,y,set,size);
		printf("Your unification is done.\n");
		printf("%d  and  % d is accordingly in  %d  and  %d set.\n",x,y,findset(x,set),findset(y,set));
		break;
		   }
	case 0: c=-1;
		break;
	}
	}
	_getch();
	return 0;
}