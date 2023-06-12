#pragma once

#define ROW 12
#define COL 30

// ���ö�����һ�߻�ʤ
#define SIZE 5

// ��ҵ����Ӻ͵��Ե�����
#define PLAYER_PIECE '1'
#define COMPUTER_PIECE '0'



// ��ʼ������
void initBoard(char board[ROW][COL], int row, int col); 

// ��ӡ����
void displayBoard(char board[ROW][COL]);

// �������
int playerMove(char board[ROW][COL], char piece);

// ��������
int computerMove(char board[ROW][COL], char piece);