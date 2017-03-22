#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * format_i - specificer i
 * @valist: valist
 * @buffer: buffer
 * @index: index
 *
 * Return: void
 */
void format_i(va_list valist, char *buffer, int *index)
{
	int i, j, numlen;
	char *num_str;

	i = va_arg(valist, int);
	numlen = num_len(i);
	if (i < 0)
	{
		*index += 1;
		numlen += 1;
	}
	num_str = malloc(numlen * sizeof(char));

	itos(num_str, i);
	for (i = *index, j = 0; j < numlen; *index += 1, i++, j++)
	{
		if (*index == 1024)
		{
			_write_buffer(buffer, index);
			reset_buffer(buffer);
			*index = 0;
		}
		buffer[*index] = num_str[j];
	}
}
/**
 * format_d - specificer d
 * @valist: valist
 * @buffer: buffer
 * @index: index
 *
 * Return: void
 */
void format_d(va_list valist, char *buffer, int *index)
{
	int i, j, numlen;
	char *num_str;

	i = va_arg(valist, int);

	numlen = num_len(i);
	if (i < 0)
	{
		numlen += 1;
	}
	num_str = malloc(numlen * sizeof(char));

	itos(num_str, i);
	for (i = *index, j = 0; j < numlen; *index += 1, i++, j++)
	{
		if (*index == 1024)
		{
			_write_buffer(buffer, index);
			reset_buffer(buffer);
			*index = 0;
		}
		buffer[*index] = num_str[j];
	}
}
