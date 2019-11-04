#include <iostream>

using namespace std;

int main() {
    int boy, girl;
    cin >> boy >> girl;
    if (boy + girl < 10)
        cout << "water" << endl;
    else if (boy > girl)
        cout << "tree" << endl;
    else
        cout << "tea" << endl;
    return 0;
}