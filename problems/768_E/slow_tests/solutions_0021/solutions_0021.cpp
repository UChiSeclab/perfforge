#include <bits/stdc++.h>
using namespace std;
map<pair<int, long long>, int> gru;
int grundy(int u, long long w) {
  if (u == 0) return 0;
  if (gru.find(make_pair(u, w)) != gru.end()) return gru[make_pair(u, w)];
  set<int> yo;
  for (int i = 1; i <= u; i++) {
    if ((w & (1 << i)) == 0) {
      yo.insert(grundy(u - i, (w | (1 << i))));
    }
  }
  set<int>::iterator it;
  int ans = 0;
  for (it = yo.begin(); it != yo.end(); it++) {
    if (ans != *it) {
      break;
    }
    ans++;
  }
  return gru[make_pair(u, w)] = ans;
}
int main() {
  int ans = 0;
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    ans ^= grundy(x, 0);
  }
  if (ans == 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
