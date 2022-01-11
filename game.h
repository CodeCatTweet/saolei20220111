#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

void menu();//打印菜单界面
void game();//游戏过程
void Initboard(char board[ROWS][COLS],int rows,int cols,char set);//初始化棋盘
void DisplayBoard(char board[ROWS][COLS], int row,int col);//打印棋盘
void Setmine(char board[ROWS][COLS],int  row,int col);
int Getminecount(char mine[ROWS][COLS], int x, int y);//获取坐标附近的雷数量
void Findmine(char mine[ROWS][ROWS],char show[ROWS][COLS], int row, int col);//排查雷

