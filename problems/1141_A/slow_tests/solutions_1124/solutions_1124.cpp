#include <bits/stdc++.h>
using namespace std;
map<int, int> s;
int f(int m, int n, int cnt = 0) {
  if (m == n) return cnt;
  int a = -1, b = -1;
  if (m == 1) return -1;
  if (m % 2 == 0) {
    a = f(m / 2, n, cnt + 1);
  }
  if (m % 3 == 0) {
    b = f(m / 3, n, cnt + 1);
  }
  return max(a, b);
}
int main() {
  int n, m;
  cin >> n >> m;
  cout << f(m, n, 0) << endl;
  return 0;
}
