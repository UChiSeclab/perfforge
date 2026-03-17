#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, b;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> b;
  map<int64_t, int64_t> mp;
  int64_t count = 0;
  int64_t tmp = b;
  if (tmp % 2 == 0) {
    while (tmp % 2 == 0) {
      count++;
      tmp = tmp / 2;
    }
    mp[2] = count;
  }
  for (int64_t i = (3); i <= (sqrt(tmp)); i++) {
    count = 0;
    while (tmp % i == 0) {
      count++;
      tmp = tmp / i;
    }
    if (count) mp[i] += count;
  }
  if (tmp > 2) mp[tmp] += 1;
  int64_t miin = 1000000000000000000;
  int64_t t1, one;
  int64_t cnt;
  for (auto kk : mp) {
    if (kk.second == 0) continue;
    one = kk.first;
    t1 = n;
    cnt = 0;
    while (t1 >= one) {
      cnt += (t1 / one);
      t1 = t1 / one;
    }
    miin = min(miin, cnt / kk.second);
  }
  cout << miin << endl;
}
