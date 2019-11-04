#include <iostream>
#include <deque>
using namespace std;
template <typename T>
class stack {
 private:
  deque<T> elems;

 public:
  void push(T const&);
  void pop(void);
  T top() const;
  bool empty() const { return elems.empty(); }
  template <typename T2>
  stack<T>& operator=(stack<T2> const&);
  typedef const T* const_iterator;
  typedef T* iterator;
  T* end(void);
  T* begin(void);
};

template <typename T>
template <typename T2>
stack<T>& stack<T>::operator=(const stack<T2>& op2) {
  if ((void*)this == (void*)&op2) return *this;
  stack<T2> tmp(op2);
  elems.clear();

  while (!tmp.empty()) {
    elems.push_front(tmp.top());
    tmp.pop();
  }
  return *this;
}

template <typename T>
void stack<T>::push(T const& elem) {
  elems.push_back(elem);
}

template <typename T>
void stack<T>::pop() {
  if (elems.empty()) return;
  elems.pop_back();
}
template <typename T>
T stack<T>::top() const {
  if (elems.empty()) throw;
  return elems.back();
}
template <typename T>
T* stack<T>::begin() {
  return (&(elems.front()));
}
template <typename T>
T* stack<T>::end() {
  return ((&(elems.back())) + 1);
}

int main() {
  stack<int> s;
  stack<int>::iterator it;
  for (int i = 0; i < 10; i++) s.push(i);
  for (it = s.begin(); it != s.end(); it++) cout << *it << " ";
  cout << endl;
  for (int i = 0; i < 10; i++) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
  if (s.empty())
    cout << "stack is empty" << endl;
  else
    cout << "stack is not empty" << endl;
  return 0;
}
