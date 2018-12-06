#include <stdio.h>
#include <windows.h>
/*
有一个字符数组的内容为:"student a am i",
请你将数组的内容改为"i am a student".
要求：
不能使用库函数。
只能开辟有限个空间（空间个数和字符串的长度无关）。

student a am i
i ma a tneduts
i am a student
*/
//写一个二分法将整个字符串逆置的函数
void Reverse_All(char* s) {
	char* start = s; //	确定起始字符位置
	char* end = s;
	while (*end != '\0') {
		++end;
	}
	--end; //确定结尾字符位置
	while (start < end) { //二分法交换位置
		char tmp = *start;
		*start = *end;
		*end = tmp;
		++start;
		--end;
	}
}
//写一个以空格为分隔符将每个分隔后的字符串按二分法逆置的函数
void Reverse_Every(char* s) {
	while (*s != '\0') {
		char* start = s; //确定每个字符串中起始字符的位置
		char* end = s;
		while (*end != ' ' && *end != '\0') {
			++end;
		}
		--end; //确定每个字符串中结尾字符的位置
		while (start < end) { //二分法交换位置
			char tmp = *start;
			*start = *end;
			*end = tmp;
			++start;
			--end;
		}
		while (*s != ' ' && *s != '\0') {//调整s的位置
			++s;
		}
		if (*s != '\0') { //调整位置,最后一个字符串特殊
			++s;
		}
	}
}
int main() {
	char string[] = "student a am i";
	printf("%s\n", string);
	Reverse_All(string);
	printf("%s\n", string);
	Reverse_Every(string);
	printf("%s\n", string);
	system("pause");
	return 0;
}
