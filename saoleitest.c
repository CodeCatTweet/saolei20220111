#include"game.h"

int main()
{
	char input = 0;//定义菜单选择值
	do
	{
		menu();//打印菜单
		printf("请选择>");
		scanf("%c", &input);//获取选择值
		switch (input)
		{
		case '1'://开始游戏
			while (getchar() != '\n');//清除缓存区
			printf("扫雷\n");
			game();//游戏过程
			break;
		case '0'://退出游戏
			printf("退出游戏\n");
			break;
		default://输入其他东西时
			while (getchar() != '\n');//清除缓存区
			printf("输入错误\n");
			break;

		}
	} while (input != '0');//非0数字为真 0为假

	return 0;
}

//现在还有两个问题没解决
//1.重复输入坐标会导致最后玩家赢条件出现bug(改成判断是否还有‘*’)
//2.点出来没雷坐标及附近也没有雷时没法自动显示（递归三条件1.不是雷2.周围没有嘞3.没有排查过）
//增加标记功能