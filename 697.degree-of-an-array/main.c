#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMS_MAX_LEN 50000
struct degree_info {
    int first;
    int last;
    int degree;
};

int findShortestSubArray(int *nums, int numsSize)
{
    /** 1. find the largest degree numbers
      * 2. find the degree numbers, whose last index - first index is longest
      */  

    struct degree_info degrees[NUMS_MAX_LEN];
    int i = 0;
    int max_degree_value = 0;
    int max_degree = 0;
    int max_degree_sublen = numsSize;

    memset(degrees, 0, sizeof(degrees));
    for (i = 0; i < numsSize; i++) {
        if (degrees[nums[i]].degree == 0) {
            degrees[nums[i]].first = i;
        }   
        degrees[nums[i]].degree++;
        degrees[nums[i]].last = i;
    }   

    for (i = 0; i < numsSize; i++) {
        if (degrees[nums[i]].degree > max_degree) {
            max_degree = degrees[nums[i]].degree;
            max_degree_sublen = (degrees[nums[i]].last - degrees[nums[i]].first + 1); 
        } else if (degrees[nums[i]].degree == max_degree) {
			if (max_degree_sublen > (degrees[nums[i]].last - degrees[nums[i]].first + 1)) {
				max_degree_sublen = degrees[nums[i]].last - degrees[nums[i]].first + 1;
			}
		}
    }   

    return max_degree_sublen;
}

int main(void)
{
	int numsSize = 0;
	int nums[NUMS_MAX_LEN] = {0};
	int i = 0;

	scanf("%d", &numsSize);
	for (i = 0; i < numsSize; i++) {
		scanf("%d", &nums[i]);
	}

	printf("%d\n", findShortestSubArray(nums, numsSize));
	return 0;
}
