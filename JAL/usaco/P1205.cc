#include <bits/stdc++.h>

using namespace std;

struct Matrix {
    int n;
    vector<vector<char>> v;

    Matrix(int n) : n(n) {
        v.resize(n);
        for (int i = 0; i < n; i++) {
            v[i].resize(n);
            fill(v[i].begin(), v[i].end(), '-');
        }
    };

    Matrix(const Matrix &that) : n(that.n) {
        v.resize(n);
        for (int i = 0; i < n; i++) {
            v[i].resize(n);
            copy(that.v[i].begin(), that.v[i].end(), v[i].begin());
        }
    };

    friend istream &operator>>(istream &is, Matrix &m) {
        for (int i = 0; i < m.n; i++)
            for (int j = 0; j < m.n; j++) {
                is >> m.v[i][j];
            }

        return is;
    }

    friend ostream &operator<<(ostream &os, const Matrix &m) {
        for (int i = 0; i < m.n; i++) {
            copy(m.v[i].begin(), m.v[i].end(), ostream_iterator<char>(os, ""));
            os << endl;
        }
        return os;
    }

    bool operator==(const Matrix &other) {
        if (n != other.n)return false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (v[i][j] != other.v[i][j])
                    return false;
        return true;
    }

    Matrix &operator=(const Matrix &other) {
        n = other.n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                v[i][j] = other.v[i][j];

    }

    void rot90() {
        vector<vector<char>> b(n, vector<char>(n, '-'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                b[i][j] = v[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                v[i][j] = b[n - j - 1][i];
    }

    void mirror() {
        vector<vector<char>> b(n, vector<char>(n, '-'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                b[i][j] = v[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                v[i][j] = b[i][n - j - 1];
    }

    bool op1(const Matrix &m) {// 1：转90度：图案按顺时针转90度。
        Matrix cp(*this);
        cp.rot90();
        return cp == m;
    }

    bool op2(const Matrix &m) {//   2：转180度：图案按顺时针转180度。
        Matrix cp(*this);
        for (int i = 0; i < 2; i++)cp.rot90();
        return cp == *this;
    }

    bool op3(const Matrix &m) {//3：转270度：图案按顺时针转270度。
        Matrix cp(*this);
        for (int i = 0; i < 3; i++)cp.rot90();
        return cp == *this;
    }

    bool op4(const Matrix &m) {//4：反射：图案在水平方向翻转（以中央铅垂线为中心形成原图案的镜像）。
        Matrix cp(*this);
        cp.mirror();
        return cp == *this;
    }

    bool op5(const Matrix &m) {
        Matrix cp(*this);
        cp.mirror();
        if (cp.op1(m))return true;
        cp = m;
        cp.mirror();
        if (cp.op2(m))return true;
        cp = m;
        cp.mirror();
        return cp.op3(m);

    }

    bool op6(const Matrix &m) {
        return *this == m;
    }

};

int main() {
    ifstream cin("input.txt");
    int sz;
    cin >> sz;
    Matrix start(sz), target(sz);
    cin >> start >> target;
    if (start.op1(target)) cout << 1 << endl;
    else if (start.op2(target)) cout << 2 << endl;
    else if (start.op3(target)) cout << 3 << endl;
    else if (start.op4(target)) cout << 4 << endl;
    else if (start.op5(target)) cout << 5 << endl;
    else if (start.op6(target)) cout << 6 << endl;
    else cout << 7 << endl;
    return EXIT_SUCCESS;
}