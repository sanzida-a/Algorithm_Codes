#include <stdio.h>
#include<conio.h>
#include <math.h>

double g(double x)
{
	return ((.5* x*x)+.25);
}

int main()
{
	double x, x0,a;
	int i = 1;
	int No;

	printf("Enter approximate x0: ");
	scanf_s("%lf", &x0);

	printf("Accuracy digit: ");
	scanf_s("%lf", &a);

	printf("Maximum Iterations: ");
	scanf_s("%d", &No);


	while (i <= No)
	{
		x= g(x0);

		if ((fabs(x - x0))<=a)
		{
			break;
		}
		printf("Iteration %d: Current value = %lf\n", i, x);

		i++;  
		x0 = x;

		if (i>No)
		{
			printf("solution incomplete after %d", No);
			printf(" iterations");
		}

	}
	_getch();
	return 0;

}