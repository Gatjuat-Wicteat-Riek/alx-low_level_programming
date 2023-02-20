#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/**
 * main - Prints positive, negative and 0
 * Return: Always (Success)
 */
int main(void)
{
	int n = 1;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 0)
	{
		printf("%d is a positive \n", n);
	}
	else if (n == 0)
	{
		printf("%d is zero \n", n);
	}
	else
	{
		printf("%d is negative \n", n);
	}
	return (0);
}
