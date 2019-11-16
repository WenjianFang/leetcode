#include <stdio.h>
#include <string.h>
#include <limits.h>

int myAtoi(char *str)
{
	int i = 0;
	int sign = 1;
	long value = 0;
	int value_len = 0;

	for (i = 0; i < strlen(str); i++) {
		if (str[i] == ' ') {
			continue;
		}

		if (str[i] == '-') {
			sign = -1;
			break;
		}
		if (str[i] == '+') {
			break;
		}
		if (str[i] >= '0' && str[i] <= '9') {
			break;
		}
		if (!((str[i] >= '0') && (str[i] <= '9'))) {
			return 0;
		}
	}
	if ((str[i] == '-') || (str[i] == '+')) {
		i++;
	}
	for (; i < strlen(str); i++) {
		if (!((str[i] >= '0') && (str[i] <= '9'))) {
			break;
		}
		value = value * 10 + str[i] - '0';
		if (value == 0) {
			continue;
		}
		if (value * sign > INT_MAX) {
			return INT_MAX;
		}
		if (value * sign < INT_MIN) {
			return INT_MIN;
		}
	}

	value = sign * value;

	return (int)value;
}

int main(void)
{
	char str[1024] = {0};

	scanf("%s", str);
	printf("%d\n", myAtoi(str));

	return 0;
}
