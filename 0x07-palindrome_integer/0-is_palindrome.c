#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"

/**
 * is_palindrome- whether or not a given unsigned integer is a palindrome
 * @n: is the number to be checked
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev = 0, temp = n;

	while (n > 0)
	{
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	if (rev == temp)
		return (1);
	else
		return (0);
}
