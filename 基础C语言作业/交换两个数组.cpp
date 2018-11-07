#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[5] = { 1, 2, 3, 4, 5, };
	int b[5] = { 10, 9, 8, 7, 6, };
	int i = 0;
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		a[i] = a[i] + b[i];
		b[i] = a[i] - b[i];
		a[i] = a[i] - b[i];
	}
	printf("arr have changed,a[5]=\n");
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		printf("%d ", a[i]);
	printf("\narr have changed,b[5]=\n");
	for (i = 0; i < sizeof(b) / sizeof(b[0]); i++)
		printf("%d ", b[i]);
	system("pause");

}

