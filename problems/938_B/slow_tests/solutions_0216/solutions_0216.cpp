#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 5;
int a[M];
int main() {
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> m;
    a[m] = 1;
  }
  int my = 1, fr = 1e6, cnt = 0, time = 0;
  while (cnt != n) {
    my++;
    fr--;
    if (a[my]) {
      cnt++;
    }
    if (my != fr && a[fr]) {
      cnt++;
    }
    time++;
  }
  cout << time << endl;
  return 0;
}
