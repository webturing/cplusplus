#include <bits/stdc++.h>

using namespace std;
typedef pair<double, double> Point;
const double pi = acos(-1);

struct Circle {
    Point centre;
    int radius;

    bool inside(Point pt) {
        double dis = hypot(pt.first - centre.first, pt.second - centre.second);
        return dis <= radius;
    }
};

vector<Circle> circles;

bool inside(Point pt) {
    for (auto circle:circles) {
        if (circle.inside(pt))
            return true;
    }
    return false;
}


int main() {
    ifstream cin("input.txt");
    int a, b;
    cin >> a >> b;
    double g;
    cin >> g;
    int n;
    cin >> n;
    while (n--) {
        int x, y, z, r;
        cin >> x >> y >> z >> r;
        Circle circle;
        circle.centre.first = (x + tan((90.0 - g) * pi / 180) * z);
        circle.centre.second = y;
        circle.radius = r;
        circles.push_back(circle);
    }
    double TOTAL = a * b * 10000, INSIDE = 0;
    for (int i = 0; i < TOTAL; i++) {
        Point pt = make_pair((double) a * rand() / (RAND_MAX - 1), (double) b * rand() / (RAND_MAX - 1));
        if (inside(pt))
            ++INSIDE;
    }
    double S = INSIDE;
    cout << fixed << setprecision(2) << (TOTAL - S) / TOTAL * a * b << endl;
    return 0;
}