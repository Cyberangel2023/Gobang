#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//���Ŷ���
#define ROW 15 //15��
#define COL 15 //15��

//��������
void InitBoard(char board[ROW][COL], int row, int col);//��ʼ������
void DisplayBoard(char board[ROW][COL], int row, int col);//��ӡ����
void PlayerMove1(char board[ROW][COL], int row, int col);//���1����
void PlayerMove2(char board[ROW][COL], int row, int col);//���2����
char IsWin(char board[ROW][COL], int row, int col);//��Ӯ�ж