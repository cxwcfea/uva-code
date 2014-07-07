#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAXN 10000
#define MAX_TRY 7

int dict[26];
char word[MAXN];
char guess[MAXN];

int pass() {
	for (int i = 0; i < 26; ++i) {
		if (dict[i]) return 0;
	}
	return 1;
}

int main() {
	freopen("489.in", "r", stdin);
	freopen("489.out", "w", stdout);
	int n;
	while (scanf("%d", &n)) {
		if (n == -1) break;
		printf("Round %d\n", n);
		memset(dict, 0, sizeof(dict));
		scanf("%s%s", word, guess);
		int try_left = MAX_TRY;
		for (int i = 0; i < strlen(word); ++i) {
			++dict[word[i]-'a'];
		}
		for (int j = 0; j < strlen(guess); ++j) {
			if (dict[guess[j]-'a']) {
				dict[guess[j]-'a'] = 0;
				if (pass()) {
					printf("You win.\n");
					try_left = 0;
					break;
				}
			} else {
				--try_left;
				if (!try_left) {
					printf("You lose.\n");
					break;
				}
			}
		}
		if (try_left) {
			printf("You chickened out.\n");
		}
	}
	
	return 0;
}
