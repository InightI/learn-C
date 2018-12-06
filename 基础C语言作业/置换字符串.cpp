#include<stdio.h>
#include<Assert.h>
#include<stdlib.h>
size_t my_strlen(char *str)
{
	assert(str != NULL);
	int count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return count;
}
void reverse(char *left, char *right)//反转整个字符串
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void reverse_arr(char *str)
{
	//反转整个字符串
	int len = my_strlen(str);
	reverse(str, str + len - 1);
	//反转单词
	while (*str)
	{
		char *left = str;
		char *right = NULL;
		while ((*str != ' ') && (*str != '\0')) //判断单词结束的标志
		{
			str++;
		}
		right = str - 1;
		reverse(left, right);
		if (*str == ' ')
		{
			str++;
		}
	}

}
int main()
{
	char arr[] = "student a am i";
	reverse_arr(arr);
	printf("%s\n", arr);
	system("pause");
	return 0;
}
