#define _CRT_SECURE_NO_WARNINGS 2
#include "game.h"
menu()
{
	printf("***************************************\n");
	printf("******         三子棋游戏      ********\n");
	printf("**************1.开始游戏***************\n");
	printf("**************0.退出游戏***************\n");
	printf("***************************************\n");

}
void game()
{
	char board[ROW][COL];//存储数据--二维数组
	InitBoard(board, ROW, COL);//初始化棋盘--初始化空格
	DisplayBoard(board, ROW, COL);//打印棋盘--本质是打印数组的内容
	char ret = 0;//接收游戏状态
	while (1)
	{
		PlayerMove(board, ROW, COL);//玩家下棋
		DisplayBoard(board, ROW, COL);
		ret=IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		ComputerMove(board, ROW, COL);//电脑下棋
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	else if(ret == '#') 
	{
		printf("电脑赢了\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);

}

int main()
{
	int a = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	}
	while(a);
	return 0;
}

