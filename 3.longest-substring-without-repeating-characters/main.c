#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_LEN 256
#define MAX_STR_LEN 1024
int lengthOfLongestSubstring(char * s)
{
	int i = 0, j = 0;
	int position[CHAR_LEN];
	int curr_len = 0, max_len = 0;

	if (!s) {
		return 0;
	}

	for (i = 0; i < CHAR_LEN; i++) {
		position[i] = -1;
	}

	i = 0;
	while (i < strlen(s) && j < strlen(s)) {
		if (position[s[j]] < i) {
			position[s[j]] = j;
			curr_len++;
		} else {
			if (curr_len > max_len) {
				max_len = curr_len;
			}
			i = position[s[j]] + 1;
			position[s[j]] = j;
			curr_len = j - i + 1;
		}
		j++;
	}
	if (curr_len > max_len) {
		max_len = curr_len;
	}
	return max_len;
}

int main(void)
{
	char s[MAX_STR_LEN] = {0};
	scanf("%s", s);
	
	int max_len = lengthOfLongestSubstring(s);

	printf("%d\n", max_len);

	return 0;
}
