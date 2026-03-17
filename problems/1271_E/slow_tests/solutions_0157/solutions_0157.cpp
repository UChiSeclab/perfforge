#include <bits/stdc++.h>
using namespace std;
unsigned long long int N, k;
string tgt;
string toStr(unsigned long long int x) {
  string res = "";
  while (x) {
    res = (char)(x % 2 + '0') + res;
    x /= 2;
  }
  return res;
}
unsigned long long int f(string str) {
  string cmp = tgt.substr(0, str.length());
  unsigned long long int res;
  if (cmp == str) {
    res = (1ULL << (tgt.length() - str.length())) - 1;
    for (unsigned long long int i = str.length(); i < tgt.length(); i++) {
      if (tgt[i] == '1') {
        res += (1ULL << (tgt.length() - i - 1));
      }
    }
    res++;
    if (str[str.length() - 1] == '0') {
      str[str.length() - 1] = '1';
      res += f(str);
    }
  } else if (cmp > str) {
    res = (1ULL << (tgt.length() - str.length() + 1)) - 1;
    if (str[str.length() - 1] == '0') {
      str[str.length() - 1] = '1';
      res += f(str);
    }
  } else {
    res = (1ULL << (tgt.length() - str.length())) - 1;
    if (str[str.length() - 1] == '0') {
      str[str.length() - 1] = '1';
      res += f(str);
    }
  }
  return res;
}
unsigned long long int getPath(unsigned long long int x) {
  if (x > N)
    return 0;
  else
    return f(toStr(x));
}
signed main() {
  cin >> N >> k;
  tgt = toStr(N);
  unsigned long long int l = 1, r = (N + 10) / 2, m, a, b;
  while (l + 1 < r) {
    m = (l + r) / 2;
    if (getPath(2 * m) >= k) {
      l = m;
    } else
      r = m;
  }
  a = 2 * l;
  l = 0, r = (N + 10) / 2;
  while (l + 1 < r) {
    m = (l + r) / 2;
    if (getPath(2 * m + 1) >= k) {
      l = m;
    } else
      r = m;
  }
  b = 2 * l + 1;
  if (getPath(a) < k)
    cout << b << endl;
  else
    cout << max(a, b) << endl;
}
