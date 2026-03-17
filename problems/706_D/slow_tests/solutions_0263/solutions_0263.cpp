#include <bits/stdc++.h>
using namespace std;
int node = 1;
string change(int x) {
  string s = "";
  while (x != 0) {
    s += (char)(x % 2 + 48);
    x = x / 2;
  }
  reverse(s.begin(), s.end());
  while (s.size() < 32) s = '0' + s;
  return s;
}
const int N = 1e7 + 9;
int check[N][2];
int f[N];
void add(int x) {
  string s = change(x);
  int curr = 1, tmp;
  for (int i = 0; i < s.size(); i++) {
    tmp = curr;
    if (check[curr][s[i] - 48] == 0) {
      node++;
      check[curr][s[i] - 48] = node;
      curr = node;
    } else
      curr = check[curr][s[i] - 48];
    f[curr]++;
  }
}
void remove(int x) {
  string s = change(x);
  int curr = 1;
  for (int i = 0; i < s.size(); i++) {
    curr = check[curr][s[i] - 48];
    f[curr]--;
  }
}
string res;
int kt[N];
void find(int x, string key, int d) {
  d++;
  kt[0] = (check[x][0] == 0 || f[check[x][0]] == 0) ? false : true;
  kt[1] = (check[x][1] == 0 || f[check[x][1]] == 0) ? false : true;
  if (!kt[0] && !kt[1]) return;
  if (!kt[0] || !kt[1]) {
    if (!kt[0]) {
      if (key[d] == '1')
        res += '0';
      else
        res += '1';
      find(check[x][1], key, d);
    } else {
      if (key[d] == '1')
        res += '1';
      else
        res += '0';
      find(check[x][0], key, d);
    }
  } else {
    res += '1';
    if (key[d] == '1')
      find(check[x][0], key, d);
    else
      find(check[x][1], key, d);
  }
}
long long revert(string s) {
  reverse(s.begin(), s.end());
  long long res = 0;
  for (int i = 0; i <= 30; i++) {
    long long tmp = s[i] - 48;
    if (tmp != 0) res += tmp * (long long)pow(2, i);
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, x;
  char c;
  cin >> n;
  add(0);
  for (int i = 1; i <= n; i++) {
    cin >> c >> x;
    if (c == '+') add(x);
    if (c == '-') remove(x);
    if (c == '?') {
      res = "";
      find(2, change(x), 0);
      cout << revert(res) << endl;
    }
  }
  return 0;
}
