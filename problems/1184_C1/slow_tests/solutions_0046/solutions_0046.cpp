#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> ar(4 * n + 1);
  for (int i = (0); i < 4 * n + 1; i++) cin >> ar[i].first >> ar[i].second;
  for (int i = (0); i < 51; i++) {
    for (int j = (0); j < 51; j++) {
      for (int k = (0); k < 51; k++) {
        int cnt = 0;
        pair<int, int> te;
        for (int l = (0); l < 4 * n + 1; l++) {
          if (!(ar[l].first == i + k || ar[l].first == i || ar[l].second == j ||
                ar[l].second == j + k) ||
              ar[l].first > i + k || ar[l].second > j + k || ar[l].first < i ||
              ar[l].second < j)
            cnt++, te = ar[l];
        }
        if (cnt == 1) {
          cout << te.first << " " << te.second << "\n";
          return 0;
        }
      }
    }
  }
}
