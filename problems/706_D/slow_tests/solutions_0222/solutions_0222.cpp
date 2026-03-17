#include <bits/stdc++.h>
using namespace std;
struct trieNode {
  trieNode *children[2];
  int counter;
  trieNode() {
    counter = 0;
    for (int i = 0; i < 2; i++) children[i] = NULL;
  }
} *root = new trieNode();
void add(string s, int delta) {
  trieNode *cur = root;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    int idx = s[i] - '0';
    if (cur->children[idx] == NULL) cur->children[idx] = new trieNode();
    cur = cur->children[idx];
    cur->counter += delta;
  }
}
int query(string s) {
  int n = s.length();
  int ret = 0;
  trieNode *cur = root;
  for (int i = 0; i < n; i++) {
    int idx = s[i] - '0';
    idx = 1 - idx;
    if (cur->children[idx] != NULL && cur->children[idx]->counter != 0) {
      ret += (1 << (n - i - 1));
      cur = cur->children[idx];
    } else {
      cur = cur->children[1 - idx];
    }
  }
  return ret;
}
string toBinary(int x) {
  string ret = "";
  while (x) {
    if (x % 2 == 0)
      ret = "0" + ret;
    else
      ret = "1" + ret;
    x /= 2;
  }
  while (ret.length() != 30) ret = "0" + ret;
  return ret;
}
int main() {
  int q;
  cin >> q;
  add(toBinary(0), 1);
  while (q--) {
    char type;
    int x;
    cin >> type >> x;
    if (type == '+') add(toBinary(x), 1);
    if (type == '-') add(toBinary(x), -1);
    if (type == '?') cout << query(toBinary(x)) << '\n';
  }
}
