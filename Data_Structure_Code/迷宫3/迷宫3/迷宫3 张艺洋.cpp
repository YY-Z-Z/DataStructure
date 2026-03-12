//迷宫问题的描述为：
// 假设主体放在一个迷宫地图入口处，迷宫中有许多墙，使得大多数的路径都被挡住而无法行进。
// 主体可以通过遍历所有可能到出口的路径来到达出口。
// 当主体走错路时需要将走错的路径记录下来，避免下次走重复的路径，直到找到出口。主体需遵从如下三个原则：
//
//一次步进只能走一格；
//遇到路径堵塞后，退后直到找到另一条路径可行；
//走过的路径记录下来，不会再走第二次。

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
// 二维数组中，x表示行，y表示列
#define EAST MAZE[x][y+1]   // 东方向
#define WEST MAZE[x][y-1]   // 西方向
#define SOUTH MAZE[x+1][y]  // 南方向
#define NORTH MAZE[x-1][y]  // 北方向
int ExitX;        // 出口x坐标 
int ExitY;       // 出口y坐标 
const int BeginX = 1;//起点
const int BeginY = 1;
int MAZE[50][50];
int SizeX, SizeY;//迷宫大小

//路径链表
struct list
{
	int x, y;//迷宫中的下标
	struct list* next;//上一个路径
};
typedef struct list node;//定义结构体
typedef node* link;//定义结构体指针

//迷宫生成
void get_maze()
{
	int i, j;
	//先来个围墙
	for (i = 0; i < SizeY; i++)
	{
		MAZE[0][i] = 1;
		MAZE[SizeX - 1][i] = 1;
	}
	for (i = 1; i < SizeX; i++)
	{
		MAZE[i][0] = 1;
		MAZE[i][SizeY - 1] = 1;
	}
	//srand(time(0));
	//随机生成迷宫
	for (i = 1; i < SizeX - 1; i++)
	{
		for (j = 1; j < SizeY - 1; j++)
		{
			MAZE[i][j] = rand() % 2;
		}
	}
	//初始化起点终端
	MAZE[BeginX][BeginY] = 0;
	MAZE[ExitX][ExitY] = 0;
}

//走一步（xy加入链表）
link push(link path, int x, int y)
{
	link newnode;
	newnode = new node;//分配新node内存
	if (!newnode)
	{
		printf("Error:内存分配失败！");
		return NULL;
	}
	newnode->x = x;
	newnode->y = y;
	newnode->next = path;
	path = newnode;
	return path;
}

//撞墙退一退
link pop(link path, int* x, int* y)
{
	link top;
	if (path != NULL)
	{
		//保存当前路径
		top = path;
		path = path->next;//退回上一路径
		*x = top->x;
		*y = top->y;
		delete top;//释放内存
		return path;
	}
	else//路径链表为空，已经无路可退
	{
		*x -= 1;
	}
	return path;
}

//打印迷宫
void OutputMaze()
{
	int i, j;
	for (i = 0; i < SizeX; i++)
	{
		for (j = 0; j < SizeY; j++)
		{
			printf("  %d  ", MAZE[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int i, j;
	printf("请输入迷宫大小：（x,y)\n");
	while (~scanf("%d%d", &SizeX, &SizeY))
	{
		//生成迷宫
		ExitX = SizeX - 2;
		ExitY = SizeY - 2;
		int x = BeginX;        // 入口x坐标
		int y = BeginY;        // 入口y坐标
		printf("迷宫图\n0的位置可走，1的位置为墙\n");
		printf("起点(% d, % d), 终点(% d, % d)：\n", BeginX, BeginY, ExitX, ExitY);//显示地图
		get_maze();
		OutputMaze();

		// 开始走迷宫
		int finish = 0;//判断是否走成功
		link path = NULL;//初始化路径链表
		while (x <= ExitX || y <= ExitY)
		{
			if (x == 0 || y == 0)break;//防止走出外
			MAZE[x][y] = 2;//走的位置
			//各方都试一试
			if (EAST == 0)
			{
				y += 1;
				path = push(path, x, y);
			}
			else if (SOUTH == 0 )
			{
				x += 1;
				path = push(path, x, y);
			}
			else if (NORTH == 0)
			{
				x -= 1;
				path = push(path, x, y);
			}
			else if (WEST == 0 )
			{
				y -= 1;
				path = push(path, x, y);
			}
			else//无路可走
			{
				MAZE[x][y] = 2;
				path = pop(path, &x, &y);//退一步
			}
			if (x == BeginX && y == BeginY && MAZE[x][y + 1] != 0 && MAZE[x + 1][y] != 0)//没救了
			{//退回起点又无路可走
				break;
			}
			if (x == ExitX && y == ExitY)//找到出口
			{
				MAZE[ExitX][ExitY] = 2;
				finish = 1;
				break;
			}
		}
		if (finish == 1)
		{
			printf("通关!啦啦啦~（0的位置未走，1的位置为墙，2的位置已走）：\n");
		}
		else
		{
			printf("失败！呜呜呜~（0的位置未走，1的位置为墙，2的位置已走）：\n");
		}
		OutputMaze();
		printf("\n\n");
		printf("请输入迷宫大小：（x,y)\n");
	}
	return 0;
}