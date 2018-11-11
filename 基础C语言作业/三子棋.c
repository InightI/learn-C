#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
//����������һ���ߣ�����б�����ʤ

#define ROW 3
#define COL 3
char g_board[ROW][COL];
//1.�������̵ĳ�ʼ��
void Init(char g_board[ROW][COL])
{
	srand((unsigned int) time(0));
	for (int row = 0; row < ROW; ++row)
	{
		for (int col = 0; col < COL; ++col)
		{
			g_board[row][col] = ' ';
		}		
	}
}



void Print(char g_board[ROW][COL])
{
		int row = 0;
		printf("   1   2   3 \n");
		printf("  ___________\n");
		for (row = 0; row < ROW; row++)
		{
			printf("%d", row + 1);
			printf("| %c | %c | %c |\n", g_board[row][0], g_board[row][1], g_board[row][2]);
			if (row != 2)
				printf(" |---|---|---|\n");
		}
		printf(" ~~~~~~~~~~~~~\n");
}





void PlayerMove(char g_board[ROW][COL])
{
	printf("���������!\n");
	while (1)
	{

		printf("����������������꣨row col):");
		int row, col;
		scanf("%d %d", &row, &col);
		row = row - 1;
		col = col - 1;
		if (row < 0 || row >= ROW || col < 0 || col >= COL)
		{
			printf("�벻Ҫ���£����������壡\n");
			continue;
		}
		if (g_board[row][col] != ' ')
		{
			 printf("��ǰλ���ѱ����ȣ�����������\n");
			 continue;
		}
		g_board[row][col] = 'x';
		break;
	}

}


char CheckFull(char g_board[ROW][COL])
{
	int row = 0;
	int col = 0;
	for (row = 0; row < ROW; row++)
	{
	    for (col = 0; col < COL; col++)
	    {
		    if (g_board[row][col] == ' ')	    
			  return 0;		     
	    }
    }
	return 1;
}




void ComputerMove(char g_board[ROW][COL])
{
	int row = 0;
	int col = 0;
	printf("���������!\n");
	while (1)
	{		
		row = rand() % ROW;
		col = rand() % COL;
		if (CheckFull(g_board))
			break;
		if (g_board[row][col] == ' ')
		{
			g_board[row][col] = 'o';
			break;
		}
		
		
	}

}




char CheckWinner(char g_board[ROW][COL])
{
	
	//����У�����б���Ƿ�����3��
	//�����
	for (int row = 0; row < ROW; ++row)
	{
		if (g_board[row][0] == g_board[row][1] && g_board[row][0] == g_board[row][2]
			&& g_board[row][0] != ' ')
		{
			return g_board[row][0];
		}
	}
	//�����
	for (int col = 0; col < COL; ++col)
	{
		if (g_board[0][col] == g_board[1][col] && g_board[0][col] == g_board[2][col]
			&& g_board[0][col] != ' ')
		{
			return g_board[0][col];
		}
	}
	//��������Խ���
	if (g_board[0][0] == g_board[1][1] && g_board[0][0] == g_board[2][2]
		&& g_board[0][0] != ' ')
	{
		return g_board[0][0];
	}
	if (g_board[2][0] == g_board[1][1] && g_board[2][0] == g_board[0][2]
		&& g_board[2][0] != ' ')
	{
		return g_board[2][0];
	}
	//�жϺ���
	if (CheckFull(g_board))
		return 'q';
	else
		return ' ';

}





void Game(char g_board[ROW][COL])
{
	Init(g_board);
	char winner = 0;
	do
	{
		//2.��ӡ�����̣���һ����һ���հ׵����̣�
		Print(g_board);
		//3.������ӣ��ж���Ϸ�Ƿ����
		PlayerMove(g_board);
		Print(g_board);
		winner = CheckWinner(g_board);
		if (winner != ' ')
		{
			break;
		}
		//��ҵ���Ϊx�����Ե���Ϊo
		//winner ==> x���ʤ
		//winner ==> o����ʤ
		//winner ==> ' 'ʤ��δ��
		//winner ==> q ����
		//winner = CheckWinnner();

		ComputerMove(g_board);
		winner = CheckWinner(g_board);

		//4.�������ӣ��ж���Ϸ�Ƿ����
		//ComputerMove();
		//winner = CheckWinner();

	} while (winner == ' ');
	Print(g_board);
	if (winner == 'x')
	
		printf("��Ӯ��\n");
	
	if (winner == 'o')
	
		printf("��������Զ����䣬��ò˰�\n");
	
	if (winner == 'q')
	    printf("��������Զ��ܺ��壬��ܲ����װ�\n");
	
}





void manu()
{
	printf("��ӭ������������Ϸ\n");
	printf("*****************************\n");
	printf("*****************************\n");
	printf("*********1.������Ϸ**********\n");
	printf("*********2.�˳���Ϸ**********\n");
	printf("*****************************\n");
	printf("*****************************\n");
}





int main()
{
	int input = 0;
	while (1)
	{
		manu();
		scanf("%d", &input);
		if (input == 1)
		{
			Game(g_board);
			break;
		}
		else
			return 0;
	}
	system("pause");
	return 0;
}