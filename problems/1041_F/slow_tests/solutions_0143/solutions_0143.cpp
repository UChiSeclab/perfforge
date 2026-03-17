#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, y1;
  cin >> n >> y1;
  map<long long int, long long int> fre;
  vector<long long int> arr1(n);
  for (long long int i = 0; i < n; i++) {
    cin >> arr1[i];
    fre[arr1[i]]++;
  }
  long long int m, y2;
  cin >> m >> y2;
  vector<long long int> arr2(m);
  for (long long int i = 0; i < m; i++) {
    cin >> arr2[i];
    fre[arr2[i]]++;
  }
  long long int ans = 0;
  for (auto x : fre) {
    ans = max(ans, x.second);
  }
  for (long long int i = 0; i < 32; i++) {
    long long int val = ((long long int)1 << i);
    val *= 2;
    map<long long int, long long int> m1;
    for (long long int i = 0; i < n; i++) {
      m1[arr1[i] % val]++;
    }
    for (long long int i = 0; i < m; i++) {
      m1[(arr2[i] + val / 2) % val]++;
    }
    for (auto x : m1) {
      ans = max(ans, x.second);
    }
    m1.clear();
    for (long long int i = 0; i < m; i++) {
      m1[arr2[i] % val]++;
    }
    for (long long int i = 0; i < n; i++) {
      m1[(arr1[i] + val / 2) % val]++;
    }
    for (auto x : m1) {
      ans = max(ans, x.second);
    }
  }
  cout << ans << "\n";
}
