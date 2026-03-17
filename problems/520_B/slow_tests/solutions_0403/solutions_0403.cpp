#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  queue<int> q;
  q.push(n);
  map<int, int> mp;
  mp[n] = 1;
  while (q.size()) {
    int cur = q.front();
    q.pop();
    if (cur == m) break;
    if (cur != 1 && mp[cur - 1] == 0)
      q.push(cur - 1), mp[cur - 1] = mp[cur] + 1;
    if (mp[cur * 2] == 0 && cur <= m)
      q.push(cur * 2), mp[cur * 2] = mp[cur] + 1;
  }
  cout << mp[m] - 1;
  return 0;
}
