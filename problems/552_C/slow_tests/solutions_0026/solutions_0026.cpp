#include <bits/stdc++.h>
using namespace std;
long long w, m, val[105];
map<long long, int> sb;
int ed, st = 1, limit;
bool dfs(int cur, long long tmp) {
  if (cur == ed) {
    if (st)
      sb[tmp]++;
    else {
      if (sb.count(m - tmp))
        return true;
      else
        return false;
    }
  } else {
    if (dfs(cur + 1, tmp) || dfs(cur + 1, tmp + val[cur]) ||
        dfs(cur + 1, tmp - val[cur]))
      return true;
    return false;
  }
  return false;
}
int main(int argc, char *argv[]) {
  cin >> w >> m;
  val[0] = 1;
  for (int i = 1; i <= 101; ++i) {
    val[i] = val[i - 1] * w;
    if (val[i] > m) {
      limit = i;
      break;
    }
  }
  limit++;
  int mid = limit / 2;
  ed = mid;
  dfs(0, 0);
  ed = limit;
  st = 0;
  if (dfs(mid, 0))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
