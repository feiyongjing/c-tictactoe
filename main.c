# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
# include "game.h"

void menu() {

	printf("****************************************\n");
	printf("**********  1��play   0��exit  *********\n");
	printf("****************************************\n");

}


void game() {
	char board[ROW][COL] = { 0 };

	initBoard(board, ROW, COL);
	displayBoard(board);


	while (1) {
		// ��������ӡ����
		if(playerMove(board, PLAYER_PIECE)) break;

		// ���������ӡ����
		if(computerMove(board, COMPUTER_PIECE)) break;
	}
	
}

int main() {

	int x, y, print=0;

	do {
		menu();
		printf("��ѡ��\n");
		printf("��ʼ��Ϸ��1\n");
		printf("�˳���Ϸ��0\n");
		scanf("%d", &print);
		switch (print) {
		case 0:
			print = 0;
			break;
		case 1:
			game();
			break;
		default:
			printf("����ѡ��\n");
			break;
		}

	} while (print);


	return 0;
}


