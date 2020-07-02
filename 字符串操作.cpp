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
    str = new string[len + 1]; //+1ʹ���ַ�������ŵ����±�
    for (int i = 1; i < len + 1; i++)
        cin >> str[i];
    
    string cmd;
    while (true)
    {
        cin.sync(); //���cin����������δ��ȡ����Ϣ
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

int GetN(string s) //����N��X��L����find��rfind�������ʽ����
{
    if (s == "find")
        return Find();
    else if (s == "rfind")
        return RFind();
    else
        return s[0] - '0';
}

string GetS(string s) //S��S1��S2����copy��add�������ʽ����
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

string Copy() //ȡ����N���ַ�����X���ַ���ʼ�ĳ���ΪL���ַ���
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

string Add() //�ж�S1��S2�Ƿ�Ϊ0-99999֮�����������������ת��Ϊ�������ӷ��������ǣ������ַ����ӷ������ص�ֵΪһ�ַ���
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

int Find() //�ڵ�N���ַ����д���ʼ��ѰS�ַ������������һ�γ��ֵ�λ�ã���û���ҵ��������ַ����ĳ���
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

int RFind() //�ڵ�N���ַ����д��ҿ�ʼ��ѰS�ַ������������һ�γ��ֵ�λ�ã���û���ҵ��������ַ����ĳ���
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

void Insert() //�ڵ�N���ַ����ĵ�X���ַ�λ���в���S�ַ���
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

void Reset() //����N���ַ�����ΪS
{
    string S, n;
    int N;

    cin >> S;
    S = GetS(S);
    cin >> n;
    N = GetN(n);

    str[N].assign(S);
}

void Print() //��ӡ�����N���ַ���
{
    string n;
    int N;

    cin >> n;
    N = GetN(n);

    cout << str[N] << endl;
}

void PrintAll() //��ӡ��������ַ���
{
    for (int i = 1; i < len + 1; i++)
        cout << str[i] << endl;
}