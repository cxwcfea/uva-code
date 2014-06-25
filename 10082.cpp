#include<stdio.h>
#include<string.h>

int main() {
    char *s = "1234567890-=\\QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";
    char c, i;
	while ((c  = getchar()) != EOF) {
		for (i = 0; i < strlen(s); ++i) {
			if (c == s[i]) {
				putchar(s[i-1]);
				break;
			}
		}
		if (i == strlen(s)) putchar(c);
	}
    return 0;
}
