#include<stdio.h> 
int main(void)
{
 int a[10];
 int b;
 int c = 0; 
 printf("请输入十个数\n");
 
 for(b=0;b<10;b++)
 {
  scanf("%d",&a[b]); 
  if(c<a[b]) c=a[b];  
 }
 printf("最大值%d\n",c);
 syetem("pause") ;
 return 0; 
}
