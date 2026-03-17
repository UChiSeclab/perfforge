#include <bits/stdc++.h>
using namespace std;
vector<int> num;
vector<int> pos;
int main(void) {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int tnum;
    cin >> tnum;
    num.push_back(tnum);
  }
  int posLen = 0;
  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    int x = num[i];
    while (x > 0) {
      pos.push_back(x);
      posLen++;
      x /= 2;
    }
  }
  for (int id = 0; id < posLen; id++) {
    vector<int> cnt;
    for (int i = 0; i < n; i++) {
      int cur = 0;
      int x = num[i];
      while (x > pos[id]) {
        x /= 2;
        cur++;
      }
      if (x == pos[id]) {
        cnt.push_back(cur);
      }
    }
    if (int(cnt.size()) < k)
      continue;
    else {
      sort(cnt.begin(), cnt.end());
      ans = min(ans, accumulate(cnt.begin(), cnt.begin() + k, 0));
    }
  }
  cout << ans << endl;
  return 0;
}
