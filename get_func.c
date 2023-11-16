#include "monty.h"

/**
 * getline - Read a line from a file stream.
 * @lineptr: Pointer to a pointer that will store the line.
 * @n: Pointer to a variable holding the size of the buffer.
 * @stream: The file stream from which to read the line.
 *
 * Description:
 * The getline function reads a line from the specified file stream and stores
 * it in a dynamically allocated buffer.
 * Return: ('\0')  returned on success. If an error occurs, -1
 */

size_t getline(char **lineptr, size_t *n, FILE *stream) {
	int c;
	size_t i = 0;

	if (*lineptr == NULL || *n == 0) {
		*n = 1024;
		*lineptr = malloc(*n);
		if (*lineptr == NULL) {
			return -1;
		}
	}

	while ((c = fgetc(stream)) != EOF) {
		if (c == '\n') {
			break;
		}

		if (i == *n) {
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL) {
				return -1;
			}
		}

		(*lineptr)[i++] = c;
	}

	if (c == EOF) {
		return -1;
	}

	(*lineptr)[i++] = '\0';
	return i;
}
