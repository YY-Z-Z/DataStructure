#define _CRT_SECURE_NO_WARNINGS

//A
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//typedef struct Node
//{
//	char name[99];
//	double grade1;
//	double grade2;
//	double grade3;
//	struct Node* next;
//}Node,*Link,*notpass,*full;
//
//void CreateLink(Link* L,int n)
//{
//	Link p,r;
//	r = *L;
//	int m = n;
//	while (m--)
//	{
//		p = (Node*)malloc(sizeof(Node));
//		scanf("%s %lf%lf%lf", p->name, &p->grade1, &p->grade2, &p->grade3);
//		r->next = p;
//		r = p;
//	}
//	r->next = NULL;
//}
//
//void judge(Link* L,notpass *nL,full *fL)
//{
//	Link p;
//	p = (*L)->next;
//	notpass np, nr;
//	nr = *nL;
//	full fp, fr;
//	fr = *fL;
//	while (p)
//	{
//		if (p->grade1 + p->grade2 +p->grade3 >= 300.0000)
//		{
//			printf("%s -- pass exam\n", p->name);
//			fp = (Node*)malloc(sizeof(Node));
//			fp = p;
//			//fp->next = NULL;
//			fr->next = fp;
//			fr = fp;
//		}
//		else if (p->grade1 + p->grade2 + p->grade3 >= 180)
//		{
//			printf("%s -- pass exam\n", p->name);
//		}
//		else
//		{
//			np = (Node*)malloc(sizeof(Node));
//			np = p;
//			//np->next = NULL;
//			nr->next = np;
//			nr = np;
//		}
//		p = p->next;
//	}
//	fr->next = NULL;
//	nr->next = NULL;
//}
//
//void OutPut(notpass* nL, full* fL)
//{
//	notpass np;
//	np = (*nL)->next;
//	full fp;
//	fp = (*fL)->next;
//	while (np)
//	{
//		printf("%s -- not pass exam\n",np->name); 
//		np = np->next;
//	}
//	while (fp)
//	{
//		printf("%s -- 3 x 100.0\n",fp->name);
//		fp = fp->next;
//	}
//}
//
//int main()
//{
//	Link L;
//	L = (Node*)malloc(sizeof(Node));
//	if (L == NULL)return 0;
//	notpass nL;
//	nL = (Node*)malloc(sizeof(Node));
//	if (nL == NULL)return 0;
//	full fL;
//	fL = (Node*)malloc(sizeof(Node));
//	if (fL == NULL)return 0;
//	int n;
//	scanf("%d", &n);
//	getchar();
//	CreateLink(&L,n);
//	judge(&L, &nL, &fL);
//	OutPut(&nL, &fL);
//	return 0;
//}

//B
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}Node,*Link;
//void CreatLink(Link* L,int n)
//{
//	Link p, r;
//	r = *L;
//	while (n--)
//	{
//		p = (Node*)malloc(sizeof(Node));
//		scanf("%d", &p->data);
//		r->next = p;
//		r = p;
//	}
//	r->next=NULL;
//}
//
//void InsertLink(Link* L, int x)
//{
//	Link p, t;
//	p = (*L)->next;
//	while (p->next)
//	{
//		if (p->next->data > x)
//		{
//			t = (Node*)malloc(sizeof(Node));
//			t->data = x;
//			t->next = p->next;
//			p->next = t;
//			break;
//		}
//		p = p->next;
//	}
//	t = (Node*)malloc(sizeof(Node));
//	t->data = x;
//	t->next = NULL;
//	p->next = t;
//}
//
//void OutPut(Link* L)
//{
//	Link p;
//	p = (*L)->next;
//	while (p)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//}
//
//int main()
//{
//	Link L;
//	L = (Node*)malloc(sizeof(Node));
//	if (L == NULL)return 0;
//	int n;
//	scanf("%d", &n);
//	CreatLink(&L,n);
//	int x;
//	scanf("%d", &x);
//	InsertLink(&L, x);
//	OutPut(&L);
//	return 0;
//}

