#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> Point;
struct Rectangle {
    Point leftDown;
    Point rightUp;
};

int main() {
    ifstream cin("input.txt");
    int R;
    cin >> R;
    int N;
    cin >> N;
    vector<Rectangle> rects(N);
    int subS = 0;
    for (auto &rect:rects) {
        int L, T, W, H;
        cin >> L >> T >> W >> H;
        subS += W * H;
        rect.leftDown.first = L;
        rect.leftDown.second = T - H;
        rect.rightUp.first = L + W;
        rect.rightUp.second = T;
    }

    int best = 0, dif = subS;
    for (int mid = R; mid >= 0; --mid) {
        int leftS = 0;
        for (auto rect:rects) {
            int a = rect.leftDown.first;
            int b = rect.leftDown.second;
            int c = rect.rightUp.first;
            int d = rect.rightUp.second;
            leftS += (d - b) * (min(c, mid) - a);
        }
        if (2 * leftS > subS && 2 * leftS - subS < dif) {
            dif = 2 * leftS - subS;
            best = mid;
        }
    }

    cout << best << endl;
    return 0;
}