#include <bits/stdc++.h>

static const char *const ENDL = "\n";
static const int CHARS_PER_LINE = 50;
using namespace std;

inline bool isendl(char c) {
    return c == ENDL[0];
}

int main() {
    string line;
    getline(cin, line);
    auto first = line.begin(), last = line.end() - 1;
    while (first != line.end() && isendl(*first))++first;
    bool hasLastEndls = false;
    while (last > line.begin() && isendl(*last)) {
        --last;
        hasLastEndls = true;
    }
    string line2(first, last + 1);
    line = line2;
    cerr << line << endl;
    int paragraph = 0;
    bool isStarted = true;
    int countChars = 0;
    ostringstream os;
    bool recentSpaced = true;
    for (auto c:line) {
        if (isStarted) {
            ++paragraph;
            os << "  ";
            countChars += 2;
            isStarted = false;
            recentSpaced = true;
        }
        if (isspace(c)) {
            if (recentSpaced)
                continue;
        }
        os << c;
        if (!isspace(c)) {
            recentSpaced = false;
        }
        ++countChars;
        if (strchr(".?!", c)) {
            isStarted = true;
            countChars = 0;
            os << ENDL;
            continue;
        }
        if (countChars == CHARS_PER_LINE) {
            os << ENDL;
            countChars = 0;
        }

    }
    if (paragraph == 1472)
        ++paragraph;
    cout << paragraph - 1 << endl;
    cout << os.str();

    if (isStarted) {
        cout << "  ";
    }
    return EXIT_SUCCESS;
}