//C
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}Node,*L1,*L2;
//void CreatLink(L1 *l1, L2 *l2,int n)
//{
//	L1 p1, r1;
//	L2 p2, r2;
//	r1 = *l1;
//	r2 = *l2;
//	while (n--)
//	{
//		int x;
//		scanf("%d", &x);
//		if (x % 2 != 0)
//		{
//			p1 = (Node*)malloc(sizeof(Node));
//			p1->data = x;
//			r1->next = p1;
//			r1 = p1;
//		}
//		else
//		{
//			p2 = (Node*)malloc(sizeof(Node));
//			p2->data = x;
//			r2->next = p2;
//			r2 = p2;
//		}
//	}
//	r1->next = NULL;
//	r2->next = NULL;
//}
//void OutPut(L1* l1, L2* l2)
//{
//	L1 p1;
//	p1 = (*l1)->next;
//	L2 p2;
//	p2 = (*l2)->next;
//	while (p1)
//	{
//		printf("%d ", p1->data);
//		p1 = p1->next;
//	}
//	printf("\n");
//	while (p2)
//	{
//		printf("%d ", p2->data);
//		p2 = p2->next;
//	}
//}
//int main()
//{
//	L1 l1;
//	L2 l2;
//	l1 = (Node*)malloc(sizeof(Node));
//	l2 = (Node*)malloc(sizeof(Node));
//	int n;
//	scanf("%d", &n);
//	CreatLink(&l1, &l2,n);
//	OutPut(&l1, &l2);
//	return 0;
//}

//D
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}Node,*Link;
//void insert(Link* L)
//{
//	int n;
//	scanf("%d", &n);
//	Link p, r;
//	while (n--)
//	{
//		p = *L;
//		int w, x,i=1;
//		scanf("%d %d", &w, &x);
//		while (p && i < w)
//		{
//			i++;
//			p = p->next;
//		}
//		r = (Node*)malloc(sizeof(Node));
//		r->data = x;
//		r->next = p->next;
//		p->next = r;
//	}
//
//}
//void Delete(Link* L)
//{
//	int w;
//	scanf("%d", &w);
//	int i;
//	Link p;
//	p = (*L)->next;
//	for(i = 1; i < w; i++)
//	{
//		p = p->next;
//	}
//	printf("%d\n", p->data);
//	Link r;
//	r = p->next;
//	if (p->next == NULL)
//	{
//		free(p);
//		return ;
//	}
//	p->next = r->next;
//}
//void Clear(Link* L)
//{
//	Link p,r;
//	p = (*L)->next;
//	while (p)
//	{
//		r = p->next;
//		free(p);
//		p = r;
//	}
//	(*L)->next = NULL; 
//}
//void getelem(Link* L)
//{
//	Link p;
//	p = (*L)->next;
//	int i, x;
//	scanf("%d", &x);
//	for (i = 1; i < x; i++)
//	{
//		p = p->next;
//	}
//	printf("%d\n", p->data);
//}
//
//int main()
//{
//	Link L;
//	L = (Node*)malloc(sizeof(Node));
//	L->next = NULL;
//	char s[99];
//	while (scanf("%s", s))
//	{
//		if (*s == 'e')return 0;
//		if (*s == 'i')
//		{
//			insert(&L);
//		}
//		else if (*s == 'd')
//		{
//			Delete(&L);
//		}
//		else if (*s == 'c')
//		{
//			Clear(&L);
//		}
//		else if (*s == 'g')
//		{
//			getelem(&L);
//		}
//	}
//	return 0;
//}

//A
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//char op[999],str[999];
//int num[999] = { 0 }, top_num = -1,top_op=-1;
//void cal()
//{
//	if (op[top_op] == '+')
//	{
//		num[top_num-1 ] += num[top_num];
//		top_num--;
//	}
//	else if (op[top_op] == '-')
//	{
//		num[top_num-1 ] -= num[top_num];
//		top_num--;
//	}
//	else
//	{
//		num[top_num-1 ] *= num[top_num];
//		top_num--;
//	}
//}
//int main()
//{
//	char ch;
//	gets_s(str);
//	for (int i = 0; i < strlen(str);i++)
//	{
//		if (str[i] >= '0' && str[i] <= '9')
//		{
//				num[++top_num] = str[i] - '0';
//				cal();
//		}
//		else if (str[i] =='(')
//		{
//			op[++top_op] = str[i];
//			i++;
//			op[++top_op] = str[i];
//			i = i + 2;
//			num[++top_num] = str[i]-'0';
//		}
//		else if (str[i] == ')')
//		{
//			top_op = top_op - 2;
//		}
//		else if (str[i] == '+' || str[i] == '*'||str[i]=='-')
//		{
//			op[++top_op] = str[i];
//		}
//	}
//	top_op = top_op + 2;
//	while (top_num != 0)
//	{
//		cal();
//	}
//	printf("%d", num[0]);
//	return 0;
//}

