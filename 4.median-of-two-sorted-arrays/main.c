#include <stdio.h>

/**
  * median-of-two-sorted-arrays A and B, assume that len(A) > len(B)
  * partition A to {a[0], ..., a[i - 1], a[i], ..., a[n - 1]}
  * partition B to {b[0], ..., b[j - 1], b[j], ..., b[m - 1]}
  * len{a[0 ~ i - 1], b[0 ~ j - 1]} == len{a[i ~ n - 1], b[j ~ m - 1]} -> len1 == len2
  * OR len1 == len2 + 1;
  * REQ: a[i - 1] <= b[j] && a[i] >= b[j - 1]
  * if a[i - 1] > b[j], goto [j + 1, max]
  * if a[i] < b[j - 1], goto [min, j - 1]
  */

static double find_median(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	int left = 0, right = nums2Size;
	int idx_nums1 = 0, idx_nums2 = 0;
	/* partition len would always be (nums1Size + nums2Size + 1) / 2 */
	int partition_len = (nums1Size + nums2Size + 1) / 2;
	double left_max = 0.0, right_min = 0.0;

	while (left <= right) {
		idx_nums2 = (left + right) / 2;
		idx_nums1 = partition_len - idx_nums2;

		if ((idx_nums2 > 0) && (idx_nums1 < nums1Size) && (nums2[idx_nums2 - 1] > nums1[idx_nums1])) {
			right = idx_nums2 - 1;
		} else if ((idx_nums1 > 0) && (idx_nums2 < nums2Size) && (nums2[idx_nums2] < nums1[idx_nums1 - 1])) {
			left = idx_nums2 + 1;
		} else {
			/* find middle */
			if (idx_nums1 == 0) {
				left_max = nums2[idx_nums2 - 1];
			} else if (idx_nums2 == 0) {
				left_max = nums1[idx_nums1 - 1];
			} else {
				left_max = nums1[idx_nums1 - 1] > nums2[idx_nums2 - 1] ? nums1[idx_nums1 - 1] : nums2[idx_nums2 - 1];
			}
			if (((nums1Size + nums2Size) % 2) == 1) {
				return left_max;
			}

			if (idx_nums1 == nums1Size) {
				right_min = nums2[idx_nums2];
			} else if (idx_nums2 == nums2Size) {
				right_min = nums1[idx_nums1];
			} else {
				right_min = nums1[idx_nums1] < nums2[idx_nums2] ? nums1[idx_nums1] : nums2[idx_nums2];
			}
			return (left_max + right_min) / 2.0;
		}
	}
	return 0.0;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	double median = 0.0;

	/* we assume that nums1Size >= nums2Size  */
	if (nums1Size >= nums2Size) {
		median = find_median(nums1, nums1Size, nums2, nums2Size);
	} else {
		median = find_median(nums2, nums2Size, nums1, nums1Size);
	}

	return median;
}

int main(void)
{
	int nums1[1024] = {0};
	int nums2[1024] = {0};
	int nums1Size = 0, nums2Size = 0;

	scanf("%d %d", &nums1Size, &nums2Size);

	int i = 0;
	for (i = 0; i < nums1Size; i++) {
		scanf("%d", &nums1[i]);
	}
	for (i = 0; i < nums2Size; i++) {
		scanf("%d", &nums2[i]);
	}

	printf("%f\n", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));

	return 0;
}
