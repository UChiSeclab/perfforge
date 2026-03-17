#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, r1, r2, r3, d;
  cin >> n >> r1 >> r2 >> r3 >> d;
  long long mi = min(r1, min(r2, r3));
  long long sum = d * (n - 1);
  long long a[n];
  pair<long long, long long> b[n];
  pair<long long, long long> b1[n];
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    vector<long long> v;
    vector<long long> v1;
    v1.push_back(r2 + mi);
    v1.push_back(r1 * a[i] + r1 + mi);
    v.push_back(r1 * a[i] + r3);
    v1.push_back(r1 * a[i] + r3);
    v1.push_back(r1 * a[i] + r2 + mi);
    v.push_back(r3 * a[i] + r3);
    v1.push_back(r3 * a[i] + r3);
    v1.push_back(r3 * a[i] + r2 + mi);
    v1.push_back(r3 * a[i] + r1 + mi);
    b[i] = {*min_element(v.begin(), v.end()),
            *min_element(v1.begin(), v1.end())};
    b1[i] = b[i];
    b[i].first = min(b[i].first, b[i].second + 2 * d);
  }
  long long pr1[n + 1];
  pr1[0] = 0;
  pr1[1] = b[0].first;
  for (long long i = 2; i <= n; ++i) {
    pr1[i] = 1e18;
    pr1[i] = min(pr1[i], pr1[i - 1] + b[i - 1].first);
    pr1[i] =
        min(pr1[i], pr1[i - 2] + b[i - 2].second + 2 * d + b[i - 1].second);
    if (i >= 3) {
      pr1[i] = min(pr1[i], pr1[i - 3] + b[i - 3].second + 4 * d +
                               b[i - 2].second + b[i - 1].second);
    }
    if (i == n) {
      pr1[i] = min(pr1[i], pr1[i - 2] + b[i - 2].second + d + b[i - 1].first);
    }
  }
  cout << pr1[n] + sum;
  return 0;
}
