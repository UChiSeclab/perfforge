#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long ans = 1e18;
  for (long long i = 0; i < n; i++) {
    long long cnt = 0, tmpp = v[i];
    bool bl = true;
    while (tmpp >= 0) {
      if (bl == false) {
        break;
      }
      if (tmpp == 0) {
        bl = false;
      }
      vector<long long> tmp;
      for (long long j = 0; j < n; j++) {
        if (j == i) {
          continue;
        }
        if (tmpp == v[j]) {
          tmp.push_back(0);
        } else if (v[i] > v[j]) {
          continue;
        } else {
          long long nm = v[j], cl = 0;
          while (nm != tmpp) {
            nm /= 2;
            cl++;
            if (nm <= tmpp) {
              break;
            }
          }
          if (nm == tmpp) {
            tmp.push_back(cl);
          } else {
            continue;
          }
        }
      }
      if (tmp.size() < k - 1) {
        tmpp /= 2;
        cnt++;
        continue;
      }
      sort(tmp.begin(), tmp.end());
      long long qq = 0;
      for (long long y = 0; y < k - 1; y++) {
        qq += tmp[y];
      }
      qq += cnt;
      if (qq < ans) {
        ans = qq;
      }
      tmpp /= 2;
      cnt++;
    }
  }
  cout << ans;
}
