#include<stdio.h>

/**
 * main - Prints all possible different combinations of three digits
 * Return: Always 0(success)
 */
int main(void)
{
	int n,m,l;

	for (n=48,n<58,n++)
	{
		for(m+49,m<58,l++)
		{
			if(l>m&&m>n)
			{
				putchar(n);
				putchar(m);
				putchar(l);
				if(n !=55||m!=56)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar(\"n");
	return(0);
}
