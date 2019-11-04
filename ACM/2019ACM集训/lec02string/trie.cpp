//
// Created by jal on 19-3-9.
//
#include <bits/stdc++.h>

using namespace std;
const int SIZE = 26;

struct Node {
    int sum;
    bool isEnd;
    char val;
    vector<Node *> son;

    Node(char val) :
            sum(0), isEnd(false), val(val) {
        son.resize(SIZE);
        for (auto &node : son) {
            node = NULL;
        }
    }
};

struct Trie {//字典树，实现单词的增删查写
    Node *root;

    Trie() {
        root = new Node('a');
    }

    /*
     * 往字典树中插入字符串
     */
    void insert(string s) {
        if (s.size() <= 0 || s == "")return;
        Node *node = root;
        for (auto &c: s) {
            int p = c - 'a';
            if (NULL == node->son[p]) {
                node->son[p] = new Node(c);
            }
            node->son[p]->sum++;
            node = node->son[p];
        }
        node->isEnd = true;
    }

    /*
     * 查找字符串是否在字典树中
     */
    bool search(string s) {
        if (s.size() <= 0 || s == "")return false;
        Node *node = root;
        for (auto &c: s) {
            int p = c - 'a';
            if (NULL == node->son[p]) {
                return false;
            }
            node = node->son[p];
        }
        return node->isEnd;
    }

    /*
     * 统计以s为前缀的字符串的个数
     */
    int countPrefix(string s) {
        if (s.size() <= 0 || s == "")return 0;
        Node *node = root;
        for (auto &c: s) {
            int p = c - 'a';
            if (NULL == node->son[p]) {
                return 0;
            }
            node = node->son[p];
        }
        return node->sum;
    }

    /*
     * 从字典树中删除s,成功返回true，失败返回false
     */
    void deleteString(string s) {
        if (s.size() <= 0 || s == "")return;
        Node *node = root;
        for (auto &c: s) {
            int p = c - 'a';
            if (NULL == node->son[p]) {
                return;
            }
            if (node->son[p]->sum-- <= 1) {
                node->son[p] = NULL;
                return;
            }
            node = node->son[p];
        }
        node->isEnd = false;
    }

    /*
     * 查找以s为前缀的字符串在字典中的节点指针
     */
    Node *getPrefixNode(string s) {
        if (s.size() <= 0 || s == "")return NULL;
        Node *node = root;
        for (auto &c: s) {
            int p = c - 'a';
            if (NULL == node->son[p]) {
                return NULL;
            }
            node = node->son[p];
        }
        return node;
    }

    /*
     * 先序遍历打印以s为前缀，指针为root的字典树
     */
    void preTraverse(string s, Node *root) {
        if (root->isEnd) {
            cout << s << endl;
        }
        for (int i = 0; i < SIZE; ++i) {
            if (root->son[i] != NULL) {
                preTraverse(s + root->son[i]->val, root->son[i]);
            }
        }
        return;
    }

    /*
     * 打印以s为前缀的字符串
     */
    void printStringByPrefix(string s) {
        if (s.size() <= 0 || s == "")return;
        if (countPrefix(s) <= 0)return;
        if (search(s))cout << s << endl;
        Node *node = getPrefixNode(s);
        preTraverse(s, node);
    }
};

int main() {
    Trie trie;
    trie.insert("jal");
    trie.insert("jiailing");
    trie.insert("jiailingx");
    trie.insert("jisuanji");
    cout << trie.search("jiailing") << endl;
    cout << trie.countPrefix("iai") << endl;
    cout << trie.countPrefix("ji") << endl;
    cout << trie.countPrefix("j") << endl;
    cout << trie.search("jal") << endl;
    trie.deleteString("jal");
    cout << trie.search("jal") << endl;
    cout << trie.countPrefix("j") << endl;
    trie.printStringByPrefix("j");
}
