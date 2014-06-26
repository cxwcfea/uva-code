/*
 * =====================================================================================
 *
 *       Filename:  272.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/26/2014 22:32:35
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>

int main() {
#ifdef Debug
	freopen("272.in", "r", stdin);
#endif
	char ch;
	bool flag = false;
	while ((ch = getchar()) != EOF) {
		if (ch == '\"') {
			if (flag) {
				printf("''");
			} else {
				printf("``");
			}
			flag = !flag;
		} else {
			printf("%c", ch);
		}	
	}
	return 0;
}
