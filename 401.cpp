/*
 * =====================================================================================
 *
 *       Filename:  401.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/25/2014 21:05:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstring>
#include <cctype>

const char dict[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
char buf[256];
const char *result[] = { "-- is not a palindrome.", 
	"-- is a regular palindrome.", 
	"-- is a mirrored string.",
	"-- is a mirrored palindrome." };

char r(const char ch) {
	if (isalpha(ch)) {
		return dict[ch - 'A'];
	} else {
		return dict[ch - '0' + 25];
	}
}

int main() {
#ifdef Debug
	freopen("401.in", "r", stdin);
#endif
	while (scanf("%s", buf) == 1) {
		int len = strlen(buf);
		int p = 1, m = 1;
		for (int i = 0; i < (len+1)/2; ++i) {
			if (buf[i] != buf[len-1-i]) {
				p = 0;
			}
			if (buf[len-1-i] != r(buf[i])) {
				m = 0;
			}
		}
		printf("%s %s\n", buf, result[2*m+p]);
	}
	return 0;
}
