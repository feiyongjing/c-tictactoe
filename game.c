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
		// ��ӡ���̵��к�
		if (i == 0) {
			// ��ӡÿ�����ӵķָ��
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

		// ��ӡÿ�����ӵķָ��
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
		// ��ӡÿ������
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

		// ��ӡ���һ�еķָ���
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

// �ж��Ƿ�����
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
		printf("�����ʤ\n");
		return 1;
	}
	return 0;
}

// �ж��Ƿ����
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
		printf("���ݻ�ʤ\n");
		return 1;
	}
	return 0;
}

// �ж��Ƿ���б��
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
		printf("��б���ʤ\n");
		return 1;
	}
	return 0;
}

// �ж��Ƿ���б��
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
		printf("��б���ʤ\n");
		return 1;
	}
	return 0;
}

// �ж��Ƿ�ƽ��
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


// ������岢��ӡ���Ӻ������
int playerMove(char board[ROW][COL], char piece) {
	int x, y;
	while (1) {
		printf("������������������\n");
		scanf("%d %d", &x, &y);
		if (x < 0 || x >= ROW || y<0 || y>COL) {
			printf("����Խ��Ƿ���������ѡ����������\n");
			continue;
		}

		if (board[x][y] != ' ') {
			printf("�������Ѿ��������ˣ�������ѡ����������\n");
			continue;
		}
		break;
	}

	board[x][y] = piece;
	displayBoard(board);
	// �ж��Ƿ��ʤ
	if (sidebySide(board, x, y, piece) ||
		vertical(board, x, y, piece) ||
		leftObliquePeak(board, x, y, piece) ||
		rightObliquePeak(board, x, y, piece)) {
		printf("��һ�ʤ��\n");
		return 1;
	}

	if (isPin(board)) {
		printf("�������ˣ�˫��ƽ�֣�\n");
		return 1;
	}
	return 0;

}

// �������岢��ӡ���Ӻ������
int computerMove(char board[ROW][COL], char piece) {
	int x, y;
	printf("��������\n");
	while (1) {

		x = rand() % ROW;
		y = rand() % COL;

		if (x < 0 || x >= ROW || y<0 || y>COL) {
			printf("����Խ��Ƿ���������ѡ����������\n");
			continue;
		}

		if (board[x][y] != ' ') {
			printf("�������Ѿ��������ˣ�������ѡ����������\n");
			continue;
		}
		break;
	}
	board[x][y] = piece;
	displayBoard(board);
	// �ж��Ƿ��ʤ
	if (sidebySide(board, x, y, piece) ||
		vertical(board, x, y, piece) ||
		leftObliquePeak(board, x, y, piece) ||
		rightObliquePeak(board, x, y, piece)) {
		printf("���Ի�ʤ��\n");
		return 1;
	}

	if (isPin(board)) {
		printf("�������ˣ�˫��ƽ�֣�\n");
		return 1;
	}

	return 0;

}

