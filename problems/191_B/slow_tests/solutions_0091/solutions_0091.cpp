#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int a[MAXN];
long long sss[MAXN];
int main() {
  int n, k;
  cin >> n >> k;
  long long b;
  cin >> b;
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<pair<int, int> > buf;
  for (int i = 0; i < n - 1; i++) buf.push_back(make_pair(a[i], i));
  sort(buf.begin(), buf.end());
  sss[n - 2] = buf[n - 2].first;
  for (int i = n - 3; i >= 0; i--) sss[i] = buf[i].first + sss[i + 1];
  int fans = n - 1;
  for (int i = 0; i < n - 1; i++) {
    if (n - 2 - i >= k) {
      long long slaves = sss[n - 2 - (k - 1) + 1];
      if (slaves + buf[i].first > b) {
        fans = min(fans, buf[i].second);
      }
    } else {
      if (sss[n - 2 - k + 1] > b) fans = min(fans, buf[i].second);
    }
  }
  cout << fans + 1;
  return 0;
}
