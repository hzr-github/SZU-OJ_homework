/*
问题 A: 字符串操作（string）
时间限制: 3 Sec  内存限制: 128 MB
提交: 129  解决: 80
[提交][状态][讨论版]

题目描述
给定n个字符串（从1开始编号），每个字符串中的字符位置从0开始编号，长度为1-500，现有如下若干操作：
copy N X L：取出第N个字符串第X个字符开始的长度为L的字符串。
add S1 S2：判断S1，S2是否为0-99999之间的整数，若是则将其转化为整数做加法，若不是，则作字符串加法，返回的值为一字符串。  
find S N：在第N个字符串中从左开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。  
rfind S N：在第N个字符串中从右开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。  
insert S N X：在第N个字符串的第X个字符位置中插入S字符串。
reset S N：将第N个字符串变为S。
print N：打印输出第N个字符串。
printall：打印输出所有字符串。
over：结束操作。
其中N，X，L可由find与rfind操作表达式构成，S，S1，S2可由copy与add操作表达式构成。

提示：本题练习string类使用，所有的操作可调用string的方法实现。

输入
 第一行为一个整数n（n在1-20之间）  接下来n行为n个字符串，字符串不包含空格及操作命令等。  接下来若干行为一系列操作，直到over结束。

输出
 根据操作提示输出对应字符串。

样例输入
3
329strjvc
Opadfk48
Ifjoqwoqejr
insert copy 1 find 2 1 2 2 2
print 2
reset add copy 1 find 3 1 3 copy 2 find 2 2 2 3
print 3
insert a 3 2
printall
over

样例输出
Op29adfk48
358
329strjvc
Op29adfk48
35a8
*/
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
using namespace std;

int len = 0;
string *str;

int GetN(string s);
string GetS(string s);
bool IsInt(string s);
string Copy();
string Add();
int Find();
int RFind();
void Insert();
void Reset();
void Print();
void PrintAll();

int main()
{
    cin >> len;
    str = new string[len + 1]; //+1使得字符串的序号等于下标
    for (int i = 1; i < len + 1; i++)
        cin >> str[i];
    
    string cmd;
    while (true)
    {
        cin.sync(); //清空cin缓冲区里面未读取的信息
        cin >> cmd;

        if (cmd == "over")
            break;
        else if (cmd == "copy")
        {
            Copy();
        }
        else if (cmd == "add")
        {
            Add();
        }
        else if (cmd == "find")
        {
            Find();
        }
        else if (cmd == "rfind")
        {
            RFind();
        }
        else if (cmd == "insert")
        {
            Insert();
        }
        else if (cmd == "reset")
        {
            Reset();
        }
        else if (cmd == "print")
        {
            Print();
        }
        else if (cmd == "printall")
        {
            PrintAll();
        }
    }

    delete[] str;

    return 0;
}

int GetN(string s) //其中N，X，L可由find与rfind操作表达式构成
{
    if (s == "find")
        return Find();
    else if (s == "rfind")
        return RFind();
    else
        return s[0] - '0';
}

string GetS(string s) //S，S1，S2可由copy与add操作表达式构成
{
    if (s == "add")
        return Add();
    else if (s == "copy")
        return Copy();
    else
        return s;
}

bool IsInt(string s)
{
    if (s.length() > 6)
        return false;

    for (int i = 0; i < s.length(); i++)
        if (s.at(i) < '0' || s.at(i) > '9')
            return false;

    return true;
}

string Copy() //取出第N个字符串第X个字符开始的长度为L的字符串
{
    int N[3];
    string s;
    for (int i = 0; i < 3; i++)
    {
        cin >> s;
        N[i] = GetN(s);
    }
    return str[N[0]].substr(N[1], N[2]);
}

string Add() //判断S1，S2是否为0-99999之间的整数，若是则将其转化为整数做加法，若不是，则作字符串加法，返回的值为一字符串
{
    string S[2];
    for (int i = 0; i < 2; i++)
    {
        cin >> S[i];
        S[i] = GetS(S[i]);
    }

    if (IsInt(S[0]) && IsInt(S[1]))
    {
        int n1 = atoi(S[0].c_str());
        int n2 = atoi(S[1].c_str());

        string s;
        stringstream ss;
        ss << n1 + n2;
        ss >> s;

        return s;
    }
    return S[0] + S[1];
}

int Find() //在第N个字符串中从左开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度
{
    string S, n;
    int N;

    cin >> S;
    S = GetS(S);
    cin >> n;
    N = GetN(n);

    if (str[N].find(S) == -1)
        return str[N].size();
    return str[N].find(S);
}

int RFind() //在第N个字符串中从右开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度
{
    string S, n;
    int N;

    cin >> S;
    S = GetS(S);
    cin >> n;
    N = GetN(n);

    if (str[N].rfind(S) == -1)
        return str[N].size();
    return str[N].rfind(S);
}

void Insert() //在第N个字符串的第X个字符位置中插入S字符串
{
    string S, nx;
    int N, X;

    cin >> S;
    S = GetS(S);
    cin >> nx;
    N = GetN(nx);
    cin >> nx;
    X = GetN(nx);

    str[N].insert(X, S);
}

void Reset() //将第N个字符串变为S
{
    string S, n;
    int N;

    cin >> S;
    S = GetS(S);
    cin >> n;
    N = GetN(n);

    str[N].assign(S);
}

void Print() //打印输出第N个字符串
{
    string n;
    int N;

    cin >> n;
    N = GetN(n);

    cout << str[N] << endl;
}

void PrintAll() //打印输出所有字符串
{
    for (int i = 1; i < len + 1; i++)
        cout << str[i] << endl;
}
