#include <bits/stdc++.h>
using namespace std;
const int N = 26;
string s, target;
int vis[N][2][15], id = 1;
int f[15];
bool dp[N][2][15];
int get(char x, int ind, char y) {
  if (x == y) return ind + 1;
  if (ind) return get(x, f[ind - 1], target[f[ind - 1]]);
  return 0;
}
bool solve(int ind, bool l, int j) {
  if (ind == (int)s.size()) return (j + 1 == target.size()) && l;
  int &v = vis[ind][l][j];
  bool &ret = dp[ind][l][j];
  if (v == id) return ret;
  ret = 0;
  v = id;
  for (char i = '0'; i <= '9'; i++) {
    if (i < s[ind] && !l) continue;
    ret |= solve(ind + 1, l | (i > s[ind]), get(i, j, target[j]));
  }
  return ret;
}
void build(int ind, bool l, int j, string &t) {
  if (ind == s.size()) return;
  for (char i = '0'; i <= '9'; i++) {
    if (i < s[ind] && !l) continue;
    if (solve(ind + 1, l | (i > s[ind]), get(i, j, target[j]))) {
      t += i;
      build(ind + 1, l | (i > s[ind]), get(i, j, target[j]), t);
      break;
    }
  }
}
void build(string &t) {
  int j = 0;
  f[0] = 0;
  for (int i = 1; i < t.size(); ++i) {
    while (j > 0 && t[i] != t[j]) j = f[j - 1];
    if (t[i] == t[j]) ++j;
    f[i] = j;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (s.size() < 20) s += "0";
  s += "1988";
  string T = s;
  int n;
  cin >> n;
  while (n--) {
    string t;
    cin >> t;
    target = " ";
    s = T;
    int i = t.size() - 1;
    while (t[i] >= '0' && t[i] <= '9') {
      target = t[i] + target;
      build(target);
      i--;
      id++;
      solve(0, 0, 0);
      string f = "";
      build(0, 0, 0, f);
      s = f;
    }
    i = 0;
    while (i < s.size() && s[i] == '0') i++;
    cout << s.substr(i) << '\n';
  }
  return 0;
}
