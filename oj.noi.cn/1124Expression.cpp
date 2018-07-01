#include<bits/stdc++.h>

using namespace std;

/*推断符号间的优先关系函数
*1表示>,0表示=,-1表示<
*c1栈内的算符。c2栈外的算符
*/
int Judge(char c1, char c2) {
    int a1, a2;
    if ('+' == c1 || '-' == c1) a1 = 3;
    if ('*' == c1 || '/' == c1)a1 = 5;
    if ('(' == c1) a1 = 1;
    if (')' == c1) a1 = 7;
    if ('#' == c1) a1 = 0;

    if ('+' == c2 || '-' == c2)a2 = 2;
    if ('*' == c2 || '/' == c2)a2 = 4;
    if ('(' == c2) a2 = 6;
    if (')' == c2) a2 = 1;
    if ('#' == c2) a2 = 0;
    if (a1 > a2) return 1;
    if (a1 == a2) return 0;
    if (a1 < a2) return -1;
}

//符号运算函数
double run(char c, double d1, double d2) {
    switch (c) {
        case '+':
            return d1 + d2;
        case '-':
            return d1 - d2;
        case '*' :
            return d1 * d2;
        case '/':
            return d1 / d2;
        default:
            return 0.0;
    }
}

int main() {
    char *op = "+-*/()#";
    string str;
    cin >> str;
    //给表达式字符串str加入'#'结束标识符
    str.append(1, '#');
    stack<char> OPTR;//运算符栈
    stack<double> OPND;//操作数栈
    int a = -1;
    //先将#符号入栈
    OPTR.push('#');
    while (true) {
        int b = a + 1;
        a = str.find_first_of(op, a + 1);
        if (a == string::npos) break;
        if (a != b) {
            string ss(str, b, a - b);
            double d = atof(ss.c_str());
            //数据先入栈
            OPND.push(d);
        }
        //运算符优先级比較
        int ju = Judge(OPTR.top(), str[a]);
        if (-1 == ju)//栈外优先级大直接入栈
        {
            OPTR.push(str[a]);
        }
        if (0 == ju)//栈内外优先级相等则出栈
        {
            OPTR.pop();
        }
        if (1 == ju)//栈内优先级大,出栈进行运算
        {
            double d1 = OPND.top();
            OPND.pop();
            double d2 = OPND.top();
            OPND.pop();
            d1 = run(OPTR.top(), d2, d1);
            //运算结果入栈
            OPND.push(d1);
            OPTR.pop();
            a--;
        }
    }
    //删除表达式最后的'#'结束标识符
    str.erase(str.length() - 1, 1);
    cout << fixed << setprecision(2) << OPND.top() << endl;
}