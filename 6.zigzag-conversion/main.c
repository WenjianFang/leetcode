#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 1024

char *convert(char *s, int numRows)
{
	if (!s) {
		return NULL;
	}

	int str_len = strlen(s);
	char *new_str = malloc(str_len + 1);
	int i = 0;
	int row = 0, column = 0;
	/* direction = 0, up->down. direction = 1, left->right up */
	int direction = 0;

	memset(new_str, 0, str_len + 1);
	if (numRows < 2) {
		/* if only need one row */
		for (i = 0; i < str_len; i++) {
			new_str[i] = s[i];
		}
		return new_str;
	}

	char **zigzag = malloc(numRows * sizeof(char *));
	memset(zigzag, 0, numRows * sizeof(char *));
	for (i = 0; i < numRows; i++) {
		zigzag[i] = malloc(str_len + 1);
		memset(zigzag[i], 0, str_len + 1);
	}

	for (i = 0; i < str_len; i++) {
		zigzag[row][column] = s[i];
		if (!direction) {
			row++;
			if (row == numRows) {
				direction = !direction;
				row -= 2;
				column++;
			}
		} else {
			row--;
			if (row < 0) {
				direction = !direction;
				row += 2;
			} else {
				column++;
			}
		}
	}

	i = 0;
	for (row = 0; row < numRows; row++) {
		for (column = 0; column < str_len; column++) {
			if (zigzag[row][column] != 0) {
				new_str[i] = zigzag[row][column];
				i++;
			}
		}
		free(zigzag[row]);
	}
	free(zigzag);
	return new_str;
}

int main(void)
{
	char s[MAX_STRING_LEN] = {0};
	int numRows = 0;
	char *new_str = NULL;

	scanf("%s", s);
	scanf("%d", &numRows);

	new_str = convert(s, numRows);
	printf("%s\n", new_str);

	free(new_str);
	return 0;
}
