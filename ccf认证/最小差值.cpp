#include<iostream>
#include<list>
#include<cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    list<int> mylist;
    int temp = 0;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        mylist.push_back(temp);
    }

    int min = 10001;
    list<int>::iterator it1 = mylist.begin();
    list<int>::iterator it2 = mylist.begin();

    for (; it1 != mylist.end(); it1++) {
        it2 = it1;
        it2++;
        for (; it2 != mylist.end(); it2++) {
            if (abs(*it1 - *it2) < min)
                min = abs(*it1 - *it2);
        }
    }
    cout << min << endl;
    return 0;
} 
