#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RETURN_SIZE 1024

/* recursively solve
 * step is from this digits to next digits
 * options are foreach digits' letters, do next one until the last one
 */
void letter_combine(char **return_arrays, int *return_size,
					char *curr_array, int index, char *digits, int digits_idx, char *letters[])
{
	int i = 0;

	/* end condition */
	if (digits_idx == strlen(digits)) {
		return_arrays[*return_size] = calloc(1, strlen(digits) + 1);
		memcpy(return_arrays[*return_size], curr_array, strlen(digits));

		*return_size = *return_size + 1;
		return;
	}

	/* options */
	for (i = 0; i < strlen(letters[digits[digits_idx] - '0']); i++) {
		curr_array[index] = letters[digits[digits_idx] - '0'][i];
		letter_combine(return_arrays, return_size, curr_array, index + 1, digits, digits_idx + 1, letters);
	}
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **letterCombinations(char *digits, int *returnSize)
{
	char **return_arrays = calloc(1, MAX_RETURN_SIZE * sizeof(char *));
	char *curr_array = calloc(1, strlen(digits) + 1);
	char *letters[] = {"", "!@#", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	int return_size = 0;

	if (strlen(digits) == 0) {
		free(curr_array);
		*returnSize = return_size;
		return return_arrays;
	}

	letter_combine(return_arrays, &return_size, curr_array, 0, digits, 0, letters);
	*returnSize = return_size;

	free(curr_array);

	return return_arrays;
}

int main(void)
{
	char digits[MAX_RETURN_SIZE] = {0};
	int return_size = 0;
	int i = 0;

	scanf("%s", digits);
	char **return_arrays = letterCombinations(digits, &return_size);
	for (i = 0; i < return_size; i++) {
		printf("%s\n", return_arrays[i]);
		free(return_arrays[i]);
	}
	free(return_arrays);

	return 0;
}
