# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "game.h"



void initBoard(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			board[i][j] = ' ';
		}
	}
}

void displayBoard(char board[ROW][COL]) {
	for (int i = 0; i < ROW; i++) {
		// 打印棋盘的列号
		if (i == 0) {
			// 打印每行棋子的分割符
			for (int j = 0; j < COL; j++) {
				if (j == 0) {
					printf("  |");
				}
				if (j == COL - 1) {
					if (j < 10) {
						printf("%s%d%c\n", " ", j, '|');
					}
					else {
						printf("%d%c\n", j, '|');
					}
				}
				else {
					if (j < 10) {
						printf("%s%d%c", " ", j, '|');
					}
					else {
						printf("%d%c", j, '|');
					}
				}
			}
		}

		// 打印每行棋子的分割符
		for (int j = 0; j < COL; j++) {
			if (j == 0) {
				printf("---");
			}
			if (j == COL - 1) {
				printf("%s\n", "---");
			}
			else {
				printf("%s", "---");
			}
		}
		// 打印每行棋子
		for (int j = 0; j < COL; j++) {
			if (j == 0) {
				if (i < 10) {
					printf(" %d| %c", i, board[i][j]);
				}
				else {
					printf("%d| %c", i, board[i][j]);
				}
			}
			else {
				printf("| %c", board[i][j]);
			}

		}
		printf("|\n");

		// 打印最后一行的分隔符
		if (i == ROW - 1) {
			printf("---");
			for (int j = 0; j < COL; j++) {
				if (j == COL - 1) {
					printf("%s\n", "---");
				}
				else {
					printf("%s", "---");
				}
			}
		}
	}
}

// 判断是否连横
int sidebySide(char board[ROW][COL], int x, int y, char piece) {

	int size = 1;
	for (int i = 1; i < SIZE; i++) {
		if (y + i >= COL || board[x][y + i] != piece) {
			break;
		}
		size += 1;
	}
	for (int i = 1; i < SIZE; i++) {
		if (y - i < 0 || board[x][y - i] != piece) {
			break;
		}
		size += 1;
	}

	if (size >= SIZE) {
		printf("连横获胜\n");
		return 1;
	}
	return 0;
}

// 判断是否合纵
int vertical(char board[ROW][COL], int x, int y, char piece) {
	int size = 1;
	for (int i = 1; i < SIZE; i++) {
		if (x + i >= ROW || board[x + i][y] != piece) {
			break;
		}
		size += 1;
	}
	for (int i = 1; i < SIZE; i++) {
		if (x - i < 0 || board[x - i][y] != piece) {
			break;
		}
		size += 1;
	}

	if (size >= SIZE) {
		printf("合纵获胜\n");
		return 1;
	}
	return 0;
}

// 判断是否左斜峰
int leftObliquePeak(char board[ROW][COL], int x, int y, char piece) {
	int size = 1;
	for (int i = 1; i < SIZE; i++) {
		if (x + i >= ROW || y - i < 0 || board[x + i][y - i] != piece) {
			break;
		}
		size += 1;
	}

	for (int i = 1; i < SIZE; i++) {
		if (x - i < 0 || y + i >= COL || board[x - i][y + i] != piece) {
			break;
		}
		size += 1;
	}

	if (size >= SIZE) {
		printf("左斜峰获胜\n");
		return 1;
	}
	return 0;
}

// 判断是否右斜峰
int rightObliquePeak(char board[ROW][COL], int x, int y, char piece) {
	int size = 1;
	for (int i = 1; i < SIZE; i++) {
		if (x - i < 0 || y - i < 0 || board[x - i][y - i] != piece) {
			break;
		}
		size += 1;
	}

	for (int i = 1; i < SIZE; i++) {
		if (x + i >= ROW || y + i >= COL || board[x + i][y + i] != piece) {
			break;
		}
		size += 1;
	}

	if (size >= SIZE) {
		printf("右斜峰获胜\n");
		return 1;
	}
	return 0;
}

// 判断是否平局
int isPin(char board[ROW][COL]) {
	int size = 1;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < ROW; j++) {
			if (board[i][j] == ' ') {
				return 0;
			}
		}
	}

	return 1;
}


// 玩家下棋并打印落子后的棋盘
int playerMove(char board[ROW][COL], char piece) {
	int x, y;
	while (1) {
		printf("玩家请输入下棋的坐标\n");
		scanf("%d %d", &x, &y);
		if (x < 0 || x >= ROW || y<0 || y>COL) {
			printf("坐标越界非法，请重新选择落子坐标\n");
			continue;
		}

		if (board[x][y] != ' ') {
			printf("该坐标已经有棋子了，请重新选择落子坐标\n");
			continue;
		}
		break;
	}

	board[x][y] = piece;
	displayBoard(board);
	// 判断是否获胜
	if (sidebySide(board, x, y, piece) ||
		vertical(board, x, y, piece) ||
		leftObliquePeak(board, x, y, piece) ||
		rightObliquePeak(board, x, y, piece)) {
		printf("玩家获胜！\n");
		return 1;
	}

	if (isPin(board)) {
		printf("棋盘满了，双方平局！\n");
		return 1;
	}
	return 0;

}

// 电脑下棋并打印落子后的棋盘
int computerMove(char board[ROW][COL], char piece) {
	int x, y;
	printf("电脑下棋\n");
	while (1) {

		x = rand() % ROW;
		y = rand() % COL;

		if (x < 0 || x >= ROW || y<0 || y>COL) {
			printf("坐标越界非法，请重新选择落子坐标\n");
			continue;
		}

		if (board[x][y] != ' ') {
			printf("该坐标已经有棋子了，请重新选择落子坐标\n");
			continue;
		}
		break;
	}
	board[x][y] = piece;
	displayBoard(board);
	// 判断是否获胜
	if (sidebySide(board, x, y, piece) ||
		vertical(board, x, y, piece) ||
		leftObliquePeak(board, x, y, piece) ||
		rightObliquePeak(board, x, y, piece)) {
		printf("电脑获胜！\n");
		return 1;
	}

	if (isPin(board)) {
		printf("棋盘满了，双方平局！\n");
		return 1;
	}

	return 0;

}

