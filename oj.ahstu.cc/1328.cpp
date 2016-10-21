#include<iostream>
#include<cctype>

using namespace std;

int main(int argc, char const *argv[]) {
    for (string line; getline(cin, line);) {
        cout << (char)toupper(line[0]);
        for (int i = 1; i < line.length(); i++)
            cout << (char)tolower(line[i]);
        cout << endl;
    }
    return 0;
}
