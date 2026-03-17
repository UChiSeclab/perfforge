#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int a[maxn], n;
map<int, int> mp;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i = i * 2) mp[i] = 1;
  long long ans = 0;
  multiset<int> s;
  for (int i = n; i >= 1; i--) {
    if (a[i] == -1) break;
    s.insert(a[i]);
    if (mp[i]) {
      ans += *s.begin();
      s.erase(s.begin());
    }
  }
  cout << ans << endl;
  return 0;
}
