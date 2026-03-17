#include <bits/stdc++.h>
int a, b, c, t;
using namespace std;
int f(int c) {
  if (c == 0) return a;
  if (c == 1) return b;
  return f(c - 1) + f(c - 2);
}
int main() {
  int k;
  cin >> a >> b >> c;
  k = f(c);
  cout << k;
  getchar();
  getchar();
}
