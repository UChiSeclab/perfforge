#include <bits/stdc++.h>
using namespace std;
void file() {}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
int com(double a, double b) {
  if (abs(a - b) <= 1e-6)
    return 0;
  else if (a > b)
    return 1;
  else
    return 2;
}
int valid(vector<int>& v1, double num, int k) {
  double pos = 0, neg = 0;
  for (int i = 0; i < (int)(v1.size()); i++) {
    if (com(v1[i], num) == 1)
      pos += (v1[i] - num);
    else if (com(v1[i], num) == 2)
      neg += (num - v1[i]) * 100 / (100 - k);
  }
  return com(neg, pos);
}
int main() {
  file();
  fast();
  double n, k;
  cin >> n >> k;
  vector<int> v1(n);
  for (int i = 0; i < n; i++) cin >> v1[i];
  double start = 0, end = INT_MAX, mid, ans = -1;
  for (int i = 0; i < 1000; i++) {
    mid = (start + end) / 2.0;
    if (valid(v1, mid, k) == 2)
      start = mid;
    else {
      end = mid;
      ans = mid;
    }
  }
  cout << fixed << setprecision(9);
  cout << ans << "\n";
  return 0;
}
