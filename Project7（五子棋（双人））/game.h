#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//符号定义
#define ROW 15 //15行
#define COL 15 //15列

//函数声明
void InitBoard(char board[ROW][COL], int row, int col);//初始化棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);//打印棋盘
void PlayerMove1(char board[ROW][COL], int row, int col);//玩家1下棋
void PlayerMove2(char board[ROW][COL], int row, int col);//玩家2下棋
char IsWin(char board[ROW][COL], int row, int col);//输赢判定