#include"game.h"

int main()
{
	char input = 0;//����˵�ѡ��ֵ
	do
	{
		menu();//��ӡ�˵�
		printf("��ѡ��>");
		scanf("%c", &input);//��ȡѡ��ֵ
		switch (input)
		{
		case '1'://��ʼ��Ϸ
			while (getchar() != '\n');//���������
			printf("ɨ��\n");
			game();//��Ϸ����
			break;
		case '0'://�˳���Ϸ
			printf("�˳���Ϸ\n");
			break;
		default://������������ʱ
			while (getchar() != '\n');//���������
			printf("�������\n");
			break;

		}
	} while (input != '0');//��0����Ϊ�� 0Ϊ��

	return 0;
}

//���ڻ�����������û���
//1.�ظ���������ᵼ��������Ӯ��������bug(�ĳ��ж��Ƿ��С�*��)
//2.�����û�����꼰����Ҳû����ʱû���Զ���ʾ���ݹ�������1.������2.��Χû����3.û���Ų����
//���ӱ�ǹ���