/*
 * =====================================================================================
 *
 *       Filename:  512.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/2014 15:38:48
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <vector>

using namespace std;

struct Command {
	char type;
	bool row;
	int num_of_operand;
	int data[11];

	void ToString() {
		printf("type:%c row:%d, ", type, row);
		for (int i = 0; i < num_of_operand; ++i) {
			printf("%d ", data[i]);
		}	
	}
};

vector<Command> commands;
int origin_r, origin_c;

void simulation(int r, int c) {
	int row = r;
	int col = c;
	bool gone = false;
	for (int i = 0; i < commands.size(); ++i) {
		row = r;
		col = c;
		if (gone) break;
		if (commands[i].type == 'E') {
			if (commands[i].data[0] == r && commands[i].data[1] == c) {
				r = commands[i].data[2];
				c = commands[i].data[3];
			} else if (commands[i].data[2] == r && commands[i].data[3] == c) {
				r = commands[i].data[0];
				c = commands[i].data[1];
			}
		} else if (commands[i].type == 'D') {
			if (commands[i].row) {
				for (int j = 0; j < commands[i].num_of_operand; ++j) {
					if (commands[i].data[j] < row) {
						--r;
					} else if (commands[i].data[j] == row) {
						gone = true;
						break;
					}
				}
			} else {
				for (int j = 0; j < commands[i].num_of_operand; ++j) {
					if (commands[i].data[j] < col) {
						--c;
					} else if (commands[i].data[j] == col) {
						gone = true;
						break;
					}
				}
			}
		} else {
			if (commands[i].row) {
				for (int j = 0; j < commands[i].num_of_operand; ++j) {
					if (commands[i].data[j] <= row) {
						++r;
					}
				}
			} else {
				for (int j = 0; j < commands[i].num_of_operand; ++j) {
					if (commands[i].data[j] <= col) {
						++c;
					}
				}
			}
		}
		/*
		printf("\nafter operation ");
		commands[i].ToString();
		printf("\nr:%d c:%d\n", r, c);	
  */
	}
	if (gone) {
		printf("GONE\n");
	} else {
		printf("moved to (%d,%d)\n", r, c);
	}
}

int main() {
#ifdef Debug
	freopen("512.in", "r", stdin);
#endif
	int n, cases = 0;
	while (scanf("%d%d", &origin_r, &origin_c) == 2 && origin_r && origin_c) {
		if (cases) 
			printf("\n");
		printf("Spreadsheet #%d\n", ++cases);
		commands.clear();
		//printf("%d %d\n", origin_r, origin_c);
		scanf("%d", &n);
		//printf("%d\n", n);
		char operation[3];
		int num_of_operand;
		for (int i = 0; i < n; ++i) {
			getchar();
			scanf("%s %d", operation, &num_of_operand);		
			//printf("%s %d ", operation, num_of_operand);
			Command command;
			command.type = operation[0];
			command.row = operation[1] == 'R' ? true : false;
			command.num_of_operand = num_of_operand;
			int j = 0;
			if (operation[0] == 'E') {
				command.data[0] = num_of_operand;
				num_of_operand = 4;
				j = 1;
			}
			for (; j < num_of_operand; ++j) {
				scanf("%d", &(command.data[j])); 
				//printf("%d ", command.data[j]);
			}
			//printf("\n");
			commands.push_back(command);
		}
		scanf("%d", &n);
		//printf("%d\n", n);
		int r, c;
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &r, &c);
			printf("Cell data in (%d,%d) ", r, c);
			simulation(r, c);
		}
	}

	return 0;
}
