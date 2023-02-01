#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < ROW;i++)
	{
		for (j = 0;j < COL;j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < ROW;i++)
	{
		for (j = 0;j < COL;j++)
		{
			printf(" %c ", board[i][j]);
			if (j < COL - 1)
			{
				printf("|" );
			}
		}
		printf("\n");
		if (i < ROW - 1)
		{
			for (j = 0;j < COL;j++)
			{
				printf("---");
				if (j < COL - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)//定义玩家走的棋子为*  电脑的为#
{
	int x = 0;
	int y = 0;
	printf("请玩家输入坐标：");
	scanf("%d %d", &x, &y);
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
	{
		if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '*';
		}
		else
		{
			printf("坐标被占用，请重新输入\n");
		}
	}
	else
	{
		printf("输入错误，请重新输入\n");
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑走\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;//主函数内srand函数使得时间作为参数，由于row col是3，故摸上row结果必定是0~2
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}

}

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//棋盘没满
			}
		}
	}
	return 1;//棋盘满了
}


char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col - 2;j++)
		{
			if (board[i][j + 1] == board[i][j] && board[i][j + 1] == board[i][j + 2] && board[i][j]!= ' ') {
				// printf("...."); 
				return board[i][j];
				
				//妙！这里无需判断是玩家三子，还是电脑三子，只需要返回三子处的棋子就是返回是谁赢了
			}

		/*	printf("行：i = %d, j = %d",i,j);
			printf("\n");*/
		}
	}
	for (j = 0;j < col;j++)
	{
		for (i = 0;i < row - 2;i++)
		{
			if (board[i+1][j] == board[i][j] && board[i+1][j] == board[i+2][j] && board[i][j] != ' ')
				return board[i][j];//妙！这里无需判断是玩家三子，还是电脑三子，只需要返回三子处的棋子就是返回是谁赢了
			//printf("列：i = %d, j = %d", i, j);
			//printf("\n");
		}

	}
	/*for (i = 1;i < row - 1;i++)
	{
		for (j = 1;j < col - 1;j++)
		{
			if (board[i][j] == board[i+1][j+1] && board[i][j] == board[i-1][j-1])
			{
				return board[i][j];
			}
			if (board[i][j] == board[i-1][j+1] && board[i][j] == board[i+1][j-1])
			{
				return board[i][j];
			}
		}
	}*/

	// 判断正对角线
	for (i = 0;i < row-2;i++)
	{
		for (j = 0;j < col-2;j++)
		{
			if (board[i][j] == board[i + 1][j + 1] && board[i+1][j+1] == board[i+2][j+2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		/*	printf("对角线：i = %d, j = %d", i, j);
			printf("\n");*/
		}
	}

	// 判断反对角线
	for (i = 0;i < row - 2;i++)
	{
		for (j = col-1;j > 1;j--)
		{
			if (board[i][j] == board[i - 1][j - 1] && board[i - 1][j - 1] == board[i - 2][j - 2] && board[i][j] != ' ')
			{
				return board[i][j];
			}

		/*	printf("反对角线：i = %d, j = %d", i, j);
			printf("\n");*/
		}
	}


	int ret = IsFull(board, row, col);//判断是否平局
		if (ret == 1)
		{
			return 'Q';
		}
		return 'C';
}