#include<stdio.h>
int my_strlen(char *string)
{
	int count = 0;
	while (*string++ != '\0')
	{
		count++;
	}
	return count;
}

int main()
{
	char *str = "abcdefewr";
	printf("%d\n", my_strlen(str));
	system("pause");
	return 0;
}