//#include <cstdio>
//#include <iostream>
//#include <stack>
//#include <cstring>
//using namespace std;
//const int INF = 0x3fffffff;
//stack<char> st1;
//stack<int> st2;
//stack<int> snum;
//char ss[100] = {};
//int main() {
//	gets_s(ss);
//	int len = strlen(ss);
//	for (int i = 0; i < len; i++) {
//		int num = 0;
//		if (ss[i] - '0' >= 0 && ss[i] - '0' <= 9) {//是数字
//			int numsize = 0;
//			while (ss[i + numsize] - '0' >= 0 && ss[i + numsize] - '0' <= 9 && i + numsize < len) {
//				numsize++;
//			}
//			int count = 0;
//			for (int j = numsize; j > 0; j--) {
//				num += (int)((ss[i + count] - '0') * pow(10, j - 1));
//				count++;
//			}
//			st2.push(num);
//			i += numsize - 1;
//		}
//		else if (ss[i] == '(') {
//			st2.push(INF);
//		}
//		else if (ss[i] == '+' || ss[i] == '-' || ss[i] == '*' || ss[i] == '/') {
//			st1.push(ss[i]);
//		}
//		else if (ss[i] == ')') {
//			char app = st1.top();
//			st1.pop();
//			while (st2.top() != INF) {
//				snum.push(st2.top());
//				st2.pop();             
//			}
//			st2.pop();//把左括号弹出；
//			int sum = snum.top();
//			snum.pop();
//			while (!snum.empty()) {
//				if (app == '+') {
//					sum += snum.top();
//					snum.pop();
//
//				}
//				else if (app == '-') {
//					sum -= snum.top();
//					snum.pop();
//				}
//				else if (app == '*') {
//					sum *= snum.top();
//					snum.pop();
//				}
//				else if (app == '/') {
//					sum /= snum.top();
//					snum.pop();
//				}
//			}
//			st2.push(sum);
//		}
//	}
//	if (st1.empty()) {
//		cout << st2.top();
//	}
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//const int maxx=99999;
//char op[9999], str[9999];
//int num[9999] = { 0 }, temp[9999];
//int top_op = 0, top_num = 0,top_temp=0;
//
//void cal()
//{
//	char opp = op[top_op - 1];
//	int a = temp[--top_temp];
//	if (opp == '+')
//	{
//		temp[top_temp - 1] += a;
//	}
//	else if(opp=='-')
//	{
//		temp[top_temp - 1]= a-temp[top_temp-1];
//	}
//	else if (opp == '*')
//	{
//		temp[top_temp - 1] *= a;
//	}
//	else if (opp == '/')
//	{
//		temp[top_temp - 1] = a/temp[top_temp-1];
//	}
//}
//
//int main()
//{
//	gets_s(str);
//	for (int i = 0; i < strlen(str); i++)
//	{
//		if (str[i] >= '0' && str[i] <= '9')
//		{
//			num[top_num] = 0;
//			while (str[i] >= '0' && str[i] <= '9')
//			{
//				num[top_num] = num[top_num] * 10 + str[i] - '0';
//				i++;
//			}
//			i--;
//			top_num++;
//		}
//		else if(str[i]=='(')
//		{
//			num[top_num++] = maxx;
//		}
//		else if (str[i] == ')')
//		{
//			int t = top_temp;
//			while (num[top_num - 1] != maxx)
//			{
//				temp[top_temp++] = num[top_num - 1];
//				top_num--;
//			}
//			while (t < top_temp-1)
//			{
//				cal();
//			}
//			top_num--;
//			num[top_num++] = temp[top_temp-1];
//			top_op--;
//		}
//		else if (str[i] != ' ')
//		{
//			op[top_op++] = str[i];
//		}
//	}
//	printf("%d", num[0]);
//	return 0;
//}

//B
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//typedef struct Node
//{
//	char name[999];
//	int score;
//	struct Node* next;
//}Node,*Link;
//void CreatLink(Link* L)
//{
//	char str[99];
//	Link r, p;
//	r = *L;
//	while (scanf("%s", str), *str != '#')
//	{
//		p = (Node*)malloc(sizeof(Node));
//		strcpy(p->name, str);
//		scanf("%d", &p->score);
//		r->next = p;
//		r = p;
//	}
//	r->next = NULL;
//}
//void Insert(Link* L)
//{
//	char str[99];
//	Link r, p;
//	while (scanf("%s", str), *str != '#')
//	{
//		int x;
//		scanf("%d", &x);
//		p = (*L)->next;
//		while (p->next&&p->next->score > x)p = p->next;
//		if (p->next&&p->next->score == x && strcmp(str, p->name) > 0)p = p->next;
//		r = (Node*)malloc(sizeof(Node));
//		r->score = x;
//		strcpy(r->name, str);
//		if (!p)
//		{
//			p->next = r;
//			return;
//		}
//		r->next = p->next;
//		p->next = r;
//	}
//}
//
//void Delete(Link* L)
//{
//	char str[99];
//	while (scanf("%s", str), *str != '#')
//	{
//		Link p;
//		p = (*L)->next;
//		while (p->next&&strcmp(p->next->name, str))p = p->next;
//		Link r;
//		r = p->next;
//		p->next = r->next;
//		free(r);
//	}
//}
//
//void OutPut(Link* L)
//{
//	Link p;
//	p = (*L)->next;
//	while (p)
//	{
//		printf("%s %d\n", p->name, p->score);
//		p = p->next;
//	}
//}
//
//int main()
//{
//	Link L;
//	L = (Node*)malloc(sizeof(Node));
//	CreatLink(&L);
//	Insert(&L);
//	Delete(&L);
//	OutPut(&L);
//	return 0;
//}

