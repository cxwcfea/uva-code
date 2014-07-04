/*
 * =====================================================================================
 *
 *       Filename:  232.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/04/2014 19:54:49
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>

enum class NodeType {
	BLACK,
	ELIGIBLE,
	WHITE
};

struct Node {
	NodeType type;
	char ch;
	int value;
	bool process_for_down;

	Node(NodeType t = NodeType::WHITE, char c = '*') : type{t}, ch{c}, value{0}, process_for_down{false} {} 
	void reset() {
		type = NodeType::WHITE;
		ch = '*';
		value = 0;
		process_for_down = false;
	}
};

const int kMax = 12;

Node matrix[kMax][kMax];
char input[kMax];

int main() {
#ifdef Debug
	freopen("232.in", "r", stdin);
#endif
	int r, c, cases = 0;
	while (1) {
		scanf("%d", &r);
		if (!r) {
			break;
		}
		scanf("%d", &c);
		getchar();

		if (cases)
			printf("\n");
		printf("puzzle #%d:\n", ++cases);
		printf("Across\n");

		int word_num = 0, count = 0;
		bool processing = false;
		for (int i = 0; i < r; ++i) {
			fgets(input, kMax, stdin);
			for (int j = 0; j < c; ++j) {
				matrix[i][j].reset();
				if (input[j] == '*') {
					if (processing) {
						printf("\n");
						processing = false;
					}
					matrix[i][j].type = NodeType::BLACK;
				} else {
					if (j == 0 || 
						i == 0 || 
						matrix[i-1][j].type == NodeType::BLACK || 
						matrix[i][j-1].type == NodeType::BLACK) {
						matrix[i][j].type = NodeType::ELIGIBLE;
						matrix[i][j].value = ++count;
						if (j == 0 && processing) {
							printf("\n");
							processing = false;
						}
						if (!processing) {
							processing = true;
							printf("%3d.%c", count, input[j]);
						} else {
							printf("%c", input[j]);
						}
					} else {
						printf("%c", input[j]);
					}
					matrix[i][j].ch = input[j]; 
				}
			}
		}
		if (processing)
			printf("\n");

		printf("Down\n");
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (matrix[i][j].type == NodeType::ELIGIBLE && !matrix[i][j].process_for_down) {
					matrix[i][j].process_for_down = true;
					processing = true;
					printf("%3d.%c", matrix[i][j].value, matrix[i][j].ch);
					int x = i + 1;
					while (x < r && matrix[x][j].type != NodeType::BLACK) {
						matrix[x][j].process_for_down = true;
						printf("%c", matrix[x][j].ch);
						++x;
					}
					printf("\n");
				}
			}
		}
		/*
		int count = 0;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (matrix[i][j].type == NodeType::BLACK) {
					printf(" * ");
				} else if (matrix[i][j].type == NodeType::ELIGIBLE) {
					printf("%2d ", ++count);
				} else {
					printf("%2c ", matrix[i][j].ch);
				}
			}
			printf("\n");
		}
  */
	}
	return 0;
}
