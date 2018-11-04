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
	if (max < min)//找到最大的数
	{
		temp = max;
		max = min;
		min = temp;
	}
	while (max % min != 0)//辗转相除
	{
		temp = min;
		min = max % min;
		max = temp;
	}
	printf("最大公倍数：%d\n", min);
	printf("最小公倍数：%d\n", mul / min);
	system("pause");
	return 0;
}
