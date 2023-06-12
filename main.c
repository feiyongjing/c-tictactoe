# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
# include "game.h"

void menu() {

	printf("****************************************\n");
	printf("**********  1、play   0、exit  *********\n");
	printf("****************************************\n");

}


void game() {
	char board[ROW][COL] = { 0 };

	initBoard(board, ROW, COL);
	displayBoard(board);


	while (1) {
		// 玩家下棋打印棋盘
		if(playerMove(board, PLAYER_PIECE)) break;

		// 电脑下棋打印棋盘
		if(computerMove(board, COMPUTER_PIECE)) break;
	}
	
}

int main() {

	int x, y, print=0;

	do {
		menu();
		printf("请选择\n");
		printf("开始游戏按1\n");
		printf("退出游戏按0\n");
		scanf("%d", &print);
		switch (print) {
		case 0:
			print = 0;
			break;
		case 1:
			game();
			break;
		default:
			printf("错误选择\n");
			break;
		}

	} while (print);


	return 0;
}


