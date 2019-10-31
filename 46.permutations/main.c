#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void permute_recu(int *nums, int numsSize, int start, int **returnArrays, int *ret_index)
{
	int i = 0;
	int curr = 0;
	if (start == (numsSize - 1)) {
		returnArrays[*ret_index] = malloc(numsSize * sizeof(int));
		memcpy(returnArrays[*ret_index], nums, numsSize * sizeof(int));
		*ret_index = *ret_index + 1;
		return;
	}

	for (i = start; i < numsSize; i++) {
		curr = nums[i];
		nums[i] = nums[start];
		nums[start] = curr;
		permute_recu(nums, numsSize, start + 1, returnArrays, ret_index);
		nums[start] = nums[i];
		nums[i] = curr;
	}

	return;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
	int i = numsSize;
	int ret_index = 0;
	int rs = 1;

        /* total permutes */
	for (i = numsSize; i >= 1; i--) {
		rs = rs * i;
	}
	*returnSize = rs;
	int **returnArrays = malloc(rs * sizeof(int *));
	int *returnColumnSize = malloc(rs * sizeof(int));
	*returnColumnSizes = returnColumnSize;
	permute_recu(nums, numsSize, 0, returnArrays, &ret_index);
	for (i = 0; i < *returnSize; i++) {
		returnColumnSize[i] = numsSize;
	}
	return returnArrays;
}

int main(void)
{
	int nums[3] = {1, 2, 3};
	int numsSize = 3;
	int returnSize = 0;
	int *returnColumnSizes = NULL;
	int **returnArrays = NULL;
	int i = 0, j = 0;

	returnArrays = permute(nums, numsSize, &returnSize, &returnColumnSizes);

	for (i = 0; i < returnSize; i++) {
		for (j = 0; j < returnColumnSizes[i]; j++) {
			printf("%d ", returnArrays[i][j]);
		}
		free(returnArrays[i]);
		printf("\n");
	}
	free(returnArrays);
	free(returnColumnSizes);

	return 0;
}
