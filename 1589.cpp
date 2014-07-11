/*
 * =====================================================================================
 *
 *       Filename:  1589.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/11/2014 11:17:15
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
#include <cctype>

const int CHECK = -1;

enum PieceType {
	BLACK = 1,
	RED,
	CHARIOT,
	HORSE,
	CANNON
};

int board[11][10];
int h_d[8][2] = { {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2} };
int b_d[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {-1, 0} };

void PrintBoard() {
	printf("\n");
	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= 9; ++j) {
			if (board[i][j] == BLACK) {
				printf("b ");
			} else if (board[i][j] == RED) {
				printf("g ");
			} else if (board[i][j] == CHARIOT) {
				printf("r ");
			} else if (board[i][j] == CANNON) {
				printf("c ");
			} else if (board[i][j] == HORSE) {
				printf("h ");
			} else if (board[i][j] == CHECK) {
				printf("x ");
			} else {
				printf("%d ", board[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

bool win;

int pieces[11][3];

bool ReadBoard() {
	int n, r, c;
	char input[10];
	char ch;
	memset(pieces, 0, sizeof(pieces));
	memset(board, 0, sizeof(board));
	
	while (true) {
		fgets(input, 10, stdin);
		if (sscanf(input, "%d%d%d", &n, &r, &c) != 3)
			continue;
		//printf("%d %d %d\n", n, r, c);
		if (n == 0)
			return false;
		break;
	}

	pieces[BLACK][0] = r;
	pieces[BLACK][1] = c;
	board[r][c] = BLACK;
	for (int i = 0; i < n; ++i) {
		fgets(input, 10, stdin);
		sscanf(input, "%c %d %d", &ch, &r, &c);
		//printf("%c %d %d\n", ch, r, c);
		if (ch == 'G') {
			pieces[RED][0] = r;
			pieces[RED][1] = c;
			board[r][c] = RED;
		} else if (ch == 'R') {
			pieces[CHARIOT][0] = r;
			pieces[CHARIOT][1] = c;
			board[r][c] = CHARIOT;
		} else if (ch == 'H') {
			pieces[HORSE][0] = r;
			pieces[HORSE][1] = c;
			board[r][c] = HORSE;
		} else if (ch == 'C') {
			pieces[CANNON][0] = r;
			pieces[CANNON][1] = c;
			board[r][c] = CANNON;
		}
	}
	return true;
}

void MarkGenal() {
	int col = pieces[RED][1];
	int row = pieces[RED][0];
	//printf("General col:%d\n", col);
	for (int i = row-1; i > 0; --i) {
		if (board[i][col] > 1) {
			pieces[board[i][col]][2] = 1;
			break;
		} else if (board[i][col] == 1) {
			continue;
		}
		board[i][col] = CHECK;
	}	
}

void MarkHorse() {
	if (pieces[HORSE][0] == 0)
		return;
	int row, col;
	for (int i = 0; i < 8; ++i) {
		if (pieces[HORSE][0] > 1 && board[pieces[HORSE][0]-1][pieces[HORSE][1]] > 0) {
			if (i == 0 || i == 1)
				continue;
		}
		if (pieces[HORSE][1] < 9 && board[pieces[HORSE][0]][pieces[HORSE][1]+1] > 0) {
			if (i == 2 || i == 3)
				continue;
		}
		if (pieces[HORSE][0] < 10 && board[pieces[HORSE][0]+1][pieces[HORSE][1]] > 0) {
			if (i == 4 || i == 5)
				continue;
		}
		if (pieces[HORSE][1] > 1 && board[pieces[HORSE][0]][pieces[HORSE][1]-1] > 0) {
			if (i == 6 || i == 7)
				continue;
		}
		row = pieces[HORSE][0] + h_d[i][0];
		col = pieces[HORSE][1] + h_d[i][1];
		if (row > 0 && row < 11 && col > 0 && col < 10) {
			if (board[row][col] == 0) {
				board[row][col] = CHECK;
			} else if (board[row][col] > 0) {
				pieces[board[row][col]][2] = 1;
			}
		}
	}
}

void MarkChariot() {
	if (pieces[CHARIOT][0] == 0)
		return;
	int row = pieces[CHARIOT][0];
	int col = pieces[CHARIOT][1];
	for (int i = row-1; i > 0; --i) {
		if (board[i][col] > 1) {
			pieces[board[i][col]][2] = 1;
			break;
		} else if (board[i][col] == 1) {
			continue;
		}
		board[i][col] = CHECK;
	}
	for (int i = row+1; i < 11; ++i) {
		if (board[i][col] > 1) {
			pieces[board[i][col]][2] = 1;
			break;
		} else if (board[i][col] == 1) {
			continue;
		}
		board[i][col] = CHECK;
	}
	for (int i = col-1; i > 0; --i) {
		if (board[row][i] > 1) {
			pieces[board[row][i]][2] = 1;
			break;
		} else if (board[row][i] == 1) {
			continue;
		}
		board[row][i] = CHECK;
	}
	for (int i = col+1; i < 10; ++i) {
		if (board[row][i] > 1) {
			pieces[board[row][i]][2] = 1;
			break;
		} else if (board[row][i] == 1) {
			continue;
		}
		board[row][i] = CHECK;
	}
}

void MarkCannon() {
	if (pieces[CANNON][0] == 0)
		return;
	int row = pieces[CANNON][0];
	int col = pieces[CANNON][1];

	bool meet_block = false;
	for (int i = row - 1; i > 0; --i) {
		if (board[i][col] > 1) {
			if (!meet_block) {
				meet_block = true;
				continue;
			} else {
				pieces[board[i][col]][2] = 1;
				break;
			}
		}
		if (meet_block && board[i][col] != 1) {
			board[i][col] = CHECK;
		}
	}

	meet_block = false;
	for (int i = row + 1; i < 11; ++i) {
		//printf("row:%d meet_block:%d\n", i, meet_block);
		if (board[i][col] > 1) {
			if (!meet_block) {
				meet_block = true;
				continue;
			} else {
				pieces[board[i][col]][2] = 1;
				break;
			}
		}
		if (meet_block && board[i][col] != 1) {
			board[i][col] = CHECK;
		}
	}

	meet_block = false;
	for (int i = col - 1; i > 0; --i) {
		if (board[row][i] > 1) {
			if (!meet_block) {
				meet_block = true;
				continue;
			} else {
				pieces[board[row][i]][2] = 1;
				break;
			}
		}
		if (meet_block && board[row][i] != 1) {
			board[row][i] = CHECK;
		}
	}

	meet_block = false;
	for (int i = col + 1; i < 10; ++i) {
		if (board[row][i] > 1) {
			if (!meet_block) {
				meet_block = true;
				continue;
			} else {
				pieces[board[row][i]][2] = 1;
				break;
			}
		}
		if (meet_block && board[row][i] != 1) {
			board[row][i] = CHECK;
		}
	}
}

void MarkBoard() {
	MarkGenal();
	MarkHorse();
	MarkChariot();
	MarkCannon();
}

void Check() {
	win = true;
	int row, col;
	for (int i = 0; i < 4; ++i) {
		row = pieces[BLACK][0] + b_d[i][0];
		col = pieces[BLACK][1] + b_d[i][1];
		if (row > 0 && row < 4 && col > 3 && col < 7) {
			if (board[row][col] == 0) {
				win = false;
			} else if (board[row][col] > 0 && pieces[board[row][col]][2] == 0) {
				win = false;
			}	
		}
	}
}

int main() {
#ifdef Debug
	freopen("1589.in", "r", stdin);
#endif
	while (ReadBoard()) {
		MarkBoard();
		Check();
		if (win) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
		PrintBoard();
	}

	return 0;
}
