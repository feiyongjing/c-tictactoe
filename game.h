#pragma once

#define ROW 12
#define COL 30

// 设置多少子一线获胜
#define SIZE 5

// 玩家的棋子和电脑的棋子
#define PLAYER_PIECE '1'
#define COMPUTER_PIECE '0'



// 初始化棋盘
void initBoard(char board[ROW][COL], int row, int col); 

// 打印棋盘
void displayBoard(char board[ROW][COL]);

// 玩家下棋
int playerMove(char board[ROW][COL], char piece);

// 电脑下棋
int computerMove(char board[ROW][COL], char piece);