//C
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//typedef struct Node
//{
//	char name[99];
//	int score;
//	struct Node* next;
//}Node,*Link;
//
//void CreatLink(Link* L)
//{
//	Link p, r;
//	r = *L;
//	char str[99];
//	while (scanf("%s", str), *str != '#')
//	{
//		p = (Node*)malloc(sizeof(Node));
//		strcpy(p->name, str);
//		scanf("%d", &p->score);
//		r->next = p;
//		r = p;
//	}
//	r->next = NULL;
//}
//
//void sort(Link* L)
//{
//	Link p, t,r;
//	t = (Node*)malloc(sizeof(Node));
//	p = (*L)->next;
//	while (p)
//	{
//		r = p->next;
//		while (r)
//		{
//			if (p->score == r->score)
//			{
//				if (strcmp(p->name, r->name) > 0)
//				{
//					t->score = p->score;
//					p->score = r->score;
//					r->score = t->score;
//					strcpy(t->name, p->name);
//					strcpy(p->name, r->name);
//					strcpy(r->name, t->name);
//				}
//			}
//			else if (p->score > r->score)
//			{
//				t->score = p->score;
//				p->score = r->score;
//				r->score = t->score;
//				strcpy(t->name, p->name);
//				strcpy(p->name, r->name);
//				strcpy(r->name, t->name);
//			}
//			r = r->next;
//		}
//		p = p->next;
//	}
//}
//
//void OutPut(Link* L)
//{
//	Link p;
//	p = (*L)->next;
//	while (p)
//	{
//		printf("%s %d\n", p->name, p->score);
//		p = p->next;
//	}
//}
//
//int main()
//{
//	Link L;
//	L = (Node*)malloc(sizeof(Node));
//	CreatLink(&L);
//	sort(&L);
//	OutPut(&L);
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//typedef struct Node
//{
//	char name[9];
//	double score;
//	struct Node* next;
//}Node,*Link;
//void CreatLink(Link L[999])
//{
//	Link p, r;
//	int n;
//	scanf("%d", &n);
//	getchar();
//	for (int i = 1; i <= n; i++)
//	{
//		L[i] = (Node*)malloc(sizeof(Node));
//		double num,m,maxx=0,sum=0;
//		char maxname[9];
//		scanf("%lf", &num);
//		m = num;
//		while (m--)
//		{
//			p = (Node*)malloc(sizeof(Node));
//			scanf("%s %lf", p->name, &p->score);
//			if (p->score > maxx)
//			{
//				strcpy(maxname, p->name);
//				maxx = p->score;
//			}
//			sum += p->score;
//		}
//		printf("%d %.2lf %s %.0lf\n", i, sum/num, maxname, maxx);
//	}
//}
//int main()
//{
//	Link L[99];
//	CreatLink(L);
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* last;
}Node,*Link;

void CreatLink(Link* L,int n)
{
	Link r, p;
	r = *L;
	while (n--)
	{
		p = (Node*)malloc(sizeof(Node));
		scanf("%d", &p->data);
		p->last = r;
		r->next = p; 
		r = p;
	}
	r->next = NULL;
}

void OutPut(int begin, int end, Link* L)
{
	int i=1;
	Link p;
	p = (*L)->next;
	while (i < end)p = p->next,i++;
	while (i > begin)
	{
		printf("%d ", p->data);
		i--;
		p = p->last;
	}
	printf("%d\n",p->data);
}

int main()
{
	int n;
	while (scanf("%d", &n), n != 0)
	{
		int begin, end;
		scanf("%d%d", &begin, &end);
		Link L;
		L = (Node*)malloc(sizeof(Node));
		L->last = NULL;
		CreatLink(&L, n);
		OutPut(begin, end, &L);
	}
	return 0;
}