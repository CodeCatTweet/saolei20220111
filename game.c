#include"game.h"

void menu()
{//��ӡ�˵�����
	printf("*********************************\n");
	printf("**********   1.play    **********\n");
	printf("**********   0.exit    **********\n");
	printf("*********************************\n");
}

void game()
{
	//��Ϸ����

	char mine[ROWS][COLS];//����ʵ����������
	char show[ROWS][COLS];//������ʾ��������
	Initboard(mine, ROWS, COLS, '0');//��ʼ��ʵ������ ����λ�ö�Ϊ0������Ϊ1
	Initboard(show, ROWS, COLS, '*');//��ʼ����ʾ���� ����λ�ö�Ϊ*
	

	Setmine(mine, ROW, COL);//������

	//DisplayBoard(mine, ROW, COL);//��ӡ����
	DisplayBoard(show, ROW, COL);//��ӡ����

	Findmine(mine, show, ROW, COL);//�Ų���
}
void Initboard(char board[ROWS][COLS], int rows, int cols,char set)//��ʼ������
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
void DisplayBoard(char board[ROWS][COLS], int row, int col)//��ӡ����
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
		//��������±�
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] != '1')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int Getminecount(char mine[ROWS][COLS], int x, int y)//��ȡ���긽����������
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


void Findmine(char mine[ROWS][ROWS], char show[ROWS][COLS], int row, int col)//�Ų���
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<=(row*col)-EASY_COUNT)
	{
		printf("������Ҫ�Ų��׵�����\n");
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= row) && (x >= 1 && x <= row))
		{
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				int count = Getminecount(mine, x, y);//��ȡ���긽����������
				show[x][y] = count+'0';//�ַ�������Ҫת��'3'-'0'=3,��ascallֵת��
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}

	}


	if (win == (row * col) - EASY_COUNT)
	{
		printf("��ϲ�����׳ɹ�\n");
	}
	while (getchar() != '\n');//���������


}




