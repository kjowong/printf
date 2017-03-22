#include "holberton.h"

/**
 * format_R - format in rot13
 * @valist: valist
 * @buffer: buffer
 * @index: index
 *
 * Return: void
 */
void format_R(va_list valist, char *buffer, int *index)
{
	char *s;
	int i, j;

	char *s1 = "abcdefghijklmABCDEFGHIJKLM ,?!;'@-=+\"\\$%^&*()`~<>/:[]{}_|";
	char *s2 = "nopqrstuvwxyzNOPQRSTUVWXYZ ,?!;'@-=+\"\\$%^&*()`~<>/:[]{}_|";

	s = va_arg(valist, char *);

	for (i = 0; s[i] != '\0'; i++, *index += 1)
	{
		for (j = 0; s1[j] != '\0'; j++)
		{
			if (s[i] == s1[j])
			{
				buffer[*index] = s2[j];
			}
			else if (s[i] == s2[j])
			{
				buffer[*index] = s1[j];
			}
		}

	}
}
