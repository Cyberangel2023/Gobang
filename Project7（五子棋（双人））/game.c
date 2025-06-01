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
			board[i][j] = ' ';//����ÿһ������Ϊ�ո�
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (i == 0) //��ӡ������
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

		if (i < 9) //��ӡ������
		{
			printf("%d ", i + 1);
		}
		else
		{
			printf("%d", i + 1);
		}

		for (j = 0; j < col; j++) //��ӡ����ÿһ��ķֽ���
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("ح");
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
					printf("ح");
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
		printf("���1��(��������):>");
		scanf("%d %d", &x, &y);

		//��¼��һ��������������
		m = x;
		n = y;

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ') //�ж������Ƿ��������
			{
				board[x - 1][y - 1] = 'O';
				system("cls");
				break;
			}
			else
			{
				printf("�����ѱ�ռ�ã�����������\n");
			}
		}
		else
			printf("���겻���ڣ�����������\n");
	}
}

void PlayerMove2(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("���2��(��������):>");
		scanf("%d %d", &x, &y);

		//��¼��һ��������������
		m = x;
		n = y;

		if (x >= 1 && x <= row && y >= 1 && y <= col) 
		{
			if (board[x - 1][y - 1] == ' ') //�ж������Ƿ��������
			{
				board[x - 1][y - 1] = 'X';
				system("cls");
				break;
			}
			else
			{
				printf("�����ѱ�ռ�ã�����������\n");
			}
		}
		else
			printf("���겻���ڣ�����������\n");
	}
}

int IsFull(char board[ROW][COL], int row, int col) //�ж������Ƿ�����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0; //δ������0
			}
		}
	}
	return 1; //��������1
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0, num = -1;
	for (i = m; i <= row; i++) //��¼��һ���������ж��ٸ���ͬ����
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
	for (i = m; i <= row; i--) //��¼��һ���������ж��ٸ���ͬ����
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
	if (num >= 5) //�����һ�������������д��ڵ������������ͬ�����ʤ
	{
		return board[m - 1][n - 1]; //���ػ�ʤ��ҵ���������
	}
	num = -1;
	for (j = n; j <= col; j++) //��¼��һ���������ж��ٸ���ͬ����
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
	for (j = n; j <= col; j--) //��¼��һ���������ж��ٸ���ͬ����
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
	if (num >= 5) //�����һ��������������д��ڵ������������ͬ�����ʤ
	{
		return board[m - 1][n - 1]; //���ػ�ʤ��ҵ���������
	}
	num = -1;
	for (i = m, j = n; i <= row && j <= col; j++, i++) //��¼��һ�����������ж��ٸ���ͬ����
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
	for (i = m, j = n; i <= row && j <= col; j--, i--) //��¼��һ�����������ж��ٸ���ͬ����
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
	if (num >= 5) //�����һ��������-���·���������д��ڵ������������ͬ�����ʤ
	{
		return board[m - 1][n - 1]; //���ػ�ʤ��ҵ���������
	}
	num = -1;
	for (i = m, j = n; i <= row && j <= col; j--, i++) //��¼��һ�����������ж��ٸ���ͬ����
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
	for (i = m, j = n; i <= row && j <= col; j++, i--) //��¼��һ�����������ж��ٸ���ͬ����
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
	if (num >= 5) //�����һ��������-���·���������д��ڵ������������ͬ�����ʤ
	{
		return board[m - 1][n - 1]; //���ػ�ʤ��ҵ���������
	}

    //���δ���򷵻�C�����򷵻�Q
	if (IsFull(board, row, col))
	{
		return 'Q';
	}
	return 'C';
}

