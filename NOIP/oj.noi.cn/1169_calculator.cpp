#include <bits/stdc++.h>
using  namespace std;
const double PI = 3.141592653;
int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n;
    cin >> n;
    while(n--){
        int op;
        double x;
        cin >> op >> x;
        switch (op){
            case 1:cout << fixed << setprecision(3) << sqrt(x) << endl;
                break;
            case 2:x = x / 180 * PI; cout << fixed << setprecision(3) << sin(x) << "  " << cos(x) << "  " << tan(x) << endl;
                break;
            case 3:cout << fixed << setprecision(3) << asin(x) << "  " << acos(x) << endl;
                break;
            case 4:cout << fixed << setprecision(3) << atan(x) << endl;
        }
    }
}