#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  Node* next, *prev;
  Node(int data = 0, Node* next = NULL, Node* prev = NULL)
      : data(data), next(next), prev(prev) {}
};
struct List {
  Node* head, *tail;
  int _size;
  List() {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
    _size = 0;
  }
  friend ostream& operator<<(ostream& os, List& q) {
    Node* p = q.head->next;
    while (p != q.tail) {
      os << p->data << " ";
      p = p->next;
    }
    return os;
  }
  inline int& size() { return _size; }
  inline bool empty() { return _size == 0; }
  inline int back() { return tail->prev->data; }
  inline int front() { return head->next->data; }
  void push_front(Node* node) { insert(head, node, head->next); }
  void push_back(Node* node) { insert(tail->prev, node, tail); }
  void insert(Node* p, Node* q, Node* r) {
    p->next = q;
    q->prev = p;
    q->next = r;
    r->prev = q;
    ++_size;
  }
  void remove(Node* p, Node* q, Node* r) {
    p->next = r;
    r->prev = p;
    --_size;
  }
  void pop_front() { remove(tail->prev->prev, tail->prev, tail); }
  void pop_back() { remove(head, head->next, head->next->next); }
  void reverse() {
    for (Node* node = head; node != tail; node = node->next)
      swap(node->prev, node->next);
    swap(head, tail);
  }
};
int main() {
  ifstream cin("B.txt");
  ios::sync_with_stdio(false);
  for (int n, q; cin >> n >> q;) {
    vector<List> V(n + 1);
    while (q--) {
      int op;
      cin >> op;
      if (op == 1) {
        int u, w, val;
        cin >> u >> w >> val;
        if (w == 1)
          V[u].push_back(new Node(val));
        else
          V[u].push_front(new Node(val));
      } else if (op == 2) {
        int u, w;
        cin >> u >> w;
        if (V[u].empty())
          cout << -1 << endl;
        else {
          int ele;
          if (w == 1) {
            ele = V[u].back();
            V[u].pop_back();
          } else {
            ele = V[u].front();
            V[u].pop_front();
          }
          cout << ele << endl;
        }
      } else if (op == 3) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w == 1) {
          V[v].reverse();
        }
        while (V[v].size()) {
          V[u].push_back(new Node(V[v].front()));
          V[v].pop_front();
        }
      }
    }
  }
  return 0;
}