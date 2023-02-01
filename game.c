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

void PlayerMove(char board[ROW][COL], int row, int col)//��������ߵ�����Ϊ*  ���Ե�Ϊ#
{
	int x = 0;
	int y = 0;
	printf("������������꣺");
	scanf("%d %d", &x, &y);
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
	{
		if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '*';
		}
		else
		{
			printf("���걻ռ�ã�����������\n");
		}
	}
	else
	{
		printf("�����������������\n");
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("������\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;//��������srand����ʹ��ʱ����Ϊ����������row col��3��������row����ض���0~2
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
				return 0;//����û��
			}
		}
	}
	return 1;//��������
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
				
				//����������ж���������ӣ����ǵ������ӣ�ֻ��Ҫ�������Ӵ������Ӿ��Ƿ�����˭Ӯ��
			}

		/*	printf("�У�i = %d, j = %d",i,j);
			printf("\n");*/
		}
	}
	for (j = 0;j < col;j++)
	{
		for (i = 0;i < row - 2;i++)
		{
			if (board[i+1][j] == board[i][j] && board[i+1][j] == board[i+2][j] && board[i][j] != ' ')
				return board[i][j];//����������ж���������ӣ����ǵ������ӣ�ֻ��Ҫ�������Ӵ������Ӿ��Ƿ�����˭Ӯ��
			//printf("�У�i = %d, j = %d", i, j);
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

	// �ж����Խ���
	for (i = 0;i < row-2;i++)
	{
		for (j = 0;j < col-2;j++)
		{
			if (board[i][j] == board[i + 1][j + 1] && board[i+1][j+1] == board[i+2][j+2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		/*	printf("�Խ��ߣ�i = %d, j = %d", i, j);
			printf("\n");*/
		}
	}

	// �жϷ��Խ���
	for (i = 0;i < row - 2;i++)
	{
		for (j = col-1;j > 1;j--)
		{
			if (board[i][j] == board[i - 1][j - 1] && board[i - 1][j - 1] == board[i - 2][j - 2] && board[i][j] != ' ')
			{
				return board[i][j];
			}

		/*	printf("���Խ��ߣ�i = %d, j = %d", i, j);
			printf("\n");*/
		}
	}


	int ret = IsFull(board, row, col);//�ж��Ƿ�ƽ��
		if (ret == 1)
		{
			return 'Q';
		}
		return 'C';
}