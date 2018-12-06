
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
unsigned int reverse_bit(unsigned int value)
{
	int bin[32] = { 0 };
	int i = 0;
	unsigned int tmp = 0;
	unsigned int sum = 0;
	for (i = 0; i < 32; i++)
	{
		bin[i] = value & 1;
		value >>= 1;
	}
	for (i = 0; i <32; i++)
	{
		tmp = (unsigned int)pow(2, i) * bin[31 - i];
		sum += tmp;
	}
	return sum;
}
int main()
{
	unsigned int n = 25;
	printf("%u", reverse_bit(n));
	system("pause");
	return 0;
}
