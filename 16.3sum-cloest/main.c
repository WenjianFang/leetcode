#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int two_sum_closest(int *nums, int left, int right, int target)
{
	int sum = 0;
	int gap = 0;
	int min_gap = INT_MAX;
	int min_gap_sum = 0;

	while (left < right) {
		sum = nums[left] + nums[right];
		gap = abs(sum - target);
		if (gap < min_gap) {
			min_gap = gap;
			min_gap_sum = sum;
		}
		if (sum == target) {
			return sum;
		}
		if (sum < target) {
			left++;
		} else {
			right--;
		}
	}

	return min_gap_sum;
}

int threeSumClosest(int *nums, int numsSize, int target)
{
	int min_gap = INT_MAX;
	int i = 0;
	int left = 0;
	int right = numsSize - 1;
	int gap = 0;
	int min_gap_target = 0;
	int two_sum = 0;

	qsort(nums, numsSize, sizeof(int), compare);
	for (i = 0; i < numsSize; i++) {
		if ((i + 1) >= (numsSize - 1)) {
			break;
		}
		two_sum = two_sum_closest(nums, i + 1, numsSize - 1, target - nums[i]);
		gap = abs(target - (nums[i] + two_sum));
		if (min_gap > gap) {
			min_gap = gap;
			min_gap_target = nums[i] + two_sum;
		}
	}
	return min_gap_target;
}

int main(void)
{
	int nums[1024] = {0};
	int numsSize = 0;
	int target = 0;
	int i = 0;

	scanf("%d %d", &numsSize, &target);
	for (i = 0; i < numsSize; i++) {
		scanf("%d", &nums[i]);
	}
	printf("%d\n", threeSumClosest(nums, numsSize, target));
	return 0;
}
