#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 3;
long long n, a, cnt, ans, sum, k;
map<long long, long long> mp, pm;
void DNM() {
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    cin >> a;
    if (a < k) mp[a]++;
  }
  while (1) {
    cnt = 0;
    pm.clear();
    for (long long i = 1; i < k; i++) {
      if (mp[i] > 0) mp[i]--, pm[i + 1]++, cnt = 1;
    }
    for (long long i = 1; i < k; i++) mp[i] += pm[i];
    if (cnt == 0) {
      cout << sum << endl;
      return;
    }
    sum++;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int Qu_l_uQ = 1;
  while (Qu_l_uQ--) DNM();
}
