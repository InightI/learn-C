#include<stdio.h> 
int main(void)
{
 int a[10];
 int b;
 int c = 0; 
 printf("������ʮ����\n");
 
 for(b=0;b<10;b++)
 {
  scanf("%d",&a[b]); 
  if(c<a[b]) c=a[b];  
 }
 printf("���ֵ%d\n",c);
 syetem("pause") ;
 return 0; 
}
