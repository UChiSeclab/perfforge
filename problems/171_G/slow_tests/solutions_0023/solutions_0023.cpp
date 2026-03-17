#include <bits/stdc++.h>
using namespace std;
int a0, a1, n;
int f(int n) {
  if (n == 0) return a0;
  if (n == 1) return a1;
  return f(n - 1) + f(n - 2);
}
int main() {
  cin >> a0 >> a1 >> n;
  cout << f(n) << endl;
  return 0;
}
