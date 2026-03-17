#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long linf = 1ll * inf * inf;
const int N = 100000 + 7;
const int M = 30;
const int multipleTest = 0;
const double pi = acos(-1);
string s[N];
string x[N];
int n;
void rotate() {
  string t[N];
  for (int i = (0), _b = (n); i < _b; ++i) {
    t[i] = "";
    for (int j = (0), _b = (n); j < _b; ++j) t[i] += '0';
  }
  for (int i = (0), _b = (n); i < _b; ++i)
    for (int j = (0), _b = (n); j < _b; ++j) t[i][j] = s[j][n - 1 - i];
  for (int i = (0), _b = (n); i < _b; ++i) s[i] = t[i];
}
void flip() {
  for (int i = (0), _b = (n); i < _b; ++i)
    for (int j = (i + 1), _b = (n); j < _b; ++j) swap(s[i][j], s[j][i]);
}
void solve() {
  cin >> n;
  for (int i = (0), _b = (n); i < _b; ++i) cin >> s[i];
  for (int i = (0), _b = (n); i < _b; ++i) cin >> x[i];
  for (int t = (0), _b = (4); t < _b; ++t) {
    bool check = true;
    for (int i = (0), _b = (n); i < _b; ++i)
      if (s[i] != x[i]) check = false;
    if (check) {
      puts("Yes");
      return;
    }
    ::rotate();
  }
  ::flip();
  for (int t = (0), _b = (4); t < _b; ++t) {
    bool check = true;
    for (int i = (0), _b = (n); i < _b; ++i)
      if (s[i] != x[i]) check = false;
    if (check) {
      puts("Yes");
      return;
    }
    ::rotate();
  }
  puts("No");
}
int main() {
  int Test = 1;
  if (multipleTest) {
    cin >> Test;
  }
  for (int i = 0; i < Test; ++i) {
    solve();
  }
}
