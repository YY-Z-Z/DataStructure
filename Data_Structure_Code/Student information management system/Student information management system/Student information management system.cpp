#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#define Length sizeof(struct student)        
int n = 0;

struct student
{
	char name[20];           
	int num;            
	int breath;
	struct student* next;
}*head, * p, * p1, * p2;     

void add()                
{
	p1 = (struct student*)malloc(Length);         
	if (n == 0)
	{
		head = p1;
	}
	else
	{
		p2->next = p1;
	}
	system("cls");
	printf("请输入学生基本信息：\n序号：");
	scanf_s("%d", &p1->num);
	printf("姓名：");
	scanf_s("%s", &p1->name,5);
	printf("成绩：");
	scanf_s("%d", &p1->breath);
	p2 = p1;                                       
	p2->next = NULL;                             
	n += 1; 
	system("pause");
	system("cls");
}

void print()            
{
	if (n != 0)
	{
		p = head;                                   
		system("cls");
		printf("序号\t姓名\t\t成绩\n");
		p = head;
		while(p!=NULL)
		{
			printf("%-8d%-16s%-8d%\n", p->num, p->name, p->breath);
			p = p->next;                            
		} 
	}
	else
	{
		printf(" Σ( °△ °|||)︴您还没有添加数据!\n");
	}
		system("pause");
	system("cls");
}

void find()           
{
	void find1();
	void find2();
	if (n != 0)
	{
		int a;
		system("cls");
		printf("骚年，请选择查询方法\n1.按姓名查找\n2.按学号查询\n");
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:
			find1();
			break;
		case 2:
			find2();
			break;
		}
	}
	else
	{
		printf(" Σ( °△ °|||)︴震惊！您的数据跑走了!\n"); system("pause");
	}
}
void Delete()
{
	if (n != 0)
	{
		struct student* f, * l=NULL;                            
		char a[20];
		printf("输入你看着不爽的姓名(* ￣︿￣)：");
		scanf_s("%s", a,5);
		p = head;
		if (strcmp(head->name, a) == 0)
		{
			f = head; head = head->next; free(f);
		}
		else
		{
			do
			{
				if (strcmp(p->name, a) == 0)
				{
					f = p; l->next = p->next; free(f); break;
				}
				l = p;                                          
				p = p->next;
			} while (p != NULL);
		}
	}
	else
	{
		printf("Σ( °△ °|||)︴震惊！您的数据飞走了!\n");
	}
	printf("数据已经被删除\n");
	system("pause");                                   
	system("cls");
}
void amend()   
{
	if (n != 0)
	{
		int c;
		char a[20];
		printf("请输入要修改的姓名：");
		scanf_s("%s", a,5);
		p = head;
		do
		{
			if (strcmp(a, p->name) == 0)
			{
				printf("\n被修改人信息如下：\n学号\t姓名\t\t成绩\n");
				printf("%-8d%-16s%-8d%\n", p->num, p->name, p->breath);
				break;
			}
			p = p->next;                            
		} 
		while (p != NULL);
			printf("\n\n1.修改姓名\n2.修改学号\n3.修改成绩\n4.退出修改\n\n");
			scanf_s("%d", &c);
			switch (c)
			{
			case 1:
				printf("姓名修改为：");
				scanf_s("%s", p->name,5); break;
			case 2:
				printf("学号修改为：");
				scanf_s("%d", &p->num); break;
			case 3:
				printf("成绩修改为：");
				scanf_s("%d", &p->breath); break;
			case 4:
				break;
			}
			printf("\n\n操作成功!\n\n");
	}
	else
	{
		printf("Σ( °△ °|||)︴震惊！您的数据逃跑了!\n");
	}
	system("pause");
	system("cls");
}

void save()
{
	FILE* fp=NULL;
	struct student* p;
	if ((fopen_s(&fp, "grade.txt", "wb")) == NULL)
	{
		printf("Can not open the file!");
		fopen_s(&fp, "grade.txt", "w");
	}
	p = head;
	while (p != NULL)
	{
		if (fwrite(p, Length, 1, fp) != 1)
		{
			printf("写入数据出错\n");
			fclose(fp);
			break;
		}
		p = p->next;
	}
	if (fp != NULL)
	{
		fclose(fp);
	}
	printf("存储完成\n");
	system("pause");
	system("cls");
}

