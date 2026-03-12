//KMP算法 
//Subject:
//给定一个模式串 S，以及一个模板串 P，所有字符串中只包含大小写英文字母以及阿拉伯数字。
//模板串 P 在模式串 S 中多次作为子串出现。
//求出模板串 P 在模式串 S 中所有出现的位置的起始下标。
//输入格式
//第一行输入整数 N，表示字符串 P 的长度。
//第二行输入字符串 P。
//第三行输入整数 M，表示字符串 S 的长度。
//第四行输入字符串 S。
//输出格式
//共一行，输出所有出现位置的起始下标（下标从 0 开始计数），整数之间用空格隔开。
//数据范围
//1≤N≤1e5
//1≤M≤1e6
//输入样例：
//3
//aba
//5
//ababa
//输出样例：
//0 2

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
const int N = 100009,M=1000009;
int ne[N];
char p[N], s[M];
int num_p, num_s;

void CreatNext()
{
	int i, j;
	for (i = 2, j = 0; i <= num_p; i++)
	{
		while (j && p[j + 1] != p[i])j = ne[j];
		if (p[i] == p[j + 1])j++;
		ne[i] = j;
	}
}

void Compare_s()
{
	int i, j;
	for (i = 1, j = 0; i <= num_s; i++)
	{
		while (j && p[j + 1] != s[i])j = ne[j];
		if (p[j + 1] == s[i])j++;
		if (j == num_p)
		{
			printf("%d ", i - num_p);
			j = ne[j];
		}
	}
}

int main()
{
	scanf("%d%s%d%s", &num_p, p + 1, &num_s, s + 1);
	CreatNext();
	Compare_s();
	return 0;
}