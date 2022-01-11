#include"game.h"

void menu()
{//打印菜单界面
	printf("*********************************\n");
	printf("**********   1.play    **********\n");
	printf("**********   0.exit    **********\n");
	printf("*********************************\n");
}

void game()
{
	//游戏过程

	char mine[ROWS][COLS];//创建实际棋盘数组
	char show[ROWS][COLS];//创建显示棋盘数组
	Initboard(mine, ROWS, COLS, '0');//初始化实际棋盘 棋子位置都为0，有雷为1
	Initboard(show, ROWS, COLS, '*');//初始化显示棋盘 棋子位置都为*
	

	Setmine(mine, ROW, COL);//布置雷

	//DisplayBoard(mine, ROW, COL);//打印棋盘
	DisplayBoard(show, ROW, COL);//打印棋盘

	Findmine(mine, show, ROW, COL);//排查雷
}
void Initboard(char board[ROWS][COLS], int rows, int cols,char set)//初始化棋盘
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)//打印棋盘
{
	int i = 0;
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		int j = 0;
		for (j = 1; j <= col; j++)
		{
			printf("---");
		}
		printf("\n");
		for (j = 1; j <= col ; j++)
		{
			printf("|%c|", board[i][j]);
		}
		printf("%d", i);
		printf("\n");

	}
	for (i = 1; i <= col; i++)
	{
		printf("---");
	}
	printf("\n");
	for (i = 1; i <=row; i++)
	{
		printf(" %d ", i);
	}
	printf("\n");
}

void Setmine(char board[ROWS][COLS], int  row, int col)
{
	srand((unsigned int)time(NULL));
	int count = EASY_COUNT;
	while (count)
	{
		//生成随机下标
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] != '1')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int Getminecount(char mine[ROWS][COLS], int x, int y)//获取坐标附近的雷数量
{
	return (mine[x - 1][y - 1] +
			mine[x - 1][y] +
			mine[x - 1][y + 1] +
			mine[x][y - 1] +
			mine[x][y + 1] +
			mine[x + 1][y - 1] +
			mine[x + 1][y] +
			mine[x + 1][y + 1]) - (8 * '0');
}


void Findmine(char mine[ROWS][ROWS], char show[ROWS][COLS], int row, int col)//排查雷
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<=(row*col)-EASY_COUNT)
	{
		printf("请输入要排查雷的坐标\n");
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= row) && (x >= 1 && x <= row))
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				int count = Getminecount(mine, x, y);//获取坐标附近的雷数量
				show[x][y] = count+'0';//字符数整型要转换'3'-'0'=3,用ascall值转换
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}

	}


	if (win == (row * col) - EASY_COUNT)
	{
		printf("恭喜你排雷成功\n");
	}
	while (getchar() != '\n');//清除缓存区


}