//struct student* createstu(int num,char name,int breath)
//{
//	struct student* newstu = (struct student*)malloc(sizeof(struct student));
//	newstu->num = num;
//	*newstu->name = name;
//	newstu->breath = breath;
//	newstu->next = NULL;
//	return newstu;
//}
//
//void insert(struct student* head, int num,char name,int breath)
//{
//	struct student* newstu = createstu(num,name,breath);
//	head = (student*)malloc(sizeof(student));
//	newstu->next = head->next;
//	head->next = newstu;
//}
//
//void read(FILE *fp,struct student *head)
//{
//	fopen_s(&fp, "grade.txt", "r");
//	if (fp== NULL)
//	{
//		printf("Can not open file!\n"); 
//		perror("open\n");
//		printf("open new file\n");
//		fopen_s(&fp, "grade.txt", "w");
//	}
//	struct student stu;
//		while(fscanf_s(fp,"%d %s %d\n",&stu.num,stu.name,&stu.breath)!=EOF)
//	{
//			insert(head, stu.num,*stu.name,stu.breath);
//			memset(&stu, 0, sizeof(stu));
//	} 
//	fclose(fp);
//	printf("读取完成!\n\n");
//	system("pause");
//	system("cls");
//}

void read()
{
	char sh;
	FILE* file;
	fopen_s(&file,"grade.txt", "r");
	if (file == NULL)
	{
		perror("read error");
	}
	else
	{
		sh = fgetc(file);
		while (!feof(file))
		{
			printf("%c", sh);
			sh = fgetc(file);
		}
	}
	fclose(file);
	system("pause");
}
 

void find1()
{
	char a[20];
	printf("请输入要查找的姓名：");
	scanf_s("%s", a,5);
	p = head;
	do
	{
		if (strcmp(a, p->name) == 0)
		{
			printf("\n信息已被找到：\n学号\t姓名\t\t成绩\n");
			printf("%-8d%-16s%-8d\n\n", p->num, p->name, p->breath);
		}
		p = p->next;
	} while (p != NULL);
	system("pause");
	system("cls");

}
void find2()
{
	int a;
	printf("请输入要查找的学号：");
	scanf_s("%d", &a);
	p = head;
	do
	{

		if (a == p->num)
		{
			printf("\n信息已被找到：\n学号\t姓名\t\t成绩\n");
			printf("%-8d%-16s%-8d\n\n", p->num, p->name, p->breath);
		}
		p = p->next;
	} while (p != NULL);
	system("pause");
	system("cls");
}

void free_list(student *head)
{
	student pointer;

	while (head != NULL)
	{
		pointer = *head;
		head = head->next;
		free(&pointer);
	}
}


void main()                                  
{
	int a = 1;
	FILE *fp;
	fopen_s(&fp, "grade.txt", "r");
	if (fp == NULL)
	{
		printf("open new\n");
		fopen_s(&fp, "grade.txt", "w");
	}
	while (a != 0)
	{
		system("cls");//清屏
		read();
		printf("Hi~ o(*￣▽￣*)ブ   学 生 成 绩 管 理 系 统(肺活量）   *(- ▽ -*)\n\n");
		printf("           (*^▽^*) 1.增加学生信息\n");
		printf("           (*^▽^*) 2.显示全部信息\n");
		printf("           (*^▽^*) 3.查找学生信息\n");
		printf("           (*^▽^*) 4.删除学生信息\n");
		printf("           (*^▽^*) 5.修改学生信息\n");
		printf("           (*^▽^*) 6.保存学生信息\n");
		printf("           (*^▽^*) 7.读取学生信息\n");
		printf("           (*^▽^*) 8.销毁链表\n");
		printf("           (*^▽^*) 0.退出系统+保存+销毁链表\n\n");
		printf(" o(*￣3￣)o 这位客官~~请选择：");
		scanf_s("%d", &a);
		if (a >= 0 && a <= 9)
		{
			if (a == 0)
			{
				save();
				free_list(head);
			}
			switch (a)
			{
			case 1:
				add();
				break;
			case 2:
				print();
				break;
			case 3:
				find();
				break;
			case 4:
				Delete();
				break;
			case 5:
				amend();
				break;
			case 6:
				save();
				break;
			case 7:
				//read(fp, head);
				read();
				break;
			case 8:
				free_list(head);
				break;
			}
		}
		else
		{
			printf(" (⊙_⊙) 您输入的不符合要求，将返回主菜单!\n");
			system("pause");
		}
	}
}



