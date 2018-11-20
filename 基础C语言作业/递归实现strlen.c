#include<stdio.h>
int my_strlen(char *string)
{
	int count = 0;
	if (*string != '\0')
	{
		string++;
		count = 1 + my_strlen(string);
	}
	return count;
}

int main()
{
	char *str = "abcdefetr";
	printf("%d\n", my_strlen(str));
	system("pause");
	return 0;
}






