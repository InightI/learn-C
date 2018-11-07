#include<stdio.h>
#include<stdlib.h>
 struct PERSON
{
 char name [20];
 char phonenum [15];
 struct PERSON *next; 
}; 

struct PERSON *head;

void Creat ()
{
	int i,pNum;
	struct PERSON *p, *pr;
	printf("please input the number of person.\n");
	scanf("%d",&pNum);
	fflush(stdin);
	p = (struct PERSON*)malloc(sizeof(struct PERSON));
	if (p==NULL)
	{
		printf("NO enough memory.\n");
		exit(0);
	}
	else
	{
		printf("please input the information of people.\n.\n");
		fgets(p->name,20,stdin);
		fgets(p->phonenum,15,stdin);
		head = p;
		pr = p;
	}
	for (i = 1; i<pNum; i++)
	{
		p = (struct PERSON*)malloc(sizeof(struct PERSON));
	    if (p==NULL)
	  {
		printf("NO enough memory.\n");
		exit(0);
	  }
	else
	{
		printf("please input the information of people.\n");
		fgets(p->name,20,stdin);
		fgets(p->phonenum,15,stdin);
		pr->next=p;
		pr=p;
	}
   }
  pr->next = NULL;

}

int main()
{
	char name [20];
	struct PERSON *p;
	Creat ();
	printf("please input the name of person you want to search:\n");
	fgets(name,20,stdin);
}
