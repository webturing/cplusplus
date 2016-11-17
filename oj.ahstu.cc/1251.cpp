#include <vector>
#include <string>
#include <iostream>

using namespace std;

void split(const string &s,
           const string &delim,
           vector<string> &ret) {
    size_t last = 0;
    size_t index = s.find_first_of(delim, last);
    while (index != string::npos) {
        ret.push_back(s.substr(last, index - last));
        last = index + 1;
        index = s.find_first_of(delim, last);
    }
    if (index - last > 0) {
        ret.push_back(s.substr(last, index - last));
    }
}

int atoi(const string &s) {
    int ret = 0;
    for (size_t i = 0; i < s.length(); i++)
        ret = ret * 10 + s[i] - '0';
    return ret;
}

int D[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int leap(int y) {
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

int main() {

    for (string line; getline(cin, line);) {
        vector<string> v;
        split(line, "/", v);
        int y = atoi(v[0]), m = atoi(v[1]), d = atoi(v[2]);
        for (int i = 1; i < m; i++)
            d += D[leap(y)][i];
        cout << d << endl;

    }
    return 0;
}