#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX_NUM_LEN 64

int reverse(int x)
{
	char num_str[MAX_NUM_LEN] = {0};
	int sign = 1;
	int num = x;
	int i = 0;
	long reverse_num = 0;

	if (x == INT_MIN) {
		return 0;
	}

	if (x < 0) {
		sign = -1;
		num = -num;
	}
	while (num > 0) {
		num_str[i] = num % 10 + '0';
		i++;
		num = num / 10;
	}

	for (i = 0; i < strlen(num_str); i++) {
		reverse_num = reverse_num * 10 + (num_str[i] - '0');
	}

	reverse_num = sign * reverse_num;
	if ((reverse_num < INT_MIN) || (reverse_num > INT_MAX)) {
		return 0;
	}
	return (int)reverse_num;
}

int main(void)
{
	int x = 0;

	scanf("%d", &x);

	printf("%d\n", reverse(x));

	return 0;
}
