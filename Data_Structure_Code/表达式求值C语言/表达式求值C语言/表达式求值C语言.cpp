#include<stdio.h>
#include<string.h>

int num[100009];//存数
char s[100009];//存完整表达式
char op[100009];//存运算符
int ni = -1, oi = -1;//分别为num[] op[]的栈顶指针

int h(char c)//运算符优先级
{
	if (c == '-' || c == '+')return 1;
	else return 2;
}

//运算,从右往左进行
void cal()
{
	int a = num[ni--];
	int b = num[ni--];
	char f = op[oi--];
	if (f == '+')
	{
		num[++ni] = a + b;
	}
	else if (f == '-')
	{
		num[++ni] = b - a;//∵从右往左，所以b是被除数
	}
	else if (f == '*')
	{
		num[++ni] = a * b;
	}
	else
	{
		num[++ni] = b / a;
	}
}

int main()
{
	gets_s(s);
	int l = strlen(s);
	for (int i = 0; i < l; i++)
	{
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9)//存数字
		{
			num[++ni] = s[i] - '0';
			while (s[i + 1] - '0' >= 0 && s[i + 1] - '0' <= 9)
			{
				i++;
				num[ni] = num[ni] * 10 + s[i] - '0';
			}
		}
		else if (s[i] == '(')
		{
			op[++oi] = '(';
		}
		else if (s[i] == ')')//找到），则向前运算
		{
			while (op[oi] != '(')//一直找到对应的括号，得出括号里的值
			{
				cal();
			}
			oi--;//op[oi]为'('，oi--即跳过'('
		}
		else
		{
			//括号外算值，考虑运算符的优先级！
			//若前面的运算符优先级高，前面先执行，如果后面的高，则再和下一次比较
			while (op[oi] != '(' && oi >= 0 && h(op[oi]) >= h(s[i]))
			{
				cal();
			}
			op[++oi] = s[i];
		}
	}
	while (oi >= 0)cal();//继续运算直到栈空
	printf("%d", num[0]);//栈顶即最终结果
	return 0;
}