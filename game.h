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

void menu();//��ӡ�˵�����
void game();//��Ϸ����
void Initboard(char board[ROWS][COLS],int rows,int cols,char set);//��ʼ������
void DisplayBoard(char board[ROWS][COLS], int row,int col);//��ӡ����
void Setmine(char board[ROWS][COLS],int  row,int col);
int Getminecount(char mine[ROWS][COLS], int x, int y);//��ȡ���긽����������
void Findmine(char mine[ROWS][ROWS],char show[ROWS][COLS], int row, int col);//�Ų���

