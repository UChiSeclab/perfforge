#include <bits/stdc++.h>
using namespace std;
int f(int n1, int n2, int n) {
  if (n == 0)
    return n1;
  else if (n == 1)
    return n2;
  return f(n1, n2, n - 1) + f(n1, n2, n - 2);
}
int main() {
  int n1, n2, n;
  cin >> n1 >> n2 >> n;
  cout << f(n1, n2, n);
}
