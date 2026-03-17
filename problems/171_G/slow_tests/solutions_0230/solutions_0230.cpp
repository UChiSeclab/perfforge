#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int f(int n);
int main() {
  cin >> a >> b >> c;
  cout << f(c);
  return 0;
}
int f(int n) {
  if (n == 0) {
    return a;
  }
  if (n == 1) {
    return b;
  }
  return f(n - 2) + f(n - 1);
}
