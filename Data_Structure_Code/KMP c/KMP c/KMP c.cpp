#define _CRT_SECURE_NO_WARNINGS
//时间复杂度O(n+m)
#include<stdio.h>
char s[1000009], p[100009];
int ne[100009];

int main()
{
	int n, m, i, j;
	scanf("%d%s%d%s", &n, p + 1, &m, s+1);
		//构造ne[]
		//下标从1开始，ne[0]=0,ne[1]=0,表示若第一个不匹配，则从重新开始配 
		for (i = 2, j = 0; i <= n; i++) //p，s，ne下标都从1开始 
		{
			//i找后缀，j找前缀 
			//如果j还能向前&&p[j+1]与p[i]不匹配时，j往前找后缀对应的前缀位置
			//即j相当于当前后缀位置，ne[j]为与j匹配的后缀位置
			//即p[j]==p[ne[j]]
			//若ne[j]==0,则没有对应相等的前缀 
			while (j && p[j + 1] != p[i])j = ne[j];
			if (p[i] == p[j + 1])j++; //若相等，则继续往下找
			ne[i] = j;//每个元素i都对应一个相等前缀的下标j，使p[ne[i]]==p[j]||ne[i]==0 
		}
	//s[]p[]匹配
	for (i = 1, j = 0; i <= m; i++)
	{
		//i遍历s[],j遍历p[]
		while (j && s[i] != p[j + 1])j = ne[j]; //不匹配时，p[]往s[]的后移 
		if (s[i] == p[j + 1])j++;//匹配成功，继续匹配 
		if (j == n)//全部匹配成功 
		{
			printf("%d ", i - n);
			j = ne[j];//继续匹配 
		}
	}
	return 0;
}