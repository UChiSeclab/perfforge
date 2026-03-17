#include <bits/stdc++.h>
using namespace std;
int n, k;
long long dp[202][202][202];
string s, t;
long long fun(int pos, int mov, long long ase) {
  if (pos < 0) {
    return 0;
  }
  if (dp[pos][mov][ase] != -1) {
    return dp[pos][mov][ase];
  }
  long long res = 0;
  if (s[pos] == t[0]) {
    if (t[0] == t[1]) {
      res = max(res, ase + fun(pos - 1, mov, ase + 1));
    } else
      res = max(res, ase + fun(pos - 1, mov, ase));
  }
  if (s[pos] == t[1]) {
    if (t[0] == t[1]) {
      res = max(res, ase + fun(pos - 1, mov, ase + 1));
    } else
      res = max(res, fun(pos - 1, mov, ase + 1));
  }
  if ((mov - 1) >= 0) {
    if (t[0] == t[1]) {
      res = max(res, ase + fun(pos - 1, mov - 1, ase + 1));
    }
    res = max(res, ase + fun(pos - 1, mov - 1, ase));
    res = max(res, fun(pos - 1, mov - 1, ase + 1));
    if (s[pos] == t[1]) {
      if (t[0] == t[1])
        res = max(res, ase + fun(pos - 1, mov, ase + 1));
      else
        res = max(res, fun(pos - 1, mov, ase + 1));
    } else {
      res = max(res, fun(pos - 1, mov, ase));
    }
  } else {
    if (s[pos] == t[1]) {
      if (t[0] == t[1])
        res = max(res, ase + fun(pos - 1, mov, ase + 1));
      else
        res = max(res, fun(pos - 1, mov, ase + 1));
    } else {
      res = max(res, fun(pos - 1, mov, ase));
    }
  }
  return dp[pos][mov][ase] = res;
}
int main() {
  while (cin >> n >> k) {
    cin >> s >> t;
    memset(dp, -1, sizeof dp);
    cout << fun(n - 1, k, 0) << endl;
  }
  return 0;
}
