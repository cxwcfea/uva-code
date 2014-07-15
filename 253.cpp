/*
 * =====================================================================================
 *
 *       Filename:  253.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/13/2014 19:46:15
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

const int kMax = 15;
const int kLen = 24;

int possible_num[kLen][6] = {
	{1, 2, 3, 4, 5, 6},
	{1, 3, 5, 2, 4, 6},
	{1, 5, 4, 3, 2, 6},
	{1, 4, 2, 5, 3, 6},
	{2, 6, 3, 4, 1, 5},
	{2, 3, 1, 6, 4, 5},
	{2, 4, 6, 1, 3, 5},
	{2, 1, 4, 3, 6, 5},
	{3, 2, 6, 1, 5, 4},
	{3, 5, 1, 6, 2, 4},
	{3, 1, 2, 5, 6, 4},
	{3, 6, 5, 2, 1, 4},
	{4, 2, 1, 6, 5, 3},
	{4, 1, 5, 2, 6, 3},
	{4, 6, 2, 5, 1, 3},
	{4, 5, 6, 1, 2, 3},
	{5, 1, 3, 4, 6, 2},
	{5, 3, 6, 1, 4, 2},
	{5, 4, 1, 6, 3, 2},
	{5, 6, 4, 3, 1, 2},
	{6, 5, 3, 4, 2, 1},
	{6, 3, 2, 5, 4, 1},
	{6, 2, 4, 3, 5, 1},
	{6, 4, 5, 2, 3, 1}
};
char possible_color[kLen][7];
char input[kMax];
char other_color[7];

void GenerateAllColorCombination() {
	for (int i = 1; i < kLen; ++i) {
		for (int j = 0; j < 6; ++j) {
			possible_color[i][j] = possible_color[0][possible_num[i][j]-1];
		}
		possible_color[i][6] = '\0';
	}
}

void PrintAllColorCombination() {
	printf("%s\n", possible_color[0]);
	printf("\n");
	for (int i = 0; i < kLen; ++i) {
		printf("%s\n", possible_color[i]);
	}
	printf("\n");
	printf("%s\n", other_color);
}

bool Check() {
	for (int i = 0; i < kLen; ++i) {
		if (!strcmp(possible_color[i], other_color)) {
			return true;
		}
	}
	return false;
}

int main() {
#ifdef Debug
	freopen("253.in", "r", stdin);
#endif
	while (fgets(input, kMax, stdin)) {
		strncpy(possible_color[0], input, 6);
		possible_color[0][6] = '\0';
		strncpy(other_color, input+6, 6);
		other_color[6] = '\0';
		GenerateAllColorCombination();
		//PrintAllColorCombination();
		if (Check()) {
			printf("TRUE\n");
		} else {
			printf("FALSE\n");
		}
	}	
	return 0;
}
