#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL], int row, int col);//初始化棋盘

void DisplayBoard(char board[ROW][COL], int row, int col);//打印棋盘函数

void PlayerMove(char board[ROW][COL], int row, int col);//

void ComputerMove(char board[ROW][COL], int row, int col);//

char IsWin(char board[ROW][COL], int row, int col);
//玩家赢了 - ‘*’
//电脑赢了 - ‘#’
//平局 - ‘Q’
//游戏继续 - ‘C''