#include <stdio.h>
#include <windows.h>
/*
��һ���ַ����������Ϊ:"student a am i",
���㽫��������ݸ�Ϊ"i am a student".
Ҫ��
����ʹ�ÿ⺯����
ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���

student a am i
i ma a tneduts
i am a student
*/
//дһ�����ַ��������ַ������õĺ���
void Reverse_All(char* s) {
	char* start = s; //	ȷ����ʼ�ַ�λ��
	char* end = s;
	while (*end != '\0') {
		++end;
	}
	--end; //ȷ����β�ַ�λ��
	while (start < end) { //���ַ�����λ��
		char tmp = *start;
		*start = *end;
		*end = tmp;
		++start;
		--end;
	}
}
//дһ���Կո�Ϊ�ָ�����ÿ���ָ�����ַ��������ַ����õĺ���
void Reverse_Every(char* s) {
	while (*s != '\0') {
		char* start = s; //ȷ��ÿ���ַ�������ʼ�ַ���λ��
		char* end = s;
		while (*end != ' ' && *end != '\0') {
			++end;
		}
		--end; //ȷ��ÿ���ַ����н�β�ַ���λ��
		while (start < end) { //���ַ�����λ��
			char tmp = *start;
			*start = *end;
			*end = tmp;
			++start;
			--end;
		}
		while (*s != ' ' && *s != '\0') {//����s��λ��
			++s;
		}
		if (*s != '\0') { //����λ��,���һ���ַ�������
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
