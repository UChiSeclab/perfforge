#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 10004;
int a[MAX_N];
int main() {
  int n, k;
  double sum = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  double left = 0;
  double right = 1e6;
  for (int i = 0; i < 10000; i++) {
    double middle = (left + right) / 2;
    double pod = middle * n;
    for (int i = 0; i < n; i++) {
      if (a[i] < middle) {
        pod += (middle - a[i]) * ((double)100 / (double)(100 - k) - (double)1);
      }
    }
    if (pod > sum)
      right = middle;
    else
      left = middle;
  }
  cout << fixed << setprecision(10) << left;
  return 0;
}
