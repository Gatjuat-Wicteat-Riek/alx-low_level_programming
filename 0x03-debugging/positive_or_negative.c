#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/**
 * positive_or_negative - Prints positive, negative and 0
 * @i: The integer
 * Return: void
 */
void positive_or_negative(int i)
{
	if (i > 0)
	{
		printf("%d is a positive \n", i);
	}
	else if (i == 0)
	{
		printf("%d is zero \n", i);
	}
	else
	{
		printf("%d is negative \n", i);
	}
}
