#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
const int MAX2 = 1e9;
const long long MAX3 = 1e12;
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  int a1 = a % b;
  return gcd(b, a1);
}
void swap1(char& x, char& y) {
  char t = x;
  x = y;
  y = t;
}
int main() {
  int n, a, b, c, sum = 0;
  cin >> n >> a >> b >> c;
  for (int x = 0; x <= n; x++) {
    for (int y = 0; y <= n; y++) {
      int s = a * x + b * y;
      int z = abs(n - s) / c;
      if (sum < x + y + z && s + c * z == n) {
        sum = x + y + z;
      }
    }
  }
  cout << sum;
}
