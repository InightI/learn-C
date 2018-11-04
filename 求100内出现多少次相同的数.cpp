#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n = 1;
	int count = 0;
	while (n < 100)
	{
		if (n % 10 == 8)
			count++;
		if (n % 100 - n % 10 == 80)
			count++;
		n++;
	}
	printf("8出现的次数为 %d次\n",count);
	system("pause");
	return 0;
	
}
