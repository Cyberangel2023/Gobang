#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void game()
{
	char board[ROW][COL];//存储数据-二维数组(存储棋子)
	InitBoard(board, ROW, COL);//初始化棋盘(设置为空)
	DisplayBoard(board, ROW, COL);//打印棋盘
	char ret = 0;
	while (1)
	{
		PlayerMove1(board, ROW, COL);//玩家1下棋
		DisplayBoard(board, ROW, COL);//打印棋盘
		ret = IsWin(board, ROW, COL);//判断是否获胜或者平局
		if (ret != 'C')//获胜或平局则退出，获胜则ret等于O，平局则ret等于Q
			break;
		PlayerMove2(board, ROW, COL);//玩家2下棋
		DisplayBoard(board, ROW, COL);//打印棋盘
		ret = IsWin(board, ROW, COL);//判断是否获胜或者平局
		if (ret != 'C')//获胜或平局则退出，获胜则ret等于X，平局则ret等于Q
			break;
	}
	if (ret == 'O')
	{
		printf("玩家1获胜\n");
	}
	else if (ret == 'X')
	{
		printf("玩家2获胜\n");
	}
	else
	{
		printf("平局\n");
	}
	system("pause");
	system("cls");
}
void menu() //打印菜单
{
	printf("-------------------------\n");
	printf("----------五子棋---------\n");
	printf("--------1.游戏开始-------\n");
	printf("--------0.退出程序-------\n");
	printf("-------------------------\n");
}
int main()
{
	int input = 0;
	do {
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			game(); //进入游戏
			break;
		case 0:
			exit(0); //退出游戏
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
	return 0;
}