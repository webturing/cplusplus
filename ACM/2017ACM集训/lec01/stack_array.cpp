#include<iostream>
#include<string>
using namespace std;
template<class T>
class stack
{
private:
    T *s;
    int end;
    int len;
public:
    void init(int n);
    void push(T t);
    void pop();
    int size();
    void clear();
    T top();
};

template<class T>
void stack<T>::init(int n)
{
    s=new T[n];
    len=n;
    end=0;
}
template<class T>
void stack<T>::push(T t)
{
    if(end<len)
    {
        s[end]=t;
        end++;
    }
}
template<class T>
void stack<T>::pop()
{
    end--;
}
template<class T>
int stack<T>::size()
{
    return end;
}
template<class T>
void stack<T>::clear()
{
    end=0;
    delete[] s;
}
template<class T>
T stack<T>::top()
{
    return s[end-1];
}
int main()
{
    stack<int> s;
    s.init(10);
    for(int i=0;i<10;i++)
        s.push(i);
    while(s.size())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    s.clear();
    return 0;
}
