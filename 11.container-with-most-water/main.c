#include <stdio.h>

int min(int a, int b)
{
	return a < b ? a : b;
}

int maxArea(int *height, int heightSize)
{
	int start = 0;
	int end = heightSize - 1;
	int max_area = (end - start) * (min(height[start], height[end]));

	while (start < end) {
		if (height[start] < height[end]) {
			start++;
		} else {
			end--;
		}
		if (max_area < (end - start) * (min(height[start], height[end]))) {
			max_area = (end - start) * (min(height[start], height[end]));
		}
	}

	return max_area;
}

int main(void)
{
	int height[1024] = {0};
	int heightSize = 0;
	int i = 0;

	scanf("%d", &heightSize);

	for (i = 0; i < heightSize; i++) {
		scanf("%d", &height[i]);
	}

	printf("%d\n", maxArea(height, heightSize));

	return 0;
}
