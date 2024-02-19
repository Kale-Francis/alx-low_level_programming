#include "main.h"
/**
 * _isupper - func check if uppercase letters
 * @c: char to check
 *
 * Return: if uppercase return 1, else return 0
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);

	return (0);
}
