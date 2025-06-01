#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void game()
{
	char board[ROW][COL];//�洢����-��ά����(�洢����)
	InitBoard(board, ROW, COL);//��ʼ������(����Ϊ��)
	DisplayBoard(board, ROW, COL);//��ӡ����
	char ret = 0;
	while (1)
	{
		PlayerMove1(board, ROW, COL);//���1����
		DisplayBoard(board, ROW, COL);//��ӡ����
		ret = IsWin(board, ROW, COL);//�ж��Ƿ��ʤ����ƽ��
		if (ret != 'C')//��ʤ��ƽ�����˳�����ʤ��ret����O��ƽ����ret����Q
			break;
		PlayerMove2(board, ROW, COL);//���2����
		DisplayBoard(board, ROW, COL);//��ӡ����
		ret = IsWin(board, ROW, COL);//�ж��Ƿ��ʤ����ƽ��
		if (ret != 'C')//��ʤ��ƽ�����˳�����ʤ��ret����X��ƽ����ret����Q
			break;
	}
	if (ret == 'O')
	{
		printf("���1��ʤ\n");
	}
	else if (ret == 'X')
	{
		printf("���2��ʤ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	system("pause");
	system("cls");
}
void menu() //��ӡ�˵�
{
	printf("-------------------------\n");
	printf("----------������---------\n");
	printf("--------1.��Ϸ��ʼ-------\n");
	printf("--------0.�˳�����-------\n");
	printf("-------------------------\n");
}
int main()
{
	int input = 0;
	do {
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			game(); //������Ϸ
			break;
		case 0:
			exit(0); //�˳���Ϸ
		default:
			printf("�������\n");
			break;
		}
	} while (input);
	return 0;
}