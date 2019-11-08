#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 1024

/** p[i][j] means whether s[i]->s[j] is a palindrome
  * p[i][j] = p[i + 1][j - 1]; if (s[i] == s[j])
  * init: p[i][i] = 1; p[i][i + 1] = 1; if (s[i] == s[i + 1])
  */
char * longestPalindrome(char * s)
{
	if (!s) {
		return NULL;
	}

	int p[MAX_STR_LEN][MAX_STR_LEN];
	int i = 0, j = 0;
	unsigned int lp_len = 1;
	int lp_start = 0, lp_end = 0;

	memset(p, 0, sizeof(p));

	for (i = 0; i < strlen(s); i++) {
		p[i][i] = 1;
		if ((i < (strlen(s) - 1)) && (s[i] == s[i + 1])) {
			p[i][i + 1] = 1;
		}
	}

	for (i = strlen(s) - 1; i >= 0; i--) {
		for (j = i; j < strlen(s); j++) {
			if (((i + 1) < strlen(s)) && ((j - 1) >= 0) && ((j - i - 2) >= 0) && (s[i] == s[j])) {
				p[i][j] = p[i + 1][j - 1];
			}
		}
	}

	for (i = 0; i < strlen(s); i++) {
		for (j = i; j < strlen(s); j++) {
			if ((p[i][j]) && (lp_len < (j - i + 1))) {
				lp_len = j - i + 1;
				lp_start = i;
				lp_end = j;
			}
		}
	}

	char *lp = malloc(lp_len + 1);
	memset(lp, 0, lp_len + 1);
	j = 0;
	for (i = lp_start; i <= lp_end; i++) {
		lp[j] = s[i];
		j++;
	}
	return lp;
}

int main(void)
{
	char s[MAX_STR_LEN] = {0};
	char *lp = NULL;

	scanf("%s", s);

	lp = longestPalindrome(s);

	if (!lp) {
		printf("0\n");
	} else {
		printf("%s\n", lp);
	}
	free(lp);
	return 0;
}
