#include<stdio.h>
#include<math.h>
   int main()

{
	   int i;
	   double sum = 0.0;
	   double sq = 0.0;
	   for (i = 1; i <= 100; i++)
	   {
		   sq = pow(-1, i + 1);
		   sum = sum + sq * 1 / i;
	   }
	   printf("sum is %lf\n", sum);
	   system("pause");
	   return 0;
}
