#include <bits/stdc++.h>
using namespace std;
long long n;
void sero(long long x, int i) {
  if (x > n) return;
  if (x == n) {
    cout << i;
    exit(0);
  }
  sero(x * 2, i + 1);
  sero(x * 3, i + 1);
}
int main() {
  int x;
  cin >> x >> n;
  sero(x, 0);
  cout << "-1";
  return 0;
}
