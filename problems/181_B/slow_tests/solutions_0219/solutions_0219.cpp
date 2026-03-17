#include <bits/stdc++.h>
using namespace std;
int main() {
  float n, ans = 0, x, y, a, b;
  int i, j, k, s, e, mid;
  cin >> n;
  vector<pair<long long, long long> > v;
  for (i = 0; i < n; i++) {
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  sort(v.begin(), v.end());
  for (i = 0; i < (n - 2); i++)
    for (j = i + 2; j < n; j++) {
      a = (v[i].first + v[j].first) / 2.0;
      b = (v[i].second + v[j].second) / 2.0;
      s = i + 1;
      e = j - 1;
      while (s <= e) {
        mid = (s + e) / 2;
        if (v[mid].first == a && v[mid].second == b) {
          ans++;
          break;
        } else if (v[mid].first > a)
          e = mid - 1;
        else if (v[mid].first < a)
          s = mid + 1;
        else if (v[mid].first == a) {
          if (v[mid].second > b)
            e = mid - 1;
          else if (v[mid].second < b)
            s = mid + 1;
        }
      }
    }
  cout << ans << endl;
  return 0;
}
