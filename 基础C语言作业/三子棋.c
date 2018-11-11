#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
//三个字连成一条线，横竖斜都算获胜

#define ROW 3
#define COL 3
char g_board[ROW][COL];
//1.进行棋盘的初始化
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
	printf("玩家请落子!\n");
	while (1)
	{

		printf("请玩家输入棋子坐标（row col):");
		int row, col;
		scanf("%d %d", &row, &col);
		row = row - 1;
		col = col - 1;
		if (row < 0 || row >= ROW || col < 0 || col >= COL)
		{
			printf("请不要乱下，请认真下棋！\n");
			continue;
		}
		if (g_board[row][col] != ' ')
		{
			 printf("当前位置已被抢先，请重新落子\n");
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
	printf("请电脑落子!\n");
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
	
	//检查列，竖，斜线是否连成3个
	//检查行
	for (int row = 0; row < ROW; ++row)
	{
		if (g_board[row][0] == g_board[row][1] && g_board[row][0] == g_board[row][2]
			&& g_board[row][0] != ' ')
		{
			return g_board[row][0];
		}
	}
	//检查列
	for (int col = 0; col < COL; ++col)
	{
		if (g_board[0][col] == g_board[1][col] && g_board[0][col] == g_board[2][col]
			&& g_board[0][col] != ' ')
		{
			return g_board[0][col];
		}
	}
	//检查两条对角线
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
	//判断和棋
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
		//2.打印出棋盘（第一次是一个空白的棋盘）
		Print(g_board);
		//3.玩家落子，判定游戏是否结束
		PlayerMove(g_board);
		Print(g_board);
		winner = CheckWinner(g_board);
		if (winner != ' ')
		{
			break;
		}
		//玩家的子为x，电脑的子为o
		//winner ==> x玩家胜
		//winner ==> o电脑胜
		//winner ==> ' '胜负未分
		//winner ==> q 和棋
		//winner = CheckWinnner();

		ComputerMove(g_board);
		winner = CheckWinner(g_board);

		//4.电脑落子，判定游戏是否结束
		//ComputerMove();
		//winner = CheckWinner();

	} while (winner == ' ');
	Print(g_board);
	if (winner == 'x')
	
		printf("你赢了\n");
	
	if (winner == 'o')
	
		printf("连这个电脑都能输，你好菜啊\n");
	
	if (winner == 'q')
	    printf("连这个电脑都能和棋，你很不容易啊\n");
	
}





void manu()
{
	printf("欢迎来到三子棋游戏\n");
	printf("*****************************\n");
	printf("*****************************\n");
	printf("*********1.进入游戏**********\n");
	printf("*********2.退出游戏**********\n");
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