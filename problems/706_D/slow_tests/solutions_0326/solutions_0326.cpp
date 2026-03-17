#include <bits/stdc++.h>
using namespace std;
struct node {
  int isend = 0;
  int cnt = 0;
  struct node* left;
  struct node* right;
};
node* root = new node();
struct node* getnode() {
  struct node* cur = new node();
  cur->left = NULL;
  cur->right = NULL;
  return cur;
}
void insert(struct node* root, string s) {
  struct node* cur = root;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '0') {
      if (cur->left == NULL) {
        cur->left = getnode();
      }
      cur->left->cnt++;
      cur = cur->left;
    } else {
      if (cur->right == NULL) {
        cur->right = getnode();
      }
      cur->right->cnt++;
      cur = cur->right;
    }
  }
  cur->isend++;
}
void deleteit(struct node* root, string s) {
  struct node* cur = root;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '0') {
      cur->left->cnt--;
      if (cur->left->cnt == 0) {
        cur->left = NULL;
        break;
      } else
        cur = cur->left;
    } else {
      cur->right->cnt--;
      if (cur->right->cnt == 0) {
        cur->right = NULL;
        break;
      } else
        cur = cur->right;
    }
  }
}
long long find(struct node* root, string s) {
  struct node* cur = root;
  long long ans = 0;
  int flag = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '0') {
      if (cur->right != NULL) {
        ans += (1ll << (31 - i));
        cur = cur->right;
      } else if (cur->left != NULL) {
        cur = cur->left;
        continue;
      }
    } else {
      if (cur->left != NULL) {
        ans += (1ll << (31 - i));
        cur = cur->left;
      } else if (cur->right != NULL)
        cur = cur->right;
      continue;
    }
  }
  return ans;
}
string get(int x) {
  string s = "";
  int sz = 0;
  while (x) {
    s = (char)(x % 2 + 48) + s;
    x /= 2;
    sz++;
  }
  while (sz <= 31) {
    s = '0' + s;
    sz++;
  }
  return s;
}
int main() {
  int q, i, j, k;
  cin >> q;
  insert(root, get(0));
  while (q--) {
    char ch;
    cin >> ch;
    if (ch == '+') {
      long long x;
      cin >> x;
      insert(root, get(x));
    }
    if (ch == '-') {
      long long x;
      cin >> x;
      deleteit(root, get(x));
    } else if (ch == '?') {
      long long x;
      cin >> x;
      long long ans = find(root, get(x));
      if (ans == 0) ans = x;
      cout << ans << "\n";
    }
  }
  return 0;
}
