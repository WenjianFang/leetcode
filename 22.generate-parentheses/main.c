#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

static void generate(char **return_arr, int *return_idx, char *array, int arr_idx,
						int left, int right, int n)
{
	if (arr_idx == (n + n)) {
		/* this is a solution
		 * copy array to return_arr, return_idx increase */
		return_arr[*return_idx] = calloc(1, n + n + 1);
		memcpy(return_arr[*return_idx], array, n + n);
		*return_idx = *return_idx + 1;
		return;
	}

	if (left < n) {
		array[arr_idx] = '(';
		generate(return_arr, return_idx, array, arr_idx + 1, left + 1, right, n);
	}

	if (right < left) {
		array[arr_idx] = ')';
		generate(return_arr, return_idx, array, arr_idx + 1, left, right + 1, n);
	}
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **generateParenthesis(int n, int *returnSize)
{
	char **return_arr = calloc(1, MAX_LEN * sizeof(char *));
	int return_idx = 0;
	char *array = calloc(1, n + n + 1);

	generate(return_arr, &return_idx, array, 0, 0, 0, n);

	*returnSize = return_idx;

	free(array);
	return return_arr;
}

int main(void)
{
	int n = 0;
	int returnSize = 0;

	scanf("%d", &n);

	char **ret_arr = generateParenthesis(n, &returnSize);

	int i = 0;
	for (i = 0; i < returnSize; i++) {
		printf("%s\n", ret_arr[i]);
		free(ret_arr[i]);
	}
	free(ret_arr);

	return 0;
}
