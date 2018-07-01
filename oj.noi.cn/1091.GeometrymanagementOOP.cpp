#include <bits/stdc++.h>

using namespace std;

class Shape {
public:
    Shape() {}

    virtual void show() const =0;
};

class Triangle : public Shape {
public:
    int side;

    Triangle(int side = 0) : side(side) {}

    virtual void show() const {
        cout << "Triangle " << side << endl;
    }
};

class Circle : public Shape {
public:
    int radius;

    Circle(int radius = 0) : radius(radius) {};

    virtual void show() const {
        cout << "Circle " << radius << endl;
    }
};

struct Rectangle : public Shape {
public:
    int length, width;

    Rectangle(int length = 0, int width = 0) : length(length), width(width) {}

    virtual void show() const {
        cout << "Rectangle " << length << " " << width << endl;
    }
};

int main(int argc, char const *argv[]) {
    ifstream cin("input.txt");
    int n, Q;
    cin >> n >> Q;
    vector<Shape *> shapes(n + 1);
    for (int i = 1; i <= n; i++) {
        string type;
        cin >> type;
        if (type == "T") {
            Triangle *t = new Triangle;
            cin >> t->side;
            shapes[i] = t;
        } else if (type == "C") {
            Circle *c = new Circle;
            cin >> c->radius;
            shapes[i] = c;
        } else if (type == "R") {
            Rectangle *r = new Rectangle;
            cin >> r->length >> r->width;
            shapes[i] = r;
        }
    }
    while (Q--) {
        int idx;
        cin >> idx;
        shapes[idx]->show();
    }
    for (int i = 1; i <= n; i++)
        delete shapes[i];
    return 0;
}