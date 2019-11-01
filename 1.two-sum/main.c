#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS_LEN 128
#define MAX_RETURN_LEN 2

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int *returnArray = malloc(MAX_RETURN_LEN * sizeof(int));
	int i = 0, j = 0;

	for (i = 0; i < numsSize - 1; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if ((nums[i] + nums[j]) == target) {
				returnArray[0] = i;
				returnArray[1] = j;
				*returnSize = 2;
				return returnArray;
			}
		}
	}

	return NULL;
}

int main(void)
{
	int nums[MAX_NUMS_LEN] = {0};
	int numsSize = 0, target = 0, returnSize = 0;
	int *returnArray = NULL;
	int i = 0;

	scanf("%d %d", &numsSize, &target);
	for (i = 0; i < numsSize; i++) {
		scanf("%d", &nums[i]);
	}

	returnArray = twoSum(nums, numsSize, target, &returnSize);

	printf("%d %d\n", returnArray[0], returnArray[1]);

	free(returnArray);

	return 0;
}
