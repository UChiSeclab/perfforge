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
int valid(vector<long long>& v1, double num, long long k) {
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
  long long n, k;
  cin >> n >> k;
  vector<long long> v1(n);
  for (int i = 0; i < n; i++) cin >> v1[i];
  double start = 0, end = 1e12, mid, ans = -1;
  for (int i = 0; i < 1000; i++) {
    if (com(start, end) == 1) break;
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
