#include<iostream>
using namespace std;
class s
{
private:
    int a;
public:
    int b;
    void changea(int n);
    void printa()
    {
        cout<<this->a<<endl;
    }
};
void s::changea(int n)
{
    this->a=n;
}
int main()
{
    s t;
    t.changea(10);
    t.printa();
    return 0;
}
