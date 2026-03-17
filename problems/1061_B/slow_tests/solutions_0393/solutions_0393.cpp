#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, t, b, k, p;
  cin >> n >> k;
  long long ans = 0;
  long long maxi = 0;
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    cin >> b;
    maxi = max(maxi, b);
    v.push_back(b);
  }
  if (n == 1) {
    cout << 0;
    return 0;
  }
  sort(v.begin(), v.end());
  for (int i = v.size() - 1; i >= 1; i--) {
    if (maxi == 0) {
      ans += (v[i] - 1);
      continue;
    }
    if (v[i - 1] == v[i]) {
      maxi--;
      ans += (v[i] - 1);
    } else {
      if (maxi > v[i - 1]) {
        ans += (v[i] - (maxi - v[i - 1]));
        maxi = v[i - 1];
      } else {
        maxi--;
        ans += (v[i] - 1);
      }
    }
  }
  if (maxi == 0) {
    ans += (v[0] - 1);
  } else {
    ans += (v[0] - maxi);
  }
  cout << ans;
  return 0;
}
