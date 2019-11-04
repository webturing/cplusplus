#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class StringTopoSort {
public :
    StringTopoSort(vector<string> [], int);

    ~StringTopoSort();

    vector<string> string_topo_sort();

private :
    void visit(int index);

    int len;
    vector<string> *str_lists;
    vector<string> unsorted;
    vector<string> sorted;
    vector<int> *digit_eq;
    vector<int> digit_sorted;
    vector<bool> is_visited;
};


StringTopoSort::StringTopoSort(vector<string> *_str_lists, int _len) {
    str_lists = _str_lists;
    len = _len;
    digit_eq = new vector<int>[len];
    for (int i = 0; i < len; i++) {
        is_visited.push_back(false);
        unsorted.push_back(str_lists[i].at(0));
    }
    for (int i = 0; i < len; i++) {
        for (vector<string>::iterator it = str_lists[i].begin(); it < str_lists[i].end(); ++it) {
            vector<string>::iterator index = find(unsorted.begin(), unsorted.end(), *it);
            if (index != unsorted.end())
                digit_eq[i].push_back(index - unsorted.begin());
        }
    }
}

StringTopoSort::~StringTopoSort() {}

vector<string> StringTopoSort::string_topo_sort() {
    for (int i = 0; i < len; i++) {
        if (is_visited[i] == false)
            visit(i);
    }

    for (int i = 0; i < digit_sorted.size(); i++)
        sorted.push_back(unsorted[digit_sorted[i]]);

    return sorted;
}

void StringTopoSort::visit(int index) {
    is_visited[index] = true;

    for (vector<int>::iterator i = digit_eq[index].begin(); i < digit_eq[index].end(); i++) {
        if (!is_visited[*i])
            visit(*i);
    }
    digit_sorted.push_back(index);
}


int main(int argc, char **argv) {
    vector<string> headers[] = {{"A", "B", "C"},
                                {"B", "D"},
                                {"C"},
                                {"D", "C"}};
    StringTopoSort sorter(headers, 4);
    vector<string> sorted = sorter.string_topo_sort();
    for (int i = 0; i < sorted.size(); i++)
        cout << sorted[i] << " -- ";
    cout << endl;
    return 0;
}