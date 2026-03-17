#include <bits/stdc++.h>
using namespace std;
int a1, a2;
int f(int n) {
  if (n == 0) return a1;
  if (n == 1) return a2;
  return f(n - 1) + f(n - 2);
}
int main() {
  int n;
  cin >> a1 >> a2 >> n;
  cout << f(n);
  return 0;
}
