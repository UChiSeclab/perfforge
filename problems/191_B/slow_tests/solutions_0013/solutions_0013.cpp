#include <bits/stdc++.h>
using namespace std;
ifstream Cin("input.txt");
ofstream Cout("output.txt");
int main() {
  long long n, k, scur, s, sum = 0, i, cur, cmin;
  cin >> n >> k >> s;
  vector<pair<long long, long long> > r(n), r_sort = r;
  cmin = n - 1;
  n--;
  if (k == 1) {
    for (i = 0; i < n; i++) {
      cin >> r[i].first;
      if (r[i].first > s) cmin = min(cmin, i);
    }
  } else {
    for (i = 0; i < n; i++) {
      cin >> r[i].first;
      r[i].second = i;
    }
    r_sort = r;
    sort(r_sort.rbegin(), r_sort.rend());
    for (i = 0; i < n && i < k; i++) sum += r_sort[i].first;
    for (cur = 0; cur < n; cur++) {
      scur = sum;
      if (r[cur].first >= r_sort[k - 1].first) {
        scur -= r[cur].first;
      } else {
        scur -= r_sort[k - 1].first;
      }
      if (r[cur].first > s - scur) cmin = min(cmin, cur);
    }
  }
  cout << cmin + 1;
}
