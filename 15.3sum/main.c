#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * qsort
 * fix one
 * two point
 */
#define MAX_RETURN_SIZE 1024
#define ARRAYS_LEN 3

int compare(const void *value1, const void *value2)
{
	return *((int *)value1) - *((int *)value2);
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
	int i = 0;
	int left = 0;
	int right = 0;
	int **returnArrays = calloc(1, MAX_RETURN_SIZE * sizeof(int *));
	int *returnColumnSize = calloc(1, MAX_RETURN_SIZE * sizeof(int));
	int ex_two_sum = 0;

	qsort(nums, numsSize, sizeof(int), compare);
	*returnSize = 0;

	for (i = 0; i < numsSize; i++) {
		ex_two_sum = 0 - nums[i];
		left = i + 1;
		right = numsSize - 1;
		if ((i > 0) && (nums[i] == nums[i - 1])) {
			continue;
		}
		while ((left < right) && (nums[i] <= 0)) {
			/* minus too small */
			if (ex_two_sum > (nums[right] + nums[left])) {
				left++;
			} else if (ex_two_sum < (nums[left] + nums[right])) {
				right--;
			} else {
                if ((*returnSize > 0) && (nums[i] == returnArrays[*returnSize - 1][0])
                    && (nums[left] == returnArrays[*returnSize - 1][1])
                    && (nums[right] == returnArrays[*returnSize - 1][2])) {
                    left++;
                    right--;
                    continue;
                }
				returnColumnSize[*returnSize] = ARRAYS_LEN;
				returnArrays[*returnSize] = calloc(1, sizeof(int) * returnColumnSize[*returnSize]);
				returnArrays[*returnSize][0] = nums[i];
				returnArrays[*returnSize][1] = nums[left];
				returnArrays[*returnSize][2] = nums[right];
				*returnSize = *returnSize + 1;

				left++;
				right--;
			}
		}
	}

	*returnColumnSizes = returnColumnSize;
	return returnArrays;
}

int main(void)
{
	int numsSize = 0;
	int nums[MAX_RETURN_SIZE] = {0};
	int i = 0;
	int j = 0;

	scanf("%d", &numsSize);
	for (i = 0; i < numsSize; i++) {
		scanf("%d", &nums[i]);
	}

	int *returnColumnSize = NULL;
	int returnSize = 0;
	int **returnArrays = threeSum(nums, numsSize, &returnSize, &returnColumnSize);

	for (i = 0; i < returnSize; i++) {
		for (j = 0; j < returnColumnSize[i]; j++) {
			printf("%d ", returnArrays[i][j]);
		}
		printf("\n");
		free(returnArrays[i]);
	}
	free(returnArrays);
	free(returnColumnSize);
	return 0;
}
