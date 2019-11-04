#include<iostream>     //标准输入输出流头文件。
#include<cstdlib>     //标准exit()所包含的头文件。
#include<iomanip>     //标准流格式头文件。
#include<stack>     //标准栈头文件。
//#include<gmpxx.h>     //GMP大数库头文件。
#include<windows.h>    //Windows头文件。
#include<cmath>

using namespace std;     //命名空间。
stack<double> A;     //数据栈 (存有效数字)。
stack<char> B;     //字符栈 (存运算符)。
void color(unsigned long);     //字体颜色设置。
void about(void);    //关于计算器。
void run(void);     //混合运算函数。// 
unsigned long priority(char);     //运算符优先级。
double computing(char);     //简单运算函数。
double fmod(double, double);     //自定义求模运算函数。
double pow(double, unsigned long);     //自定义乘方运算函数。
const double Max = 1e+10;    //最大范围，用科学计数法表示。
const double Min = -1e+10;     //最大范围，用科学计数法表示。
const double PI = 3.1415926535;     //PI的高精度值。
//////////////////////////////////////////////////////////////////////////////////////////
int main() {
    system("cls");   //清屏函数。（调用DOS命令）
    about();    //关于计算器。
    for (;;)   //无限循环。
        run();   //调用混合运算函数。
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
void color(unsigned long x) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x | 0);
}

//////////////////////////////////////////////////////////////////////////////////////////
void about() {
    color(8);    //更改输出的字体颜色。
    cout << "Calculator 2.6  Author: HuaJun Liu  Changed by Bobo" << endl;
    cout << "help: A=ABS, S=SQRT, P=PI. Q:Exit" << endl;////加上这个说明
}

//////////////////////////////////////////////////////////////////////////////////////////
double fmod(int x, int y) {     //自定义求模运算函数。
    int n = 0;
    if (x < 0)
        n = (int) (x / y);     //如果X小于零则向上取整。/////////???
    else
        n = (int) (x / y);     //如果X大于零则向下取整。
    return x - n * y;
}

//////////////////////////////////////////////////////////////////////////////////////////
double pow(double x, unsigned long y) {    //自定义乘方运算函数。
    unsigned long n;
    if (y >= 0)
        n = (unsigned long) y;    //强制类型转换成长整型。
    else
        n = (unsigned long) (-y);
    for (int z = 1;; x *= x) {    //比递归更高效的循环二分算法。
        if ((n & 1) != 0)
            z *= x;
        if ((n >>= 1) == 0)
            return (y < 0 ? double(1) / z : z);    //终止循环并返回最终值。
    }
}

