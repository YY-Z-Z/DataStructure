#define _CRT_SECURE_NO_WARNINGS
//时间复杂度O（m*n）
#include<stdio.h>
#include<string.h>
const int N = 100009;
char s[N], p[N];
int main()
{
	int i, j,n,m,k;
	scanf("%d%s%d%s", &n, p, &m, s);
	for (i = 0; i < strlen(s); i++)
	{
		k = i;
		for (j = 0; j < strlen(p); j++)
		{
			if (s[k++] != p[j])
			{
				break;
			}
			if (j== strlen(p)-1)
			{
				printf("%d ", i );
			}
		}
	}
	return 0;
}
