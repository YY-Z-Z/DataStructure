#include <iostream>
#include <cstring>
#include <stack>
#include <unordered_map>

using namespace std;

stack<int> num;//数字栈
stack<char> op;//符号栈

unordered_map<char, int> ta;//无序关联容器：映射表达式

//运算
void eval(stack<int>& num, stack<char>& op)
{
    int b = num.top();
    num.pop();
    int a = num.top();
    num.pop();
    char calc = op.top();
    op.pop();
    int ans = 0;
    if (calc == '+') {
        ans = a + b;
    }
    else if (calc == '-') {
        ans = a - b;
    }
    else if (calc == '*') {
        ans = a * b;
    }
    else {
        ans = a / b;
    }
    num.push(ans);
}

int main() {
    string str;
    cin >> str;

    //运算符优先级
    ta['+'] = 1;
    ta['-'] = 1;
    ta['*'] = 2;
    ta['/'] = 2;

    for (int i = 0; i < str.size(); i++)
    {
        auto ele = str[i];
        if (ele == ' ') continue;
        if (ele >= '0' && ele <= '9') //数字入栈
        {
            int j = i, tmp = 0;
            while (j < str.size() && str[j] >= '0' && str[j] <= '9')
            {
                tmp = tmp * 10 + (str[j] - '0');
                j++;
            }
            num.push(tmp);
            i = j - 1;//抵消多加的j++
        }
        else if (ele == '(')
        {
            op.push(ele);
        }
        else if (ele == ')')
        {
            while (op.size() && op.top() != '(') eval(num, op);//得出括号里的内容
            op.pop();   //弹出左括号
        }
        else
        {
            int rank = ta[ele];
            while (op.size() && op.top() != '(' && ta[op.top()] >= rank) eval(num, op);
            op.push(ele);
        }
    }

    while (op.size()) eval(num, op);

    cout << num.top() << endl;

    return 0;
}