//////////////////////////////////////////////////////////////////////////////////////////
void run() {////中缀转后缀表达式（运算符进出栈B）、后缀表达式的计算（数字进出栈A），"一起"进行，拿笔推算一遍就理解了
    ////初始化
    int c = 0, d = 0, bk = 0;////bk是B栈内左括号数目
    double P = 0, Z = 0, Re = 0;////变量名（初始值，位数）
    char ch = 0, ab = 0;     //"ab"变量用来标记上一次进栈的是数字还是运算符。
    cin.clear();
    cin.sync();      //清空输入流。
    while (!A.empty())
        A.pop();       //清空数据栈。
    while (!B.empty())
        B.pop();       //清空运算符栈。
    color(8);    //更改输出的字体颜色。
    cout << "Import: ";
    ////处理
    while (cin) {      //检查输入流是否可用。
        color(7);    //更改输入的字体颜色。
        cin.get(ch);      //输入表达式。（能读取空格符、换行符、回车符。）
        switch (ch) {
            case '(':
                if (ab != 'A') {     //左括号前不能是数字。
                    B.push(ch);
                    bk++;
                    break;
                }
                color(4);    //更改输出的字体颜色。
                cerr << "Expression Error" << endl;        ////抛出错误，然后退出
                return;
            case ')':
                if (bk != 0 && ab == 'A') {    //运算符栈中必须有左括号与右括号前必须是数字。
                    while (B.top() != '(') {
                        try {     //异常定义。（可能抛出异常的语句）
                            A.push(computing(B.top()));    //如果出现异常，函数内部会抛出异常。
                        } catch (double) {     //捕获并处理异常。
                            color(4);    //更改输出的字体颜色。
                            cerr << "Divisor Is Zero" << endl;
                            return;
                        }
                        B.pop();     //运算符出栈。
                    }
                    B.pop();
                    bk--;     //左括号出栈。
                    break;
                }
                color(4);    //更改输出的字体颜色。
                cerr << "Expression Error" << endl;    ////抛出错误，然后退出
                return;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                if (ch == '-' && ab != 'A') {     //当上一次进栈的是运算符，////则//// 当前'-'为负数标号。
                    cin.putback(ch);     //此函数将当前字符送回到缓冲区中。
                    if (cin >> P) {          //检查读取的数字是否有效。		////测试了一下，只会读取数字部分，不会读多。这样子就是一口气读出一个数字出来了
                        A.push(P);
                        ab = 'A';     //读取的数字进栈，"ab"变量记录下来。
                        break;
                    }
                    color(4);    //更改输出的字体颜色。
                    cerr << "Invalid Number" << endl;
                    return;
                } else if (ab != 'A') {     //运算符前面必须是数字。
                    color(4);    //更改输出的字体颜色。
                    cerr << "Expression Error" << endl;
                    return;
                }
                ////运算符处理
                while (!B.empty() && B.top() != '(') {   //运算符栈为空或栈顶元素为左括号时停止循环。
                    c = priority(B.top());
                    d = priority(ch);
                    if (c >= d) {////判断优先级后，决定1：运算符出栈B.top()，同时使得数字栈出栈，进行运算computing()，最后将运算结果压进栈A.push()
                        try {     //异常定义。（可能抛出异常的语句）
                            A.push(computing(B.top()));    //如果出现异常，函数内部会抛出异常。
                        } catch (double) {     //捕获并处理异常。
                            color(4);    //更改输出的字体颜色。
                            cerr << "Divisor Is Zero" << endl;
                            return;
                        }
                        B.pop();
                    } else
                        break;     //跳出循环。
                }
                B.push(ch);
                ab = 'B';     //运算符进栈，"ab"变量记录下来。////判断优先级后，决定2：运算符进栈
                break;
            case 'A':
                if (ab == 'A') {     //标记符前面必须是数字。
                    Re = A.top();
                    A.pop();     //（数字栈）栈顶元素赋给Re，然后出栈。
                    A.push(abs(Re));//Re>0?Re:-Re);     //abs(x) x的绝对值。
                    break;
                }
                color(4);    //更改输出的字体颜色。
                cerr << "Expression Error" << endl;
                return;
            case 'S':
                if (ab == 'A') {     //标记符前面必须是数字。
                    Re = A.top();
                    A.pop();     //（数字栈）栈顶元素赋给Re，然后出栈。
                    A.push(sqrt(Re));     //sqrt(x) x的平方根。
                    break;
                }
                color(4);    //更改输出的字体颜色。
                cerr << "Expression Error" << endl;
                return;
            case 'P':
                if (ab != 'A') {     //标记符前面必须是字符或者为空。
                    A.push(PI);
                    ab = 'A';      //读取的数字进栈，"ab"变量记录下来。
                    break;
                }
                color(4);    //更改输出的字体颜色。
                cerr << "Expression Error" << endl;
                return;
            case '\n':
            case '\r':
            case '=':
                if (B.empty() && A.empty()) {
                    system("cls");
                    about();     //清屏后打印帮助与程序说明。
                    return;
                } else if (bk != 0 || ab != 'A') {    //等号前不能出现左括号和不能没有数字。
                    color(4);    //更改输出的字体颜色。
                    cerr << "Expression Error" << endl;
                    return;
                }
                while (!B.empty()) {
                    try {     //异常定义。（可能抛出异常的语句）
                        A.push(computing(B.top()));    //如果出现异常，函数内部会抛出异常。
                    } catch (double) {     //捕获并处理异常。
                        color(4);    //更改输出的字体颜色。
                        cerr << "Divisor Is Zero" << endl;
                        return;
                    }
                    B.pop();
                }
                Z = A.top();
                A.pop();      //清空最后一个数据栈。
                if (Max > Z && Min < Z) {     //检查结果是否超出最大数据范围。
                    color(8);    //更改输出的字体颜色。
                    cout << "Amount: ";
                    color(2);    //更改输出的字体颜色。
                    cout << fixed << setprecision(4) << Z << endl;
                    return;
                }
                color(4);    //更改输出的字体颜色。
                cerr << "Overflow Error" << endl;
                return;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '.':
                cin.putback(ch);     //此函数将当前字符送回到缓冲区中。
                if (ab == 'A') {     //上一次进栈如果是数字，就说明表达式错误。
                    color(4);    //更改输出的字体颜色。
                    cerr << "Expression Error" << endl;
                    return;
                } else if (cin >> P) {      //检查读取的数字是否有效。    ////测试了一下，只会读取数字部分，不会读多。这样子就是一口气读出一个数字出来了
                    A.push(P);
                    ab = 'A';      //读取的数字进栈，"ab"变量记录下来。
                    break;
                }
                color(4);    //更改输出的字体颜色。
                cerr << "Invalid Number" << endl;
                return;
            case 'Q':
                exit(1);    //退出程序。
            default:
                color(4);    //更改输出的字体颜色。
                cerr << "Invalid Character" << endl;
                return;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////
unsigned long priority(char x) {
    switch (x) {
        case '+':
        case '-':
            return 0;     //将运算符优先级标记为数字。
        case '*':
        case '/':
        case '%':
            return 1;     //将运算符优先级标记为数字。
        case '^':
            return 2;     //将运算符优先级标记为数字。
        default:
            exit(1);////???
    }
}

//////////////////////////////////////////////////////////////////////////////////////////
double computing(char x) {////小运算：处理运算符和两个数字
    double a = 0, b = 0;
    switch (x) {
        case '+':
            b = A.top();
            A.pop();     //（数字栈）栈顶元素赋给b，然后出栈。
            a = A.top();
            A.pop();     //（数字栈）栈顶元素赋给a，然后出栈。
            return a + b;
        case '-':
            b = A.top();
            A.pop();     //（数字栈）栈顶元素赋给b，然后出栈。
            a = A.top();
            A.pop();     //（数字栈）栈顶元素赋给a，然后出栈。
            return a - b;
        case '*':
            b = A.top();
            A.pop();     //（数字栈）栈顶元素赋给b，然后出栈。
            a = A.top();
            A.pop();     //（数字栈）栈顶元素赋给a，然后出栈。
            return a * b;
        case '/':
            b = A.top();
            A.pop();     //（数字栈）栈顶元素赋给b，然后出栈。
            a = A.top();
            A.pop();     //（数字栈）栈顶元素赋给a，然后出栈。
            if (b != 0)
                return a / b;
            throw b;    //抛出异常。////【!!!!!】
        case '%':
            b = A.top();
            A.pop();     //（数字栈）栈顶元素赋给b，然后出栈。
            a = A.top();
            A.pop();     //（数字栈）栈顶元素赋给a，然后出栈。
            if (b != 0)
                return fmod(a, b);     //自定义求模运算函数。
            throw b;    //抛出异常。
        case '^':
            b = A.top();
            A.pop();     //（数字栈）栈顶元素赋给b，然后出栈。
            a = A.top();
            A.pop();     //（数字栈）栈顶元素赋给a，然后出栈。
            return pow(a, b);//.get_ui());    //自定义乘方运算函数。
        default:
            exit(1);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////
