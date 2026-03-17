#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  long long k[n];
  long long curst = 1, curval = -1;
  for (long long i = 0; i < n; i++) {
    if (curst == i + 1) {
      curval++;
      curst *= 2;
    }
    k[i] = curval;
  }
  cerr << "k : \n";
  for (long long i = 0; i < n; i++) {
    cerr << k[i] << ' ';
  }
  cerr << endl;
  long long a[n];
  long long num;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == -1) num = i;
  }
  multiset<long long> s;
  long long it = n - 1;
  long long ans = 0;
  for (long long i = curval; i > k[num]; i--) {
    while (k[it] == i) {
      s.insert(a[it]);
      it--;
    }
    ans += *(s.begin());
    s.erase(s.begin());
  }
  cout << ans;
  return 0;
}
