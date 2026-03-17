#include <bits/stdc++.h>
using namespace std;
const long long Max = 1000000000;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v;
    long long x = 5;
    v.push_back(2);
    for (long long i = 1; i <= 25820; i++) {
      long long k = v[v.size() - 1] + x;
      v.push_back(k);
      x += 3;
    }
    int cnt = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
      cnt += (n / v[i]);
      n = (n - (n / v[i] * v[i]));
    }
    cout << cnt << endl;
  }
}
