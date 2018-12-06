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
void reverse(char *left, char *right)//��ת�����ַ���
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
	//��ת�����ַ���
	int len = my_strlen(str);
	reverse(str, str + len - 1);
	//��ת����
	while (*str)
	{
		char *left = str;
		char *right = NULL;
		while ((*str != ' ') && (*str != '\0')) //�жϵ��ʽ����ı�־
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
