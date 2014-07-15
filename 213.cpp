/*
 * =====================================================================================
 *
 *       Filename:  213.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/2014 13:50:42
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstring>

const int kMax = 2000;
int code[8][260];
char input[kMax];

void PrintCodes() {
	for (int i = 1; i <= 7; ++i) {
		for (int j = 0; j < (1 << i) - 1; ++j)
			printf("%c", code[i][j]);
	}
}

bool ReadCodes() {
	memset(code, 0, sizeof(code));
	char extra_char;
	do {
		extra_char = getchar();
	} while (extra_char == '\r' || extra_char == '\n');
	if (extra_char == EOF) {
		return false;
	}
	code[1][0] = extra_char;
	fgets(input, kMax, stdin);
	int len = strlen(input);
	int code_len = 2;
	int v = 0;
	int max_value = (1 << code_len) - 1;
	for (int i = 0; i < len; ++i) {
		if (input[i] != '\r' && input[i] != '\n') {
			//printf("len:%d v:%d %c\n", code_len, v, input[i]);
			code[code_len][v++] = input[i];
			if (v == max_value) {	
				++code_len;
				max_value = (1 << code_len) - 1;
				v = 0;
			}
		}
	}
	return true;
}

int ReadKey(int len) {
	int value = 0;
	while (len) {
		char d = getchar();
		if (d != '\r' && d != '\n') {
			value = value * 2 + (d - '0');
			--len;
		}
	}
	return value;
}

int main() {
#ifdef Debug
	freopen("213.in", "r", stdin);
#endif
	while (ReadCodes()) {
		while (1) {
			int key_len = ReadKey(3);
			if (key_len == 0) {
				printf("\n");
				break;
			}
			int end_mark = (1 << key_len) - 1;
			int key;
			while ((key = ReadKey(key_len)) != end_mark) {
				printf("%c", code[key_len][key]);
			}
		}
	}
	return 0;
}

