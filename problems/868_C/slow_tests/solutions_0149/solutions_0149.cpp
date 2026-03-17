#include <bits/stdc++.h>
using namespace std;
set<int> si;
int n, k;
bool solve(set<int> &cands, vector<int> &chosen) {
  if (cands.empty()) {
    if (chosen.empty()) {
      return false;
    }
    for (int i = 0; i < k; ++i) {
      int cnt = 0;
      for (const int num : chosen) {
        cnt += (((num >> i) & 0x1) ? -1 : 1);
      }
      if (cnt < 0) {
        return false;
      }
    }
    return true;
  }
  int val = *cands.begin();
  bool ok = false;
  cands.erase(val);
  ok |= solve(cands, chosen);
  chosen.push_back(val);
  ok |= solve(cands, chosen);
  chosen.pop_back();
  cands.insert(val);
  return ok;
}
int main(int argc, char **argv) {
  std::ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int val = 0;
    for (int j = 0; j < k; ++j) {
      int t;
      cin >> t;
      val |= (t << j);
    }
    si.insert(val);
  }
  vector<int> chosen;
  cout << (solve(si, chosen) ? "YES\n" : "NO\n");
}
