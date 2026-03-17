#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, s, d, i, j, k;
  cin >> a;
  vector<long long> v;
  for (i = 0; i < a; i++) {
    cin >> s;
    long long pol = min(s, i + 1);
    pol = min(pol, a - i);
    v.push_back(pol);
  }
  vector<long long> v2;
  long long now = 1e18;
  for (i = 0; i < a; i++) {
    now = min(now + 1, v[i]);
    v[i] = now;
  }
  now = 1e18;
  for (i = a - 1; i >= 0; i--) {
    now = min(now + 1, v[i]);
    v[i] = now;
  }
  long long ma = 0;
  for (i = 0; i < a; i++) ma = max(ma, v[i]);
  cout << ma;
}
