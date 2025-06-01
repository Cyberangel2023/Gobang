#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';//棋盘每一格设置为空格
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (i == 0) //打印横坐标
		{
			printf("  ");
			for (j = 1; j <= col; j++)
			{
				if (j < 10)
				{
					printf(" %d   ", j);
				}
				if (j >= 10)
				{
					printf(" %d  ", j);
				}
			}
			printf("\n");
		}

		if (i < 9) //打印纵坐标
		{
			printf("%d ", i + 1);
		}
		else
		{
			printf("%d", i + 1);
		}

		for (j = 0; j < col; j++) //打印棋盘每一格的分界线
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("丨");
		}
		printf("\n");
		printf("  ");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("丨");
			}
			printf("\n");
		}
	}
	printf("\n");
}

int m, n;

void PlayerMove1(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家1走(输入坐标):>");
		scanf("%d %d", &x, &y);

		//记录这一步玩家下棋的坐标
		m = x;
		n = y;

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ') //判断棋盘是否可以下子
			{
				board[x - 1][y - 1] = 'O';
				system("cls");
				break;
			}
			else
			{
				printf("坐标已被占用，请重新输入\n");
			}
		}
		else
			printf("坐标不存在，请重新输入\n");
	}
}

void PlayerMove2(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家2走(输入坐标):>");
		scanf("%d %d", &x, &y);

		//记录这一步玩家下棋的坐标
		m = x;
		n = y;

		if (x >= 1 && x <= row && y >= 1 && y <= col) 
		{
			if (board[x - 1][y - 1] == ' ') //判断棋盘是否可以下子
			{
				board[x - 1][y - 1] = 'X';
				system("cls");
				break;
			}
			else
			{
				printf("坐标已被占用，请重新输入\n");
			}
		}
		else
			printf("坐标不存在，请重新输入\n");
	}
}

int IsFull(char board[ROW][COL], int row, int col) //判断棋盘是否下满
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0; //未满返回0
			}
		}
	}
	return 1; //已满返回1
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0, num = -1;
	for (i = m; i <= row; i++) //记录这一步棋向右有多少个相同旗子
	{
		if (board[i - 1] ==board[m - 1][n - 1] && i == row - 1)
		{
			num++;
			break;
		}
		if (board[i - 1][n - 1] != board[m - 1][n - 1])
		{
			break;
		}
		num++;
	}
	for (i = m; i <= row; i--) //记录这一步棋向左有多少个相同旗子
	{
		if (board[i - 1][n - 1] == board[m - 1][n - 1] && i == 0)
		{
			num++;
			break;
		}
		if (board[i - 1][n - 1] != board[m - 1][n - 1])
		{
			break;
		}
		num++;
	}
	if (num >= 5) //如果这一步棋横向加起来有大于等于五个旗子相同，则获胜
	{
		return board[m - 1][n - 1]; //返回获胜玩家的棋子类型
	}
	num = -1;
	for (j = n; j <= col; j++) //记录这一步棋向下有多少个相同旗子
	{
		if (board[m - 1][j - 1] == board[m - 1][n - 1] && j == col - 1)
		{
			num++;
			break;
		}
		if (board[m - 1][j - 1] != board[m - 1][n - 1])
		{
			break;
		}
		num++;
	}
	for (j = n; j <= col; j--) //记录这一步棋向上有多少个相同旗子
	{
		if (board[m - 1][j - 1] == board[m - 1][n - 1] && j == 0)
		{
			num++;
			break;
		}
		if (board[m - 1][j - 1] != board[m - 1][n - 1])
		{
			break;
		}
		num++;
	}
	if (num >= 5) //如果这一步棋纵向加起来有大于等于五个旗子相同，则获胜
	{
		return board[m - 1][n - 1]; //返回获胜玩家的棋子类型
	}
	num = -1;
	for (i = m, j = n; i <= row && j <= col; j++, i++) //记录这一步棋向右下有多少个相同旗子
	{
		if (board[i - 1][j - 1] == board[m - 1][n - 1] && (j == col - 1 || i == row - 1))
		{
			num++;
			break;
		}
		if (board[i - 1][j - 1] != board[m - 1][n - 1])
		{
			break;
		}
		num++;
	}
	for (i = m, j = n; i <= row && j <= col; j--, i--) //记录这一步棋向左上有多少个相同旗子
	{
		if (board[i - 1][j - 1] == board[m - 1][n - 1] && (j == 0 || i == 0))
		{
			num++;
			break;
		}
		if (board[i - 1][j - 1] != board[m - 1][n - 1])
		{
			break;
		}
		num++;
	}
	if (num >= 5) //如果这一步棋左上-右下方向加起来有大于等于五个旗子相同，则获胜
	{
		return board[m - 1][n - 1]; //返回获胜玩家的棋子类型
	}
	num = -1;
	for (i = m, j = n; i <= row && j <= col; j--, i++) //记录这一步棋向右上有多少个相同旗子
	{
		if (board[i - 1][j - 1] == board[m - 1][n - 1] && (j == 0 || i == row - 1))
		{
			num++;
			break;
		}
		if (board[i - 1][j - 1] != board[m - 1][n - 1])
		{
			break;
		}
		num++;
	}
	for (i = m, j = n; i <= row && j <= col; j++, i--) //记录这一步棋向左下有多少个相同旗子
	{
		if (board[i - 1][j - 1] == board[m - 1][n - 1] && (j == col - 1 || i == 0))
		{
			num++;
			break;
		}
		if (board[i - 1][j - 1] != board[m - 1][n - 1])
		{
			break;
		}
		num++;
	}
	if (num >= 5) //如果这一步棋右上-左下方向加起来有大于等于五个旗子相同，则获胜
	{
		return board[m - 1][n - 1]; //返回获胜玩家的棋子类型
	}

    //如果未满则返回C，否则返回Q
	if (IsFull(board, row, col))
	{
		return 'Q';
	}
	return 'C';
}

