#include<stdio.h>
#include<stdlib.h>

int main()
{
	int max = 0;
	int min = 0;
	int temp = 0;
	int mul = 0;
	printf("Please enter two num:\n");
	scanf_s("%d %d", &max, &min);
	mul = max * min;
	if (max < min)//�ҵ�������
	{
		temp = max;
		max = min;
		min = temp;
	}
	while (max % min != 0)//շת���
	{
		temp = min;
		min = max % min;
		max = temp;
	}
	printf("��󹫱�����%d\n", min);
	printf("��С��������%d\n", mul / min);
	system("pause");
	return 0;
}
