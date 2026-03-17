#include <bits/stdc++.h>
using namespace std;
const int kInf = 1e9;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int& ai : a) cin >> ai;
  sort(a.begin(), a.end());
  int q;
  cin >> q;
  for (int qi = 0; qi < q; ++qi) {
    int x;
    cin >> x;
    int answer = kInf;
    for (int cnt = 1; cnt <= k; ++cnt) {
      for (int cnt1 = 1; cnt1 <= cnt; cnt1++) {
        int cnt2 = cnt - cnt1;
        vector<int> b = a;
        for (int& bi : b) bi *= cnt2;
        int it = b.size() - 1;
        for (const int& ai : a) {
          int rem = x - ai * cnt1;
          if (rem == 0) answer = min(answer, cnt1);
          if (rem < 0) break;
          while (it >= 0 && b[it] > rem) it--;
          if (it >= 0 && b[it] == rem) answer = min(answer, cnt);
        }
      }
    }
    if (answer == kInf) answer = -1;
    cout << answer << endl;
  }
  return 0;
}
