#define _CRT_SECURE_NO_WARNINGS 2
#include "game.h"
menu()
{
	printf("***************************************\n");
	printf("******         ��������Ϸ      ********\n");
	printf("**************1.��ʼ��Ϸ***************\n");
	printf("**************0.�˳���Ϸ***************\n");
	printf("***************************************\n");

}
void game()
{
	char board[ROW][COL];//�洢����--��ά����
	InitBoard(board, ROW, COL);//��ʼ������--��ʼ���ո�
	DisplayBoard(board, ROW, COL);//��ӡ����--�����Ǵ�ӡ���������
	char ret = 0;//������Ϸ״̬
	while (1)
	{
		PlayerMove(board, ROW, COL);//�������
		DisplayBoard(board, ROW, COL);
		ret=IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		ComputerMove(board, ROW, COL);//��������
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if(ret == '#') 
	{
		printf("����Ӯ��\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
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
		printf("��ѡ��");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	}
	while(a);
	return 0;
}

