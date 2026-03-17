#include <bits/stdc++.h>
using namespace std;
long long n, m, an, maxh, ans1, ans2, i;
map<long long, long long> mp;
long long s;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> n >> m;
  ans1 = 0;
  ans2 = 0;
  mp[0] = 1;
  while (n != 0 && m != 0) {
    long long b1 = ans1, b2 = ans2;
    while (mp[ans1] == 1) ans1 += 2;
    while (mp[ans2] == 1) ans2 += 3;
    if (ans1 < ans2) {
      mp[ans1] = 1, n--, ans2 = b2;
    } else if (ans1 == ans2) {
      if (n <= m) {
        mp[ans2] = 1, m--, ans1 = b1;
      } else {
        mp[ans1] = 1, n--, ans2 = b2;
      }
    } else {
      mp[ans2] = 1, m--, ans1 = b1;
    }
  }
  while (n != 0) {
    while (mp[ans1] == 1) ans1 += 2;
    mp[ans1] = 1;
    n--;
  }
  while (m != 0) {
    while (mp[ans2] == 1) ans2 += 3;
    mp[ans2] = 1;
    m--;
  }
  cout << max(ans1, ans2);
  ;
  return 0;
}
