#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    stack<double> st;
    vector<string> v((istream_iterator<string>(cin)), istream_iterator<string>());
    for (auto i = v.rbegin(); i != v.rend(); ++i) {
        string s = *i;
        if (strstr("+-*/", s.c_str())) {
            cout << s << endl;
            double b = st.top();
            st.pop();
            double a = st.top();
            st.pop();
            if (s == "+")
                st.push(a + b);
            else if (s == "-")
                st.push(a - b);
            else if (s == "*")
                st.push(a * b);
            else st.push(a / b);
        } else {
            istringstream iss(s);
            double t;
            iss >> t;
            st.push(t);

        }
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << st.top() << endl;
    return 0;
}